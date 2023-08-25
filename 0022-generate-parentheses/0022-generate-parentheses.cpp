class Solution {
public:
    void fillset(string str,set<string> &st){
        int n = str.size();
        for(int i = 0; i < n; i++){
            string ans = "";
            ans = str.substr(0,i)+"()"+str.substr(i,n-i);
            st.insert(ans);
        }
    }
    vector<string> generateParenthesis(int n) {
        set<string> st;
        if(n>=1){
            st.insert("()");
        }
        for(int i = 2; i <= n; i++ ){
            int sz = st.size();
            vector<string> vec;
            for(auto it:st){
                vec.push_back(it);
            }
            for(int i = 0; i < sz; i++){
                fillset(vec[i],st);
            }
        }
        vector<string> ans;
        for(auto it:st){
            if(it.size()!=2*n){
                continue;
            }
            ans.push_back(it);
        }
        return ans;
    }
};