class Solution {
public:
    string sortVowels(string s) 
    {
        vector<char> vec;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' || s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' ||s[i]=='U')
                vec.push_back(s[i]);
        }
        string res="";
        sort(vec.begin(),vec.end());
        
        int j=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' || s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' ||s[i]=='U')
                res.push_back(vec[j++]);
            else
                res.push_back(s[i]);
        }
        return res;
    }
};