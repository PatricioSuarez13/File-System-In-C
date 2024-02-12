#ENGLISH
# File-System-In-C
This is a Mini File System made in C, it has some basic commands like creating directories or files, manipulating their parameters, etc. It was a Work at my University so the commands are in Spanish so if you have any doubts please read this README 


File System In C

Welcome to my File System, this is a system made completely in C. it can create directories, files, manipulating their parameters or even adding text to them. It simulates as if it were a Linux system, so the commands would be practically the same.

What can it do?

# CD nombreDirectorio
With this one you can move between the directories you have created the format is the same as beeing in Linux (Ex. CD exampleDirectory). Note: When booting up the system it creates the RAIZ (ROOT in english) directory. 
# MKDIR nombreDirectorio
With this command you can create as many directories as you want. the format is the same as beeing in Linux (Ex. MKDIR exampleDirectory).
# RMDIR nombreDirectorio
With this command you can delete the directories you have created , it doesn't have options like in Linux, like -rf (Ex. RMDIR exampleDirectory). Note: When deleting a directory with files in it, it alse deletes the files in it. Note: For Deleting a directory it must have been created first, otherwise, a ERROR message will be displayed.
# MOVE nombre directorioDestino
With this command you can move files to other directories, you only need the name of the file and the name of the destination directory (Ex. MOVE exampleFile exampleDirectory). Note: the file and the destinaton directory must be created first, otherwise, an ERROR message will be displayed
# DIR parametro
This command displays the contents of the current directory, whether subdirectories or files. using the /S parameter it displays the directory structure starting from the current directory, organized as follows: first the full path of the current directory is printed, from the ROOT directory. The files are then listed. Current directory and subsequently the content of each of the subdirectories following the same procedure (recursively).
# CREATEFILE nombreArchivo
This commands creates a file in the current directory you're in (Ex. CREATEFILE exampleFile). Note: you can't create a file with the same name twice, otherwise an ERROR message will be displayed.
# DELETE nombreArchivo
This command deletes a file from the current directory, as long as it is not read-only. (Ex. DELETE exampleArchive) Note: the file must have been created first, otherwise an ERROR message will be displayed.
# ATTRIB nombreArchivo parametro
This command changes the attributes of a file belonging to the current directory. For example, if we have a given structure and considering that the current directory is "exampleDirecotry", if we want the file "file112.txt" to be
read only, then: ATTRIB file112.txt -W
# IC nombreArchivo texto
Adds some text to the beginning of the file FileName. If the total length allowed is exceeded, the resulting text will be truncated at the end so as not to exceed the total length TEXT_MAX. (Ex. IC file112.txt “The fish”). Note: the file must be created first an must have the write permission, otherwise an ERROR message will be displayed
# IF nombreArchivo texto
Adds some text to the end of the file FileName. If the total length allowed is exceeded, the resulting text will be truncated at the end so as not to exceed the total length TEXT_MAX. (Ex. IF file112.txt “from the pond”). Note: the file must be created first an must have the write permission, otherwise an ERROR message will be displayed 
# DC nombreArchivo k
Removes at most K first characters from the parameter file. Regarding the previous example, (Ex. DC file112.txt 13).
# DF nombreArchivo k
Removes at most K last characters from the parameter file. Regarding the previous example, (DF file112.txt 6).
# TYPE nombreArchivo
Prints the contents of the parameter file, regardless of its Read/Write condition (Ex. TYPE file112.txt).
# SEARCH nombreArchivo texto
Search within the file for the existence of the text. (Ex. SEARCH exampleFile HelloImAnExampleText).
# REPLACE nombreArchivo texto1 texto2
Searches and replaces within the file the existence of text1 with text2 (Ex. REPLACE exampleFile HelloImAnExampleText ImAnotherExampleTooLol).
# SALIR
This just terminates the program, eliminating the system and closing it.






