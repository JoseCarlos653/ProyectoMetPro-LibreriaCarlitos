
#ifndef PRODUCTO
#define PRODUCTO

#include "usuario.h"
#include "movimientos.h"
#include "stdio.h"
#include <string.h>

struct producto
{
    char codigoBarra[100];
    char nombre[100];
    char marca[100];
    int cantidad; 
    char ubicacion[100];
};

// estructura que ocuparemos para listar todos los productos en memoria, almacenaremos un punteros y el numero de producto. 
struct lista
{
    int tamaño;
    producto *p;
};

char pathProducto [300]= "D:\\Personal\\Escritorio\\PROYECTO CODIGO\\Proyecto METPRO\\Registro\\producto.dat";

void enviarEntrada(producto producto, usuario us)
{
    entrada entrada;
    char fecha[100];
    obtenerFecha(fecha);
    
    validacionArchivoEntrada();
    
    strcpy(entrada.fecha, fecha);
    strcpy(entrada.nombreArticulo, producto.nombre);
    strcpy(entrada.usuario, us.username);
    entrada.cantidad =producto.cantidad; 
    
    if(agregarEntradaArchivo(entrada)!=1){
        cout<<"\nError al guardar Entrada";
    }

}



// funcion que guarda el producto en archivos binario. retorna 1 si se agrego exitosamente 
int agregarProductoArchivo(producto producto)
{
    int a = 0; 
    FILE * ptr = NULL; 
    ptr = fopen(pathProducto, "a+");
    if (fwrite(&producto, sizeof (struct producto),1, ptr)==1){
        a= 1;
    }
    fclose(ptr);
    return a; 
}

void agregarProducto(usuario us)
{
    FILE * ptr = NULL;
    ptr = fopen(pathProducto,"rb");
    if(ptr == NULL){
        fclose(ptr);
        ptr = fopen(pathProducto,"wb");
        fclose(ptr);
    }else{
        fclose(ptr);
    }
    char cb [100];
    char nombre[100];
    char marca[100];
    int cantidad;
    char ubicacion[100];
    
    producto producto; 
    cout<<"---AGREGAR PRODUCTO---- "<<endl;
    cout <<"\nIngresa el codigo de barra: ";
    scanf (" %[^\n]s", cb);
    
    cout<<"\nIngresa el nombre: ";
    scanf (" %[^\n]s",nombre);

    
    cout<<"\nIngresa la marca: ";
    scanf (" %[^\n]s", marca);

    cout<<"\nIngresa la cantidad: ";
    scanf("%i",&cantidad);

    cout<<"\nIngrese la ubicación: ";
    scanf (" %[^\n]s", ubicacion);
    
    //pegando resultados al producto 
    strcpy(producto.codigoBarra, cb);
    strcpy(producto.nombre, nombre);
    strcpy(producto.ubicacion, ubicacion);
    strcpy(producto.marca, marca);
    producto.cantidad= cantidad;


   
    if(agregarProductoArchivo(producto)==1){
        enviarEntrada(producto,us);
        cout<<"\nProducto Guardado exitosamente\n\n";
      
    }else{

         cout<<"\nError al guardar el producto\n\n";

    }
  
    
}
void mostrarProductos()
{
    producto registro;
        FILE * ptr = NULL; 
        ptr = fopen(pathProducto, "r");

        if ( ptr != NULL){
            cout<<"\n---INVENTARIO---";
            cout<<"\nCodigo Barra\t\tNombre\t\t\tMarca\t\tCantidad\t\tUbicación\n\n";
            
            
          
            while(fread(&registro, sizeof(struct producto), 1, ptr)==1){
               
                cout<<registro.codigoBarra<<"\t"<<"\t"<<registro.nombre<<"\t"<<"\t"
                <<registro.marca<<"\t"<<"\t"<<registro.cantidad<<"\t"<<"\t"<<"\t"<<registro.ubicacion <<"\n";
            }
      
        }

    fclose(ptr);
}
int obtenerTamañoArchivo()
{
    int a = 0;
    producto producto;
    FILE * ptr = NULL; 
    ptr = fopen(pathProducto, "r+b");

    
    while(fread(&producto, sizeof(struct producto),1, ptr)==1){
        a++;
    }
    fclose(ptr);
    
    return a;
}
lista listarProductos()
{
    lista listaTamaño; // declaramos una estructura tipo lista;
    int tamaño = obtenerTamañoArchivo(); // obtenemos la cantidad de archivos de productos almacenados 
    producto registro; // declaramos un producto registro que ocuparemos en el fread
    int i=0; // contador
    
   //gestionamos manualmente el uso de la memoria, por que no esta permitido hacer arreglos de tamaños variables.// debemos liberarla
    producto * lista =(producto*)malloc(sizeof(struct producto)*tamaño);



    FILE * ptr = NULL; 
    ptr = fopen(pathProducto, "r");

    //cargando todos los datos en memoría

    while (fread(&registro, sizeof(struct producto), 1, ptr)==1)
    {  
        strcpy(lista[i].codigoBarra, registro.codigoBarra);
        strcpy(lista[i].nombre, registro.nombre);
        strcpy(lista[i].marca, registro.marca);
        strcpy(lista[i].ubicacion, registro.ubicacion);
        lista[i].cantidad=registro.cantidad;
        i++;
    }
    fclose(ptr);
    listaTamaño.tamaño=tamaño;
    listaTamaño.p=lista;
    return listaTamaño; 
}

