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
    if(rear==SIZE-1){
        printf("overflow\n");
        return;
    }else{
       if(front==-1){
           front=0;
       }
       printf("enter the element to be inserted:");
       scanf("%d",&item);
       rear=rear+1;
       q[rear]=item;
       printf("%d inserted to queue\n",q[rear]);
    }
}
void deq(){
    if(front==-1||front>rear){
        printf("underflow\n");
    }else{
        printf("Element dequeued:%d",q[front]);
        front=front+1;
    }
}
void display(){
    if(front==-1){
        printf("underflow\n");
    }else{
        printf("element of queue:\n");
        for(int i=front;i<=rear;i++){
            printf("%d\n",q[i]);
        }
    }
}