#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	if(argc > 2)
	{
		//Primer paso, definir variables
		char *ip;
		int client_socket, numbytes,puerto;
		char buf[100];
		puerto=atoi(argv[2]);
		ip=argv[1];

		struct sockaddr_in server;
		/* informaciÃ³n sobre la direcciÃ³n del servidor */

		if(inet_pton(AF_INET, argv[1], &server.sin_addr)<=0) { 
			printf("\nInvalid address/ Address not supported \n"); 
			return -1; 
		} 

		printf( "Abriendo un socket\n" );
		//Paso 2, definicion de socket
		if ((client_socket=socket(AF_INET, SOCK_STREAM, 0))==-1){
			/* llamada a socket() */
			printf("socket() error\n");
			exit(-1);
		}
		
		//Datos del servidor
		server.sin_family = AF_INET;
		server.sin_port = htons(puerto);
		bzero(&(server.sin_zero),8);

		printf( "Conectando a %s:%s\n", argv[1], argv[2] );
		//Paso 3, conectarnos al servidor
		if(connect(client_socket, (struct sockaddr *)&server, sizeof(struct sockaddr))==-1){
			/* llamada a connect() */
			printf("connect() error\n");
			exit(-1);
		}

		printf( "Recibiendo...\n" );
		if ((numbytes=recv(client_socket,buf,100,0)) == -1){
			/* llamada a recv() */
			printf("Error en recv() \n");
			exit(-1);
		}

		buf[numbytes]='\0';

		printf("Mensaje del Servidor: %s\n",buf);
		 /* muestra el mensaje de bienvenida del servidor =) */

		shutdown(client_socket, 2);
	} else{
		printf("No se ingreso el ip y puerto por parametro\n");
	}
}