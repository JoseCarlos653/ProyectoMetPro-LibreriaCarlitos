
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <windows.h>
#include "menu.h"

using namespace std;

void menuProducto(void);

int main()
{	
	cliente client;
	usuario user; 
	usuarioauth userAuth; 

	primerUsuario();
	
	userAuth = autenticarUsuario();
	if(userAuth.n==1){
		user =userAuth.us;
		menu(user, client);
	
	}
	
	return 0;
}

