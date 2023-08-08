//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
    public:
    int countFractions(int n, int numerator[], int denominator[])
    {
        map<pair<int,int>,int> st;
        for(int i = 0; i < n; i++){
            int gcd = __gcd(numerator[i],denominator[i]);
            numerator[i] /= gcd;
            denominator[i] /= gcd;
            st[{numerator[i],denominator[i]}] += 1;
        }
        
        int count = 0 , half = 0;
        for(auto it : st){
            int num = it.first.second - it.first.first;
            int den = it.first.second;
            
            pair<int,int> number = {num,den};
            if((!(num==1 && den==2)) && st.find(number)!=st.end()){
                count += st[number]*st[{it.first.first,it.first.second}];
            }
            else if(num==1 && den==2){
                half = st[{num,den}];
            }
        }
      //  cout<<count <<" "<<half<<endl;
        count = count/2 + (half*(half-1))/2;
        return count;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int numerator[n],denominator[n];
        for(int i=0;i<n;i++)
            cin>>numerator[i];
        for(int i=0;i<n;i++)
            cin>>denominator[i];
        Solution ob;
        int ans=ob.countFractions(n,numerator,denominator);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends