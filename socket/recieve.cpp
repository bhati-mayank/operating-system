#include <iostream>
#include <cstdlib>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

using namespace std;

#define PORT 10000
#define BACKLOG 20

int main()
{
    // call socket
    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);

    // check socket failure
    if(socket_fd < 0)
    {
        perror("socket failed\n");
        return EXIT_FAILURE;
    }

    // get addres info
    sockaddr_in address;

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // call bind
    int bind_result = bind(socket_fd, (struct sockaddr *)&address, sizeof(address));


    // check bind failure
    if(bind_result < 0)
    {
        perror("bind failed\n");
        return EXIT_FAILURE;
    }

    // call listen
    int listen_result = listen(socket_fd, BACKLOG);

    //check listen failure
    if(listen_result < 0)
    {
        perror("listen failed\n");
        return EXIT_FAILURE;
    }

    // call accept
    int client_fd = accept(socket_fd, NULL, NULL);

    //check accept failure
    if(client_fd < 0)
    {
        perror("client failed\n");
        return EXIT_FAILURE;
    }

    // call recv
    // create buffer
    char buffer[1024] = {0};
    int reads = recv(client_fd, buffer, sizeof(buffer), 0);

    // print the recieved input
    cout << "recieved: " << buffer << endl;

    // close the file discriptors
    close(socket_fd);
    close(client_fd);

    cout << "accept succesfull\n" << endl;

    //return
    return 0;
}
