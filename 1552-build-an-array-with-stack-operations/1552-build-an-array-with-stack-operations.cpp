class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> vec;
        
        int i = target.size()-1;
        int j = target[i];
        while(i>=0 && j >= 1){
            if(target[i]==j){
                vec.push_back("Push");
                i -= 1;
                j -= 1;
            }
            else{
                vec.push_back("Pop");
                vec.push_back("Push");
                j -= 1;     
            }
        }
        while(j>=1){
            vec.push_back("Pop");
            vec.push_back("Push");
            j -= 1;
        }
        reverse(vec.begin(),vec.end());
        return vec;
    }
};