#include <stdio.h>
void sort(int arr[],int size);
void linear(int arr[],int size,int n);
void binary(int arr[],int size,int n);
void main(){
    int arr[30],n,size,i,ch;
    printf("Enter size of array:");
    scanf("%d",&size);
    printf("enter array elements:");
    for(i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }
    do{
        printf("1.linear\n2.binary\n3.exit\nenter choice:");
        scanf("%d",&ch);
        switch(ch){
            case 1:
            printf("Enter element to be searched:");
            scanf("%d",&n);
            linear(arr,size,n);
            break;
            case 2:
            sort(arr,size);
            printf("Enter element to be searched:");
            scanf("%d",&n);
            binary(arr,size,n);
            break;
            case 3:
            printf("exiting...\n");
            break;
            default:
            printf("invalid choice");
            break;
        }
    }while(ch!=3);
}
void linear(int arr[],int size,int n){
    int f=0,i;
    for(i=0;i<size;i++){
        if(arr[i]==n){
            f=1;
            printf("Element %d found at index %d\n",n,i);
            break;
        }
        
    }
    if(!f){
           printf("Element %d not found",n); 
        }
}
void sort(int arr[],int size){
    int temp,i,j;
    for(i=0;i<size-1;i++){
        for(j=0;j<size-i-1;j++){
           if(arr[j]>arr[j+1]){
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
           }
        }
    }
    printf("array elements after sorting:\n");
    for(i=0;i<size;i++){
        printf("%d\n",arr[i]);
    }
    printf("\n");
}
void binary(int arr[],int size,int n){
  int mid,low=0,high=size-1,f=0;  
  while(low<=high){
      mid=(low+high)/2;
      if(arr[mid]==n){
          f=1;
           printf("Element %d found at index %d\n",n,mid);
            break;
      }else if(arr[mid]<n){
          low=mid+1;
      }else{
          high=mid+1;
  }
  }
  if(f==0){
      printf("Element %d not found",n); 
  }
}




