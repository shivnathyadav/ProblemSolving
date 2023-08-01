class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2,
     int k){
         int cnt = 0;
         priority_queue<pair<long long ,pair<int,int>>> pq;
         
         for(int i = 0; i < nums1.size(); i++){
             for(int j = 0; j < nums2.size(); j++){
                 long long sum = nums1[i]+nums2[j];
                 if(pq.size() < k ){
                     pq.push({sum , {nums1[i],nums2[j]}});
                 } 
                 else if(sum<pq.top().first){
                     pq.pop();
                     pq.push({sum,{nums1[i],nums2[j]}});
                 }
                 else{
                     break;
                 }
             }
         }
         vector<vector<int>> ans;
         while(!pq.empty()){
             ans.push_back({pq.top().second.first,pq.top().second.second});
             pq.pop();
         }
         reverse(ans.begin(),ans.end());
        return ans;
    }
};