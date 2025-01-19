#include <stdio.h>
#include <stdlib.h>
#define SIZE 5
int q[SIZE];
void enq();
void deq();
void display();
int rear=-1,front=-1;
void main(){
    int ch;
    while(1){
        printf("1.enqueue\n2.dequeue\n3.display\n4.exit\nenter a choice:");
        scanf("%d",&ch);
        switch(ch){
        case 1:
        enq();
        break;
        case 2:
        deq();
        break;
        case 3:
        display();
        break;
        case 4:
        printf("exiting.....\n");
        exit(0);
        break;
        }
    }
}
void enq(){
    int item;
    if((rear+1)%SIZE==front){
        printf("overflow\n");
        return;
    }
    if(front==-1){
        front=0;
    }
    printf("enter the element:");
    scanf("%d",&item);
    rear=(rear+1)%SIZE;
    q[rear]=item;
    printf("%d inserted to queue\n",q[rear]);
}
void deq(){
  if(front==-1){
      printf("underflow\n");
      return;
  }
  printf("%d dequeued\n",q[front]);
    if(front==rear){
        front=rear=-1;
    }else{
        front=(front+1)%SIZE;
    }
}
void display(){
   if(front==-1&&rear==-1){
       printf("underflow\n");
       return;
   }
   printf("queue elements are:\n");
   int i=front;
   while(i!=rear){
       printf("%d\n",q[i]);
       i=(i+1)%SIZE;
   }
   printf("%d\n",q[rear]);
}