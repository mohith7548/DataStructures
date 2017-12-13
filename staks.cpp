#include<iostream>
using namespace std;
const int size=999;
class Stack {
	int top;
	public:
	int a[size];
	Stack(){
		top=-1;
	};
	void push_obj();
	void pop_obj();
	void display_stack();
};
void Stack::push_obj() {
	if(top<size){
		cout<<"Enter the element you want to push:"<<endl;
		cin>>a[++top];
		cout<<"Element pushed into the stack is "<<a[top]<<endl;
	}
	else{
		cout<<"Stack Overflow"<<endl;
	}
}
void Stack::pop_obj() {
	if(top<0) cout<<"Stack Underflow"<<endl;
	else cout<<"Element poped out of Stack is "<<a[top--]<<endl;
}
void Stack::display_stack() {
	for(int i=0;i<=top;i++) cout<<a[i]<<" ";
	cout<<endl;
}
int main(){
	/*int top=-1,i,size,choice=1,choice1;
	cout<<"Enter size of the stack:"<<endl;
	cin>>size;
	int *a=new int[size];*/
	Stack s;
	int choice=1,choice1;
	while(choice==1){
		cout<<"`````````````````OPERATIONS ON STACKS```````````````"<<endl;
		cout<<"1-Push into stack"<<endl;
		cout<<"2-pop from the stack"<<endl;
		cout<<"3-Display stack"<<endl;
		cout<<"Enter your choice:"<<endl;
		cin>>choice1;
		switch(choice1){
			case 1:cout<<"``````````````Pushing the element into the stack```````````````"<<endl;
			       s.push_obj();
			       break;
			case 2:cout<<"``````````````poping the element from the stack````````````````"<<endl;
			       s.pop_obj();
			       break;
			case 3:cout<<"```````````````Displaying stack````````````````"<<endl;
			       s.display_stack();
			       break;
		        default:cout<<"Wrong entry try again"<<endl;
		}
		cout<<"Press 1-continue;0-exit"<<endl;
		cin>>choice;
	}
	return 0;
}
		

