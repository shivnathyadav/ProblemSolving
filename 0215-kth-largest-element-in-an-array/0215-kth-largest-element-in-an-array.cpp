class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        map<int,int> mp;
        for(auto it :  nums){
            mp[it]++;
        }
        k = n - k + 1;
        for(auto it: mp){
            cout<<k<<endl;
            if(k-it.second>0){
                k = k - it.second;
            }
            else{
                return it.first;
            }
        }
        return -1;
    }
};