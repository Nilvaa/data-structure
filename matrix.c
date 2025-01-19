#include <stdio.h>
void add(int a[20][20],int b[20][20],int m,int n);
void sub(int a[20][20],int b[20][20],int m,int n);
void mul(int a[20][20],int b[20][20],int m1,int n1,int m2, int n2);
void main(){
    int a[20][20],b[20][20];
    int m1,n1,m2,n2,c,i,j;
    printf("enter no rows and columns of 1st matrix:");
    scanf("%d%d",&m1,&n1);
    printf("Enter no of elements:");
    for(i=0;i<m1;i++){
        for(j=0;j<n1;j++){
            scanf("%d",&a[i][j]);
        }
    }
     printf("1st matrix:\n");
    for(i=0;i<m1;i++){
        for(j=0;j<n1;j++){
            printf("\t%d\t",a[i][j]);
        }
        printf("\n");
    }
    printf("enter no of rows and columns of 2nd matrix:");
    scanf("%d%d",&m2,&n2);
    printf("enter no of elements:");
    for(i=0;i<m2;i++){
        for(j=0;j<n2;j++){
            scanf("%d",&b[i][j]);
        }
    }
    printf("2nd matrix:\n");
    for(i=0;i<m2;i++){
        for(j=0;j<n2;j++){
            printf("\t%d\t",b[i][j]);
        }
        printf("\n");
    }
    do{
        printf("1.add\n2.sub\n3.mul\n4.exit\nenter a choice:");
        scanf("%d",&c);
        switch(c){
            case 1:
            if(m1==m2&&n1==n2){
                add(a,b,m1,n1);
            }else{
                printf("Incompatable\n");
            }
            break;
            case 2:
            if(m1==m2&&n1==n2){
                sub(a,b,m1,n1);
            }else{
                printf("Incompatable\n");
            }
            break;
            case 3:
            if(n1==m2){
                mul(a,b,m1,n1,m2,n2);
            }else{
                printf("Incompatable\n");
            }
            break;
            case 4:
            printf("exiting....\n");
            break;
            default:
            printf("Invalid choice\n");
            break;
        }
        
    }while(c!=4);
}
void add(int a[20][20],int b[20][20],int m,int n){
    int sum[20][20],i,j;
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            sum[i][j]=a[i][j]+b[i][j];
        }
    }
    printf("add matrix\n");
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            printf("\t%d\t",sum[i][j]);
        }
        printf("\n");
    }
}
void sub(int a[20][20],int b[20][20],int m,int n){
    int sub[20][20],i,j;
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            sub[i][j]=a[i][j]-b[i][j];
        }
    }
     printf("add matrix\n");
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            printf("\t%d\t",sub[i][j]);
        }
        printf("\n");
    }
}
void mul(int a[20][20],int b[20][20],int m1,int n1,int m2,int n2){
    int mul[20][20]={0},i,j,k;
    for(i=0;i<m1;i++){
        for(j=0;j<n2;j++){
            for(k=0;k<n1;k++){
                mul[i][j]+=a[i][k]*b[k][j];
            }
        }
    }
     printf("multi matrix\n");
    for(i=0;i<m1;i++){
        for(j=0;j<n1;j++){
            printf("\t%d\t",mul[i][j]);
        }
        printf("\n");
    }
}