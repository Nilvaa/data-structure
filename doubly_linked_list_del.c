#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node* next;
    struct node* prev;
};
struct node* head=NULL;
void create(int data);
void insert_be(int data);
void insert_end(int data);
void del_be();
void del_end();
void display();
void main(){
    int ch,data;
    do{
        printf("1.create\n2.insert first\n3.insert last\n4.delete first\n5.delete end\n6.display\n7.exit\nenter a choice:");
        scanf("%d",&ch);
        switch(ch){
            case 1:
            printf("enter data:");
            scanf("%d",&data);
            create(data);
            break;
            case 2:
             printf("enter data at first:");
            scanf("%d",&data);
            insert_be(data);
            break;
            case 3:
             printf("enter data at end:");
            scanf("%d",&data);
            insert_end(data);
            break;
            case 4:
            del_be();
            break;
            case 5:
            del_end();
            break;
            case 6:
            display();
            break;
            case 7:
            printf("exiting...\n");
            break;
        }
    }while(ch!=7);
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
void insert_be(int data){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    if(!newnode){
        printf("memory failed\n");
        return;
    }
  newnode->data=data;
  newnode->next=head;
  newnode->prev=NULL;
  if(head!=NULL){
      head->prev=newnode;
  }
  head=newnode;
  printf("%d inserted at first\n",data);
}
void insert_end(int data){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    if(!newnode){
        printf("memory failed\n");
        return;
    }
    newnode->data=data;
    newnode->next=NULL;
    if(head==NULL){
        newnode->prev=NULL;
        head=newnode;
    }else{
        struct node* temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->prev=temp;
    }
    printf("%d inserted last\n",data);
}
void del_be(){
    if(head==NULL){
        printf("list empty\n");
        return;
    }
    struct node* temp=head;
    head=head->next;
    if(head!=NULL){
        head->prev=NULL;
    }
    printf("%d deleted\n",temp->data);
    free(temp);
}
void del_end(){
    if(head==NULL){
        printf("list empty\n");
        return;
    }
    if(head->next==NULL){
        printf("deleted %d\n",head->data);
        free(head);
        head=NULL;
        return;
    }
    struct node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    printf("deleted:%d\n",temp->data);
    temp->prev->next=NULL;
    free(temp);
}
void display(){
    if(head==NULL){
        printf("list empty\n");
        return; 
    }
    struct node* temp=head;
    printf("list elements:\n");
    while(temp!=NULL){
        printf("%d<->",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}