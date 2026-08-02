#include <iostream>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <cstdlib>

using namespace std;



int main()
{
    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);

    if(socket_fd < 0)
    {
        cout << "socket failed" << endl;
        return EXIT_FAILURE;
    }
    
    cout << "socket established" << endl;

    close(socket_fd);

    return 0;
}