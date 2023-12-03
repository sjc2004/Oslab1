// Write a program to implement orphan process

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main() {
	int child_pid = fork();
	if(child_pid < 0) { printf("fork failed."); }
	else if(child_pid == 0) {
		printf("Inside child process with PID: %d\n", getpid());
		printf("Parent process: %d\n", getppid());
		sleep(10);
		printf("child process is done.\n");
	}
	else {
		printf("Parent process is running %d \n", getpid());
		printf("Parent process is done.\n");
	}

	return 0;
}
