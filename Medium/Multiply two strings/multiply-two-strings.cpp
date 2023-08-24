//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
class Solution{
  public:
    /*You are required to complete below function */
    string add(string str1,string str2){
        string ans="";
        int i = str1.size()-1;
        int j = str2.size()-1;
        int carry = 0;
        while(i >= 0 && j >= 0){
            int sum = (str1[i]-'0')+(str2[j]-'0')+carry;
            ans.push_back((sum%10+'0'));
            carry = sum/10;
            i-=1;
            j-=1;
        }
        while(i>=0){
            int sum = (str1[i]-'0')+carry;
            ans.push_back((sum%10+'0'));
            carry = sum/10;
            i-=1;
        }
        while(j>=0){
            int sum = (str2[j]-'0')+carry;
            ans.push_back((sum%10+'0'));
            carry = sum/10;
            j-=1;
        }
        if(carry!=0){
            ans.push_back(carry+'0');
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    string multiplyStrings(string s1, string s2) {
       //Your code here
       int sign = 1;
       int n = s1.size() , m = s2.size();
       if(s1[0]=='-'){
           s1.erase(0,1);
           sign = sign*(-1);
           n = n-1;
       }
       if(s2[0]=='-'){
           s2.erase(0,1);
           sign = sign*(-1);
           m = m-1;
       }
       
       string str2="0";
       
       for(int i = m-1; i >= 0; i--){
           string str1="";
           int carry = 0;
           for(int j = n-1; j >=0; j--){
               int prod = (s1[j]-'0')*(s2[i]-'0')+carry;
               int val = prod%10;
               str1.push_back(val+'0');
               carry = prod/10;
           }
           if(carry!=0){
               str1.push_back(carry+'0');
           }
           reverse(str1.begin(),str1.end());
           int k = m - 1 - i;
           for(int t = 0; t < k; t++){
               str1.push_back('0');
           }
           str2 = add(str1,str2);
        }
        int i = 0;
        while (str2[i] == '0')
            i++;
      
        // The erase function removes i characters
        // from given index (0 here)
        str2.erase(0, i);
       if(sign==-1){
           str2 = "-"+str2;
       }
       return str2;
    }

};

//{ Driver Code Starts.
 
int main() {
     
    int t;
    cin>>t;
    while(t--)
    {
    	string a;
    	string b;
    	cin>>a>>b;
    	Solution obj;
    	cout<<obj.multiplyStrings(a,b)<<endl;
    }
     
}
// } Driver Code Ends