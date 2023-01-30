//cycle redundancy check(CRC)
/* ==>CRC: error detection algo, check vality of data sent by sender
   ==>more theory: https://www.scaler.com/topics/crc-program-in-c/
   ==>idea: given data and key generate a signal and check its validity on the reciever side 
   with a recieved data...
*/
#include<bits/stdc++.h>
using namespace std;
string xor1(string a, string b) //function for doing xor of the strings...
{
     
    // Initialize result
    string result = "";
     
    int n = b.length();
     
    // Traverse all bits, if bits are
    // same, then XOR is 0, else 1
    for(int i = 1; i < n; i++)
    {
        if (a[i] == b[i])
            result += "0";
        else
            result += "1";
    }
    return result;
}
string division(string dividend,string divisor){
    // Number of bits to be XORed at a time.
    int pick = divisor.length();
     
    // Slicing the dividend to appropriate
    // length for particular step
    string tmp = dividend.substr(0, pick);
     
    int n = dividend.length();
     
    while (pick < n)
    {
        if (tmp[0] == '1')
         
            // Replace the dividend by the result
            // of XOR and pull 1 bit down
            tmp = xor1(divisor, tmp) + dividend[pick];
        else
         
            // If leftmost bit is '0'.
            // If the leftmost bit of the dividend (or the
            // part used in each step) is 0, the step cannot
            // use the regular divisor; we need to use an
            // all-0s divisor.
            tmp = xor1(std::string(pick, '0'), tmp) +
                  dividend[pick];
                   
        // Increment pick to move further
        pick += 1;
    }
     
    // For the last n bits, we have to carry it out
    // normally as increased value of pick will cause
    // Index Out of Bounds.
    if (tmp[0] == '1')
        tmp = xor1(divisor, tmp);
    else
        tmp = xor1(std::string(pick, '0'), tmp);
         
    return tmp;
    }
int main(){
	string data,key;
	cout<<"enter data:	";
	cin>>data;
	string d = data;
	cout<<"enter the key(generating polynomial):	";
	cin>>key;
	
	//==> check the length 'n' of the key and add n-1 zero in the data
	int keylen = key.length();
	for(int i=0; i<keylen-1; i++)data += "0";
	
	int datalen = data.length();
	
	//perform division... to generate the signal
	string remainder = division(data,key);
	string encodedw = d+remainder; //data+remainder
	cout<<"remainder: "<<remainder;
	cout<<"encoded data : "<<encodedw;
	string check;
	cout<<"enter data recieved";
	cin>>check;
	string rem = division(check,key); 
	int l  = rem.length();
	for(int i=0; i<l; i++){if(rem[i]=='1'){
	cout<<"Error detected!!";return 0;
	}}
	cout<<"no error detected";
	return 0;
	}
