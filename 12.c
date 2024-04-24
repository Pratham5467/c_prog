/*
WAP to Evaluate the given Postfix expression strictly using Stacks.
*/

#include <stdio.h>
#include <ctype.h>
#include <math.h>

int stack[20];
int s = sizeof(stack)/sizeof(stack[0]);
int top = -1;


// pushing into the stack
void PUSH(int elem){
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


int main(){
    char post_exp[30],*c;
    int A,B,res,num;

    printf("Enter the postfix exp : ");
    scanf("%s",post_exp);

    c=post_exp;

    while(*c != '\0'){
        if(isdigit(*c)){
            num = *c - 48;
            PUSH(num);
        }
        else{
            A=POP();
            B=POP();
            switch(*c){
                case '+':
                    res = B + A;
                    break;
                case '-':
                    res = B - A;
                    break;
                case '*':
                    res = B * A;
                    break;
                case '/':
                    res = B / A;
                    break;
                case '^':
                    res = pow(B,A);
                    break;
            }
            PUSH(res);
        }
        c++;
    }

    // printf("The result of expression %s  =  %d",post_exp,POP());
    printf("result is : %d",POP());

    return 0; 
}