#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <cstdlib>
#include <sys/wait.h>


int main()
{
    int num = 100;
    printf("THIS IS BEFORE FORK : %d\n", num);



    pid_t a = fork();

    if(a < 0)
    {
        printf("Fork failed\n");
        exit(1);
    }

    else if(a == 0)
    {
        //child process
        num = num*10;
        printf("%d", num);
        printf("\n");
        printf("i am child process with pid : %d\n", getpid());
    }

    else{
        wait(NULL);
        num /= 10;
        printf("%d", num);
        printf("\n");
        printf("And this is the parent with pid : %d \n", getpid());
    }

    return 0;
}