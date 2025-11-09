#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Seat {
    int seat_no;
    struct Seat *prev, *next;
} Seat;

Seat* rows[10];
int booked[10][7];

Seat* createSeat(int n) {
    Seat* s = malloc(sizeof(Seat));
    s->seat_no = n;
    s->prev = s->next = NULL;
    return s;
}

void updateList() {
    for(int r=0; r<10; r++) {
        rows[r] = NULL;
        Seat *last = NULL;
        for(int s=0; s<7; s++) {
            if(!booked[r][s]) {
                Seat *n = createSeat(s+1);
                if(!rows[r]) rows[r] = n;
                else { last->next = n; n->prev = last; }
                last = n;
            }
        }
    }
}

void showSeats() {
    printf("\nAvailable Seats:\n");
    for(int r=0; r<10; r++) {
        printf("Row %d: ", r+1);
        Seat* t = rows[r];
        if(!t) printf("No seats");
        while(t) { printf("%d ", t->seat_no); t = t->next; }
        printf("\n");
    }
}

void book(int r, int s) {
    if(booked[r][s]) printf("Already booked!\n");
    else { booked[r][s] = 1; updateList(); printf("Booked!\n"); }
}

void cancel(int r, int s) {
    if(!booked[r][s]) printf("Already free!\n");
    else { booked[r][s] = 0; updateList(); printf("Cancelled!\n"); }
}

int main() {
    srand(time(NULL));
    for(int r=0;r<10;r++)
        for(int s=0;s<7;s++)
            booked[r][s] = rand()%2;

    updateList();

    while(1){
        int c,r,s;
        printf("\n1.Show\n2.Book\n3.Cancel\n4.Exit\nChoice: ");
        scanf("%d",&c);
        if(c==1) showSeats();
        else if(c==2){
            printf("Row(1-10): "); scanf("%d",&r);
            printf("Seat(1-7): "); scanf("%d",&s);
            book(r-1,s-1);
        }
        else if(c==3){
            printf("Row(1-10): "); scanf("%d",&r);
            printf("Seat(1-7): "); scanf("%d",&s);
            cancel(r-1,s-1);
        }
        else if(c==4) break;
        else printf("Invalid!\n");
    }
    return 0;
}