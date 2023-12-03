// Write a program to implement and explain how creation of zombie process 
// can be avoided

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main() {
	int pid = fork();
	if(pid < 0) printf("Fork failed");
	else if(pid == 0) {
		printf("Child process is running with PID %d\n", getpid());
		sleep(2);
		printf("Child process is done.\n");
	}
	else{
		printf("Parent process with PID %d is running \n", getpid());
		int status;
		wait(&status);
		printf("Parent process is done.\n");
	}
	return 0;
}
