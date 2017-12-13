#include<iostream>
using namespace std;
const int SIZE=999;
class Queue{
        private:
                int front,back;
                int queue[SIZE];
        public:
                Queue(){
                        front=0;
                        back=-1;
                }
                void push();
                void pop();
                void display();
}a,b;
void Queue::push(){
        if(back==SIZE-1) cout<<"Stack is Full"<<endl;
        else{
                cout<<"Enter the element you want to push:"<<endl;
                cin>>queue[++back];
        }
        b=a;
}
void Queue::pop(){
        if(back==-1) cout<<"Stack is empty"<<endl;
        else{
                for(int i=0;i<=back;i++){}
                cout<<"Element poped is "<<queue[back--]<<endl;
        }
}
void Queue::display(){
        if(back==-1) cout<<"Queue is empty"<<endl;
        else{
                for(int i=front;i<=back;i++) cout<<queue[i]<<" ";
        cout<<endl;
        }
}
int main(){
        int choice=1,choice1;
        while(choice==1){
                cout<<"1:push"<<endl;
                cout<<"2:pop"<<endl;
                                                                                                                                                      1,1           Top
                cout<<"3:display"<<endl;
                cout<<"Enter your choice"<<endl;
                cin>>choice1;
                switch(choice1){
                        case 1: a.push();break;
                        case 2: b.pop();break;
                        case 3: a.display();
                                cout<<endl;
                                b.display();
                                break;
                }
                cout<<"press 1to menu; 0 to Exit"<<endl;
                cin>>choice;
        }
        return 0;
}
