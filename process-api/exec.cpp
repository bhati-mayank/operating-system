#include <iostream>
#include <unistd.h>
#include <sys/wait.h>

using namespace std;

int main()
{
    // calling fork
    pid_t pid = fork();


    //fails
    if(pid < 0)
    {
        perror("fork");
        return 1;
    }

    else if(pid == 0){
        //child
        execl("/bin/ls", "ls", "-l", NULL);

        perror("execl");

    }

    else{
        cout << "this is parent\n";
    }

    return 0;
}