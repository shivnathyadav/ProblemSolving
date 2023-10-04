//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    int romanToDecimal(string &str) {
        // code here
        int n=str.length();
     int k=0;
    for(int i=n-1;i>=0;i--){
        if(str[i]=='I')
           k+=1;
        else if(str[i]=='V')
           k+=5;
        else if(str[i]=='X')
           k+=10;
        else if(str[i]=='L')
           k+=50;
        else if(str[i]=='C')
           k+=100;
        else if(str[i]=='D')
           k+=500;
        else if(str[i]=='M')
           k+=1000;
        if(i-1>=0  && (str[i]=='V' || str[i]=='X') && str[i-1]=='I'){
            k-=1;
            i--;
        }
        else if(i-1>=0  && (str[i]=='L' || str[i]=='C') && str[i-1]=='X'){
            k-=10;
            i--;
        }
        else if(i-1>=0  && (str[i]=='D' || str[i]=='M') && str[i-1]=='C'){
            k-=100;
            i--;
        }
    }
          return k;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.romanToDecimal(s) << endl;
    }
}
// } Driver Code Ends