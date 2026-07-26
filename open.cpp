#include <iostream>
#include <cstdio>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <fcntl.h>
using namespace std;


int main()
{
    // open a file
    int fd = open("text.h",     O_RDWR | O_CREAT, 0644);

    if(fd == -1)
    {
        // open fail
        perror("failed");
    }

    pid_t pid = fork();

    // if fork fail
    if(pid < 0)
    {
        cout << "fork fail" << '\n';
    }

    else if(pid == 0)
    {
        //child
        cout << "this is child\n" << 'n';
        for(int i = 0; i <= 10; i++){
            write(fd, "child\n",  6);
        }
    }

    else 
    {
        //parent
        cout << "this is parent\n";

        for(int i = 0; i <= 10; i++){
            write(fd, "parent\n",7);
        }

        wait(NULL);
    }
    close(fd);

    return 0;
}