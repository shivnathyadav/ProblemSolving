class Solution {
public:
    string reorganizeString(string s) {
       int freq[26]={0};
       int n = s.size();
       int maxi = 0;
       for(auto ch:s){
           freq[ch-'a']+=1;
           maxi = max(maxi,freq[ch-'a']);
       } 
       
        if(maxi>(n-maxi+1)){
            return "";
        }
        priority_queue<pair<int,char>> pq;
        for(int i = 0; i < 26; i++){
            if(freq[i]>0){
                pq.push({freq[i],i+'a'});
            }
        }
        string ans;
        while(pq.size()>=2){
            pair<int,char> p1 = pq.top();
            pq.pop();
            pair<int,char> p2 = pq.top();
            pq.pop();
            ans.push_back(p1.second);
            ans.push_back(p2.second);
            if(p1.first > 1){
                pq.push({p1.first-1,p1.second});
            }
            if(p2.first > 1){
                pq.push({p2.first-1,p2.second});
            }
        }
        if(pq.size()==1)
        ans.push_back(pq.top().second);
        return ans;
    }
};