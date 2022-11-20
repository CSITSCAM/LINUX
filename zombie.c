#include <stdio.h> /* printf, etc. */
#include <stdlib.h> /* exit, etc. */

/* Define all the error messages */
char *error_msg[] = {
"\nUsage: ./17zombie\n\n",
"\nCould not fork\n\n"
};

/* Prototype for the function “print_error” */
void print_error(int msg_num, int exit_code);

int main(int argc, char *argv[])
{
/* Check if correct number of arguments are supplied */
if ( argc > 1 )
print_error(0,2);

/* Do the forking */
switch ( fork() )
{
case -1:
print_error(1,3);
exit(2);
case 0:
printf("Child: I am going to become a zombie\n");
return 10;
default:
printf("Parent: sleeping for 20 seconds.\n");
printf("Run 'ps -e -o pid,ppid,stat,cmd | grep Z' within this");
printf(" period from another terminal window\n");
sleep(20);
return 20;
}
}

void print_error(int error_index, int exit_code)
{
fprintf(stderr, "%s", error_msg[error_index]);
exit(exit_code);
}
