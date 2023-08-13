class Solution {
public:
    
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        vector<bool> dp(n+1,false);
        dp[0]=true;
        for(int i = 2; i <=n; i++){
            dp[i] = dp[i] || ( nums[i-1]==nums[i-2] && dp[i-2]); // cond 1
            dp[i] = dp[i] || ( i>2 && nums[i-1] == nums[i-2] &&
             nums[i-2] == nums[i-3] && dp[i-3]); // cond 2
            dp[i] = dp[i] || ( i>2 && nums[i-1]-nums[i-2]==1 && 
            nums[i-2]-nums[i-3]==1 && dp[i-3]); // cond 3
        }
        return dp[n];
    }
};