//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long int checkSum(int ind,int n,int coins[],int sum,vector<vector<long long int>> &vec){
        if(ind==0){
            if(sum%coins[0]==0){
                return 1;
            }
            else
                return 0;
        }
        if(sum<0){
            return 0;
        }
        if(vec[ind][sum]!=-1){
            return vec[ind][sum];
        }
        long long int ans1 = checkSum(ind-1,n,coins,sum,vec);
        long long ans2 = 0;
        if(coins[ind]<=sum)
            ans2 = checkSum(ind,n,coins,sum-coins[ind],vec);
        
        return vec[ind][sum]=ans1+ans2;
        
    }
    long long int count(int coins[], int n, int sum) {

        // code here.
        if(sum==0){
            return 1;
        }
        vector<vector<long long int>> vec(n,vector<long long int> (sum+1, 0));
        for(int i = 0; i <=sum; i++){
            if(i%coins[0]==0){
                vec[0][i]=1;
            }
        }
        for(int i = 1; i < n ; i++){
            for(int j = 0 ; j <= sum; j++){
                long long int take = vec[i-1][j];
                long long int not_take = 0;
                if(coins[i]<=j){
                    not_take = vec[i][j-coins[i]];
                }
                vec[i][j]= take + not_take ;
            }
        }
        return vec[n-1][sum];
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends