class Solution {
public:
    void permutation(int i,vector<int> &nums,vector<vector<int>> &vec){
        if(i>=nums.size()){
            vec.push_back(nums);
            return;
        }
        for(int ind = i ;ind < nums.size(); ind++){
            swap(nums[i],nums[ind]);
            permutation(i+1,nums,vec);
            swap(nums[i],nums[ind]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
       vector<vector<int>> vec;
       permutation(0,nums,vec);
       return vec;
    }
};