//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string fun(int n,int s,string str){
        
        
        if(s<10){
            if(n==1){
                str.push_back(s+'0');
            }
            else{
                 char ch = s + '0';
                 str = str+ch+fun(n-1,0,str);
            }
        }
        else{
            str =  str + '9' + fun(n-1,s-9,str);
        }
        return str;
    }
    string findLargest(int n, int s){
        // code here
        if(n*9<s){
            return "-1";
        }
        if(n>1 && s==0){
            return "-1";
        }
        string str = "";
        return fun(n,s,str);
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, S;
        cin>>N>>S;
        
        Solution ob;
        cout<<ob.findLargest(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends