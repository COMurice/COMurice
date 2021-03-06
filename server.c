// the target of Hello clang is to deliver the arguments to LLVM 
#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#define PORT 8080
int main(int argc, char const *argv[])
{
	int server_fd, new_socket, valread;
	struct sockaddr_in address;
	int opt = 1;
	int addrlen = sizeof(address);
	char buffer[1024] = {0};
	char *hello = "Hello from server";
	
	// Creating socket file descriptor
	if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
	{
		perror("socket failed");
		exit(EXIT_FAILURE);
	}

	address.sin_family = AF_INET;  //(IPv4 protocol)
	address.sin_addr.s_addr = INADDR_ANY ; //(any vaild address)
	address.sin_port = htons( PORT );   //(8080)
	
	// Forcefully attaching socket to the port 8080
	if (bind(server_fd, (struct sockaddr *)&address,
								sizeof(address))<0)
	{
		perror("bind failed");
		exit(EXIT_FAILURE);
	}
	if (listen(server_fd, 1) < 0)
	{
		perror("listen");
		exit(EXIT_FAILURE);
	}
	if ((new_socket = accept(server_fd, (struct sockaddr *)&address,
					(socklen_t*)&addrlen))<0)
	{
		perror("accept");
		exit(EXIT_FAILURE);
	}
        printf("**************\n");
	valread = read( new_socket , buffer, 1024);
        printf("***************\n");
	printf("%s\n",buffer );
	send(new_socket , hello , strlen(hello) , 0 );
	char recv_data[5]={0};
	int flag = recv(new_socket,recv_data,10,0);
	printf("%s\n",recv_data);
	return 0;
}
