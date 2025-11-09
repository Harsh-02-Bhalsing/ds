#include <stdio.h>
char stack[100];
int top=-1;
void push(char c){
    top++;
    stack[top]=c;
}
char pop(){
    char c=stack[top];
    top--;
    return c;
}
int priority(char c){
    if(c=='*'||c=='/'){
        return 2;
    }if(c=='+'||c=='-'){
        return 1;
    }
    return 0;
}
int main(){
    char infix[100],postfix[100];
    int i=0,j=0;
    printf("Enter infix expression: ");
    scanf("%s",&infix);
    while(infix[i]!='\0'){
        char ch=infix[i];
        if((ch>='A'&&ch<='Z')||(ch>='a'&&ch<='z')){
            postfix[j]=ch;
            j++;
        }else if((ch=='+'||ch=='-'||ch=='*'||ch=='/')){
            while(top!=-1&&priority(stack[top])>=priority(ch)){
                postfix[j]=pop();
                j++;
            }
            push(ch);
        }
        i++;
    }
    while(top!=-1){
        postfix[j]=pop();
        j++;
    }
    postfix[j]='\0';
    printf("Postfix expression %s\n",postfix);
    return 0;
}