#include<pthread.h>
#include<stdio.h>
void *th_function1();
void *th_function2();
void *th_function3();
sem_t st1,st2,st3;
int pen=1000,paper=1000,quesp=1000;
void main()
{
sem_init(&st1,0,1);
sem_init(&st2,0,1);
sem_init(&st3,0,1);
pthread_t stu1,stu2,stu3;
pthread_create(&stu1,NULL,th_function1,NULL);
pthread_create(&stu2,NULL,th_function2,NULL);
pthread_create(&stu3,NULL,th_function3,NULL);
pthread_join(stu1,NULL);
pthread_join(stu2,NULL);
pthread_join(stu3,NULL);
void *th_function1()
{
	sem_wait(&st2);
	sem_wait(&st3);
	
	sem_post(&st2);
	sem_post(&st3);
	
}
void *th_function2()
{
	sem_wait(&st1);
	sem_wait(&st3);
	
	sem_post(&st1);
	sem_post(&st3);
	
}
void *th_function3()
{
	sem_wait($st1)
	sem_wait(&st2);
	
	sem_post(&st1);
	sem_post(&st2);
	
}
}
