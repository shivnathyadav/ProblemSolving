class Solution {
public:
    vector<int> searchRange(vector<int>& arr, int x) {
         vector<int>::iterator lower,upper;
    lower=lower_bound(arr.begin(),arr.end(),x);
    upper=upper_bound(arr.begin(),arr.end(),x);
    pair<int,int> p;
//     cout<<arr[lower-arr.begin()]<<" "<<arr[upper-arr.begin()-1]<<endl;
    if(lower!=arr.end() && arr[lower-arr.begin()]==x && arr[upper-arr.begin()-1]==x){
        p.first=lower-arr.begin();
        p.second=upper-arr.begin()-1;
    }
    else{
        p.first=-1;
        p.second=-1;
    }
    vector<int> vec;
    vec.push_back(p.first);
    vec.push_back(p.second);

    return vec;
   
        
    }
};