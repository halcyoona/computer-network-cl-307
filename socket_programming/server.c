#include<stdio.h>
#include<stdlib.h>

#include<sys/types.h>
#include<sys/socket.h>

#include<netinet/in.h>


void main(){
    printf("Hello world\n");

    char server_message[256]="My Group Members are: Mehmood: Faryal: Bashir";



    // creating socket
    int network_socket;
    network_socket = socket(AF_INET, SOCK_STREAM, 0);

    if (network_socket == -1)
        printf("Error in socket");

    // specify the server address
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(9002);
    server_address.sin_addr.s_addr = INADDR_ANY;

    // bind the socket
    int bind_status = connect(network_socket, (struct sockadd*) &server_address, sizeof(server_address));
    if (bind_status == -1)
        printf("Connecttion error!!!\n");

    listen(network_socket, 5);

    int client_socket;

    client_socket = accept(network_socket, NULL, NULL);

    // send the message
    send(client_socket, server_message, sizeof(server_message), 0);


    //closing the socket
    close(network_socket);
}