// Estructuras de Datos y Algoritmos - Curso 2023
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// Trabajo Obligatorio
// directorio.c
// Modulo de Implementacion de directorio.

#include "directorio.h"
#include "definiciones.h"
#include "lista.h"
#include <iostream>
#include "archivo.h"

#include <string.h>
using namespace std;

struct nodo_directorio
{
	// directorios ver seg entrega
	// archivos archs;
	Cadena nombre;
	listaA lista_archivos;
	directorio padre;
	directorio sig_herm;
	directorio pr_hijo;
};

directorio Crear_Directorio(Cadena nombre)
{
	// Retorna un directorio de nombre "nombre".
	directorio d = new (nodo_directorio);
	d->nombre = new char[MAX_NOMBRE];
	strcpy(d->nombre, nombre);
	d->lista_archivos = crear();
	d->padre = NULL;
	d->sig_herm = NULL;
	d->pr_hijo = NULL;
	return d;
}

listaA GetListaArchivo(directorio directorio)
{
	return directorio->lista_archivos;
}

void SetListaArchivo(directorio directorio, listaA archivo)
{
	directorio->lista_archivos = archivo;
}

bool PERTENECE_ARCHIVO(directorio dir, Cadena nombre)
{
	// devuelve 1 si el ARCHVO pertenece al directorio y 0 en caso contrario.
	return PERTENECE_LISTA(dir->lista_archivos, nombre);
}

void ImprimirArchivos(directorio dir)
{
	ImprimirNombres(dir->lista_archivos);
}

void AgregarArchivo(directorio dir, Cadena nombreArchivo)
{
	SetListaArchivo(dir, InsertarOrdenado(GetListaArchivo(dir), CREAR_ARCHIVO(nombreArchivo)));
	cout << "Cantidad de archivos: " << cant(GetListaArchivo(dir)) << "\n";
}

void ACTUALIZAR_PERMISOS(directorio dir, Cadena nombre, bool esEscritura)
{
	CAMBIAR_PERMISO(DEVOLVER_ARCHIVO(GetListaArchivo(dir), nombre), esEscritura);
}

bool SOLO_LECTURA(directorio dir, Cadena nombre)
{

	return ES_SOLO_LECTURA(DEVOLVER_ARCHIVO(GetListaArchivo(dir), nombre));
}

void ELIMINAR_ARCHIVO(directorio dir, Cadena nombre)
{
	SetListaArchivo(dir, elim(GetListaArchivo(dir), DEVOLVER_ARCHIVO(GetListaArchivo(dir), nombre)));
}

Cadena GetContenido(directorio dir, Cadena nombre)
{

	return DEVOLVER_CONTENIDO(DEVOLVER_ARCHIVO(GetListaArchivo(dir), nombre));
}

void InsertarContenido(directorio dir, Cadena archivo, Cadena texto)
{

	INSERTAR_COMIENZO(DEVOLVER_ARCHIVO(GetListaArchivo(dir), archivo), texto);
}

void InsertarContenidoFinal(directorio dir, Cadena archivo, Cadena texto)
{
	INSERTAR_ALFINAL(DEVOLVER_ARCHIVO(GetListaArchivo(dir), archivo), texto);
}

void EliminarComienzo(directorio dir, Cadena archivo, int cantidad)
{
	ELIMINAR_COMIENZO(DEVOLVER_ARCHIVO(GetListaArchivo(dir), archivo), cantidad);
}

void EliminarFinal(directorio dir, Cadena archivo, int cantidad)
{
	ELIMINAR_ALFINAL(DEVOLVER_ARCHIVO(GetListaArchivo(dir), archivo), cantidad);
}

void BorrarTodosLosArchivos(directorio dir)
{
	BorrarLista(GetListaArchivo(dir));
}

bool ExisteContenido(directorio dir, Cadena archivo, Cadena texto)
{
	return Contiene(DEVOLVER_ARCHIVO(GetListaArchivo(dir), archivo), texto);
}

void ReemplazarContenido(directorio dir, Cadena nombreArchivo, Cadena texto1, Cadena texto2)
{
	REEMPLAZAR_CONTENIDO(DEVOLVER_ARCHIVO(GetListaArchivo(dir), nombreArchivo), texto1, texto2);
}

void Setpadre(directorio actual, directorio padre)
{
	actual->padre = padre;
}

void Agregarhijo(directorio padre, directorio hijo)
{
	hijo->padre = padre;
	if (padre->pr_hijo == NULL)
	{
		padre->pr_hijo = hijo;
	}
	else
	{
		if (strcasecmp(padre->pr_hijo->nombre, hijo->nombre) > 0)
		{
			hijo->sig_herm = padre->pr_hijo;
			padre->pr_hijo = hijo;
		}
		else
		{
			InsertarDirOrdenado(padre->pr_hijo, hijo);
		}
	}
}

void InsertarDirOrdenado(directorio dir, directorio insertar)
{

	if (dir->sig_herm == NULL)
	{
		dir->sig_herm = insertar;
	}
	else if (strcasecmp(dir->sig_herm->nombre, insertar->nombre) > 0)
	{
		std::cout << "Insertando: " << insertar->nombre << " contra: " << dir->sig_herm->nombre;
		directorio aux = dir->sig_herm;
		dir->sig_herm = insertar;
		insertar->sig_herm = aux;
	}
	else
	{
		InsertarDirOrdenado(dir->sig_herm, insertar);
	}
}

void Sethermano(directorio actual, directorio herm)
{
	actual->sig_herm = herm;
}

void Devolver_NombreDir(directorio actual, Cadena nombre)
{
	strcpy(nombre, actual->nombre);
}

void ImprimirRaizDir(directorio actual, Cadena nombre)
{
	if (actual->padre == NULL)
	{
		std::cout << actual->nombre;
	}
	else if (strcasecmp(actual->nombre, nombre) == 0)
	{
		std::cout << actual->nombre;
	}
	else
	{
		ImprimirRaizDir(actual->padre, nombre);
		std::cout << "/" << actual->nombre;
	}
}
void ImprimirDirectorio(directorio actual)
{
}

void Imprimir_Todos_Directorios(directorio actual)
{

	if (actual != NULL)
	{
		std::cout << actual->nombre << '\n';
		Imprimir_Todos_Directorios(actual->sig_herm);
	}
}

directorio GetHijo(directorio dir)
{
	return dir->pr_hijo;
}

bool ExisteDirectorio(directorio dir, Cadena nombre)
{
	directorio hijo = dir->pr_hijo;
	while (hijo != NULL)
	{
		if (strcasecmp(hijo->nombre, nombre) == 0)
		{
			return true;
		}
		hijo = hijo->sig_herm;
	}
	return false;
}

directorio GetPadre(directorio dir)
{
	return dir->padre;
}

directorio ConseguirDirectorio(directorio dir, Cadena nombre)
{

	if (dir == NULL)
	{
		return NULL;
	}
	{
		directorio hijo = dir->pr_hijo;
		while (hijo != NULL)
		{
			if (strcasecmp(hijo->nombre, nombre) == 0)
			{
				return hijo;
			}
			hijo = hijo->sig_herm;
		}
	}
	return NULL;
}

Cadena IMPRIMIR_TODO (directorio dir, Cadena nombre){

while (dir != NULL) {
	Devolver_NombreDir(dir);

	IMPRIMIR_TODO(dir->sig_herm);
}
