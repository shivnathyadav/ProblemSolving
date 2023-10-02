//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:	
	int distinctSubsequences(string s)
	{
	    // Your code goes here
	    int n = s.size();
	    vector<int> dp(n+1,0);
	    dp[0]=1;
	    int mod = 1000000007;
	    int indLast[26]={-1};
	    for(int i = 1;i <= n; i++){
	        //if not repeating character then it will twice of previous
	         
	        // in case of repeating remove previous subsequence
	        if(indLast[s[i-1]-'a']!=-1){
	            
	            dp[i]=(2*dp[i-1]%mod-dp[indLast[s[i-1]-'a']-1]+mod)%mod;
	        }
	        else{
	            dp[i]=(2*dp[i-1]%mod)%mod;
	        }
	        indLast[s[i-1]-'a']=i;
	    }
	    return dp[n];
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

        Solution ob;
   		cout << ob.distinctSubsequences(s) << "\n";
   	}

    return 0;
}
// } Driver Code Ends