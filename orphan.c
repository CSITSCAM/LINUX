#include <stdio.h> /* printf, etc. */
#include <stdlib.h> /* exit, etc. */

/* Define all the error messages */
char *error_msg[] = {
"\nUsage: ./18orphan\n\n",
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
/* Error case */
print_error(1,3);
exit(2);
case 0:
/* Child process */
printf("Child: I am going to become an orphan\n\n");
sleep(1); /* Let the child live longer than parent */
printf("\n\nChild: The process which adopted me now is with PPID=%d\n",(int)getppid());
system("echo; ps -C a.out -C 18orphan -o cmd,pid,ppid");
return 10;
default:
/* Parent process */
printf("\nParent: I am dieing. I won't be there to pick up child status.\n\n");
return 20;
}
}

void print_error(int error_index, int exit_code)
{
fprintf(stderr, "%s", error_msg[error_index]);
exit(exit_code);
}
