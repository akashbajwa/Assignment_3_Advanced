#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore. h>
#include<string.h>
#include<unistd.h>
#include<stdbool. h>

static int potentialCPatients = 0;
sem_t coronaPatient;
sem_t fluPatient;

typedef struct patient{
	bool infected;

patient()
{
	infected = false;
}
~patient()
{ //
	
}	

};

typedef struct flu : patient{
	char* title;
	flu(bool flag,char* name):patient(flag){
		title = name;
	}
	
	flu(){
		title = NULL;
	}
	~flu(){
		if(title != NULL)
			delete[] title;
	}
};

typedef struct corona : patient{
	char* title;
	
	corona(bool flag,char* name):patient(flag){
		title = name;
	}
	
	corona(){
			title = NULL;
	}
	~corona(){
			if(title != NULL)
				delete[] title;
	}
};

int main(int argc,char* argv[]){
	int total;
	printf("%s","Enter total patients: "); // user input
	scanf("%d",&total);
	pthread_t tid[total];
	patient List[total];
	sem_init(coronaPatient, 0,0); //intialize temp semaphore
	sem_init(fluPatient, 0,0); //intialize temp semaphore
	
	for(int i  = 0 ;  i < total ; i++){
	
		int i;
		i = rand() % 2;
		if(i = 0)
			List[i] = malloc flu("Flu Patient",flase);
		else
			List[i] = new corona("Corona Patient",true);
		
		if(pthread_create(&tid[i],NULL,incrementPatient,(void*)List[i]) == -1){
			printf("Unable to create thread# %d\n",i);
		}
	
	}
	sem_destoy(coronaPatient);
	sem_destoy(fluPatient);
	for(int j = 0  ; j  < total ; j++){
		pthread_join(&tid[j],NULL);
	}
	
	sem_destroy(&coronaPatient); 
	sem_destroy(&fluPatient); 
	
	return 0;
}
void* incrementPatient(void* param){
	potentialCPatients++;
	patient obj = new (patient*) param;
	
	if(checkInfection(obj)){
		
		sem_wait(&coronaPatient);
			printf("%s","Corona Patient Found!\n");
			
			if(test(obj)){
			 potentialCPatients--; // decrements
			}
			else{
				printf("%s","Unable to Recover Corona Patient!\n");
			}
				
			
		sem_post(&coronaPatient);
	}
	else{
		sem_wait(&fluPatient);
			potentialCPatients--; // decrements
		sem_post(&fluPatient);
	}
	
	
	pthread_exit(0);
}
	
bool test(patient obj){ // perform test
	
	if(obj.infected){
		obj.title = 'Recovered';
		obj.infected = false;
		printf("%s","Test#1 Passed\n");
		printf("%s","Test#2 Passed\n");
		return true;
	}
	
	return false;
}
bool checkInfection(patient obj)
{
	
	return obj.infected;
}