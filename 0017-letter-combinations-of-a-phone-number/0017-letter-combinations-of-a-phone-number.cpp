class Solution {
public:
    vector<string> num={{""},{""},{"abc"},{"def"},{"ghi"},{"jkl"},{"mno"},{"pqrs"},{"tuv"},{"wxyz"}};
    void combination(int ind,string &digits,string &str,vector<string> &ans){
        if(ind == digits.size()){
            ans.push_back(str);
            return ;
        }
        for(int i = 0; i < num[digits[ind]-'0'].size();i++){
            str.push_back(num[digits[ind]-'0'][i]);
            combination(ind+1,digits,str,ans);
            str.pop_back();
        }
        return ;
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.size()==0){
            return ans;
        }
        string str;
        combination(0,digits,str,ans);
        return ans;    
    }
};