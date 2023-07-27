class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        int sz = batteries.size();
        if(sz < n){
            return 0;
        }
        if(sz == n){
            int mini = *min_element(batteries.begin(),batteries.end());
            return mini;
        }
        // Variable to store the total time of all batteries
        long long total_time = 0; 

         // Calculate the total time by summing all battery times
        for(auto x : batteries)
            total_time += x;
        
        // Sort the battery times in non-ascending order
        sort(batteries.begin(), batteries.end(),greater<int>());
         
        // Loop through the sorted battery times and try to optimize the run time
        
        for(int i = 0; i < batteries.size(); i++, n--) {
            // If the current battery time is less than or equal to the average time (total_time/n),
        
            // then it won't be a bottleneck, so we can stop optimizing further
            if(batteries[i] <= (total_time / n)) break;
        
            // Reduce the total time by the current battery time
            total_time -= batteries[i]; 
        }

        // Return the optimized maximum run time
        return total_time / n; 
    }
};