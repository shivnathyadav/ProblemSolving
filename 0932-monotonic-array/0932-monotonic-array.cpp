class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int i = 1;
        int n = nums.size();
        int isInc = 0;
        while(i<n){
            if(nums[i]>nums[i-1]){
                if(isInc==-1){
                    return false;
                }
                isInc = 1;
            }
            else if(nums[i]<nums[i-1]){
                if(isInc==1){
                    return false;
                }
                isInc = -1;
            }
            i+=1;
        }
        return true;
    }
};