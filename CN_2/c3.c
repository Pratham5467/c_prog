#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<unistd.h>
#include<string.h>

int main(){
	struct sockaddr_in client;
	int s, flag;
	char buffer[20];
	s= socket(AF_INET,SOCK_STREAM,0);
	client.sin_family=AF_INET;
	client.sin_port=9145;
	client.sin_addr.s_addr=htons(INADDR_ANY);
	connect(s,(struct sockaddr*)&client,sizeof client);
	for(;;){
		printf("Enter a string to check palindrome:");
		scanf("%s",buffer);
		printf("Client: %s\n",buffer);
		send(s,buffer,sizeof(buffer),0);
		recv(s,&flag,sizeof(int),0);

		if(flag==1){
			printf("Server: string is palindrome\n");
			break;
		}

		else{
			printf("Server: string is not palindrome\n");
			break;
		}
	}
	close(s);
}
