//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function teamplate for C++

class Solution{
  public:
    vector<int> printClosest(int arr[], int brr[], int n, int m, int x) {
        //code here
        int i=0;
        int j = m-1;
        int diff = INT_MAX;
        vector<int> p(2,0);
        while(i<n && j>=0){
            int sum = arr[i]+brr[j];
            if((x-sum)==0)
            return {arr[i],brr[j]};
            if(diff>abs(x-sum)){
            diff = abs(x-sum);
            p[0]=arr[i];
            p[1]=brr[j];
            }
            
            if(x-sum>0)
            i++;
            else
            j--;
        }
        return p;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	int m,n,x;
	while(t--)
    {
        cin>>n>>m;
        int a[n],b[m];
        
        for(int i=0;i<n;i++)
            cin>>a[i];
            
        for(int i=0;i<m;i++)
            cin>>b[i];
            
        cin>>x;
        
        vector<int> ans;
        Solution ob;
        ans = ob.printClosest(a, b, n, m, x);
        cout << abs(ans[0] + ans[1] - x) << endl;
        
    }
    return 0;
}

// } Driver Code Ends