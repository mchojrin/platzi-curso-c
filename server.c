// Ficheros de cabecera
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>

int main(int argc, char **argv)
{
	if(argc > 1)
	{
		//Primer paso, definir variables
		int server_socket,client_socket,longitud_cliente,puerto;
		
		puerto = atoi(argv[1]);

		//Se necesitan dos estructuras del tipo sockaddr
		//La primera guarda info del server
		//La segunda del cliente
		struct sockaddr_in server;
		struct sockaddr_in client;

		//Configuracion del servidor
		server.sin_family= AF_INET; //Familia TCP/IP
		server.sin_port = htons(puerto); //Puerto
		server.sin_addr.s_addr = INADDR_ANY; //Cualquier cliente puede conectarse
		bzero(&(server.sin_zero),8); //Funcion que rellena con 0's

		//Paso 2, definicion de socket
		if (( server_socket=socket(AF_INET,SOCK_STREAM,0) )<0){
			perror("Error de apertura de socket");
			exit(-1);
		}

		//Paso 3, avisar al sistema que se creo un socket
		if( bind( server_socket,(struct sockaddr*)&server, sizeof(struct sockaddr))==-1) {
			printf("error en bind() \n");
			exit(-1);
		}

		//Paso 4, establecer el socket en modo escucha
		if ( listen(server_socket,5) == -1 ) {
			printf("error en listen()\n");
			exit(-1);
		}

		//Paso5, aceptar conexiones
		longitud_cliente= sizeof(struct sockaddr_in);
		printf("Todo listo! Esperando clientes en el puerto %d\n", puerto);
		/* A continuaciÃ³n la llamada a accept() */
		if ( (client_socket = accept(server_socket,(struct sockaddr *)&client,&longitud_cliente))==-1 ) {
			printf("error en accept()\n");
			exit(-1);
		}
		
		char str[INET_ADDRSTRLEN];
		inet_ntop(AF_INET, &(client.sin_addr), str, INET_ADDRSTRLEN);
		printf( "Se conecto un cliente desde %s:%d. Lo saludo\n", str, client.sin_port );

		send(client_socket,"Bienvenido a mi servidor.\n",26,0);
		
		printf( "Saludo enviado!\n" );
		shutdown( client_socket, 2 );
		shutdown( server_socket, 2 );
		
	} else {
		printf("NO se ingreso el puerto por parametro\n");
	}

	return 0;
}