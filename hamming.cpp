#include <bits/stdc++.h>
using namespace std;

bool rbit(int index,int arr[], int size){
    bool ans=0;
    for(int i=index;i<=size;i=i+2*index){
        for(int j=0;j<index && i+j<=size;j++){
            ans ^= arr[i+j];
        }
    }
    return ans;
}

int main() {
	cout<<"Hamming Code\n\n";
	cout<<"-----Sender-----\n\n";
	cout<<"Enter size of Msg : ";
	int m;
	cin>>m;
	
	int r=1;
	while(m+1+r>pow(2,r)){
	    r++;
	}
	cout<<r<<endl;
	cout<<"Enter msg (space seperated) : ";
	
	int size = m+r;
	int data[size+1];
	//stored in reverse order
	//0th index is blank
	int k=r-1;
	for(int i=size;i>0;i--){
	    if(i == pow(2,k)){
	        data[i] = 0;
	        k--;
	        continue;
	    }
	    cin>>data[i];
	}
	for(int i=0;i<r;i++){
	    data[(int)pow(2,i)] = rbit(pow(2,i),data,size);
	}
	
	//print the msg
	for(int i = size;i>0;i--)
	    cout<<data[i]<<" ";
	
	cout<<"\n\n-----Receiver-----\n\n";
	cout<<"Enter size of Msg : ";
	int n;
	cin>>n;
	int msg[n+1];
	cout<<"Enter msg (space seperated) :";
	for(int i = n;i>0;i--){
		cin >> msg[i];
	}
	int rb=1;
	while(pow(2,rb)<n){
		rb++;
	}
	int err[rb+1];	//0th blank
	for(int i=0;i<rb;i++){
	    err[i+1] = rbit(pow(2,i),msg,n);
	}
	int error=0;
	for(int i=1;i<=rb;i++){
		error += pow(2,i-1)*err[i];
	}
	if(error == 0)	cout<<"Noiseless Data"<<endl;
	else{
		cout<<"Error at "<<error<<" position"<<endl;;
		msg[error] = 1 - msg[error];
		cout<<"corrected data : ";
		for(int i = n;i>0;i--)
	    	cout<<msg[i]<<" ";
	}
	cout<<endl;
	return 0;
}
