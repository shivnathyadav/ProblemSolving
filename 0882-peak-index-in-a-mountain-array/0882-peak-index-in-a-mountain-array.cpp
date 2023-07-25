class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size() ;
        int left = 0, right = n - 1;
        while(left < right){

            int mid = (left+right)/2;
            
            if(mid > 0 && mid < n && arr[mid] > arr[mid-1] 
            && arr[mid] > arr[mid+1] ){
                return mid;
            }
            else if(mid < n-1 && arr[mid] > arr[mid+1]){
                right = mid-1 ;
            }
            else{
                left = mid+1;
            }
            
        }

        return left;
    }
};