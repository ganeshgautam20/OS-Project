#include<pthread.h>
#include<stdio.h>
void *th_function1();
void *th_function2();
void *th_function3();
sem_t st1;
sem_t st2;
sem_t st3;
int pen=10,paper=10,quesp=10;
main()
{
sem_init(&st1,0,1);
sem_init(&st2,0,1);
sem_init(&st3,0,1);
pthread_t stu1,stu2,stu3;
int user1_paper=1;
int user2_pen=1;
int user3_quesp=1;
pthread_create(&stu1,NULL,th_function1,(void*)user1_paper);
pthread_create(&stu2,NULL,th_function2,(void*)user2_pen);
pthread_create(&stu3,NULL,th_function3,(void*)user3_quespap);
pthread_join(stu1,NULL);
pthread_join(stu2,NULL);
pthread_join(stu3,NULL);
}
void *th_function1(void* user1_paper)
{
	sem_wait(&st2);
	sem_wait(&st3);
	
	long long user1_paper_fun1=(long long)user1_paper;

	

	sem_post(&st2);
	sem_post(&st3);
	
}
void *th_function2(void* user2_pen)
{
	sem_wait(&st1);
	sem_wait(&st3);
	long long user2_pen_fun2=(long long)user2_pen;
	

	
	sem_post(&st1);
	sem_post(&st3);
	
}
void *th_function3(void* user3_quesp)
{
	sem_wait($st1)
	sem_wait(&st2);
	
	long long user3_paper_fun3=(long long)user3_quesp;
	
	
	sem_post(&st1);
	sem_post(&st2);
	
}

