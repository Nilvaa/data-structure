#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node* next;
};
void create(int data);
void del_be();
void del_end();
void del_pos(int pos);
void traverse();
struct node* head=NULL;
void main(){
    int ch,key,data;
    do{
        printf("1.create\n2.delete from begining\n3.delete from end\n4.delete from position\n5.traverse\n6.exit\nenter a choice:");
        scanf("%d",&ch);
        switch(ch){
            case 1:
            printf("enter data:");
            scanf("%d",&data);
            create(data);
            break;
            case 2:
            del_be();
            break;
            case 3:
            del_end();
            break;
            case 4:
            printf("enter key to delete:");
            scanf("%d",&key);
            del_pos(key);
            break;
            case 5:
            traverse();
            break;
            case 6:
            printf("Exiting.....");
            exit(0);
            break;
        }
    }while(ch!=6);
}
void create(int data){
   struct node* newnode=(struct node*)malloc(sizeof(struct node));
   if(!newnode){
       printf("Memory failed\n");
       return;
   }
   newnode->data=data;
   newnode->next=NULL;
   if(head==NULL){
       head=newnode;
   }else{
       struct node* temp=head;
       while(temp->next!=NULL){
           temp=temp->next;
       }
       temp->next=newnode;
     
   }
    printf("%d inserted\n",data);
}
void del_be(){
    if(head==NULL){
        printf("list empty\n");
        return;
    }
    struct node* temp=head;
    head=head->next;
    printf("%d deleted\n",temp->data);
    free(temp);
}
void del_end(){
    if(head==NULL){
        printf("list empty\n");
        return;
    }
   if(head->next==NULL){
       printf("%d deleted\n",head->data);
       free(head);
       head=NULL;
       return;
   }
   struct node* temp=head;
   while(temp->next->next!=NULL){
       temp=temp->next;
   }
   printf("%d deleted\n",temp->next->data);
   free(temp->next);
   temp->next=NULL;
}
void del_pos(int key){
   if(head==NULL){
       printf("list empty\n");
       return;
   }
   if(head->data==key){
       del_be();
       return;
   }
   struct node* temp=head;
   while(temp->next!=NULL &&temp->next->data!=key){
       temp=temp->next;
   }
   if(temp->next==NULL){
       printf("not found\n");
       return;
   }
   struct node* del=temp->next;
   temp->next=del->next;
   printf("%d deleted\n",del->data);
   free(del);
}
void traverse(){
    if(head==NULL){
        printf("list empty\n");
        return;
    }
    struct node* temp=head;
    while(temp!=NULL){
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}