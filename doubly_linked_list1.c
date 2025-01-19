#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node* next;
    struct node* prev;
};
struct node* head=NULL;
void create(int data);
void count();
void search(int key);
void display();
void main(){
    int ch,data;
    do{
        printf("1.create\n2.count\n3.search\n4.display\n5.exit\nenter choice:");
        scanf("%d",&ch);
        switch(ch){
            case 1:
            printf("enter data:");
            scanf("%d",&data);
            create(data);
            break;
            case 2:
            count();
            break;
            case 3:
            printf("enter data to be searched:");
            scanf("%d",&data);
            search(data);
            break;
            case 4:
            display();
            break;
            case 5:
            printf("exiting....\n");
            exit(0);
            break;
        }
    }while(ch!=5);
}
void create(int data){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    if(!newnode){
        printf("memory failed\n");
        return;
    }
  newnode->data=data;
  newnode->next=NULL;
  newnode->prev=NULL;
  if(head==NULL){
      head=newnode;
  }else{
        struct node* temp=head;
  while(temp->next!=NULL){
      temp=temp->next;
  }
  temp->next=newnode;
  newnode->prev=temp;
  }
printf("%d inserted\n",data);
}
void count(){
  int c=0;
  struct node* temp=head;
  if(head==NULL){
      printf("list empty\n");
      return;
  }
  while(temp!=NULL){
      c++;
      temp=temp->next;
  }
  printf("count:%d\n",c);
}
void search(int data){
    int pos=1;
    struct node* temp=head;
    while(temp!=NULL){
        if(temp->data==data){
            printf("%d found at position %d\n",data,pos);
            return;
        }
        temp=temp->next;
        pos++;
    }
}
void display(){
    if(head==NULL){
        printf("list empty\n");
        return;
    }
    struct node* temp=head;
    while(temp!=NULL){
        printf("%d<->",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}