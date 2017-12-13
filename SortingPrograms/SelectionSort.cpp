#include <iostream>
using namespace std;
void SelectionSort(int a[],int n){
	for(int i=0;i<n-1;i++){
		int imin = i;
		for(int j=i+1;j<n;j++){
			if (a[j] < a[imin])  imin = j;
		}
		int temp = a[i];
		a[i] = a[imin];
		a[imin] = temp;
	}
}

int main(){
	cout<<"````````This program is to implement SELECTION SORT`````````"<<endl;
	cout<<"Enter no.of elemets\n";
	int n; cin>>n;
	cout<<"Enter elements\n";
	int a[n];
	for(int i=0;i<n;i++) cin>>a[i];
	SelectionSort(a,n);
	for(int i=0;i<n;i++) cout<<a[i]<<" ";
	cout<<endl;
	return 0;
}
