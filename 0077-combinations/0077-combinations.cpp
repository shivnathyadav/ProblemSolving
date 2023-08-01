class Solution {
public:
    void combination(int ind,int k,int n,vector<int> &ans,vector<vector<int>> &vec){
        if(ind>n){
            if(ans.size()==k){
                vec.push_back(ans);
            }
            return;
        }
        ans.push_back(ind);
        combination(ind+1,k,n,ans,vec);
        ans.pop_back();
        combination(ind+1,k,n,ans,vec);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> vec;
        vector<int> ans;
        combination(1,k,n,ans,vec);
        
        return vec;
    }
};