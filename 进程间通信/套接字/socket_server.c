#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include <unistd.h>

int startup(int _port,const char* _ip)
{
    int sock=socket(AF_INET,SOCK_STREAM,0);
    if(sock<0)
    {
        perror("socket");
        exit(1);
    }

    struct sockaddr_in local;
    local.sin_family=AF_INET;
    local.sin_port=htons(_port);
    local.sin_addr.s_addr=inet_addr(_ip);

    socklen_t len=sizeof(local);

   if(bind(sock,(struct sockaddr*)&local,len)<0)
   {
     perror("bind");
     exit(2);
    }

    if(listen(sock,5)<0)
    {
        perror("listen");
        exit(3);
    }
   return sock;
}
int main(int argc,char* argv[])
{
    if(argc!=3)
    {
        printf("Usage: [local_ip] [local_port]");
        return 3;
    }
    int listen_socket=startup(atoi(argv[2]),argv[1]);

    struct sockaddr_in remote;
    socklen_t len=sizeof(struct sockaddr_in);

    while(1)
    {
        int socket=accept(listen_socket,(struct sockaddr*)&remote,&len);
        if(socket<0)
        {
            perror("accept");
            continue;
        }

        printf("client,ip:%s,port:%d\n",inet_ntoa(remote.sin_addr)\
               ,ntohs(remote.sin_port));


        char buf[1024];
        while(1)
        {
            ssize_t _s=read(socket,buf,sizeof(buf)-1);
            if(_s>0)
            {
               buf[_s]=0;
               printf("client# %s\n",buf);
            }
            else
            {
               printf("client is quit!\n");
               break;
            }

        }
        close(socket);
    }
    return 0;
}
