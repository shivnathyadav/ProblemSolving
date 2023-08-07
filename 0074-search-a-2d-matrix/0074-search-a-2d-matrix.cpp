class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        // apply binary search considering the length of array would be the equal to row*column
        // int left=0, right=matrix.size()*matrix[0].size()-1,mid;
        // if(matrix.size()==0)
        //     return false;
        // while(left<=right){
        //     mid=(left+right)/2;
        //     if(matrix[mid/matrix[0].size()][mid%matrix[0].size()]==target){
        //         return true;
        //     }
        //     else if(matrix[mid/matrix[0].size()][mid%matrix[0].size()]>target){
        //         right=mid-1;
        //     }
        //     else{
        //         left=mid+1;
        //     }
        // }
        // return false;
        /*The approach is straight and simple,

--> take the top-right corner mat[top][right]

                  top(i) = 0

                  right(j) = M-1

--> check the selected element  with X

              if matches return 1

              else if smaller increment i+=1

             else if larger decrement j-=1

            if no matches return 0*/
            int n = matrix.size();
            int m = matrix[0].size();
            int i=0 , j=m-1;
            while(i<n && j>=0){
                if(matrix[i][j]==target){
                    return true;
                }
                else if(matrix[i][j]<target){
                    i += 1;
                }
                else{
                    j -= 1;
                }
            }
            return false;
    }
};