void actualizarProductoArchivo(int tamaño, producto lista[])
{
    FILE * ptr = NULL; 
    ptr = fopen(pathProducto, "w");
    if(tamaño ==0){
        for(int i=0; i<1; i++){
        fwrite(&lista[i],sizeof(struct producto),1,ptr);
    }
    }else{
        for(int i=0; i<tamaño; i++)
        {
        fwrite(&lista[i],sizeof(struct producto),1,ptr);
        }
    }
    
    fclose(ptr);
   

}
void editarProductoNombre()
{
    lista listaProducto;
    char nombre[100];
  //  producto registro;
    char nuevaUbicacion[100];
    cout<<"\nIntroduce el nombre: ";
    scanf (" %[^\n]s", nombre);

    listaProducto = listarProductos();
    
    
   //gestionamos manualmente el uso de la memoria, por que no esta permitido hacer arreglos de tamaños variables. 
    /*
    producto * lista =(producto*)malloc(sizeof(struct producto)*tamaño);


    FILE * ptr = NULL; 
    ptr = fopen(pathProducto, "r");

    //cargando todos los datos en memoría

   
    while (fread(&registro, sizeof(struct producto), 1, ptr)==1)
    {  
        strcpy(lista[i].codigoBarra, registro.codigoBarra);
        strcpy(lista[i].nombre, registro.nombre);
        strcpy(lista[i].marca, registro.marca);
        strcpy(lista[i].ubicacion, registro.ubicacion);
        lista[i].cantidad=registro.cantidad;
        i++;
    }
    fclose(ptr);
    */
    // buscando el archivo que quieres cambiar
    for(int j= 0; j<listaProducto.tamaño; j++){
        if(strcmp(listaProducto.p[j].nombre,nombre)==0){
            cout<<"\n--INFO ACTUAL---";
            cout<<"\nCodigo barra: " << listaProducto.p[j].codigoBarra;
            cout<<"\nNombre: "<< listaProducto.p[j].nombre;
            cout<<"\nCantidad: "<<listaProducto.p[j].cantidad;
            cout<<"\nUbicacion: "<< listaProducto.p[j].ubicacion;
            cout<<"\n--INFO NUEVA";
            cout<<"\nNueva ubicacion: ";
            scanf (" %[^\n]s", nuevaUbicacion);
            strcpy(listaProducto.p[j].ubicacion,nuevaUbicacion);
            actualizarProductoArchivo(listaProducto.tamaño,listaProducto.p);
            cout<<"\nCambio realizado";


        }
    }

    // mandar el arraylist nuevo a grabar.

    free(listaProducto.p);


}

void editarProductoCodigo()
{
    lista listaProducto; 
    char codigo[100];
    char nuevaUbicacion[100];
    cout<<"\nIntroduce el codigo: ";
    scanf (" %[^\n]s", codigo);

    
    

    //gestionamos manualmente el uso de la memoria, por que no esta permitido hacer arreglos de tamaños variables. 
    
    listaProducto = listarProductos();
    
    
    // buscando el archivo que quieres cambiar
    for(int j= 0; j<listaProducto.tamaño; j++){
        if(strcmp(listaProducto.p[j].codigoBarra,codigo)==0){
            cout<<"\n--INFO ACTUAL---";
            cout<<"\nCodigo barra: " << listaProducto.p[j].codigoBarra;
            cout<<"\nNombre: "<< listaProducto.p[j].nombre;
            cout<<"\nCantidad: "<<listaProducto.p[j].cantidad;
            cout<<"\nUbicacion: "<< listaProducto.p[j].ubicacion;
            cout<<"\n--INFO NUEVA";
            cout<<"\nNueva ubicacion: ";
            scanf (" %[^\n]s", nuevaUbicacion);
            strcpy(listaProducto.p[j].ubicacion,nuevaUbicacion);
            actualizarProductoArchivo(listaProducto.tamaño,listaProducto.p);
            cout<<"\nCambio realizado";
            
            break;

        }
    }

    // mandar el arraylist nuevo a grabar.

    
    free(listaProducto.p);




}
void eliminarProducto()
{
    lista listaProducto;
    char cb[100]; 
    cout<<"\n--ELIMINAR PRODUCTO ";
    mostrarProductos();
    system("pause");
    

    listaProducto= listarProductos();
    int tam = listaProducto.tamaño;
    tam-=1; //eliminamos 1, por que el nuevo arreglo sera 1 mas pequeño. 

    //Arreglo que servira para almacenar la nueva lista
    //manejaremos la memoria ya que C no permite VLA
    producto* nuevaLista =(producto *) malloc(sizeof(struct producto)*tam);
    cout<<"\nIngrese codigo de Barra del producto a borrar:  ";
    scanf (" %[^\n]s", cb);

    
    for(int i=0; i<listaProducto.tamaño; i++)
    {
        if(strcmp(listaProducto.p[i].codigoBarra,cb)!=0)
        {
            nuevaLista[i] =listaProducto.p[i];
        }
       
    }
    actualizarProductoArchivo(tam,nuevaLista);
    cout<<"\nProducto Eliminado";
    
    free(nuevaLista);
    free(listaProducto.p);


}


