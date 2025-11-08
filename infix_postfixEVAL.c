#include <stdio.h>
#include <ctype.h>
#include <string.h>

char opStack[50]; int top=-1;
void push(char c){ opStack[++top]=c; }
char pop(){ return opStack[top--]; }
int prec(char c){ return (c=='+'||c=='-')?1:(c=='*'||c=='/')?2:0; }

void infixToPostfix(char in[], char post[]){
    int j=0; char c;
    int i;
    for(i=0; in[i]; i++){
        c=in[i];
        if(isalnum(c)) post[j++]=c;
        else if(c=='(') push(c);
        else if(c==')'){ while(opStack[top]!='(') post[j++]=pop(); pop(); }
        else{
            while(top!=-1 && prec(opStack[top])>=prec(c))
                post[j++]=pop();
            push(c);
        }
    }
    while(top!=-1) post[j++]=pop();
    post[j]='\0';
}

int evalPostfix(char p[]){
    int st[50], t=-1;
    int i;
    for(i=0; p[i]; i++){
        char c=p[i];
        if(isdigit(c)) st[++t]=c-'0';
        else{
            int b=st[t--], a=st[t--];
            switch(c){
                case '+': st[++t]=a+b; break;
                case '-': st[++t]=a-b; break;
                case '*': st[++t]=a*b; break;
                case '/': st[++t]=a/b; break;
            }
        }
    }
    return st[0];
}

int main(){
    char in[50], post[50];
    printf("Enter infix expression: ");
    scanf("%s", in);
    infixToPostfix(in, post);
    printf("Postfix expression: %s\n", post);
    printf("Evaluated value: %d\n", evalPostfix(post));
    return 0;
}

