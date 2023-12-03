// Write a program ro implement parent-child procedure and explain their concurrent execution

#include<stdio.h>
#include<unistd.h>

void main() {
	int pid;
	pid = fork();
	if(pid == 0) printf("Child PID: %d   Child PPID: %d   \n", getpid(), getppid());
	else if(pid > 0) printf("Parent PID: %d   Parent PPID: %d   \n", getpid(), getppid());
}
