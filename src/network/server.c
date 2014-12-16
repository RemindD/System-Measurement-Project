#include <sys/types.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h> 
#include <arpa/inet.h>
#include <linux/tcp.h>
#include <linux/socket.h>

typedef unsigned long long tick;
static __inline__ tick gettick (void) {
    unsigned a, d;
    __asm__ __volatile__("rdtsc": "=a" (a), "=d" (d) );
    return (((tick)a) | (((tick)d) << 32));
}

int main(int argc , char *argv[])
{
    int socket_desc , client_sock , c , read_size;
    struct sockaddr_in server , client;
    char client_message[2000];
    tick ts, te;
    //Create socket
    socket_desc = socket(AF_INET , SOCK_STREAM , 0);
    if (socket_desc == -1)
    {
        printf("Could not create socket");
    }
    puts("Socket created");
     
    //Prepare the sockaddr_in structure
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons( 8888 );
     
    //Bind
    if(bind(socket_desc,(struct sockaddr *)&server , sizeof(server)) < 0) {
        //print the error message
        perror("Error: fails to bind");
        return 1;
    }
    puts("Bind done");
     
    //Listen
    listen(socket_desc , 3);
     
    //Accept and incoming connection
    puts("Waiting for incoming connections...");
    c = sizeof(struct sockaddr_in);
     
    //accept connection from an incoming client
    while(1)
    {
    	client_sock = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&c);
    	if (client_sock < 0)
    	{
            perror("Error: fails to accept");
            return 1;
    	}
        char c = 0;
	int j;
        for (j = 0; j < 100; ++j) {
            recv(client_sock, &c, sizeof(c), 0);
            send(client_sock, &c, sizeof(c), 0);
        }
        ts = gettick ();
        close (client_sock);
        te = gettick ();
        printf ("Teardown time = %llu\n", te - ts);
    }
    puts("Connection accepted");
     
    return 0;
}
