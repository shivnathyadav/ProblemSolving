class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n=nums.size(),pick=1,unpick=1;
        
        for(int i=1;i<n;i++){
            if(nums[i] - nums[i - 1] > 0){
                pick=unpick+1;
            }
            if(nums[i] - nums[i - 1] < 0){
                unpick=pick+1;
            }
        }
        return max(pick,unpick);
    }
};