void actualizarProducto()
{
    int opc;
    cout<<"\n----ACTUALIZAR UBICACION ----";

    cout<<"\nBuscar producto por: ";
    cout<<"\n1. Codigo de barra";
    cout<<"\n2. Nombre del articulo";
    cout<<"\n3. Mostrar info de los productos";
    cout<<"\nSu opcion es: ";
    cin>>opc; 

    switch (opc)
    {
    case 1: 
        editarProductoCodigo();
        break;
    
    case 2: 
        editarProductoNombre();
        break;
    
    case 3:
        mostrarProductos();
        system("pause");
        break;
    default:
        cout<<"\nOpcion incorrecta";
        break;
    }
   
}

void actualizarInventario(producto producto)
{
    lista listaProducto = listarProductos();
    
    for(int i =0; i<listaProducto.tamaño; i++){
        if(strcmp(listaProducto.p[i].codigoBarra,producto.codigoBarra)==0)
        {
            listaProducto.p[i].cantidad=producto.cantidad;

            break; 
        }
    }

    actualizarProductoArchivo(listaProducto.tamaño, listaProducto.p);



    free(listaProducto.p);

}

producto obtenerProducto(char codigoBarra [])
{
    producto registro; 
    FILE *ptr = NULL;
    ptr =fopen(pathProducto,"r");
    while(fread(&registro, sizeof(struct producto),1, ptr)==1)
    {
        if(strcmp(registro.codigoBarra, codigoBarra)==0){
            return registro;
        }
    }
    return registro;

}

void agregarEntrada(usuario us)
{
    entrada entrada;
    producto producto;
    int ingreso;  
    char cb[100];
    char fecha[100];
    obtenerFecha(fecha);
    cout<<"\n--Agregando entradas---";
    mostrarProductos();
    cout<<"\nIngresa el codigo de Barra: ";
    scanf (" %[^\n]s", cb);

    
    producto = obtenerProducto(cb);
    

    cout<<"\nProducto: "<< producto.nombre;
    cout<<"\nCantidad Actual : "<<producto.cantidad;
    cout<<"\nIngreso cantidad: ";
    scanf("%i",&ingreso);
    producto.cantidad += ingreso;

    strcpy(entrada.fecha,fecha);
    strcpy(entrada.nombreArticulo,producto.nombre);
    strcpy(entrada.usuario,us.username);
    entrada.cantidad =ingreso;

    agregarEntradaArchivo(entrada);
    actualizarInventario(producto);

    cout<<"\nEntrada e Inventarios han sido actualizado exitosamente";
}

void agregarSalida(usuario us){
    salida salida;
    producto producto;
    int ingreso;  
    char cb[100];
    char fecha[100];
    obtenerFecha(fecha);
    cout<<"\n--Agregando salidas---";
    mostrarProductos();
    cout<<"\nIngresa el codigo de Barra: ";
    scanf (" %[^\n]s", cb);

    
    producto = obtenerProducto(cb);
    

    cout<<"\nProducto: "<< producto.nombre;
    cout<<"\nCantidad Actual : "<<producto.cantidad;
    cout<<"\nCantidad de egreso: ";
    scanf("%i",&ingreso);

    if(producto.cantidad-ingreso>=0){
        producto.cantidad -= ingreso;
        strcpy(salida.fecha,fecha);    
        strcpy(salida.nombreArticulo,producto.nombre);
        strcpy(salida.usuario,us.username);
        salida.cantidad =ingreso;

    agregarSalidaArchivo(salida);

    actualizarInventario(producto);

    cout<<"\nEntrada e Inventarios han sido actualizado exitosamente\n\n";
    }else{
        cout<<"\nNo puedes hacer egreso debido a que no hay suficiente stock del producto\n\n" ;
    }
    
}


#endif