#include<iostream>
#include<string>
using namespace std; 
int main(){
	string binary;
	cin>>binary;
	int len = binary.length();
	int count=0;
	for(int i=0; i<len; i++){
		if(binary[i]=='1')count++;
	}
	if(count%2==0) //even parity
	{
		cout<<"given binary string is even parity"<<endl;
		cout<<"Its odd parity:		"<<binary+"1"<<endl;
		cout<<"Its even parity:	"<<binary+"0"<<endl;
	}else
	{
		cout<<"given binary string is odd parity"<<endl;
		cout<<"Its even parity:		"<<binary+"1"<<endl;
		cout<<"Its odd parity:			"<<binary+"0"<<endl;
	}
	return 0;
}