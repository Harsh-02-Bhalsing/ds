#include <stdio.h>
int linearSearch(int arr[],int n,int key){
    for(int i=0;i<n;i++){
        if(arr[i]==key){
            return i;
        }
    }
    return -1;
}
int main(){
    int arr[100],n,rollno;
    printf("Enter no. of students who attended the program: ");
    scanf("%d",&n);
    printf("Enter %d Roll no.s: \n",n);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter roll no. to search: ");
    scanf("%d",&rollno);
    int result=linearSearch(arr,n,rollno);
    if (result!=-1){
        printf("Student attended program and found at index %d",result);
    }else{
        printf("Student has not attended the program");
    }
    return 0;
}