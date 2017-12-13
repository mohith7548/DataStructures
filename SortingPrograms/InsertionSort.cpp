#include <iostream>
using namespace std;
void InsertionSort(int a[],int n){
	for(int i=1;i<n;i++){
		int value = a[i];
		int hole = i;
		while(hole>0 && a[hole-1]>value){
			a[hole] = a[hole-1];
			hole = hole-1;
		}
		a[hole] = value;
	}
}

int main(){
	cout<<"````````This program is to implement Insertion SORT`````````"<<endl;
	cout<<"Enter no.of elemets\n";
	int n; cin>>n;
	cout<<"Enter elements\n";
	int a[n];
	for(int i=0;i<n;i++) cin>>a[i];
	InsertionSort(a,n);
	for(int i=0;i<n;i++) cout<<a[i]<<" ";
	cout<<endl;
	return 0;
}