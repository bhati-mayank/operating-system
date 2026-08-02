#include <iostream>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <cstdlib>



using namespace std;

int main()
{
    // create socket
    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);

    if(socket_fd < 0){
        // the socket failed
        perror("socket fail\n");

        return EXIT_FAILURE;
    }

    cout << "socket established succesfully" << endl;
    
    sockaddr_in address;

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(9999);


    //  call bind
    int bind_d = bind(socket_fd, (struct sockaddr*)&address, sizeof(address));

    if(bind_d < 0){
        perror("bind fail\n");

        return EXIT_FAILURE;
    }

    // if bind succesful
    cout << "bind succesfull" << endl;

    close(socket_fd);

    return 0;



}