class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int num1,num2,count1=0,count2=0;
        
     for(int i=0;i<nums.size();i++){
         if(nums[i]==num1){
            count1+=1;
        }
        else if(nums[i]==num2){
            count2+=1;
        }
        else if(count1==0){
            num1=nums[i];
            count1=1;
        }
        else if(count2==0){
            num2=nums[i];
            count2=1;
        }
        else{
            count1--;
            count2--;
        }
     }    
//    cout<<num1<<" "<<num2<<endl;
        count1=0;
        count2=0;
        vector<int> vec;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==num1){
                count1++;
            }
            else if(nums[i]==num2){
                count2++;
            }
        }
        if(count1>nums.size()/3)
            vec.push_back(num1);
        if(count2>nums.size()/3)
            vec.push_back(num2);
        
        return vec;
    }
};