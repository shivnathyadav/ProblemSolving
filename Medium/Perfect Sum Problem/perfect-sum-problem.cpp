//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    
	public:
	int mod = 1e9 + 7;
	int getCount(int ind,int n,int arr[],int sum,vector<vector<int>> &dp){
	    if(ind<0){
	        if(sum==0){
	            return 1;
	        }
	        else{
	            return 0;
	        }
	    }
	    if(sum<0){
	        return 0;
	    }
	    
	    if(dp[ind][sum]!=-1){
	        return dp[ind][sum];
	    }
	    int not_take = getCount(ind-1,n,arr,sum,dp)%mod;
	    int take = getCount(ind-1,n,arr,sum-arr[ind],dp) % mod;
	    
	    return dp[ind][sum] = (take + not_take)%mod;
	}
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        vector<vector<int>> dp(n , vector<int> (sum+1,-1));
        return getCount(n-1,n,arr,sum,dp);
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends