// Write a program to stop the esecution of a parent process using SIGSTOP signal from the child process.
// Resume the execution oof parent process using SIGCONT process.

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>

int main() {
	pid_t pid, ppid;
	pid = fork();
	if(pid > 0) {
		printf("Inside parent.\n");
		sleep(5);
		printf("Parent process done.\n");
	}

	else if(pid == 0) {
		ppid = getpid();
		printf("Inside child process\n");
		kill(ppid, SIGSTOP);
		printf("Parent stopped\n");
		sleep(5);
		kill(ppid, SIGCONT);
		printf("Parent resumed\n");
	}

	else { printf("Error"); }
}
