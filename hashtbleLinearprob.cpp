#include <iostream>
using namespace std;
const int size=13;
struct index{
	int data;
	bool isfull = false; 
};
index hashtable[size];
void insert(int);
void delete1(int);
void search(int);

int main(){
	cout<<"```````````This program is to Implement Open Adressing Linear Probing in Hash table`````````````"<<endl;
	int choice,data;
	while(1){
		cout<<"`````Operations on Hash table``````"<<endl;
		cout<<"1.Insert\n2.Delete\n3.Search\n";
		cout<<"enter a choice"<<endl;
		cin>>choice;
		switch(choice){
			case 1: {cout<<"Enter data to be inserted:"<<endl;
					cin>>data;
					insert(data);
					break;}
			case 2:{ cout<<"Enter data to be deleted:"<<endl;
					 cin>>data;
					 delete1(data);
					 break;}
			case 3: {cout<<"Enter data to be searched:"<<endl;
					cin>>data;
					search(data);
					break;}
			default: return 0;
		}
	}
	return 0;
}

void insert(int value){
	int hashval = value%size;
	if(hashtable[hashval].isfull == false) {
		hashtable[hashval].data = value;
		hashtable[hashval].isfull = true;
		return;
	}
	if(hashtable[hashval].isfull == true) {
		for(int i=0;i<size;i++){
			hashval = ((value%size)+i)%size;
			if(hashtable[hashval].isfull == false){
				hashtable[hashval].data = value;
				hashtable[hashval].isfull = true;
				return;
			}
		}
	}
}

void delete1(int value){
	int hashval = value%size;
	if(hashtable[hashval].isfull== true){
		if(value == hashtable[hashval].data){
			hashtable[hashval].isfull = false;
			cout<<"Element deleted successfully"<<endl;
			return;
		}
	}
	for(int i=0;i<size;i++){
		hashval = ((value%size)+i)%size;
		if(hashtable[hashval].isfull == true){
			if( value == hashtable[hashval].data){
				hashtable[hashval].isfull = false;
				cout<<"Element deleted successfully"<<endl;
				return;
			}
		}
	}
	cout<<"Element Not Found!!"<<endl;
}

void search(int value){
	int hashval = value%size;
	if(hashtable[hashval].isfull== true){
		if(value == hashtable[hashval].data){
			//hashtable[hashval].isfull = false;
			cout<<"Element Found!!"<<endl;
			return;
		}
	}
	for(int i=0;i<size;i++){
		hashval = ((value%size)+i)%size;
		if(hashtable[hashval].isfull == true){
			if( value == hashtable[hashval].data){
				//hashtable[hashval].isfull = false;
				cout<<"Element Found!!"<<endl;
				return;
			}
		}
	}
	cout<<"Element Not Found!!"<<endl;
}