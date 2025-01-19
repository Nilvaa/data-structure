#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node* next;
};
struct node* top=NULL;
void push(int data);
void pop();
void display();
void main(){
    int ch,data;
    do{
        printf("1.push\n2.pop\n3.display\n4.exit\nenter a choice:");
        scanf("%d",&ch);
        switch(ch){
            case 1:
            printf("enter data:");
            scanf("%d",&data);
            push(data);
            break;
            case 2:
            pop();
            break;
            case 3:
            display();
            break;
            case 4:
            printf("exiting....");
            exit(0);
            break;
        }
    }while(ch!=4);
}
void push(int data){
  struct node* newnode=(struct node*)malloc(sizeof(struct node));
  if(!newnode){
      printf("memory failed\n");
      return;
  }
  newnode->data=data;
  newnode->next=top;
  top=newnode;
  printf("%d pushed\n",data);
}
void pop(){
 if(top==NULL){
     printf("underflow\n");
     return;
}
struct node* temp=top;
printf("%d popped\n",temp->data);
top=top->next;
free(temp);
}
void display(){
    if(top==NULL){
        printf("underflow\n");
        return;
    }
    struct node* temp=top;
    while(temp!=NULL){
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}