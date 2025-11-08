#include <stdio.h>
#include <ctype.h>

char s[50]; int top=-1;
void push(char c){ s[++top]=c; }
char pop(){ return s[top--]; }
int prec(char c){ return (c=='+'||c=='-')?1:(c=='*'||c=='/')?2:0; }

void infixToPostfix(char in[], char post[]){
    int i,j=0; char c;
    for(i=0; in[i]; i++){
        c=in[i];
        if(isalnum(c)) post[j++]=c;
        else if(c=='(') push(c);
        else if(c==')'){ while(s[top]!='(') post[j++]=pop(); pop(); }
        else{
            while(top!=-1 && prec(s[top])>=prec(c)) post[j++]=pop();
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
            switch(c){case '+':a+=b;break;case '-':a-=b;break;case '*':a*=b;break;case '/':a/=b;break;}
            st[++t]=a;
        }
    }
    return st[t];
}

int main(){
    char in[50], post[50];
    printf("Enter infix: ");
    scanf("%s",in);
    infixToPostfix(in,post);
    printf("Postfix: %s\nValue: %d\n",post,evalPostfix(post));
    return 0;
}

