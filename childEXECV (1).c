#include<stdio.h>

int main(int argc, char *argv[]){
	printf("I am child process\n");
	printf("Argument 1 : %s\n", argv[1]);
        printf("Argument 2 : %s\n", argv[2]);
        printf("Argument 3 : %s\n", argv[3]);
}
//cc childEXECV.c -o Cexecv
//cc L7.c
//./a.out
