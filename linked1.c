#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node* next;
};
struct node* head=NULL;
void create(int data);
void insert_frnt(int data);
void insert_after(int key,int data);
void insert_end(int data);
void search(int data);
void traverse();
void main(){
   int ch,key,data;
   do{
       printf("1.creation\n2.insert at front\n3.insert after particular node\n4.insert end\n5.search\n6.traverse\n7.exit\nenter a choice:");
       scanf("%d",&ch);
       switch(ch){
           case 1:
           printf("enter data:");
           scanf("%d",&data);
           create(data);
           break;
           case 2:
           printf("Enter data to insert at front:");
           scanf("%d",&data);
           insert_frnt(data);
           break;
           case 3:
            printf("Enter key after which to insert:");
           scanf("%d",&key);
             printf("Enter data to insert:");
           scanf("%d",&data);
           insert_after(key,data);
           break;
           case 4:
             printf("Enter data to insert at end:");
           scanf("%d",&data);
           insert_end(data);
           break;
           case 5:
             printf("Enter data to search:");
           scanf("%d",&data);
           search(data);
           break;
           case 6:
           traverse();
           break;
           case 7:
           printf("Exiting....");
           exit(0);
       }
   }while(ch!=7);
}
void create(int data){
    if(head!=NULL){
        printf("list exist.....\n");
        return;
    }
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    if(!newnode){
        printf("memory allocation failed\n");
        return;
    }
    newnode->data=data;
    newnode->next=NULL;
    head=newnode;
    printf("list created with %d\n",data);
}
void insert_frnt(int data){
   struct node* newnode=(struct node*)malloc(sizeof(struct node));
    if(!newnode){
        printf("memory failed\n");
        return;
    }
    newnode->data=data;
    newnode->next=head;
    head=newnode;
    printf("%d inserted at front\n",data);
}
void insert_after(int key,int data){
    struct node* temp=head;
    while(temp->next!=NULL && temp->data!=key){
        temp=temp->next;
    }
    if(temp==NULL){
        printf("%d not found\n",key);
        return;
    }
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    if(!newnode){
        printf("memory failed\n");
        return;
    }
    newnode->data=data;
    newnode->next=temp->next;
    temp->next=newnode;
    printf("%d inserted after %d\n",data,key);
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
       head=newnode;
       printf("%d inserted at end\n",data);
      
   }
   struct node* temp=head;
   while(temp->next!=NULL){
       temp=temp->next;
   }
   temp->next=newnode;
       printf("%d inserted at end\n",data);
}
void search(int data){
   struct node* temp=head;
   int pos=1;
   while(temp!=NULL){
       if(temp->data==data){
           printf("%d found at position %d\n",data,pos);
       }
       temp=temp->next;
       pos++;
   }
   printf("%d not found\n",data);
}
void traverse(){
    if(head==NULL){
        printf("list is empty\n");
        return;
    }
    struct node* temp=head;
    while(temp!=NULL){
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}
