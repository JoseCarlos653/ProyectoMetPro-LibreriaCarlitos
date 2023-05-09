#ifndef USUARIO
#define USUARIO 
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std; 




char pathUsuario[300]="D:\\Personal\\Escritorio\\PROYECTO CODIGO\\Proyecto METPRO\\Registro\\usuario.dat";

struct usuario{
    char username[20];
    char pass[20];
    int rol; 
};

// Estructura que me va permitir regresar un usuario y un entero. 1. autentificado 0. no autentificado
struct usuarioauth{
    int n;
    usuario us;
};

void guardarUsuarioArchivo(usuario user)
{
    FILE * ptr = NULL; 
    ptr = fopen(pathUsuario, "a+");
    fwrite(&user, sizeof(struct usuario),1, ptr);
    fclose(ptr);
    cout<< "\nLa información del usuario "<< user.username << " se ha guardado exitosamente\n";
    
}

// funcion que se encarga de crear el primer usuario si no existe registro 1. Admin 0. trabajador
void primerUsuario()
{
    FILE * ptr = NULL; 
    ptr = fopen(pathUsuario, "rb");

    if ( ptr == NULL){
        fclose(ptr);
        ptr = fopen(pathUsuario, "wb");
        fclose(ptr);
        usuario user;
        cout<< "\n::Creando el primer usuario";
        cout<< "\nIngrese su nombre de usuario: ";
        cin >> user.username;
        cout<< "\nIngrese su contraseña : ";
        cin >> user.pass;
        user.rol = 1; 
        
        guardarUsuarioArchivo(user);
        
    }

    fclose(ptr);
}
usuarioauth autenticarUsuario(){
    usuario user; // aca vamos almacenar los datos que ingrese el usuario
    usuario registro; // sirve para el fread
    usuarioauth userAuth;
    userAuth.n=0; // se cambiara a 1 si se encuentra el usuario. Sirve para validar en el principal 
    cout<< "\n---Inicio de sesion---";
    cout<< "\nIngrese su nombre de usuario: ";
    cin >> user.username;
    cout<< "\nIngrese su contraseña : ";
    cin >> user.pass;


    FILE * ptr = NULL; 
    ptr = fopen(pathUsuario, "rb");
    if (ptr != NULL){

         while ( fread(&registro, sizeof(struct usuario),1, ptr)==1)
         {
           
            if (strcmp(registro.username, user.username)==0 && strcmp(registro.pass, user.pass)==0){
                cout<< "\nInformacion correcta\n\n";
                userAuth.n = 1; //significa que encontro el usuario
                userAuth.us = registro; 
                return userAuth; 
                
            }
         }
    }
    fclose(ptr);
    return userAuth;
}

void leerUsuario(usuario us)
{
    if (us.rol ==1){
        usuario registro;
        FILE * ptr = NULL; 
        ptr = fopen(pathUsuario, "r");

        if ( ptr != NULL){
            cout<<"\n---INFORMACION USUARIO---";
            cout<<"\nUsuasrio\tContraseña\tRol\n";
            while(fread(&registro, sizeof(struct usuario), 1, ptr)==1){
                
                cout<<registro.username<<"\t"<<"\t"<<registro.pass<<"\t"<<"\t"<<registro.rol<<"\n";
            }
      
        }

    fclose(ptr);
    }else {
        cout<<"\nNo tienes permiso suficiente para acceder a este modulo \n\n";
    }
    
}

void guardarUsuario(usuario us)
{
    if (us.rol == 1){
        usuario user; 
        cout<< "\nIngrese su nombre de usuario: ";
        cin >> user.username;
        cout<< "\nIngrese su contraseña : ";
        cin >> user.pass;
        cout<<"\nIngrese rol del usuario (1. Admin, 0.Trabajador): ";
        cin>> user.rol; 

        guardarUsuarioArchivo(user);
        cout<< "\nUsuario "<< user.username << " guardado exitosamente\n";
      
    }else{
        cout<<"\nNo tienes suficiente permiso para este modulo\n\n ";
    }



}

void editarUsuarioArchivo(long int posicion, usuario user)
{
    FILE * ptr = NULL; 
    ptr = fopen(pathUsuario, "r+");
    fseek(ptr, (posicion-sizeof(struct usuario)), SEEK_SET);
    fwrite(&user, sizeof(struct usuario),1, ptr);
    fclose(ptr);
    cout<< "\nLa información del usuario "<< user.username << " ha sido actualizada exitosamente\n";

}


void editarUsuario(usuario us)
{
    usuario registro;
    cout<<"\n---EDITANDO USUARIO\n";
    if (us.rol ==0 || us.rol ==1){
        cout<<"\nNombre de usuario: "<< us.username; 
        cout<<"\nIngresa tu nueva contraseña: ";
        cin>> us.pass;
        
        FILE * ptr = NULL; 
        ptr = fopen(pathUsuario, "r");

        while (fread(&registro, sizeof(struct usuario), 1, ptr)==1)
        {  
            if ( strcmp(registro.username, us.username)==0 && strcmp(registro.pass, us.pass)){
                long int posicion = ftell(ptr);
                fclose(ptr);
                editarUsuarioArchivo(posicion, us);
                break;
            }

        }
        fclose(ptr);

    }
}

#endif