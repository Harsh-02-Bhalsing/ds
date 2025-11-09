#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char keyword[50], meaning[100];
    struct node *left, *right;
} Node;

Node* create(char k[], char m[]) {
    Node* n = (Node*)malloc(sizeof(Node));
    strcpy(n->keyword, k);
    strcpy(n->meaning, m);
    n->left = n->right = NULL;
    return n;
}

Node* insert(Node* r, char k[], char m[]) {
    if (!r) return create(k, m);
    int c = strcmp(k, r->keyword);
    if (c < 0) r->left = insert(r->left, k, m);
    else if (c > 0) r->right = insert(r->right, k, m);
    else printf("Keyword already exists.\n");
    return r;
}

int search(Node* r, char k[]) {
    int cmp = 0;
    while (r) {
        cmp++;
        int c = strcmp(k, r->keyword);
        if (c == 0) return cmp;
        r = (c < 0) ? r->left : r->right;
    }
    return -1;
}

void update(Node* r, char k[]) {
    while (r) {
        int c = strcmp(k, r->keyword);
        if (c == 0) {
            printf("New meaning: ");
            scanf(" %[^\n]", r->meaning);
            printf("Updated.\n");
            return;
        }
        r = (c < 0) ? r->left : r->right;
    }
    printf("Keyword not found.\n");
}

Node* minNode(Node* r) {
    while (r->left) r = r->left;
    return r;
}

Node* del(Node* r, char k[]) {
    if (!r) return r;
    int c = strcmp(k, r->keyword);
    if (c < 0) r->left = del(r->left, k);
    else if (c > 0) r->right = del(r->right, k);
    else {
        if (!r->left) { Node* t = r->right; free(r); return t; }
        if (!r->right){ Node* t = r->left; free(r); return t; }
        Node* t = minNode(r->right);
        strcpy(r->keyword, t->keyword);
        strcpy(r->meaning, t->meaning);
        r->right = del(r->right, t->keyword);
    }
    return r;
}

void asc(Node* r) { if(r){ asc(r->left); printf("%s : %s\n", r->keyword, r->meaning); asc(r->right);} }
void desc(Node* r){ if(r){ desc(r->right); printf("%s : %s\n", r->keyword, r->meaning); desc(r->left);} }

int main() {
    Node* root = NULL;
    int ch, comp;
    char k[50], m[100];

    while (1) {
        printf("\n1.Add  2.Update  3.Delete  4.Asc  5.Desc  6.Search  7.Exit\nChoice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1: printf("Keyword: "); scanf(" %s", k);
                    printf("Meaning: "); scanf(" %[^\n]", m);
                    root = insert(root, k, m); break;

            case 2: printf("Keyword: "); scanf(" %s", k);
                    update(root, k); break;

            case 3: printf("Keyword: "); scanf(" %s", k);
                    root = del(root, k); break;

            case 4: asc(root); break;
            case 5: desc(root); break;

            case 6: printf("Keyword: "); scanf(" %s", k);
                    comp = search(root, k);
                    if (comp == -1) printf("Not found.\n");
                    else printf("Found in %d comparisons.\n", comp);
                    break;

            case 7: return 0;
            default: printf("Invalid.\n");
        }
    }
}