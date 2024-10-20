#include <stdio.h>
#include <stdlib.h>

#define MAX 10
#define NEG_INF -32768

typedef struct{
    int items[MAX];
    int front,rear;
    int count;
}CQueue;

int isFull(CQueue q){
    return q.count == MAX ? 1 : 0;
}

int isEmpty(CQueue q){
    return q.count == 0 ? 1 : 0;
}

void enqueue(CQueue *q){
    if(isFull(*q)){
        printf("\nMemory Oveflow ! Cannot Insert !");
        return;
    }
    if(q->rear == MAX-1)
        q->rear = 0;
    else
        q->rear++;

    printf("\nEnter element to insert: ");
    int element;
    scanf("%d",&element);
    q->items[q->rear] = element;
    (q->count)++;
    printf("\nInserted Element: %d",element);
}

void dequeue(CQueue *q){
    if(isEmpty(*q)){
        printf("\nMemory Underflow !");
        return;
    }
    int temp;
    temp = q->items[q->front];
    if(q->front == MAX-1)
        q->front = 0;
    else
        (q->front)++;
    (q->count)--;
    printf("\nDequeued: %d",temp);
}

void peek(CQueue q){
    if(isEmpty(q)){
        printf("\nQueue is EMPTY !");
        return;
    }
    printf("\nFirst element is: %d",q.items[q.front]);
}

void display(CQueue q){
    if(isEmpty(q)){
        printf("\nQueue is EMPTY !");
        return;
    }
    printf("\nQueue is: ");
    if(q.front <= q.rear){
        for(int i = q.front ; i <= q.rear ; i++){
            printf("%d ",q.items[i]);
        }
    }else{
        for(int i = q.front ; i < MAX ; i++){
            printf("%d ",q.items[i]);
        }
        for(int i = 0 ; i <= q.rear ; i++){
            printf("%d ",q.items[i]);
        }
    }
}

void main(){
    CQueue q;
    q.front =0;
    q.rear = -1;
    q.count =0;
    while(1){
        printf("\n1.Enqueue\n2.Dequeue\n3.Peek\n4.Display\n5.IsFull\n6.IsEmpty\nEnter choice: ");
        int choice;
        int result;
        scanf("%d",&choice);
        switch(choice){
            case 1:
                enqueue(&q);
                display(q);
                break;
            case 2:
                dequeue(&q);
                display(q);
                break;
            case 3:
                peek(q);
                break;
            case 4:
                display(q);
                break;
            case 5:
                result = isFull(q);
                if(!result){
                    printf("\nQueue not full !");
                }else{
                    printf("\nQueue is Full !");
                }
                break;
            case 6:
                result = isEmpty(q);
                if(!result){
                    printf("\nQueue not Empty !");
                }else{
                    printf("\nQueue is Empty !");
                }
                break;
            default:
                exit(0);
        }
    }
}