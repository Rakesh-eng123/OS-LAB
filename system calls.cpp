#include<stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>

int main()
{
if(fork()==0)
{
key_t key = ftok("shmfile",65);
int shmid = shmget(key,1024,0666|IPC_CREAT);
char str = (char) shmat(shmid,(void*)0,0);
printf("Write Data : \n");
scanf("%s",str);
printf("Child process written in memory: %s\n",str);
shmdt(str);
}
else
{
wait(0);
key_t key = ftok("shmfile",65);
int shmid = shmget(key,1024,0666|IPC_CREAT);
char str = (char) shmat(shmid,(void*)0,0);
printf("Parent reads from memory       : %s\n",s
