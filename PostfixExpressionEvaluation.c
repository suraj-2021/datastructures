#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

#define MAX 100 

int stack[MAX];
char infix[MAX],postfix[MAX];
int top = -1;

int space(char);
int isEmpty();
void push(char);
int pop();
int precedence(char);
void inToPost();
int post_eval();
void print();

int main(){
    printf("Provide Infix Expression: ");
    fgets(infix,sizeof(infix),stdin);
    infix[strcspn(infix, "\n")] = '\0';
    
    inToPost();
    print();
    int value = post_eval();
    
    printf("The final Resusult of the Postfix Evaluation is : %d\n",value);
    
    return 0;
}

int space(char c){
    if(c==' ' || c== '\t'){
        return 1;
    }
    return 0;
}

int isEmpty(){
    if(top==-1){
        return 1;
    }
    return 0;
}

void push(char symbol){
    if(top==MAX-1){
        printf("STACK OVERFLOW");
        return;
    }
    top = top+1;
    stack[top] = symbol;
}

int pop(){
    if(top == -1){
        printf("STACK UNDERFLOW");
        exit(-1);
    }
    char c = stack[top];
    top = top-1;
    return c;
}
int precedence(char symbol){
    switch(symbol){
        case '^':
            return 3;
        case '*':
        case '/':
             return 2;
        
        case '+':
        case '-':
             return 1;
        
        default:
             return 0;
        
    }
}


void inToPost(){
    int i,j=0;
    char next;
    char symbol;
    
    for(i=0;i<strlen(infix);i++){
        
        symbol = infix[i];
        
        if(!space(symbol)){
            switch(symbol){
            case '(':
                 push(symbol);
                 break;
            case ')':
                 while((next=pop())!='('){
                     postfix[j++] = next;
                 }
                 break;
            case '^':
            case '*':
            case '/':
            case '+':
            case '-':
                 
                 while(!isEmpty() && precedence(stack[top])>=precedence(symbol)){
                       postfix[j++] = pop();
                 }
                 push(symbol);
                 break;
            
            default:
                postfix[j++] = symbol;
                 
            }
        }
    }
    while(!isEmpty()){
            postfix[j++] = pop();
        }
        postfix[j] = '\0';
}

int post_eval(){
    char symbol;
    for(int i= 0;i<strlen(postfix); i++){
        
        symbol = postfix[i];
        
        if(symbol>= '0' && symbol<= '9'){
            push(symbol-'0');
        }
        else{
            
            int a = pop();
            int b = pop();
            
            switch(symbol){
                case '^':
                    push(pow(b,a));
                    break;
                
                case '*':
                     push(b*a);
                     break;
                case '/':
                     push(b/a);
                     break;
                
                case '+':
                     push(b+a);
                     break;
                case  '-':
                      push(b-a);
                      break;
            } 
        }
    }
    return pop();
}
void print(){
    int i=0;
    while(postfix[i]){
        printf("%c",postfix[i]);
        i++;
    }
}
