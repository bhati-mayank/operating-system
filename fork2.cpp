#include <iostream>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <cstdlib>

using namespace std;

// task is to call fork and to ensure that child always executes first without using wait
int main()
{
    // calling fork
    pid_t pid = fork();

    if(pid < 0)
    {
        //failed
        exit(1);
    }

    else if(pid == 0)
    {
        //child
        cout << "Hello\n";
    }

    else 

    {
        // parent
        sleep(1);
        cout << "World\n";
    }

    return 0;
}