#include <iostream>

using namespace std;

int main()
{
    string s;
    int n;
    cout<<"enter the no of bytes you want to send ";
    string ans="";
    cin>>n;
    cout<<"enter the sender bytes seprated by space"<< endl;
    for(int i=0;i<n;i++)
    {   
        cin>>s;
        if(s=="flag" || s=="esc")
        {
            ans+=" esc";
        }
        ans+=" "+s;
        
    }
    ans="flag"+ans+" flag";
    cout<<endl<<"byte stuffing recived by reciver"<<endl;
    cout<<ans;

    return 0;
}
