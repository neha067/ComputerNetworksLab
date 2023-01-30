// even/odd parity
/* ==>Parity of a number is the even/odd frequency of set bits
	odd if has odd number of set bits
	even if even number of set bits
   ==>idea : add one parity bit in the end of binary number
*/

//given a binary number change to odd or even parity

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
		

