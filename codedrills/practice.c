#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
int main()
{

int n=fork();

if(n==0)
{
wait(NULL);
printf("I am child process of parent \n");
printf("My ID id %d\n",getpid());
printf("My parent ID id %d \n",getppid());

}
else
{

printf("I am parent process \n");
printf("My ID id %d \n",getpid());

}

return 0;
}