//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public: 
    bool checkPrime(int n){
        for(int i = 2; i*i <= n; i++){
            if(n%i==0){
                return false;
            }
        }
        return true;
    }
    long long int largestPrimeFactor(int n){
        // code here
        if(n==2){
            return 2;
        }
        int ans =-1;
        int i = 2;
        if(checkPrime(n)){
            return n;
        }
        for(i = 2; i*i <= n; i++){
            if(n%i==0){
                if(checkPrime(i)){
                    ans=max(ans,i);
                }
                if(checkPrime(n/i)){
                    ans=max(ans,(n/i));
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.largestPrimeFactor(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends