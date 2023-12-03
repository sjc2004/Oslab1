// Write a program to kill the process using SIGKILL signal.

#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<signal.h>

int main() {
	pid_t target_pid;
	printf("Enter the pid of the process to kill: ");
	scanf("%d", &target_pid);
	if(kill(target_pid, SIGKILL) == 0) printf("Process with pid %d has been killed", target_pid);
	else printf("Error");

	return 0;
}
