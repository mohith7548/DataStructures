#include <iostream>
using namespace std;
const int size=9999;
class Queue{
private:
	int queue[size];
	int front,back;
public:
	void push();
	void pop();
	//void display();
	Queue(){
		front=0,back=-1;
	}
}a,b;
void Queue::push(){
	if(back==size-1) cout<<"Stack is Full"<<endl;
	else{
		cout<<"Enter the element you want to enter into the stack"<<endl;
		cin>>queue[++back];
	}
	b=a;
}
void Queue::pop(){
	if(back==-1) cout<<"Stak is empty"<<endl;
	else{
		for(int i=front;i<=back;i++){}
		cout<<"element poped is "<<queue[back--]<<endl;
	}
}
int main(){
	//Queue a,b;
	int choice=1,choice1;
	while(choice==1){
		cout<<"```````````Operations on Queue```````````````"<<endl;
		cout<<"1:Push"<<endl;
		cout<<"2:Pop"<<endl;
		cout<<"3:Display"<<endl;
		cout<<"Enter your choice:"<<endl;cin>>choice1;
		switch(choice1){
			case 1: cout<<"```````Push````````"<<endl;
					a.push();break;
			case 2: cout<<"```````Pop```````"<<endl;
					b.pop();break;
			/*case 3: cout<<"``````Display````````"<<endl;
					a.display();b.display();break;*/
			default: cout<<"wrong selection"<<endl;break;
		}
		cout<<"press 1 to continue;0 to exit"<<endl;
		cin>>choice1;
		if(choice1==0) break;
	}
	return 0;
}