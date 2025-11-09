#include <stdio.h>
#include <string.h>
#define MAX 10
#define NAME_LEN 30

int graph[MAX][MAX];
char cities[MAX][NAME_LEN];
int city_count = 0;

int find_city(char name[]) {
    for (int i = 0; i < city_count; i++)
        if (strcmp(cities[i], name) == 0)
            return i;
    return -1;
}

int add_city(char name[]) {
    int i = find_city(name);
    if (i != -1)
        return i;
    strcpy(cities[city_count], name);
    return city_count++;
}

void add_flight() {
    char src[NAME_LEN], dest[NAME_LEN];
    int cost;
    printf("Enter source city: ");
    scanf("%s", src);
    printf("Enter destination city: ");
    scanf("%s", dest);
    printf("Enter cost/time between them: ");
    scanf("%d", &cost);
    int s = add_city(src);
    int d = add_city(dest);
    graph[s][d] = cost;
    graph[d][s] = cost;
}

void display_matrix() {
    if (city_count == 0) {
        printf("\nNo cities added yet!\n");
        return;
    }
    printf("\n--- Adjacency Matrix (0 = No Flight) ---\n\n");
    printf("%12s", "");
    for (int i = 0; i < city_count; i++)
        printf("%12s", cities[i]);
    printf("\n");
    for (int i = 0; i < city_count; i++) {
        printf("%12s", cities[i]);
        for (int j = 0; j < city_count; j++)
            printf("%12d", graph[i][j]);
        printf("\n");
    }
}

void dfs(int node, int visited[]) {
    visited[node] = 1;
    for (int i = 0; i < city_count; i++)
        if (graph[node][i] != 0 && !visited[i])
            dfs(i, visited);
}

void check_connected() {
    if (city_count == 0) {
        printf("\nNo cities to check.\n");
        return;
    }
    int visited[MAX] = {0};
    dfs(0, visited);
    for (int i = 0; i < city_count; i++) {
        if (!visited[i]) {
            printf("\nThe graph is NOT connected.\n\n");
            return;
        }
    }
    printf("\nThe graph IS connected.\n\n");
}

int main() {
    int choice;
    while (1) {
        printf("\n--- Flight Graph Menu ---\n");
        printf("1. Add Flight\n");
        printf("2. Display Adjacency Matrix\n");
        printf("3. Check if Graph is Connected\n");
        printf("4. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_flight();
                break;
            case 2:
                display_matrix();
                break;
            case 3:
                check_connected();
                break;
            case 4:
                printf("Program exited.\n");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}