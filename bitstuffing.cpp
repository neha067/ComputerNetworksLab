#include <iostream>
using namespace std;
int main()
{
    string s;
    cout<<"enter the binary number in form of 0 and 1";
    cin>>s;
    int c=0;
    string ans="";
    for(int i=0;i<s.size();i++)
    {   
        ans+=s[i];
        if(s[i]=='1')
        {
            c++;
        }
        else
        {
            c=0;
        }
        if(c==5)
        {
           ans+='0';
           c=0;
        }
    }
    cout<<"01111110 "<<ans<<" 01111110";
}
