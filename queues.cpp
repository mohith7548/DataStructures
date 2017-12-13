#include <iostream>
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
                void enqueue();
                void dequeue();
                void display();
};
void Queue::enqueue(){
        if(back==SIZE-1) cout<<"Queue is Full"<<endl;
        else{
                cout<<"Enter the element you want to enqueue:"<<endl;
                cin>>queue[++back];
        }
}
void Queue::dequeue(){
        if(back==-1) cout<<"Queue is empty"<<endl;
        else{
                cout<<"Element dequeued is "<<queue[front++]<<endl;
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
        Queue q;
        int choice=1,choice1;
        while(choice==1){
                cout<<"!:Enqueue"<<endl;
                cout<<"2:dequeue"<<endl;
                cout<<"3:Display"<<endl;
                cout<<"Enter a choice:"<<endl;
                cin>>choice1;
                switch(choice1){
                        case 1: q.enqueue();break;
                        case 2: q.dequeue();break;
                        case 3: q.display();break;
                }
                cout<<"Press 1 to menu;0 to Exit"<<endl;
                cin>>choice;
        }
        return 0;
}
    