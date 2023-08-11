class Solution {
public:
    /*
    int ways(int ind,vector<int> &coins,int amount,vector<vector<int>> &dp){
        if(ind==0){
            if(amount%coins[0]==0){
                return 1;
            }
            else{
                return 0;
            }
        }
        if(amount<0){
            return 0;
        }
        if(dp[ind][amount]!=-1){
            return dp[ind][amount];
        }
        int not_take = ways(ind-1,coins,amount,dp);
        int take = 0;
        if(coins[ind]<=amount)
            take = ways(ind,coins,amount-coins[ind],dp);
        return dp[ind][amount]=not_take+take;
    } */
    int change(int amount, vector<int>& coins) {
        if(amount==0){
            return 1;
        }
        int n =coins.size();
        /*vector<vector<int>> dp(n,vector<int> (amount+1,-1));
        return ways(coins.size()-1,coins,amount,dp);*/

        vector<int> prev(amount+1, 0);
        for(int i = 0; i <=amount; i++){
            if(i%coins[0]==0){
                prev[i]=1;
            }
        }
        for(int i = 1; i < n ; i++){
            vector<int> curr(amount+1,0);
            for(int j = 0 ; j <= amount; j++){
                long long int take = prev[j];
                long long int not_take = 0;
                if(coins[i]<=j){
                    not_take = curr[j-coins[i]];
                }
                curr[j]= take + not_take ;
            }
            prev = curr;
        }
        return prev[amount];
    }
};