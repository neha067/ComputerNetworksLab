#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	cout<<"CRC\n\n";
	cout<<"----------Sender----------\n\n";
	vector<int> key;
	vector<int> data;
    int num;
    cout<<"enter length of key :";
    cin>>num;
    cout<<"enter key(space seperated) : ";
	while(num--){
	    int val;
	    cin>>val;
	    key.push_back(val);
	}
	cout<<"enter length of msg :";
    cin>>num;
	cout<<"enter msg(space seperated) : ";
	while(num--){
	    int val;
	    cin>>val;
	    data.push_back(val);
	}
	
	//append n-1 zeroes to data
	for(int i=1;i<(int)key.size();i++){
	    data.push_back(0);                                                                                                      
	}
	vector<int> msg(data);
	while(data.size()>=key.size()){
    	int flag=0;
    	
	    //binary division
	    for(int i=0,j=0;i<(int)key.size();i++,j++){
	        data[j] = data[j]^key[i];
	        //removing trailing zeores
            if(data[j]==0 && flag==0){
	            data.erase(data.begin());
	            j--;
	        }
	        else if(data[j]==1){
	            flag=1;
	        }
	    }
	}
	cout<<endl;
	cout<<"message to be transmitted : ";
	//adding remainder to msg
	for(int i=(int)data.size()-1,j=(int)msg.size()-1;i>=0;i--,j--){
	    msg[j] |= data[i];
	}
	for(auto &ele : msg)    cout<<ele<<" ";
	
	cout<<"\n\n----------Receiver----------\n\n";
	cout<<"enter length of msg : ";
	cin>>num;
	cout<<"Enter msg(space seperated) : ";
	vector<int> rec;
	while(num--){
	    int val;
	    cin>>val;
	    rec.push_back(val);
	}
	while(rec.size()>=key.size()){
    	int flag=0;
    	
	    //binary division
	    for(int i=0,j=0;i<(int)key.size();i++,j++){
	        rec[j] = rec[j]^key[i];
	        //removing trailing zeores
            if(rec[j]==0 && flag==0){
	            rec.erase(rec.begin());
	            j--;
	        }
	        else if(rec[j]==1){
	            flag=1;
	        }
	    }
	}
	
	if(!rec.size())    cout<<"\nNoiseless data is received";
	else    cout<<"\nData is corrupted";
	return 0;
}
