#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define SIZE 10
int stack[SIZE];
int top=-1;
void push(){
    if(top==SIZE-1){
        printf("stack overflow    ");
    }
    else{
        printf("enter element:");
        scanf("%d",&stack[top++]);
        top++;
        printf("succesfull");
    }
}
void pop(){
    if(top==-1){
        printf("stack underflow   ");

    }
    else{
        printf("%d popped out",stack[top]);
        top--;
    }
}
void display(){
    if(top==-1){
        printf("stack is empty");

    }
    else{
        int i;
        for(i=top;i>=0;i--){
            printf("  %d",stack[i]);
        }
    }
}
void main(){
    int c;
    while(1){
    printf("enter choice:");
    printf("  1.push");
    printf("  2.pop");
    printf("  3.display");
    printf("  4.exit");
    scanf("%d",&c);
    switch(c){
    case 1:
        push();
        break;
    case 2:
        pop();
        break;
    case 3:
        display();
        break;
    case 4:
        exit(0);
    default:
        printf("invalid number");
    }
    }
}


