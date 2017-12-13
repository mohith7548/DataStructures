#include <iostream>
#include <string.h>
#include <ctype.h>
using namespace std;
const int SIZE = 999 ;
class Stack{
        private:
                int top;
                char stack[SIZE];
        public:
                Stack(){
                        top=-1;
                }
                void push(char);
                char pop();
};
void Stack::push(char a){
        stack[++top]=a;
}
char Stack::pop(){
        return stack[top--];
}
int main(){
        cout<<"```````````This program is to Evaluate a postfix expression`````````````"<<endl;
        cout<<"Enter a posptfix Expression"<<endl;
        char a[50];Stack s;
        cin.getline(a,50);int i=0;
        char op,opr1,opr2;
        while(a[i]!='\0'){
                if(isdigit(a[i])){
                        s.push(a[i]);
                }
                if(a[i]=='+'||a[i]=='-'||a[i]=='%'||a[i]=='/'||a[i]=='*'){
                        op=a[i];
                        opr2=s.pop();
                        opr1=s.pop();
                        int a=(int)(opr1-'0');
                        int b=(int)(opr2-'0');
                        if(op=='+') s.push((char)(a+b+'0'));
                        if(op=='-') s.push((char)(a-b+'0'));
                        if(op=='*') s.push((char)(a*b+'0'));
                        if(op=='/') s.push((char)(a/b+'0'));
                        if(op=='%') s.push((char)(a%b+'0'));
                }
                i++;
        }
        cout<<"Ans is:"<<s.pop();
        return 0;
}
  