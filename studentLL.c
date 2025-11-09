#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    long int PRN;
    char name[50];
    struct Node *next;
} Node;

Node* createNode(long int PRN, char name[]) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->PRN = PRN;
    strcpy(newNode->name, name);
    newNode->next = NULL;
    return newNode;
}

void addPresident(Node **head, long int PRN, char name[]) {
    Node *newNode = createNode(PRN, name);
    newNode->next = *head;
    *head = newNode;
}

void addSecretary(Node **head, long int PRN, char name[]) {
    Node *newNode = createNode(PRN, name);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node *temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

void addMember(Node **head, long int PRN, char name[]) {
    Node *newNode = createNode(PRN, name);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node *temp = *head;
    while (temp->next->next != NULL)
        temp = temp->next;
    newNode->next = temp->next;
    temp->next = newNode;
}

void deletePresident(Node **head) {
    if (*head == NULL) return;
    Node *temp = *head;
    *head = (*head)->next;
    free(temp);
}

void deleteSecretary(Node **head) {
    if (*head == NULL) return;
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }
    Node *temp = *head;
    while (temp->next->next != NULL)
        temp = temp->next;
    free(temp->next);
    temp->next = NULL;
}

void deleteMember(Node **head, long int PRN) {
    if (*head == NULL) return;
    Node *temp = *head, *prev = NULL;
    while (temp != NULL && temp->PRN != PRN) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) return;
    if (prev == NULL)
        *head = temp->next;
    else
        prev->next = temp->next;
    free(temp);
}

int countMembers(Node *head) {
    int count = 0;
    Node *temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

void display(Node *head) {
    Node *temp = head;
    printf("\nClub Members:\n");
    while (temp != NULL) {
        printf("PRN: %ld  | Name: %s\n", temp->PRN, temp->name);
        temp = temp->next;
    }
}

Node* concatenate(Node *head1, Node *head2) {
    if (head1 == NULL) return head2;
    Node *temp = head1;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = head2;
    return head1;
}

int main() {
    Node *divisionA = NULL, *divisionB = NULL;
    long int PRN;
    char name[50];
    int choice, div;

    while (1) {
        printf("\n--- Pinnacle Club Menu ---\n");
        printf("1. Add President\n2. Add Secretary\n3. Add Member\n4. Delete President\n5. Delete Secretary\n6. Delete Member by PRN\n7. Count Members\n8. Display Members\n9. Concatenate Division A & B\n10. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 10) break;

        printf("Select Division (1 for A / 2 for B): ");
        scanf("%d", &div);
        Node **club = (div == 1) ? &divisionA : &divisionB;

        switch (choice) {
            case 1:
                printf("Enter PRN and Name: ");
                scanf("%ld %s", &PRN, name);
                addPresident(club, PRN, name);
                break;
            case 2:
                printf("Enter PRN and Name: ");
                scanf("%ld %s", &PRN, name);
                addSecretary(club, PRN, name);
                break;
            case 3:
                printf("Enter PRN and Name: ");
                scanf("%ld %s", &PRN, name);
                addMember(club, PRN, name);
                break;
            case 4:
                deletePresident(club);
                break;
            case 5:
                deleteSecretary(club);
                break;
            case 6:
                printf("Enter PRN to delete: ");
                scanf("%ld", &PRN);
                deleteMember(club, PRN);
                break;
            case 7:
                printf("Total Members = %d\n", countMembers(*club));
                break;
            case 8:
                display(*club);
                break;
            case 9:
                divisionA = concatenate(divisionA, divisionB);
                printf("\nLists concatenated into Division A.\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}