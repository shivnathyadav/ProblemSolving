class Solution {
public:
    bool b_search(vector<int>& nums,int l,int h,int tar){
        if(l>h){
            return false;
        }
        int mid = (l+h)/2;
        if(nums[mid]==tar){
            return true;
        }
        bool left = b_search(nums,l,mid-1,tar);
        bool right = b_search(nums,mid+1,h,tar);
        if(left==true){
            return true;
        }
        else if(right==true){
            return true;
        }
        else
            return false;
    }
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        return b_search(nums,0,n-1,target);
    }
};