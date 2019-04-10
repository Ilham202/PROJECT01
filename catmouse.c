#include<stdio.h>
#include<stdlib.h>
#include<semaphore.h>
#include<pthread.h>
#include<unistd.h>

//Funtions for Cat and Mice
void *cat_eats(void *arg);
void *mice_eats(void *arg);

//Global variables for No of cats,No of Mices and No of loops
sem_t lock_c,lock_m;
int NumBowl=1,NumLoops=0;
int NumCats,NumMice;

int main()
{
    int i,j;
    pthread_t Cats[5],Mices[5];
    sem_init(&lock_c,0,1);
    sem_init(&lock_m,0,1);
    printf("Enter the numbers of cats ->");
    scanf("%d",&NumCats);
    printf("Enter the numbers of mice ->");
    scanf("%d",&NumMice);
    for(i=0;i<=NumCats;i++)
    {
     pthread_create(&Cats[i],NULL,cat_eats,(void *)i);
	}
	for(j=0;j<=NumMice;j++)
	{
		pthread_create(&Mices[j],NULL,mice_eats,(void*)j);
	}
	for(i=0;i<=NumCats;i++)
	{
		pthread_join(Cats[i],NULL);
	}
	for(j=0;j<=NumMice;j++)
	{
		pthread_join(Mices[i],NULL);
	}
	return 0;
}

void *cat_eats(void *arg)
{
	int x;
	x=((int)arg);
	sem_wait(&lock_c);
	NumLoops+=1;
	NumBowl++;
	if(NumLoops==1)
	//lock mice signal cat
	sem_wait(&lock_m);
	sem_post(&lock_c);
	printf("Cat%d eats from bowl%d\n",x,NumBowl);
	sleep(2);
	//lock cat
	sem_wait(&lock_c);
	NumLoops-=1;
	if(NumLoops==0)
	sem_post(&lock_c);
	sem_post(&lock_m);
}

void *mice_eats(void *arg)
{
	int y;
	y=((int)arg);
	sem_wait(&lock_m);
	NumBowl++;
	printf("Mice%d eats from bowl%d\n",y,NumBowl);
	sleep(2);
	//signal mice
	sem_post(&lock_m);
}
