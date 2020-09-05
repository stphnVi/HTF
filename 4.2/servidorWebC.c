#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/sendfile.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
//para compilar -- gcc -o simple_server simple_server.case
//para ejecutar -- ./webserver
//acceder -- abrir el buscador y poner http://localhost:8080/
//Función para obtener el tamaño de la imágen
unsigned long fsize(char* file)
{
    FILE * f = fopen(file, "r");
    fseek(f, 0, SEEK_END);
    unsigned long len = (unsigned long)ftell(f);
    fclose(f);
    return len;
}

//Contenido de la página principal
char paginaweb[] =
"HTTP/1.1 200 Ok\r\n"
"Content-Type: text/html; charset=UTF-8\r\n\r\n"
"<!DOCTYPE html>\r\n"
"<html><head><title>Servidor Web en C</title>\r\n"
"<style>body { background-color: #A9D0F5 }</style></head>\r\n"
"<body><center><h1>Hola mundo!</h1></center></body></html>\r\n";

//Función principal
int main(int argc, char *argv[])
	{
	struct sockaddr_in server_addr, client_addr;
	socklen_t sin_len =sizeof(client_addr);
	int fd_server, fd_client;
	char buf[2048];
	int fdimg;
	int on = 1;

        /*Usamos socket como descriptor de archivo, con el dominio que será AF_INET para usar los protocolos
        de ARPA de internet, luego el type, donde usaremos la variable SOCK_STREAM socket de flujo, y por último
        el protocólo que será 0*/
	fd_server = socket(AF_INET, SOCK_STREAM, 0);

	if (fd_server < 0) {
		perror("socket");
		exit(1);
	}

        /* Establecemos las opciones del socket, le pasamos nuestro socket, luego SOL_SOCKET primera capa
        de socket usado para opciones independientes al socket, SO_REUSEADDR especifica las reglas de validación
        de las direcciones suministradas a bind() es un valor booleano, luego le pasamos el valor on = 1, y el
        tamaño del sock */
	setsockopt(fd_server, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(int));

        //Familia de la dirección
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = INADDR_ANY;
	server_addr.sin_port = htons(8080);

	if (bind(fd_server, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1)
	{
		perror("bind");
		close(fd_server);
		exit(1);
	}

	if (listen(fd_server, 10) == -1)
	{
		perror("listen");
		close(fd_server);
		exit(1);
	}

        //Loop principal que se ejcuta en cada conexión
	while(1) {
                //Con accpet aceptamos las conexiónes entrantes
		fd_client = accept(fd_server, (struct sockaddr *) &client_addr, &sin_len);
		if (fd_client == 1)
		{
			perror("Conexión fallida...\n");
			continue;
		}
		printf("Conexión establecida.\n");

                //Levantamos child process
		if (!fork()) {
			close(fd_server);
			memset(buf, 0, 2048);
			read(fd_client, buf, 2047);
                        //si el get nos pide el favicon.ico se lo mandamos
			if(!strncmp(buf, "GET /favicon.ico", 16))
			{
				fdimg = open("favicon.ico", O_RDONLY);
				sendfile(fd_client, fdimg, NULL, fsize("favicon.ico"));
				close(fdimg);

                        //Cuando nos pide la imagen se la mandamos para que pueda mostrarse
			} else if(!strncmp(buf, "GET /icono.png", 14)) {
				fdimg = open("icono.png", O_RDONLY);
				sendfile(fd_client, fdimg, NULL, fsize("icono.png"));
				close(fdimg);

                        //Para cuando el GET sea para /
			} else  {
				write(fd_client, paginaweb, sizeof(paginaweb) -1);

			}

			close(fd_client);
			printf("Cerrando...\n");
			exit(0);

		}
		close(fd_client);
	}

	return 0;
}
