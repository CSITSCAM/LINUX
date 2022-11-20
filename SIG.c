#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void handler(int signo)
{
printf("\n Signal no: %d", signo);
switch(signo)
{
case SIGINT: puts("\n Received program interrupt signal");
    break;
case SIGQUIT: puts("\n Received SIGQUIT");
     break;
case SIGFPE: puts("\n Received floating-point exception");
    break;
case SIGSEGV: puts("\n Received Segmentation Fault Error");
     raise(SIGSTOP);
     break;
}
}

int main(int argc, char* argv)
{
signal(SIGINT, handler);
signal(SIGQUIT, handler);
signal(SIGFPE, handler);
signal(SIGSEGV, handler);

int *ptr;
int pid=fork();
if(pid==0)
printf("%d", *ptr);
else
{
for(int i=10;;i--)
{
printf("\n%d", 10/i);
sleep(1);
}
}
}
