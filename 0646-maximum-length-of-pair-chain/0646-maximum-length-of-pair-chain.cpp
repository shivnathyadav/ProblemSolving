class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end());
        int cnt = 1;
        int n = pairs.size();
        int j = n-1;
        for(int  i = n-2;i >= 0 ; i--){
            cout<<pairs[i][0]<<" "<<pairs[i][1]<<endl;
            if(pairs[i][1]<pairs[j][0]){
                cnt += 1;
                j = i;
            }
        }
        return cnt;
    }
};