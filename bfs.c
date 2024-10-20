#include <stdio.h>
#define MAX 10
#define NEG_INF -32768

int visited[MAX] = {0};
int adj[MAX][MAX] = {0};
int edges;

typedef struct {
    int items[MAX];
    int front, rear;
} Queue;

int isEmpty(Queue *q) {
    return q->rear < q->front;
}

int isFull(Queue *q) {
    return q->rear == MAX - 1;
}

void insert(Queue *pq, int element) {
    if (isFull(pq)) {
        printf("Queue Overflow\n");
        return;
    }
    pq->items[++(pq->rear)] = element;
    // printf("Queue Inserted: %d\n", element);
}

int poll(Queue *pq) {
    if (isEmpty(pq)) {
        printf("Queue underflow\n");
        return NEG_INF;
    }
    int temp = pq->items[pq->front++];
    if (isEmpty(pq)) {
        pq->front = 0;
        pq->rear = -1;
    }
    return temp;
}

void bfs(int start) {
    Queue q;
    q.front = 0;
    q.rear = -1;

    insert(&q, start);
    visited[start] = 1;

    while (!isEmpty(&q)) {
        int k = poll(&q);
        printf("%d ", k);
        
        for (int i = 0; i < edges; i++) {
            if (adj[k][i] && !visited[i]) {
                insert(&q, i);
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
                if (ans == 1)
                    adj[i][j] = 1;
        }
    }

    printf("Your adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            printf("%d ", adj[i][j]);
        printf("\n");
    }

    edges = n; //or we can take n as parameter in bfs as well

    // printf("BFS starting from vertex 0:\n"); //graph is connected
    // bfs(0);
    printf("BFS traversal:\n"); //graph is disconnected
    for (i = 0; i < n; i++) {
        if (!visited[i]) {
            bfs(i); 
        }
    }
}