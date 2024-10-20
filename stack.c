#include <stdio.h>
#include <stdlib.h>


#define MAX 10

typedef struct{
    int items[MAX];
    int top;
}Stack;

int isFull(Stack s){
    return s.top == MAX - 1 ? 1 : 0;
}

int isEmpty(Stack s){
    return s.top == -1 ? 1 : 0;
}

void push(Stack *s){
    if(isFull(*s)){
        printf("\nMemory overflow ! Cannot push !");
        return;
    }
    int element;
    printf("\nEnter element to insert: ");
    scanf("%d",&element);
    s->items[++s->top] = element;
    printf("\nPushed element: %d",element);
}

void pop(Stack *s){
    if(isEmpty(*s)){
        printf("\nMemory underflow !");
        return;
    }
    printf("\nPopped element: %d",s->items[s->top--]);
}

void peak(Stack s){
    if(isEmpty(s)){
        printf("\nStack is Empty !");
        return;
    }
    printf("\nTop most element is: %d",s.items[s.top]);
}

void display(Stack s){
    if(isEmpty(s)){
        printf("\nStack is empty !");
        return;
    }
    printf("\nStack is:\n");
    for(int i = s.top ;i >= 0 ; i--){
        printf("%d\n",s.items[i]);
    }
}

void main(){
    Stack s;
    s.top = -1;
    while(1){
        printf("\n1.Push\n2.Pop\n3.Peak\n4.IsFull\n5.IsEmpty\n6.Display\nEnter choice: ");
        int choice;
        scanf("%d",&choice);
        int result;
        switch(choice){
            case 1:
                push(&s);
                display(s);
                break;
            case 2:
                pop(&s);
                display(s);
                break;
            case 3:
                peak(s);
                break;
            case 4:
                result = isFull(s);
                if(result != 0){
                    printf("\nStack Full !");
                }else{
                    printf("\nStack not Full !");
                }
                break;
            case 5:
                result = isEmpty(s);
                if(result != 0){
                    printf("\nStack Empty !");
                }else{
                    printf("\nStack not Empty !");
                }
                break;
            case 6:
                display(s);
                break;
            default:
                exit(0);
        }
    }
}