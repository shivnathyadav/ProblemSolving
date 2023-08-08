class Solution {
public:
    int search(vector<int> vec, int l, int h, int key){
        // l: The starting index
        // h: The ending index, you have to search the key in this range
        
        //complete the function here
            if(l>h){
                return -1;
            }
            int mid = (l+h)/2;
            if(vec[mid]==key){
                return mid;
            }
            int a = search(vec,l,mid-1,key);
            int b = search(vec,mid+1,h,key);
            if(a!=-1){
                return a;
            }
            else if(b!=-1){
                return b;
            }
            else
            return  -1;
    }
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        return search(nums,0,n-1,target);
    }
};