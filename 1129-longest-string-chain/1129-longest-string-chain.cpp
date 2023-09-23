class Solution {
public:
    bool static comp(string &s1,string &s2){
        if(s1.size()<s2.size()){
            return true;
        }
        return false;
    }
    bool compare(string str1,string str2){
        int i = 0,j = 0 ;
        int n = str1.length(), m = str2.length(); 
        
        while(i < n){
            if(str1[i]==str2[j]){
                i+=1;
                j+=1;
            }
            else{
                i+=1;
            }
        }
        if(i==n && j==m ){
            return true;
        }
        return false;
    }
    int longestStrChain(vector<string>& words) {
        //sort string based on length
        sort(words.begin(),words.end(),comp);
        int n = words.size(),maxi=0;
        vector<int> dp(n,1);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                //if there is difference of 1 in lenght && compare function is to check edit distance of words[i] and words[j] is such that words[i]>words[j]
                if(words[i].size() == words[j].size() + 1 && compare( words[i], words[j]) && ( 1 + dp[j] > dp[i])){
                    dp[i]=1+dp[j];
                }
            }
            maxi = max( maxi , dp[i] );
        }
        return maxi;
    }
};