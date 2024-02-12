#ifndef DIRECTORIO_H
#define DIRECTORIO_H

#include "definiciones.h"
#include "lista.h"

// Estructuras de Datos y Algoritmos - Curso 2023
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// Trabajo Obligatorio
// directorio.h
// Modulo de Definición de directorio.

typedef struct nodo_directorio * directorio;

directorio Crear_Directorio(Cadena nombre);
//Retorna un directorio de nombre "nombre".

listaA GetListaArchivo(directorio directorio);
//Retorna la lista de archivos de un directorio.

void SetListaArchivo(directorio directorio, listaA archivo);
//Funcion que asigna la lista de archivos al archivo.

bool PERTENECE_ARCHIVO (directorio a, Cadena nombre);
//Funcion que retorna true si el archivo pertenece al directorio, false en caso contrario

void ImprimirArchivos(directorio dir);
//Funcion que imprime el archivo.

void AgregarArchivo(directorio dir, Cadena nombreArchivo);
//Funcion que agrega un archivo a la lista.

void ACTUALIZAR_PERMISOS (directorio dir, Cadena nombre, bool esEscritura);
//Funcion que actualiza los permisos de los Archivos
//PRE: Tiene que existir un archivo con ese nombre

bool SOLO_LECTURA(directorio dir, Cadena nombre);
//Funcion que retorna TRUE si el archivo es solo lectura, false si es lectura y Escritura
//PRE: Tiene que existir un archivo con ese nombre

void ELIMINAR_ARCHIVO(directorio dir, Cadena nombreArchivo);
//Funcion que elimina el archivo de un directorio
//PRE: Tiene que existir un archivo con ese nombre

Cadena GetContenido(directorio dir, Cadena nombre);
//Funcion que devuelve el contenido del archivo.

void InsertarContenido(directorio dir, Cadena archivo, Cadena texto);
//Funcion que inserta el contenido dentro del archivo.
//PRE: Tiene que existir un archivo con ese nombre y no debe superar la cantidad maxima (22)

void InsertarContenidoFinal(directorio dir, Cadena archivo, Cadena texto);
//Funcion que inserta el contenido al final de un archivo.
//PRE: Tiene que existir un archivo con ese nombre y no debe superar la cantidad maxima (22)

void EliminarComienzo(directorio dir,Cadena archivo,int cantidad);
//Funcion que elimina el contenido al comienzo del archivo.
//PRE: Tiene que existir un archivo con ese nombre

void EliminarFinal(directorio dir, Cadena archivo, int cantidad);
//Funcion que elimina el contenido al final del archivo.
//PRE: Tiene que existir un archivo con ese nombre

void BorrarTodosLosArchivos(directorio dir);
//Funcion que borra los archivos en un directorio

bool ExisteContenido(directorio dir,Cadena archivo, Cadena texto);
//Funcion que devuelve true si el texto esta contenido en un archivo, devuelve false en caso contrario
//PRE: Tiene que existir un archivo con ese nombre

void ReemplazarContenido(directorio dir,Cadena nombreArchivo,Cadena texto1,Cadena texto2);
//Funcion que remplaza el contenido del archivo del textot1 al texto2.
//PRE: Tiene que existir un archivo con ese nombre, que contenga "texto1" y que no supere la cantidad maxima(22)

void Setpadre(directorio actual, directorio padre);
//Funcion que Setea el directorio padre al actual.

void Agregarhijo(directorio actual, directorio hijo);
//Funcion que setea el directorio hijo al actual.

void Sethermano(directorio actual, directorio herm);
//Funcion que setea el directorio hermano al actual.

void ImprimirDirectorio(directorio actual);
//Funcion que muestra los directorios

void Imprimir_Todos_Directorios(directorio actual);

void ImprimirRaizDir(directorio actual,Cadena nombre);

void Devolver_NombreDir(directorio actual, Cadena nombre);
//
directorio GetHijo(directorio dir);

void InsertarDirOrdenado(directorio dir,directorio insertar);

bool ExisteDirectorio(directorio dir, Cadena  nombre);

directorio GetPadre(directorio dir);

directorio ConseguirDirectorio(directorio dir, Cadena nombre);

void ELIMINAR_DIRECTORIO (directorio dir1, directorio dir);

void IMPRIMIR_TODO (directorio dir, Cadena nombre);

#endif
