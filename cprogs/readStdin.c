/*
Program acts like echo command when piped with other program
prog1 | this_program
*/
#include <stdio.h>

int main()
{
    char* buffer = NULL;
    size_t buflen = 100;

    // read line by line from buffer
    while (getline(&buffer, &buflen, stdin) != -1) 
    {
        printf("%s", buffer);
    }

    return 0;
}
