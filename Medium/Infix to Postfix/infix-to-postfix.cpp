//{ Driver Code Starts
// C++ implementation to convert infix expression to postfix
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to convert an infix expression to a postfix expression.
    unordered_map<char,int> mp = {{'^',5},{'*',4},{'%',4},{'/',4},{'-',3},{'+',3}};
    string infixToPostfix(string s) {
        // Your code here
        stack<char> st;
        int n = s.size();
        string str="";
        for(int i = 0; i < n; i++){
            if(mp.find(s[i])!=mp.end() || (s[i]=='(')){
                if(st.empty() || s[i]=='('){
                    st.push(s[i]);
                }
                else{
                    if(mp[s[i]]>mp[st.top()]){
                        st.push(s[i]);
                    }
                    else{
                         while(!st.empty() && mp[s[i]]<=mp[st.top()]){
                             str.push_back(st.top());
                             st.pop();
                         }
                         st.push(s[i]);
                    }
                }
            }
            else{
                if(s[i]==')'){
                    while(st.top()!='('){
                        str.push_back(st.top());
                        st.pop();
                    }
                    st.pop();
                }
                else
                    str.push_back(s[i]);
            }
        }
        while(!st.empty()){
            str.push_back(st.top());
            st.pop();
        }
        return str;
    }
};


//{ Driver Code Starts.
// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while (t--) {
        string exp;
        cin >> exp;
        Solution ob;
        cout << ob.infixToPostfix(exp) << endl;
    }
    return 0;
}

// } Driver Code Ends