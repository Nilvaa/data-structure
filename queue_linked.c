#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node* next;
};
struct node* fr=NULL;
struct node* re=NULL;
void enq(int data);
void deq();
void display();
void main(){
    int ch,data;
    do{
        printf("1.enqueue\n2.dequeue\n3.display\n4.exit\nenter a choice:");
        scanf("%d",&ch);
        switch(ch){
            case 1:
            printf("enter data:");
            scanf("%d",&data);
            enq(data);
            break;
            case 2:
            deq();
            break;
            case 3:
            display();
            break;
            case 4:
            printf("exiting...\n");
            exit(0);
            break;
        }
    }while(ch!=4);
}
void enq(int data){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    if(!newnode){
        printf("memory failed\n");
        return;
    }
  newnode->data=data;
  newnode->next=NULL;
  if(re==NULL){
      fr=re=newnode;
  }else{
      re->next=newnode;
      re=newnode;
  }
  printf("enqueued %d\n",data);
}
void deq(){
    if(fr==NULL){
        printf("underflow\n");
        return;
    }
       struct node* temp=fr;
    printf("%d dequeued\n",temp->data);
    fr=fr->next;
    if(fr==NULL){
        re=NULL;
    }
    free(temp);
}
void display(){
    if(fr==NULL){
        printf("underflow\n");
        return;
    }
    struct node* temp=fr;
     printf("queue elements:\n");
    while(temp!=NULL){
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}