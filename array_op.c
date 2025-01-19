#include <stdio.h>
int insert(int arr[],int size);
int del(int arr[],int size);
void traversal(int arr[],int size);
void main() {
 int arr[100];
 int size,i,ch;
 printf("Enter size of array:");
 scanf("%d",&size);
 printf("Enter array elements:\n");
 for(i=0;i<size;i++){
     scanf("%d",&arr[i]);
 }
 do{
     printf("1.insert\n2.delete\n3.traversal\n4.exit\nenter your choice:");
     scanf("%d",&ch);
     switch(ch){
         case 1:
         size=insert(arr,size);
         break;
         case 2:
         size=del(arr,size);
         break;
         case 3:
         traversal(arr,size);
         break;
         case 4:
         printf("exiting....\n");
         break;
         default:
         printf("Invalid choice\n");
         break;
     }
 }while(ch!=4);
}
void traversal(int arr[],int size){
    if(size==0){
      printf("Array is empty\n");  
      return;
    }
    printf("Array elements are:");
    for(int i=0;i<size;i++){
        printf("%d\t",arr[i]);
    }
    printf("\n");
}
int insert(int arr[],int size){
    int index,item;
    printf("enter index to insert the element:");
    scanf("%d",&index);
    if(index<0||index>size){
        printf("invalid syntax");
        return size;
    }
    printf("Element to be entered:");
    scanf("%d",&item);
    for(int i=size;i>index;i--){
        arr[i]=arr[i-1];
    }
    arr[index]=item;
    size++;
    printf("element %d entered at index %d\n",item,index);
    return size;
}
int del(int arr[],int size){
    int item,index;
    if(size==0){
    printf("Array is empty");
    return size;
    }
    printf("enter index to delete the element:");
    scanf("%d",&index);
    if(index<0||index>=size){
       printf("Invalid index");
       return size;
    }
    item=arr[index];
    for(int i=index;i<size-1;i++){
        arr[i]=arr[i+1];
    }
    size--;
     printf("element %d deleted from index %d\n",item,index);
    return size;
}