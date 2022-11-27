#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/msg.h>
#include <string.h>

struct msgbuf
{
long mtype;
char msgtxt[100];
};

int main()
{
struct msgbuf message;

int messageid;
key_t key;

char msg[]="hello aliens!!";

//ftok
if((key=ftok("ex22sender",'a'))==-1)
perror("key generation failed");

//msgid
if((messageid=msgget(key,0666|IPC_CREAT))==-1)
perror("msgid generation error");

//msgsnd
message.mtype=1;
strcpy(message.msgtxt,msg);

if(msgsnd(messageid,&message,sizeof(message),0)==-1)
perror("error in sending message\n");
else
printf("sent: %s\n",message.msgtxt);
}
