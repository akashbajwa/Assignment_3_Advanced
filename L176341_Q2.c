#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore. h>
#include<string.h>
#include<unistd.h>
#include<stdbool. h>

sem_t read;
char buffer1[100][100];
char buffer2[100][100];
int main()
{
	FILE* fp1,*fp2;
	char buffer1[100],buffer2[100];
	
	pid_t pid[3];
	
	pid[0] = fork();
	
	if(pid[0] < 0){
		printf("%s","Unable to Create Process-A\n");
		return;
	}
	fp1 = fopen("file-1.txt","a+");
	
	if(fp1 == NULL){ //A
		perror("Unable to open a.txt\n");
		return;
	}
	char temp[100];
	int  i =  0 
	while(fp1!= NULL){
		fgets(temp,100,fp1);
		buffer1[i] = temp;
	}
	
	if(pid[0] == 0){ // B
		pid[1] = fork();
		
		if(pid[1] < 0){
		printf("%s","Unable to Create Process-D\n");
		return;
	}		
}
	pid[2] = fork();
	
	if(pid[2] < 0){
		printf("%s","Unable to Create Process-C\n");
		return;
	}
	
	return 0;
}

void print(){
	
	
	
}
