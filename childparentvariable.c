// Write a C program to take a child process, take one variable and show its changes in child and parent process

#include<stdio.h>
#include<unistd.h>

int global = 100;
static int b = 1000;

void main() {
	int local = 10, pid;
	pid = fork();

	if(pid == 0) {
		printf("Child PID: %d   Child PPID: %d   \n", getpid(), getppid());
		printf("Static = %d \n", --b);
		printf("Global = %d \n", --global);
		printf("Local = %d \n", --local);
	}

	else if(pid > 0) {
		printf("Parent PID: %d   Parent PPID: %d   \n", getpid(), getppid());
		printf("Static = %d \n", ++b);
		printf("Global = %d \n", ++global);
		printf("Local = %d \n", ++local);
	}
	sleep(10);
}
