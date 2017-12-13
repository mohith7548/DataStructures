#include<iostream>
using namespace std;
void push();
void pop();
void display();
struct node{
        int data;
        struct node *next;
}*head=NULL,*tail=NULL;
static int count=0;
int main(){
        int choice=1,choice1;
        while(choice==1){
                cout<<"````````Operations on Linked List`````````"<<endl;
                cout<<"1:Push"<<endl;
                cout<<"2:pop"<<endl;
                cout<<"3:Display"<<endl;
                cout<<"Enter your choice"<<endl;
                cin>>choice1;
                switch(choice1){
                        case 1: push();break;
                        case 2: pop();break;
                        case 3: display();break;
                }
                cout<<"Press 1 to menu; 0 to exit"<<endl;
                cin>>choice;
        }
                return 0;
}
void push(){
        node *temp=new node;
        cout<<"enter the data to be pushed"<<endl;
        cin>>temp->data;
        if(head==NULL){
                head=temp;
                tail=temp;
        }
        else{
                tail->next=temp;
                temp->next=NULL;
                tail=temp;
        }
        count++;
}
void pop(){
        node *temp;
        temp=head;
        if(temp==NULL) cout<<"Stack is Empty"<<endl;
        else{
                cout<<"Element poped is "<<tail->data<<endl;
        //      node *temp;
        //      temp=head;
                while((temp->next)->next!=NULL){
                        temp=temp->next;
                }
                temp->next=NULL;
                tail=temp;
                count--;
        }
}
void display(){
        node *temp;
        temp=head;
        if(temp==NULL) cout<<"Stack is Empty"<<endl;
        else{
                while(temp!=NULL){
                        cout<<temp->data<<"-->";
                        temp=temp->next;
                }
                cout<<"NULL"<<endl;
        }
}
