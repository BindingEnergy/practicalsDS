#include <stdio.h>
#include <stdlib.h>
#define MAX 10
#define NEG_INF -32768

int visited[MAX] = {0};
int adj[MAX][MAX] = {0};

typedef struct {
    int items[MAX];
    int top;
} Stack;

// Stack functions
int isFull(Stack *s) {
    return s->top == MAX - 1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, int element) {
    if (isFull(s)) {
        printf("Stack Overflow\n");
        return;
    }
    s->items[++s->top] = element;
}

int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack underflow\n");
        return NEG_INF;
    }
    return s->items[s->top--];
}

void dfs(int start) {
    Stack s;
    s.top = -1;

    push(&s, start);
    visited[start] = 1;

    while (!isEmpty(&s)) {
        int k = pop(&s);
        printf("%d ", k);

        for (int i = 0; i < MAX; i++) {
            if (adj[k][i] && !visited[i]) {
                push(&s, i);
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int n, i, j, ans;
    printf("Enter the number of vertices (max %d): ", MAX);
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter the values for vertex %d (1 for adjacent, 0 for not):\n", i);
        for (j = 0; j < n; j++) {
            printf("Enter for vertex %d: ", j);
            scanf("%d", &ans);
            if (ans == 1) {
                adj[i][j] = 1;
            }
        }
    }

    printf("Your adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            printf("%d ", adj[i][j]);
        printf("\n");
    }

    printf("DFS traversal:\n");
    for (i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }

    return 0;
}
