
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <windows.h>
#include "usuario.h"
#include "producto.h"
#include "cliente.h"

using namespace std;



void menuProducto(usuario us) // 2
{
	int opcion;
	bool a = true;
	
	while(a)
	{
		cout << "\t::::GESTION DE PRODUCTOS::::" << endl;
		cout << endl;
		cout << "1. Agregar Producto" << endl;
		cout << "2. Actualizar Producto" << endl;
		cout << "3. Eliminar Producto" << endl;
		cout << "4. Salir" << endl;
		cout << endl;
		cout << "Ingrese su opcion: ";
		cin >> opcion;
		
		switch(opcion)
		{
			case 1:
				agregarProducto(us);
				break;
				
			case 2:
				actualizarProducto();
				break;
				
			case 3:
				eliminarProducto();
				break;
				
			case 4:
				a = false;
				break;
				
			default:
				cout << "Opcion no valida, porfavor vuelva a intentar";
				break;
		}
	}
	
}

void menuCliente(cliente cs) // 3
{
	int opcion;
    bool a = true;
    
    while(a)
	{
	cout << "\t::::GESTION DE CLIENTES::::" << endl;
	cout << endl;
    cout << "1.Agregar Cliente" << endl;
    cout << "2.Editar Cliente" << endl;
    cout << "3.Ver Cliente" << endl;
    cout << "4.Salir" << endl;
    cout << endl;
    cout << "Ingrese su opcion: ";
    cin >> opcion;

    switch (opcion)
	{
    	case 1:	agregarCliente(cs);
			break;
    	case 2:	//editarCliente(cs);
			break;
    	case 3: verCliente(cs);
			break;
    	case 4:
        a = false;
        break;
		default: cout << "\nOpcion Invalida, Por Favor Intentelo de Nuevo..." << endl << "\n\n"; break;	
	}
	
	}

}

void menuUsuario(usuario us) // 4
{
	int opcion;
    bool a = true;
    
    while(a)
	{
	cout << "\t::::GESTION DE USUARIOS::::"<< endl;
	cout << endl;
    cout << "1. Agregar Usuario" << endl;
    cout << "2. Editar Usuario" << endl;
    cout << "3. Ver Usuario" << endl;
    cout << "4. Salir" << endl;
    cout << endl;
    cout << "Ingrese su opcion: ";
    cin >> opcion;

    switch (opcion)
	{
    	case 1:
			guardarUsuario(us);
			break;
    	case 2:	
			editarUsuario(us);
			break;
    	case 3:
			leerUsuario(us); 
			break;
    	case 4:
        a = false;
        break;
		default: cout << "\nOpcion Invalida, Por Favor Intentelo de Nuevo..." << endl << "\n\n"; break;	
	}
	
	}

}

void menuMovimientos(usuario us) // 5
{
    int opcion;
    bool a = true;
    while(a)
	{
        cout << "\t::::MOVIMIENTOS::::" << endl;
        cout << endl;
        cout << "1. Agregar Entradas" << endl;
        cout << "2. Agregar Salidas " << endl;
        cout << "3. Salir" << endl;
        cout << endl;
        cout << "Ingrese su opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            agregarEntrada(us);
            break;
        case 2:
            agregarSalida(us);
            break;
        case 3:
            a = false;
            break;
        default:
            break;
        }
    }
}

void menuReportes() // 6
{
    int opcion;
    bool a = true;
    
    while(a)
	{
        cout << "\t::::REPORTES::::"<< endl;
        cout << endl;
        cout << "1. Mostrar Inventario" << endl;
        cout << "2. Mostrar Entradas" << endl;
        cout << "3. Mostrar Salidas" << endl;
        cout << "4. Salir" << endl;
        cout << endl;
        cout << "Ingrese su opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
			mostrarProductos();
            break;
            
        case 2:
			mostrarEntradas();
            break;
            
        case 3:
			mostrarSalidas();
            break;
            
        case 4:
            a= false;
            break;
            
        default:
        	cout << "Opcion no valida, porfavor vuelva a intentar";
            break;
        }
    }
}


void menu(usuario us, cliente cs) // 1
{
	int opcion;
	bool a = true;
	
	do
	{
		cout << "\t::::SISTEMA DE LIBRERIA CARLITOS::::" << endl;
		cout << endl;
	    cout << "1. Gestion de Productos" << endl;
	    cout << "2. Gestion de Clientes" << endl;
	    cout << "3. Gestion de Usuarios" << endl;
	    cout << "4. Movimientos" << endl;
	    cout << "5. Reportes" << endl;
	    cout << "6. Salir" << endl;
	    cout << endl;
	    cout << "Ingrese su opcion: ";
	    cin >> opcion;
	    
	    switch(opcion)
		{
			case 1:
				menuProducto(us);
				break;
				
			case 2:
				menuCliente(cs);
				break;
				
			case 3:
				menuUsuario(us);
				break;
				
			case 4:
				menuMovimientos(us);
				break;
				
			case 5:
				menuReportes();
				break;
				
			case 6:
				a = false;
				break;
				
			default:
				cout << "Opcion no valida, porfavor vuelva a intentar";
				break;	
		}
	    
	} while(a);
}

