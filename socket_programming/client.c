#include<stdio.h>
#include<stdlib.h>

#include<sys/types.h>
#include<sys/socket.h>

#include<netinet/in.h>


void main(){
    printf("Hello world\n");

    // creating socket
    int network_socket;
    network_socket = socket(AF_INET, SOCK_STREAM, 0);

    if (network_socket == -1){
        printf("Error in socket!!!");
    }

    // specify an address for the socket
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(9002);
    server_address.sin_addr.s_addr = inet_addr("192.168.43.183");

    // making a connection
    int connection_status = connect(network_socket, (struct sockadd*) &server_address, sizeof(server_address));
    if (connection_status == -1)
        printf("Connecttion error!!!\n");

    // to receive data from server 
    char server_response[256];
    recv(network_socket, &server_response, sizeof(server_response), 0);

    //printing the msg/data
    printf("%s\n", server_response);

    //closing the socket
    //close(network_socket);
}