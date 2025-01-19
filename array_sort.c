#include <stdio.h>
void main(){
  int n,i,j,temp;
  printf("Enter no of elements in array:");
  scanf("%d",&n);
  int arr[n];
   printf("Enter elements in array:");
     for(i=0;i<n;i++){
  scanf("%d",&arr[i]);
     }
     for(i=0;i<n-1;i++){
         for(j=0;j<n-i-1;j++){
             if(arr[j]>arr[j+1]){
                 temp=arr[j];
                 arr[j]=arr[j+1];
                 arr[j+1]=temp;
             }
         }
     }
     printf("elements in array after sorting:");
     for(i=0;i<n;i++){
  printf("%d\n",arr[i]);
     }
}