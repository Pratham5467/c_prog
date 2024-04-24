#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<unistd.h>
#include<string.h>

int main(){
	struct sockaddr_in client,server;
	int s1,n,sock,g,i,left,right,flag;
	char b11[20],b2[10],b3[10],b4[10];

	s1 = socket(AF_INET,SOCK_STREAM,0);
	server.sin_family=AF_INET;
	server.sin_port=9145;
	server.sin_addr.s_addr=	htons(INADDR_ANY);
	bind(s1,(struct sockaddr*)&server,sizeof server);
	listen(s1,1);
	n=sizeof client;
	sock=accept(s1,(struct sockaddr*)&client,&n);
	for(;;){
		recv(sock,b11,sizeof(b11),0);

		printf("The string recieved is:%s\n",b11);
		if(strlen(b11)==0)
			flag=1;
		else{
			left=0;
			right=strlen(b11)-1;
			flag=1;

			while(left<right && flag){
				if(b11[left]!=b11[right])
					flag=0;
				else{
					left++;
					right--;
				}
			}
		}
		send(sock,&flag,sizeof(int),0);
		break;
	}
	close(sock);
	close(s1);
}

