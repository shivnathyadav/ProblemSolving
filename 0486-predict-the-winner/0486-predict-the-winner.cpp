class Solution {
public:
    bool predictScore(int i,int j,int chance,vector<int> & nums,
    int score1,int score2){
        if(i>j){
            return score1>=score2;
        }
        if(chance==0){
            return (predictScore(i+1,j,1,nums,score1+nums[i],score2)||
                  predictScore(i,j-1,1,nums,score1+nums[j],score2));
        }
        
        return (predictScore(i+1,j,0,nums,score1,score2+nums[i])&&       
               predictScore(i,j-1,0,nums,score1,score2+nums[j]));
        
    }
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        int score1 = 0;
        int score2 = 0;
        return predictScore(0,n-1,0,nums,score1,score2);
    }
};