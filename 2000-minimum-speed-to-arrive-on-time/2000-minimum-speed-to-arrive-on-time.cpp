class Solution {
public:
    bool valid(vector<int>& dist,double hour,long speed){
        double ans = 0;
        for(int i = 0 ; i < dist.size() ; i++){
            ans = ceil(ans);
            ans += (double)dist[i]/speed;
            if(ans > hour){
                return false;
            }
        }
        return true;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n =  dist.size();
        if(hour < n-1)
            return -1;
        long miniSpeed = 1 , maxiSpeed = 1e7;
        while(miniSpeed <= maxiSpeed){
            long speed = (miniSpeed + maxiSpeed)/2;
         //   cout<<maxiSpeed<<" "<<miniSpeed<<" "<<speed<<endl;
         //   cout<<valid(dist,hour,speed)<<endl;
            if(valid(dist,hour,speed)){
                
                maxiSpeed = speed - 1;
            }
            else{
                miniSpeed = speed + 1;
            }

        }
        cout<<maxiSpeed<<" "<<miniSpeed<<endl;
        if(miniSpeed>1e7){
            return -1;
        }
        return miniSpeed;
    }
};
//https://leetcode.com/problems/minimum-speed-to-arrive-on-time/solutions/1226468/binary-answer-cheat-sheet/