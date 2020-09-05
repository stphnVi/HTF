#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h> // for open
#include <unistd.h> // for close

#include "hacking.h"

#define PORT 7890 //el puerto al que se conectan los usuarios
int main(void){
  int sockfd, new_sockfd; //escucha al sock_fd, nueva conexion new_sockfd
  struct sockaddr_in host_addr, client_addr;
  socklen_t sin_size;
  int recv_length=1, yes=1;
  char buffer[1024];

  if((sockfd = socket(PF_INET, SOCK_STREAM, 0)) == -1)
    fatal("in socket");
  if(setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int)) == -1)
    fatal("setting socket option SO_REUSEADDR");

  host_addr.sin_family = AF_INET; //orden de bytes de anfitrion
  host_addr.sin_port = htons(PORT); //corto, orden de bytes de red
  host_addr.sin_addr.s_addr = 0; //rellena automáticamente cin mi IP
  memset(&(host_addr.sin_zero),'\0',8); //Pone a cero el resto de la estructura

  if(bind(sockfd, (struct sockaddr *)& host_addr, sizeof(struct sockaddr)) == -1)
    fatal("binding to socket");

  if(listen(sockfd, 5) == -1)
    fatal("listening on socket");

  while(1){
    sin_size = sizeof(struct sockaddr_in);
    new_sockfd = accept(sockfd, (struct sockaddr *)&client_addr, &sin_size);
    if(new_sockfd == -1)
      fatal("accepting connection");
    printf("server: got connection from %s port %d\n",
      inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
    send(new_sockfd, "Hello, world!\n", 13,0);
    recv_length = recv(new_sockfd, &buffer, 1024, 0);
    while(recv_length >0){
      printf("RECV: %d bytes\n", recv_length);
      dump(buffer, recv_length);
      recv_length = recv(new_sockfd, &buffer, 1024, 0);
    }
    close(new_sockfd);
  }
  return 0;
}
