#include <stdio.h>
#include <stdlib.h>
#define MAX 5
int stack[MAX];
int top=-1;
void push(int val);
int pop();
int peek();
int isempty();
int isfull();
void display();
void main(){
    int ch,val;
    do{
        printf("1.push\n2.pop\n3.peek\n4.is empty\n5.is full\n6.display\n7.exit\nenter a choice:");
        scanf("%d",&ch);
        switch(ch){
            case 1:
            printf("Enter value to be pushed:");
            scanf("%d",&val);
            push(val);
            display();
            break;
            case 2:
            val=pop();
            if(val!=-1){
                printf("value popped:%d\n",val);
            }
            display();
            break;
            case 3:
            val=peek();
            if(val!=-1){
                printf("Top value:%d\n",val);
            }
            break;
            case 4:
            if(isempty()){
                printf("Stack is empty\n");
            }else{
                printf("Stack is not empty\n");
            }
            break;
            case 5:
            if(isfull()){
                printf("Stack is full\n");
            }else{
                printf("Stack is not full\n");
            }
            break;
            case 6:
            display();
            break;
            case 7:
            exit(0);
            break;
        }
    }while(ch!=7);
}
void push(int val){
    if(isfull()){
        printf("Stack is full\n");
    }else{
        stack[++top]=val;
        printf("Value pushed:%d\n",val);
    }
}
int pop(){
    if(isempty()){
        printf("Stack is empty\n");
        return -1;
    }else{
        return stack[top--];
    }
}
int peek(){
    if(isempty()){
        printf("Stack is empty\n");
        return -1;
    }else{
        return stack[top];
    }
}
int isempty(){
    return top==-1;
}
int isfull(){
    return top==MAX-1;
}
void display(){
    if(isempty()){
        printf("Stack is empty\n");
    }else{
        printf("Stack elements\n");
        for(int i=top;i>=0;i--){
            printf("%d\n",stack[i]);
        }
    }}