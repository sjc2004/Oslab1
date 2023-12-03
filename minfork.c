// WAP to create 8 process using minimum fork

#include<stdio.h>
#include<unistd.h>

void main() {
	int pid;
	pid = fork();
	pid = fork();
	pid = fork();

	printf("PID = %d   PPID = %d   \n", getpid(), getppid());
	sleep(10);
}
