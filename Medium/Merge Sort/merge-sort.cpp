//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;



/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


// } Driver Code Ends
class Solution
{
    public:
    void merge(int arr[], int l, int m, int r)
    {
         // Your code here
         vector<int> vec(r-l+1);
         int ind = 0;
         int i,j;
         for(i = l,j = m+1; i<=m && j<=r;){
             if(arr[i]<=arr[j]){
                 vec[ind]= arr[i];
                 i += 1;
                 ind += 1;
             }
             else{
                 vec[ind] = arr[j];
                 j += 1;
                 ind += 1;
             }
         }
         while(i <= m){
             vec[ind] = arr[i];
             ind += 1;
             i += 1;
         }
         while(j <= r){
             vec[ind] = arr[j];
             ind += 1;
             j += 1;
         }
         for(int k = l; k <= r; k++){
             arr[k] = vec[k-l];
         }
    }
    public:
    void mergeSort(int arr[], int l, int r)
    {
        //code here
        if(l>=r){
            return;
        }
        int mid = (l+r)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        merge(arr,l,mid,r);
    }
};

//{ Driver Code Starts.


int main()
{
    int n,T,i;

    scanf("%d",&T);

    while(T--){
    
    scanf("%d",&n);
    int arr[n+1];
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);

    Solution ob;
    ob.mergeSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends