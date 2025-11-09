#include <stdio.h>
#include <string.h>
struct Client{
    char name[100];
    char phone[15];
};
struct Client table[20];
int occupied[20];
int hashfunc(char *name){
    int sum=0;
    for(int i=0;name[i]!='\0';i++){
        sum+=name[i];
    }
    return sum%20;
}
int doublehashfunc(char *name){
    int sum=0;
    for(int i=0;name[i]!='\0';i++){
        sum+=name[1];
    }
    return 7-(sum%7);
}
void insertClient(struct Client c,int method){
    int index=hashfunc(c.name);
    int step=doublehashfunc(c.name);
    for(int i=0;i<20;i++){
        int newIndex;
        if(method==1){
            newIndex=(index+i)%20;
        }else if(method==2){
            newIndex=(index+i*i)%20;
        }else{
            newIndex=(index+i*step)%20;
        }
        if (occupied[newIndex] == 0) {
            table[newIndex] = c;
            occupied[newIndex] = 1;
            printf("Inserted at position %d\n", newIndex);
            return;
        }
    }
    printf("Table is full\n");   
}
void searchClient(char *name, int method) {
    int index = hashfunc(name);
    int step = doublehashfunc(name);
    for (int i = 0; i < 20; i++) {
        int newIndex;
        if (method == 1) {
            newIndex = (index + i) % 20;
        } else if (method == 2) {
            newIndex = (index + i * i) % 20;
        } else {
            newIndex = (index + i * step) % 20;
        }
        if (occupied[newIndex] == 1) {
            if (strcmp(table[newIndex].name, name) == 0) {
                printf("Found!\n");
                printf("Name: %s\n", table[newIndex].name);
                printf("Phone: %s\n", table[newIndex].phone);
                return;
            }
        }
    }
    printf("Client not found.\n");
}
int main(){
    int method, n;
    struct Client c;
    char searchName[100];
    for (int i = 0; i < 20; i++) {
        occupied[i] = 0;
    }
    printf("=== Hash Table with Collision Resolution ===\n\n");
    printf("Choose collision resolution method:\n");
    printf("1. Linear Probing\n");
    printf("2. Quadratic Probing\n");
    printf("3. Double Hashing\n");
    printf("Enter choice: ");
    scanf("%d", &method);
    printf("\nHow many clients to insert? ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("\n--- Client %d ---\n", i + 1);
        printf("Enter name: ");
        scanf("%s", c.name);
        printf("Enter phone: ");
        scanf("%s", c.phone);
        insertClient(c, method);
    }
    printf("Enter name to search: ");
    scanf("%s", searchName);
    searchClient(searchName, method);
    return 0;
}