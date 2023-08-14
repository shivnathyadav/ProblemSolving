class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        // put (n-k)th element at is right position and all element which are smaller than sorted(n-k)th before it and larger are should be after it.
        nth_element(nums.begin(), nums.end() - k, nums.end());

        return nums[nums.size()-k];
    }
};