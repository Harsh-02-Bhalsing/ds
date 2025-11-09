#include <stdio.h>
int binarySearch(int arr[],int n,int key){
    int low=0,high=n-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(arr[mid]==key){
            return mid;
        }else if(arr[mid]<key){
            low=mid+1;
        }else{
            high=mid-1;
        }
    }
    return -1;
}
int main(){
    int arr[100],n,rollno;
    printf("Enter no. of students who attended the program: ");
    scanf("%d",&n);
    printf("Enter Roll no. of students in sorted order: \n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter roll no. to search: ");
    scanf("%d",&rollno);
    int result=binarySearch(arr,n,rollno);
    if(result!=-1){
        printf("Student attended the program and found at index %d",result);
    }else{
        printf("Student did not attend the program");
    }
    return 0;
}