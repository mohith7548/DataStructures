#include <iostream>
#include <vector>
using namespace std;

struct index{
	vector<int> data; 
}hashtable[13];

void insert(int);
void delete1(int);
void search(int);

int main(){
	cout<<"```````````This program is to Implement Separate chaining in Hash table`````````````"<<endl;
	int size,choice,data;
	cout<<"Our hashtable size is: 13"<<endl;
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
			case 3: {cout<<"Enter data to be searched"<<endl;
					cin>>data;
					search(data);
					break;}
			default: return 0;
		}
	}
	return 0;
}

void insert(int value){
	int hashval=value%13;
	(hashtable[hashval].data).push_back(value);

}
void delete1(int value){
	int hashval=value%13;int c=0;
	vector<int> :: iterator it; 
	for(int i = 0;  i<hashtable[hashval].data.size();  ++i){
		it =  hashtable[hashval].data.begin()+i;
		int a = *it;
		if(value == a) {
			hashtable[hashval].data.erase(it);
			cout<<"Data deleted successdully!"<<endl;
			c=1;
			break;
		}
	}
	if(c==0) cout<<"Element Not Found!!"<<endl;
}
void search(int value){
	int hashval=value%13;int c=0;
	vector<int> :: iterator it; 
	for(int i = 0;  i<hashtable[hashval].data.size();  ++i){

		it =  hashtable[hashval].data.begin()+i;
		int a = *it;
		if(value == a) {
			//hashtable[hashval].data.erase(it);
			cout<<"Data Found!!"<<endl;
			c=1;
			break;
		}
	}
	if(c==0) cout<<"Element Not Found!!"<<endl;
}