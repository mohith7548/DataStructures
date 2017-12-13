#include <iostream>
#include <vector>
using namespace std;
static int count;
void Merge(int L[],int R[],int A[],int nl,int nr,int n){
	int i=0,j=0,k=0;
	while(i<nl && j<nr){
		if(L[i] <= R[j]) 
			A[k++] = L[i++];
		else 
			A[k++] = R[j++];
	}
	while(i<nl) A[k++] = L[i++];
	while(j<nr) A[k++] = R[j++];
}

void MergeSort(int A[],int n){
	if(n<2) return;
	int mid = n/2;
	int L[mid];
	int R[n-mid];
	for(int i=0;i<mid;i++) L[i] = A[i];
	for(int i=mid;i<n;i++) R[i-mid] = A[i];
	MergeSort(L,mid);
	MergeSort(R,n-mid);
	Merge(L,R,A,mid,n-mid,n);
}

int main(){
	cout<<"`````````This Program is to implement MergeSort using Vectors```````````"<<endl;
	cout<<"enter no.of elements"<<endl;
	int n;cin>>n;
	int A[n];
	cout<<"enter elements\n";
	for(int i=0;i<n;i++)	cin>>A[i];
	MergeSort(A,n);
	cout<<"After sorting"<<endl;
	for(int i=0;i<n;i++)  cout<<A[i]<<" ";
	cout<<endl;
	return 0;
}