class Solution {
public:
    vector<vector<int>> generate(int n) {
      
    vector<vector<int>> pascalVect;
    vector<int> tempvect; 
  
    tempvect.push_back(1);
    pascalVect.push_back(tempvect);
  
    //creating base cases
    if(n==1)
        return pascalVect;
    else if(n==2){//base case for n=2
    tempvect.push_back(1);
        pascalVect.push_back(tempvect);
    }    
    else{
        
        tempvect.push_back(1);
        pascalVect.push_back(tempvect);
        
        for(int i=2;i<n;i++){
          
            vector<int> ansVect;// creating a vector to add in 2d vector
            ansVect.push_back(1); //adding first value of any row
            vector<int> vec;  //creating  vector store addtion value - let say addtion vector
                
            for(int k=0;k<pascalVect[i-1].size()-1;k++){
                    int consecutiveSum=pascalVect[i-1][k]+pascalVect[i-1][k+1];
                    vec.push_back(consecutiveSum);
                }
            ansVect.insert(ansVect.end(),vec.begin(),vec.end()); // concat addition vector and vector 1 value
            ansVect.push_back(1);//adding last value
            pascalVect.push_back(ansVect);
            ansVect.clear();
            }    
        }
    return pascalVect;  
    }
};