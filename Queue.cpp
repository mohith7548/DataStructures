#include <iostream>
using namespace std;
const int size=999;
class Queue{
private:
	int queue[size];
	int front;
	int back;
public:
	Queue(){
		front=back=-1;
	    for(int i=0;i<size;i++) queue[i]=0;
	};
	void enqueue();
	void dequeue();
	void display();
};
void Queue::enqueue(){
	if(back==size-1) cout<<"Queue is Full"<<endl;
	else{
		/*cout<<"Enter an element you want to Enqueue"<<endl;
		cin>>queue[back++];//front=back;
		if(back==-1) {
			front++;*/
		if(front==-1){
			cout<<"Enter an element you want to Enqueue"<<endl;
			front++;back++;
			cin>>queue[front];
		}
		else{
			cout<<"Enter an element you want to Enqueue"<<endl;
			back++;
			cin>>queue[back];
		}
		
	}
}
void Queue::dequeue(){
	if(front==-1 && back==-1) cout<<"Queueis Empty"<<endl;
	else{
		cout<<"Element dequeued is "<<queue[front++]<<endl;
	}
}
void Queue::display(){
	if(queue[front]==0) cout<<"Queue is Empty"<<endl;
	else{
		if(queue[front]!=0){
			cout<<"```````````````Displaying Queue`````````````"<<endl;
			for(int i=front;i<=back;i++) cout<<queue[i]<<" ";
			cout<<endl;
		}
	}
}
int main(){
	Queue q;int choice=1,choice1;
	while(choice==1){
		cout<<"```````````Operations on Queue```````````````"<<endl;
		cout<<"1:Enqueue"<<endl;
		cout<<"2:Dequeue"<<endl;
		cout<<"3:Display"<<endl;
		cout<<"Enter your choice:"<<endl;cin>>choice1;
		switch(choice1){
			case 1: cout<<"```````Enqueue````````"<<endl;
					q.enqueue();break;
			case 2: cout<<"```````Dequeue```````"<<endl;
					q.dequeue();break;
			case 3: cout<<"``````Display````````"<<endl;
					q.display();break;
			default: cout<<"wrong selection"<<endl;break;
		}
		cout<<"press 1 to continue;0 to exit"<<endl;
		cin>>choice1;
		if(choice1==0) break;
	}
	return 0;
}
