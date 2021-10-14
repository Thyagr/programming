#include <stdio.h>
#include <unistd.h>

int main(void)
{
    pid_t childid;
    childid = fork();
    switch (childid)
    {
        case -1:
            printf("Error forking process");
            exit(-1);
        case 0:
            // child is returned 0
            printf("This is the child");
            break;
        default:
            // parent is returned child id
            printf("This is the parent, child id %d", childid);
            break;
    }
    return 0;
}
