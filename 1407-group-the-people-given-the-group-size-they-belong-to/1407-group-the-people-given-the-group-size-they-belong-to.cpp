class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        map<int,vector<int>> mp;
        int n = groupSizes.size();
        for(int i = 0; i < n; i++){
            mp[groupSizes[i]].push_back(i);
        }
        int i = 0;
        vector<vector<int>> ans;
        for(auto it:mp){
            int sz = it.first;
            vector<int> vec = it.second;
            int j = 0;
            for(int t = 0; t < (vec.size()/sz); t++){
                vector<int> num;
                int k = 0;
                while(k < sz){
                    num.push_back(vec[j]);
                    k++;
                    j+=1;
                }
                ans.push_back(num);
            }
        }
        return ans;
    }
};