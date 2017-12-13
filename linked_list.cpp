#include<iostream>
using namespace std;
void display_list();
void insert_beg();
void insert_last();
void insert_pos();
void delete_node();
void search();
void sort();
void reverse();
struct node
{
	int data;
	struct node *next;
}*head=NULL,*tail=NULL;
int count=0;  


int main()
{
	cout<<"```````````````Creating a Linked_list`````````````````"<<endl;
	char choice='y';
	int choice1=1,option;
	while(choice=='y')
	{
		node *temp=new node;
		cout<<"Enter the data in new node: "<<endl;
		cin>>temp->data;
		count++;
		if(head==NULL)
		{
			head=temp;
			tail=temp;
		}
		else
		{
			temp->next=NULL;
			tail->next=temp;
			tail=temp;
		}
		cout<<"Press 'y' to continue list; 'n' to exit"<<endl;
		cin>>choice;
	}
	display_list();
	cout<<"Size of list :"<<count<<endl;
	while(choice1==1)
	{
		cout<<"`````````````````OPERATIONS ON LINKED LIST``````````````````"<<endl;
		cout<<"1- Insert node at begining"<<endl;
		cout<<"2- Insert node at last"<<endl;
		cout<<"3- Insert node at a position"<<endl;
		cout<<"4- Search data in node"<<endl;
		cout<<"5- Delete a node"<<endl;
		cout<<"6- Sort the list"<<endl;
		cout<<"7- Reverse linked list"<<endl;
		cout<<"8- Display list"<<endl;
		cout<<"Enter your choice"<<endl;
		cin>>option;
		switch(option)
		{
			case 1: cout<<"`````````Insert node at begining``````````"<<endl;
					insert_beg();
					break;
			case 2: cout<<"`````````Insert node at last`````````"<<endl;
					insert_last();
					break;
			case 3: cout<<"`````````Insert node at a position``````````"<<endl;
					insert_pos();
					break;
			case 4: cout<<"`````````Search data in the list```````````"<<endl;
					search();
					break;
			case 5: cout<<"`````````Delete a node``````````"<<endl;
					delete_node();
					break;
			case 6: cout<<"``````````Sort the linked list````````````"<<endl;
					sort();
					break;
			case 7: cout<<"``````````Reverse the linked_list````````````"<<endl;
					reverse();
					break;
			case 8: display_list();
					break;
			default:cout<<"Wrong option"<<endl;
		}
		cout<<"Press 1- to Menu ; 0 to exit"<<endl;
		cin>>choice1;
	}
	return 0;
}
void display_list()
{
	node *temp=new node;
	temp=head;
	cout<<"``````````````````Displaying _list````````````````"<<endl;
	while(temp!=NULL)
	{
		cout<<temp->data<<"-->";
		temp=temp->next;
	}
	cout<<"NULL"<<endl;
}
void insert_beg()
{
	node *temp=new node;
	cout<<"Enter data in the new node"<<endl;
	cin>>temp->data;
	temp->next=head;
	head=temp;
	count++;
}
void insert_last()
{
	node *temp;
	temp=head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	node *new_node=new node;
	cout<<"Enter data in the new node: "<<endl;
	cin>>new_node->data;
	new_node->next=NULL;
	temp->next=new_node;
	count++;
}
void insert_pos()
{
	node *temp;
	temp=head;
	int pos,i;
	cout<<"Enter the position at which you want to enter new node: "<<endl;
	cin>>pos;
	if(pos>count) {cout<<"Insertion Not Possible\n"; return;}
	for(i=1;i<pos-1;i++) temp=temp->next;
	node *new_node=new node;
	cout<<"Enter data in the new node:"<<endl;
	cin>>new_node->data;
	new_node->next=temp->next;
	temp->next=new_node;
	count++;
}
void search()
{
	node *temp;
	temp=head;
	cout<<"Enter the data to be searched for:"<<endl;
	int key,i=0,m=0;
	cin>>key;
	while(temp!=NULL)
	{ i++;
		if(key==temp->data)
		{
		//	i++;
			cout<<"Match found at position "<<i<<endl;
			m++;
		}
		temp=temp->next;
	}
	if(m==0) cout<<"Match not found"<<endl;
	if(m!=0) cout<<"Repeated "<<m<<" no.of times"<<endl;
}
void delete_node()
{
	node *temp;
	temp=head;
	int pos,i;
	cout<<"Enter a position at which you want to delete the node"<<endl;
	cin>>pos;
	for(i=1;i<pos-1;i++)
	{
		temp=temp->next;
	}
	node *next_node;
	next_node=temp->next;
	temp->next=next_node->next;
	delete(next_node);
	count--;
}
void sort()
{
	node *temp;
	temp=head;
	int value,i,j;
	for(i=0;i<count;i++)
	{
		node *next_node;
		next_node=temp->next;
		for(j=0;j<count-i-1;j++)
		{
		if(temp->data>next_node->data)
		{
			value=temp->data;
			temp->data=next_node->data;
			next_node->data=value;
		}
		next_node=next_node->next;
		}
		temp=temp->next;
	}
}
void reverse()
{
	node *temp;
	temp=head;
	int i=0,a,b,t,j;
	while(i<=count/2)
	{
		i++;
		a=temp->data;
		for(j=i;j<=count-i-1;j++)
		{
			temp=temp->next;
			break;
		}
		b=temp->data;
		t=a;
		a=b;
		b=t;
		temp=temp->next;
	}
}
