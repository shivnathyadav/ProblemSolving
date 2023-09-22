class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0 , j = 0 ;
        int n = s.size();
        int m = t.size();
        while( i < n && j < m){
            if(s[i]==t[j]){
                i+=1;
                j+=1;
            }
            else{
                j+=1;
            }
        }
        if(i==n){
            return true;
        }
        return false;
    }
};