#include<iostream>
using namespace std;

void swap(int &a,int &b){
	int temp = a;
	a = b;
	b = temp;
}

int Partition(int A[],int start,int end){
	int pivot = A[end];
	int pIndex = start;
	for(int i=start;i<end;i++){
		if(A[i] <= pivot){
			swap(A[i],A[pIndex]);
			pIndex++;
		}
	}
	swap(A[pIndex],A[end]);
	return pIndex;
}

void QuickSort(int A[],int start,int end){
	if(start < end){
		int pIndex = Partition(A,start,end);
		QuickSort(A,start,pIndex-1);
		QuickSort(A,pIndex+1,end);
	}
}



int main(){
	cout<<"````````This program is to implement QUICK SORT`````````"<<endl;
	cout<<"Enter no.of elemets\n";
	int n; cin>>n;
	cout<<"Enter elements\n";
	int A[n];
	for(int i=0;i<n;i++) cin>>A[i];
	QuickSort(A,0,n-1);
	for(int i=0;i<n;i++) cout<<A[i]<<" ";
	cout<<endl;
	return 0;
}
