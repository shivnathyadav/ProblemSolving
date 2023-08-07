class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        vector<int> ans;
        int n2 = nums2.size();
        unordered_map<int,int> mp;
        for(int i = n2-1 ; i >= 0; i--){
            if(st.empty()){
                ans.push_back(-1);
                st.push(nums2[i]);
            }
            else{
                while(!st.empty() && nums2[i]>=st.top()){
                    st.pop();
                }
                if(!st.empty()){
                    ans.push_back(st.top());
                    st.push(nums2[i]);
                }
                else{
                    ans.push_back(-1);
                    st.push(nums2[i]);
                }
            }
            mp[nums2[i]]=ans.back();
        }
        for(int j = 0; j < nums1.size() ; j++){
            nums1[j]=mp[nums1[j]];
        }
        return nums1;
    }
};