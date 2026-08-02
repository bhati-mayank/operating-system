#include <iostream>
#include <cstdlib>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>

using namespace std;

#define BACKLOG 20
#define PORT 10000

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

    cout << "socket succesfull" << endl;

    // get address info
    sockaddr_in address;

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // call bind for the defined port and socket
    int bind_result = bind(socket_fd, (struct sockaddr*)&address, sizeof(address));

    // check bind failure
    if(bind_result < 0)
    {
        perror("bind failed\n");
        return EXIT_FAILURE;
    }

    cout << "bind successful" << endl;


    // call listen
    int listen_result = listen(socket_fd, BACKLOG);

    // check listen failure
    if(listen_result  < 0)
    {
        perror("listen failed\n");
        return EXIT_FAILURE;
    }

    cout << "listen succesfull" << endl;

    // call accept
    int client_fd = accept(socket_fd, NULL, NULL);

    // check accept failure
    if(client_fd  < 0)
    {
        perror("accept failed\n");
        return EXIT_FAILURE;
    }


    cout << "client connected" << endl;

    close(socket_fd);

    return 0;

}