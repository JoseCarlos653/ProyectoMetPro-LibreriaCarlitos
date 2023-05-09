#include <stdio.h>
#include <stdlib.h>
#include <iostream>
char pathCliente[300]="D:\\Personal\\Escritorio\\PROYECTO CODIGO\\Proyecto METPRO\\Registro\\cliente.dat";
using namespace std;
struct cliente
{
    char ruc[11];
    char nombre[25];
    char apellido[25];
};

struct clienteauth{
    int n;
    cliente cs;
};

void guardarClienteArchivo(cliente client)
{
    FILE *ptr = NULL;
    ptr = fopen(pathCliente, "a+");
    fwrite(&client, sizeof(struct cliente),1,ptr);
    fclose(ptr);
    cout<< "\nLa información del cliente "<< client.nombre << " se ha guardado exitosamente\n";
}

void agregarCliente(cliente cs)
{
    cliente client;
    cout<< "\n---AGREGANDO CLIENTE---";
    cout<< "\nIngrese su nombre: ";
    cin >> client.nombre;
    cout<< "\nIngrese su apellido: ";
    cin >> client.apellido;
    cout<< "\nIngrese su RUC: ";
    cin>>client.ruc;
        
    guardarClienteArchivo(client);
    cout<< "\nCliente "<< client.nombre << " guardado exitosamente\n";
        
    
}

void verCliente(cliente cs)
{
    cliente registro;
    FILE * ptr = NULL; 
    ptr = fopen(pathCliente, "r");

    if ( ptr != NULL){
        cout<<"\n---INFORMACION USUARIO---";
        cout<<"\nCliente\t\tApellido\tRUC\n";
        while(fread(&registro, sizeof(struct cliente), 1, ptr)==1){
                
            cout<<registro.nombre<<"\t"<<"\t"<<registro.apellido<<"\t"<<"\t"<<registro.ruc<<"\n";
        }
      
    }

    fclose(ptr);   
}

/*void editarClienteArchivo(long int posicion, cliente client)
{
    FILE *ptr = NULL;
    ptr = fopen(pathCliente, "r+");
    fseek(ptr, (posicion-sizeof(struct cliente)), SEEK_SET);
    fwrite(&client, sizeof(struct cliente),1, ptr);
    fclose(ptr);
    cout<< "\nLa información del cliente "<< client.nombre << " ha sido actualizada exitosamente\n";
}*/

/*void editarCliente(cliente cs)
{
    cliente registro;
    cout<<"\n---EDITANDO USUARIO\n";
    
        
    FILE * ptr = NULL; 
    ptr = fopen(pathCliente, "r");

    while (fread(&registro, sizeof(struct cliente), 1, ptr)==1)
    {  
        if (strcmp(registro.nombre, cs.nombre)==0 && strcmp(registro.ruc, cs.ruc)){
            long int posicion = ftell(ptr);
            fclose(ptr);
            editarClienteArchivo(posicion, cs);
            break;
        }

    }
    fclose(ptr);
}
*/


