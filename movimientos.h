#ifndef MOVIMIENTO
#define MOVIMIENTO

#include <iostream>
#include <time.h>
#include "usuario.h"
#include  <string.h>


struct entrada
{
    char fecha[100];
    char nombreArticulo[100];
    int cantidad; 
    char usuario[100];
};
struct salida
{
    char fecha[100];
    char nombreArticulo[100];
    int cantidad; 
    char usuario[100];
};


char pathEntrada[300]= "D:\\Personal\\Escritorio\\PROYECTO CODIGO\\Proyecto METPRO\\Registro\\entrada.dat";
char pathSalida[300]= "D:\\Personal\\Escritorio\\PROYECTO CODIGO\\Proyecto METPRO\\Registro\\salida.dat";

using namespace std;

// funcion que recibe un char y obtiene la fecha del sistema almacenandola en el array. 
void obtenerFecha(char fechayhora[])
{
    time_t t;
    struct tm *tm;
    

    t=time(NULL);
    tm=localtime(&t);
    strftime(fechayhora, 100, "%d/%m/%Y", tm);
    
}

//Funcion que se encarga de crear el archivo entrada y salida .dat en caso de que no exista
void validacionArchivoEntrada()
{
    FILE * ptr = NULL;
    ptr = fopen(pathEntrada,"rb");
    if(ptr == NULL){
        fclose(ptr);
        ptr = fopen(pathEntrada,"wb");
        fclose(ptr);
    }else{
        fclose(ptr);
    }
}



//Funcion que se encarga de crear el archivo entrada y salida .dat en caso de que no exista
void validacionArchivoSalida()
{
    FILE * ptr = NULL;
    ptr = fopen(pathSalida,"rb");
    if(ptr == NULL){
        fclose(ptr);
        ptr = fopen(pathSalida,"wb");
        fclose(ptr);
    }else{
        fclose(ptr);
    }
}

// funciona que se encarga de guardar la informacion en en archivo. Retorna 1 si el proceso resulto exitoso. 
int agregarEntradaArchivo(entrada entrada)
{
    int a = 0; 
    FILE * ptr = NULL; 
    ptr = fopen(pathEntrada, "a+");
    if (fwrite(&entrada, sizeof(struct entrada),1, ptr)==1){
        a= 1;
    }
    fclose(ptr);
    return a; 
}
int agregarSalidaArchivo(salida salida)
{
    int a = 0; 
    FILE * ptr = NULL; 
    ptr = fopen(pathSalida, "a+");
    if (fwrite(&salida, sizeof(struct entrada),1, ptr)==1){
        a= 1;
    }
    fclose(ptr);
    return a; 
}


void mostrarEntradas()
{
        entrada registro;
        FILE * ptr = NULL; 
        ptr = fopen(pathEntrada, "rb");

        if ( ptr != NULL){
            cout<<"\n---REGISTRO DE ENTRADAS---";
            cout<<"\nFECHA\tNombre\tCANTIDAD\tUSUARIO\n\n";
            while(fread(&registro, sizeof(struct entrada), 1, ptr)==1){
                
                cout<<registro.fecha<<"\t"<<registro.nombreArticulo<<"\t"
                <<registro.cantidad<<"\t"<<registro.usuario<<endl;
            }
      
        }

    fclose(ptr);
}

void mostrarSalidas()
{
        salida registro;
        FILE * ptr = NULL; 
        ptr = fopen(pathSalida, "rb");

        if ( ptr != NULL){
            cout<<"\n---REGISTRO DE SALIDAS---";
            cout<<"\nFECHA\tNombre\tCANTIDAD\tUSUARIO\n\n";
            while(fread(&registro, sizeof(struct entrada), 1, ptr)==1){
                
                cout<<registro.fecha<<"\t"<<registro.nombreArticulo<<"\t"
                <<registro.cantidad<<"\t"<<registro.usuario<<endl;
            }
      
        }

    fclose(ptr);
}


#endif