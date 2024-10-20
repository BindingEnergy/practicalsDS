#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

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


void postfixEvaluation(char postfix[]){
    int i, result = 0;
    int num = 0, num1 , num2;
    Stack s;
    s.top  = -1;
    int len =strlen(postfix);

    for(i = 0 ; i < len ; i++){
        if(isdigit(postfix[i])){
            while(i < len && isdigit(postfix[i])){
                num = num*10 + (((int)(postfix[i]))-48);
                i++;
            }
            push(&s,num);
            num = 0;
            i--;
        }else if(postfix[i] != ' '){
            switch(postfix[i]){
                case '+':
                    num2 = pop(&s);
                    num1 = pop(&s);
                    push(&s,(num1+num2));
                    break;
                case '-':
                    num2 = pop(&s);
                    num1 = pop(&s);
                    push(&s,num1-num2);
                    break;
                case '*':
                    num2 = pop(&s);
                    num1 = pop(&s);
                    push(&s,num1*num2);
                    break;
                case '/':
                    num2 = pop(&s);
                    num1 = pop(&s);
                    if(num2 == 0){
                        printf("\nCannot divide by 0 !");
                        return;
                    }
                    push(&s,num1/num2);
                    break;
                case '^':
                    num2 = pop(&s);
                    num1 = pop(&s);
                    push(&s,pow(num1,num2));
                    break;
                default:
                    printf("\nINVALID OPERATION encountered !");
                    return;
            }
        }
    }
    result = pop(&s);
    printf("\nThe reuslt of the expression is: %d",result);
}


void main(){
    char postfix[MAX];
    printf("\nEnter postfix expression: ");
    gets(postfix);
    postfixEvaluation(postfix);
}