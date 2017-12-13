#include <iostream>
#include <vector>
using namespace std;
void CountingSort(int arr[],int n){
	// The output character array that will have sorted arr
    int output[n+1];
    const int RANGE =225;
    int count[RANGE + 1]={0}, i;
    for(i = 0; i<n; ++i)
        ++count[arr[i]];
    for (i = 1; i <= RANGE; ++i)
        count[i] += count[i-1];
    for (i = 1; i<n+1; ++i)
    {
        output[count[arr[i]]-1] = arr[i];
        --count[arr[i]];
    }
    for (i = 1; i<n+1; ++i)
        arr[i] = output[i];
}

int main(){
	cout<<"````````This program is to implement CountingSort `````````"<<endl;
	cout<<"Enter no.of elemets\n";
	int n; cin>>n;
	cout<<"Enter elements from 1-9 \n";
	int arr[n];
	for(int i=0;i<n;i++) cin>>arr[i];
	CountingSort(arr,n);
	for(int i=0;i<n;i++) cout<<arr[i]<<" ";
	cout<<endl;
	return 0;
}