#include <iostream>
#include <chrono>
using namespace std;
void BubbleSort(int a[] , int n){
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-i-1;j++){
			if(a[j]>a[j+1]){
				int temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
	}
}

int main(){
	cout<<"````````This program is to implement Bubble SORT`````````"<<endl;
	cout<<"Enter no.of elemets\n";
	int n; cin>>n;
	cout<<"Enter elements\n";
	int a[n];
	for(int i=0;i<n;i++) cin>>a[i];
	auto start = chrono::high_resolution_clock::now();
	BubbleSort(a,n);
	auto finish = chrono::high_resolution_clock::now();
	chrono::duration<double> elapsed = finish - start;
	cout << "Elapsed time: " << elapsed.count() << " s\n";
	for(int i=0;i<n;i++) cout<<a[i]<<" ";
	cout<<endl;
	return 0;
}
