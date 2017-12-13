#include<iostream>
using namespace std;
const int SIZE=9999;
class Stack{
        private:
                int top,k=0;;
                int stack[SIZE];
        //      int stack2[SIZE];
        public:
                Stack(){
                        top=-1;
                }
                void enqueue();
                void dequeue();
                void display();
}a,b;
void Stack::enqueue(){
        if(top==SIZE-1) cout<<"Queue is Full"<<endl;
        else{
                cout<<"Enter the element you want to Enqueue:"<<endl;
                cin>>stack[++top];
        }
}
void Stack::dequeue(){
        if(top==-1) cout<<"Queue is empty"<<endl;
        else{
                int i=0;
                for(i=top;i>=k;i--){}
                cout<<"Element dequeued is :"<<stack[k++]<<endl;
        }
}
void Stack::display(){
        if(top==-1) cout<<"Stack is Empty"<<endl;
        else{
                cout<<"Displaying````"<<endl;
                for(int i=k;i<=top;i++) cout<<stack[i]<<" ";
                cout<<endl;
        }
}
int main(){
        Stack a,b;
        int choice=1,choice1;
        while(1){
                                                                                                                                                      1,18          Top
                cout<<"!:Enqueue"<<endl;
                cout<<"2:dequeue"<<endl;
                cout<<"3:Display"<<endl;
                cout<<"$: Exit"<<endl;
                cout<<"Enter a choice:"<<endl;
                cin>>choice1;
                switch(choice1){
                        case 1: a.enqueue();
                //              Stack b;
                                b=a;
                                break;
                        case 2: b.dequeue();break;
                        case 3:// a.display();
                        //      cout<<endl;
                                b.display();
                                break;
                        case 4: return 0;
                }
        //      cout<<"Press 1 to menu;0 to Exit"<<endl;
        //      cin>>choice;
        }
        return 0;
}
   