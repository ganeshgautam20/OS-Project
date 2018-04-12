#include<iostream>
#include<pthread.h>
#include<stdio.h>
#include<semaphore.h>
#include<unistd.h>
using namespace std;

sem_t st1;
sem_t st2;
sem_t st3;
int pen=10,paper=10,quesp=10;

void *th_function(void*)
{
	sem_wait(&st1);
	sem_wait(&st2);
	sem_wait(&st3);
	sem_post(&st1);
	sem_post(&st2);
	sem_post(&st3);
	
}


void *th_function1(void* user1_paper)
{
	sem_wait(&st2);
	sem_wait(&st3);
	long long user1_paper_fun1=(long long)user1_paper;
	long long user1_qp=1;
	quesp-=user1_qp;
	long long user1_pen=1;
	pen-=user1_pen;
	cout<<"Student 1 is executing\n\n";
	sleep(2);
	cout<<"Student 1 is already having paper\n\n";
    sleep(1);
    cout<<"Student 1 got pen from teacher\n\n";
    sleep(1);
    cout<<"Student 1 got question paper from teacher\n\n";
    sleep(1);
    cout<<"Processing...\n\n";
    sleep(2);
    cout<<"Process Completed\n\n";
    sleep(3);
    cout<<"<<<<<<<<<<<Next Student Process will execute>>>>>>>>>\n\n";
	sem_post(&st2);
	sem_post(&st3);
	
}
void *th_function2(void* user2_pen)
{
	sem_wait(&st1);
	sem_wait(&st3);
	long long user2_pen_fun2=(long long)user2_pen;
	
	long long user2_qp=1;
	quesp-=user2_qp;
	
	long long user2_paper=1;
	paper-=user2_paper;
	cout<<"Student 2 is executing\n\n";
	sleep(2);
	cout<<"Student 2 is already having pen\n\n";
    sleep(1);
    cout<<"Student 2 got paper from teacher\n\n";
    sleep(1);
    cout<<"Student 2 got question paper from teacher\n\n";
    sleep(1);
    cout<<"Processing...\n\n";
    sleep(2);
    cout<<"Process Completed\n\n";
    sleep(3);
    cout<<"<<<<<<<<<<<Next Student Process will execute>>>>>>>>>\n\n";
	sem_post(&st1);
	sem_post(&st3);
	
}
void *th_function3(void* user3_quesp)
{
	sem_wait(&st1);
	sem_wait(&st2);
	
	long long user3_paper_fun3=(long long)user3_quesp;
	
	long long user3_paper=1;
	paper-=user3_paper;
	
	long long user3_pen=1;
	pen-=user3_pen;
	cout<<"Student 3 is executing at first\n\n";
	sleep(2);
	cout<<"Student 3 is already having Question Paper\n\n";
    sleep(1);
    cout<<"Student 3 got pen from teacher\n\n";
    sleep(1);
    cout<<"Student 3 got paper from teacher\n\n";
    sleep(1);
    cout<<"Processing...\n\n";
    sleep(2);
    cout<<"Process Completed\n\n";
    sleep(3);
    cout<<"<<<<<<<<<<<Next Student Process will execute>>>>>>>>>\n\n";
	sem_post(&st1);
	sem_post(&st2);
	
}
main()
{
	system("color f3");
cout<<"<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<Process Syncronisation>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n\n\n";
sem_init(&st1,0,1);
sem_init(&st2,0,1);
sem_init(&st3,0,1);
pthread_t teach,stu1,stu2,stu3;
int user1_paper=1;
int user2_pen=1;
int user3_quesp=1;
pthread_create(&teach,NULL,&th_function,NULL);
pthread_create(&stu1,NULL,&th_function1,(void*)user1_paper);
pthread_create(&stu2,NULL,&th_function2,(void*)user2_pen);
pthread_create(&stu3,NULL,&th_function3,(void*)user3_quesp);
pthread_join(teach,NULL);
pthread_join(stu1,NULL);
pthread_join(stu2,NULL);
pthread_join(stu3,NULL);


}





