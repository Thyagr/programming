/* Program to help people understand the argument count and the argument vector passed
to executables

    show  users can't use comparison operators on strings, strcmp return values
    printf("%s\n", argv[1] == "-h" ? "yes": "no");
    printf("%d", strcmp(argv[1],"-h"));

 */

#include <stdio.h>
#include <string.h>

int main(int argc, const char* argv[])
{
	int i;
    if ( argc > 1 ? (!strcmp(argv[1],"-h") || !strcmp(argv[1],"-?") || !strcmp(argv[1],"--help")) : 1 )
    {
        printf("\n------------------------------------------------\n");
        printf("This executable prints the number(arg. count) and \n");
        printf("the list(arg. vector) of arguments passed to it \n");
        printf("Example usage:  argcv.exe <arg1> <arg2> ... \n");
        printf("\n------------------------------------------------\n");
    }
    else
    {
        printf("\nNumber of explicit argument(s): %d\n", argc-1);
        printf("\nThe argument(s) are:  \n");
        for (i = 1; i < argc; i++) // argv[0] is the program name
            printf("arg%d = %s \n",i,argv[i]);
    }
    printf("\n");
    return 0;
}
