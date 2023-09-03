class Solution {
public:
    int uniquePaths(int m, int n) {
      long double ans=1;
       
        // the total number of ways are (m+n-2)!/(m-1)!(n-1)!;
        
            int j=1;
            int  k=m-1;
            for(int i=m;i<=(m+n-2);i++){
                if(j<=n-1){
                    ans=(ans*i)/j;
                    j++;
                }
                else{
                    ans=ans*i;
                }
            
            }
            return (int)ans;
    
    }
};