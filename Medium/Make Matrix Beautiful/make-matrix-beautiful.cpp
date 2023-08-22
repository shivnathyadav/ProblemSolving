//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find minimum number of operations that are required 
    //to make the matrix beautiful.
    int findMinOpeartion(vector<vector<int> > matrix, int n)
    {
        // code here 
        long long sum = 0,maxsum = 0,maxSum = 0;
        for(int i = 0; i < n; i++){
            int rowSum = 0;
            int colSum = 0;
            for(int j = 0; j < n; j++){
                sum += matrix[i][j];
                rowSum += matrix[i][j];
                colSum += matrix[j][i];
                
            }
            maxSum = max<long long>(maxSum , max(rowSum,colSum));
        }
        long maxiSum = n * maxSum ;
        return maxiSum - sum;
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
        vector<vector<int> > matrix (n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>matrix[i][j];
        Solution ob;
        cout << ob.findMinOpeartion(matrix, n) << endl;
    }
    return 0;
}


// } Driver Code Ends