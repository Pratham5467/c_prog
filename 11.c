/*
WAP to convert given Infix expression to Postfix expression strictly using Stacks 
*/

#include <stdio.h>
#include <ctype.h>

char stack[100];
int s = sizeof(stack)/sizeof(stack[0]);
int top = -1;

// pushing into the stack
void PUSH(char elem){
    if(top >= s-1)
        printf("Stack is overflow/full\n");
    else{
        top++;
        stack[top] = elem;
    }
}

// popping from the stack
char POP(){
    if(top <= -1)
        printf("Stack is underflow/empty\n");
    else
        return stack[top--];
}

// checking precedence priority of operator 
int priority(char x){
    if (x == '-' || x == '+')
        return 1;
    else if (x == '*' || x == '/')
        return 2;
    else if (x == '^')
        return 3;

    return 0;
}

int main(){
    char inf_exp[100];
    char *e,x;

    printf("Enter the infix Expression : ");
    scanf("%s",inf_exp);

    e=inf_exp;

    while(*e != '\0'){
        if(isalnum(*e)){
            printf("%c",*e);
        }
        else if(*e == '('){
            PUSH(*e);
        }
        else if(*e == ')'){
            // wrapp the pop function inside parenthesis
            while((x = POP()) != '('){
                printf("%c",x);
            }
        }
        else{
            /* 
            if scanned element, has less precedence or equal precedence than that top of elem. present in stack then REPEATEDLY POP() it and add to Postfix-Expression.
            */
            while( priority(*e) <= priority(stack[top]) ){
                printf("%c",POP());
            }
            /*
            if scanned element, has high precedence than that top of elem. present in stack then PUSH() it.
            */
            PUSH(*e);
        }

        e++;
    }

    // if anything left in the stack
    while(top != -1){
        printf("%c",POP());
    }

    return 0;
}

