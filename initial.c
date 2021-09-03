// Client side C/C++ program to demonstrate Socket programming
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include<stdlib.h>
#include<sys/shm.h>
#define PORT 8080


// void Sendcwd()
// {
// 	char cwd[1000];
// 	if(getcwd(cwd,sizeof(cwd))!=NULL)
// 	{
// 		//printf("The current working dir is %s\n",cwd);
// 	}
// 	int shmid=shmget(1234567, 1024, 0666|IPC_CREAT);
// 	// printf("**************\n");
// 	// printf("break poiunt");
// 	char *shared_memory;
// 	int choose_port;
// 	shared_memory=shmat(shmid,NULL,0);
// 	memcpy(shared_memory,cwd,sizeof(cwd));
// 	shmdt(shared_memory);
// }

int main(int argc, char const *argv[])
{
	// Sendcwd();
	int sock = 0, valread;
	struct sockaddr_in serv_addr;
	int shmid=shmget(12345, sizeof(int), 0666|IPC_CREAT);
	int *shared_memory;
	int choose_port=0;
	shared_memory=shmat(shmid,NULL,0);
	if(shared_memory)
	{
		choose_port=(shared_memory[0]) + 1;
		choose_port = choose_port %2;
	}
	shared_memory[0] = choose_port;
	shmdt(shared_memory);
	
	char *hello = "Hello from client";
	
	char buffer[1000000] = {0};
	if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		printf("\n Socket creation error \n");
		return -1;
	}
	
	int port[4]={8080,8082,8084,8086};
	printf("%d\n",choose_port);
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(8080);
	// serv_addr.sin_port = htons(8080); 
	// Convert IPv4 and IPv6 addresses from text to binary form
	int rc = fcntl(sock, 4,  04000); //set socket into no-blocking model
	if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0)
	{
		printf("\nInvalid address/ Address not supported \n");
		return -1;
	}
	
    char all_argv[1000000];
    memset(all_argv,'\0',sizeof(all_argv));
    int cnt_argv=0;
	int length_argv[1000];
	
	for(char **temp_argv=argv;*temp_argv;temp_argv++)
	{
		length_argv[cnt_argv++]=strlen(*temp_argv);
		strncat(all_argv,*temp_argv,strlen(*temp_argv));
		all_argv[strlen(all_argv)]='*';
	}
	memcpy(buffer,all_argv,1000000);
	while(connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0);
	send(sock , buffer , strlen(buffer) , 0);
	char recv_data[5]={0};
	int flag;
	time_t start_time;
	start_time = time(NULL);
	while(1)
	{
		flag = recv(sock,recv_data,10,0);
		int l=strlen(recv_data);
		if(l!=0) 
		{
			break;
		}
		time_t end_time;
		end_time = time(NULL);
		if(end_time-start_time>40)
		{
			printf("Initial clang encounters timeout\n");
			close(sock);
			sock = socket(AF_INET, SOCK_STREAM, 0);
			while(connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0);
			send(sock , buffer , strlen(buffer) , 0 );    // represent there may encounter some errors.
			end_time = start_time;
			flag = recv(sock,recv_data,10,0);
		}
		close(flag);
	}
	// printf("recv_data=%s\n",recv_data);
	// printf("%s\n",buffer);
	close(sock);
	return 0;
}

// struct pollfd {
//         int fd;
//         short events;
//         short revents;
// };
