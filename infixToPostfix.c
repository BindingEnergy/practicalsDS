#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
#define NEG_INF -32768

//ADTs for symbol types
#define LEFT_PAREN -33
#define RIGHT_PAREN -44
#define OPERATOR -55
#define OPERAND -66

//ADTs for operator precision
#define ADD_PREC 1
#define SUB_PREC 1
#define MUL_PREC 2
#define DIV_PREC 2
#define MOD_PREC 2
#define POW_PREC 3

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

void push(Stack *s, int element){
    if(isFull(*s)){
        printf("\nMemory overflow ! Cannot push !");
        return;
    }
    s->items[++s->top] = element;
}

int pop(Stack *s){
    if(isEmpty(*s)){
        printf("\nMemory underflow !");
        return NEG_INF;
    }
    return s->items[s->top--];
}

int peak(Stack s){
    if(isEmpty(s)){
        printf("\nStack is Empty !");
        return NEG_INF;
    }
    return s.items[s.top];
}

int getType(char symbol){
    switch(symbol){
        case '(':
            return LEFT_PAREN; 
            break;
        case ')':
            return RIGHT_PAREN;
            break;
        case '+':
        case '-':
        case '*':
        case '/':
        case '%':
        case '^':
            return OPERATOR;
            break;
        default:
            return OPERAND;
    }
}

int getPrec(char op)
{
    switch(op)
    {
        case '+':
            return ADD_PREC;
        case '-' :
            return SUB_PREC;
        case '*' :
            return MUL_PREC;
        case '/':
            return DIV_PREC;
        case '%':
            return MOD_PREC;
        case '^':
            return POW_PREC;
        default:
            return NEG_INF;
    }
}


void infixToPostfix(char infix[] , char postfix[]){
    Stack s;
    s.top = -1;
    int i = 0,p = 0,type,prec;
    int len = strlen(infix);
    while(i < len){
        char symbol = infix[i];
        type = getType(symbol);     
        char poppedElement;   
        switch(type){
            case LEFT_PAREN:
                push(&s,symbol);
            case RIGHT_PAREN:
                while((poppedElement = pop(&s))!='('){
                    postfix[p++] = poppedElement;
                }
                break;
            case OPERAND:
                postfix[p++] = symbol;
                break;
            case OPERATOR:
                prec = getPrec(symbol);
                while(!isEmpty(s) && getPrec(peak(s)) >= prec){
                    postfix[p++] = pop(&s);
                }
                push(&s,symbol);
                break;
        }
        i++;
    }
    while(!isEmpty(s)){
        postfix[p++] = pop(&s);
    }
    postfix[p] = '\0';
}


void main(){
    char infix[MAX];
    char postfix[MAX];
    printf("\nEnter infix expression: ");
    gets(infix);
    infixToPostfix(infix,postfix);
    printf("\nPostfix expression is: %s",postfix);
}