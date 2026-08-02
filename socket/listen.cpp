#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include <netinet/in.h>
#include <sys/socket.h>

using namespace std;


#define BACKLOG 10


int main()
{
    //socket
    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);

    // check sockwt failure
    if (socket_fd < 0)
    {
        perror("socket failed\n");
        return EXIT_FAILURE;
    }

    cout << "Socket succesfull" << endl;

    // getting address info
    sockaddr_in address;

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(10000);


    // call bind
    int bind_fd = bind(socket_fd, (struct sockaddr*)&address, sizeof(address));

    // check bind fail
    if(bind_fd < 0)
    {
        perror("bind_fail\n");
        return EXIT_FAILURE;
    }

    cout << "bind succesfull " << endl;

    // call listen
    int list = listen(socket_fd, BACKLOG);

    // check listen fail
    if(list < 0)
    {
        perror("listen failed\n");
        return EXIT_FAILURE;
    }


    cout << "listen succesfull" << endl;

    close(socket_fd);
    return 0;

}