#include <stdio.h>
int queue[5], front=-1,rear=-1;
void addOrder(int order){
    if(rear==5-1){
        printf("Queue is full. No more accepting orders\n");
    }else{
        if(front==-1) front=0;
        queue[++rear]=order;
        printf("Order added %d: \n",order);
    }
}
void deleteOrder(){
    if(front==-1||front>rear){
        printf("No orders in queue.\n");
    }else{
        printf("Order deleted (served) %d\n",queue[front++]);
    }
}
void displayOrder(){
    if(front==-1||front>rear){
        printf("No orders in queue.\n");
    }else{
        printf("Orders in queue- \n");
         for(int i=front;i<=rear;i++){
        printf("%d\n",queue[i]);
        }
    }
}
int main(){
    int choice,order;
    while(1){
        printf("Pizza Parlor menu\n");
        printf("1.Add order: \n2.Delete order: \n3.Display orders: \n4.Exit: \n");
        printf("Enter choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter order no. ");
                scanf("%d",&order);
                addOrder(order);
                break;
            case 2:
                deleteOrder();
                break;
            case 3:
                displayOrder();
                break;
            case 4:
                printf("Exited, Thank you !\n");
                return 0;
            default:
            printf("Invalid Choice!\n");
        }
    }
    return 0;
}