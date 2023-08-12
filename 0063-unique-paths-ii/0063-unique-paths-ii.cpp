class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& vec) {
      int mod=1000000007;
        int n=vec.size();
        int m=vec[0].size();
        vector<vector<int>> dp(n,vector<int> (m));
        for(int i=0;i<n;i++){
            if(vec[i][0]==1){
                for(int j=i;j<n;j++){
                    dp[i][0]=0;
                }
                break;
            }
            dp[i][0]=1;
        }
        for(int i=0;i<m;i++){
           if(vec[0][i]==1){
                for(int j=i;j<m;j++){
                    dp[0][i]=0;
                }
                break;
            }
            dp[0][i]=1; 
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(vec[i][j]==1){
                    dp[i][j]=0;
                }
                else{
                    dp[i][j]=dp[i-1][j]+dp[i][j-1];
                }
            }
        }
        return dp[n-1][m-1];   
        
    }
};