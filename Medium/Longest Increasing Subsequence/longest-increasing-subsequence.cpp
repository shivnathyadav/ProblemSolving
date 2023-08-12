//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    int lis(int ind,int prev,int n,int a[],vector<vector<int>> &dp){
        if(ind==n){
            return 0;
        }
        if(dp[ind][prev+1]!=-1){
            return dp[ind][prev+1];
        }
        int len=0;
        len=lis(ind+1,prev,n,a,dp);
        if(prev==-1 || a[ind]>a[prev]){
            len = max(len,1 + lis(ind+1,ind,n,a,dp));
        }
        return dp[ind][prev+1]=len;
    }
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
       // your code here
    //   vector<vector<int>> dp(n+1,vector<int> (n+1,-1));
    //   return lis(0,-1,n,a,dp);
      /* vector<vector<int>> dp(n+1 , vector<int> (n+1,0));
       for(int j=n-1;j>=0;j--){
           for(int i=j-1;i>=-1;i--){
               int len = dp[j+1][i+1];
               if(i==-1 || a[j]>a[i]){
                   len = max(len,1+dp[j+1][j+1]);
               }
               dp[j][i+1]=len;
           }
       }
       return dp[0][0];    */
       /*int ans=0;
       vector<int> dp(n,1);
        for(int i=0;i<n;i++){
            for(int prev=0;prev<i;prev++){
                if(a[i]>a[prev]){
                    dp[i]=max(dp[i],1+dp[prev]);
                }
            }
            ans=max(ans,dp[i]);
        }
        return ans;
        */
         vector<int> temp;
        temp.push_back(a[0]);
        for(int i=1;i<n;i++){
            if(a[i]>temp.back()){
                temp.push_back(a[i]);
            }
            else{
                int ind = lower_bound(temp.begin(),temp.end(),a[i])-temp.begin();
                temp[ind]=a[i];
            }
        }
        return temp.size();
    }
};


//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends