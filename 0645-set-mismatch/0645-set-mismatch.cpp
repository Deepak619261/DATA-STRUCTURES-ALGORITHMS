class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
            int n=nums.size();
        
        int xore=0;
        
        for(int i=0;i<n;i++){
            xore=xore^(i+1);
            xore=xore^nums[i];
        }
        
        //  get the rightmost set bit 
        int bitno=0;
        
        while(1){
            if((xore & (1<<bitno))!=0){
                break;
            }
            bitno++;
        }
        
        int one=0;
        int zero=0;
        
        for(int i=0;i<n;i++){
            if((nums[i] & (1<<bitno))!=0){
               one=one^nums[i];
            }
            else{
                zero=zero^nums[i];
            }
            
            if(((i+1) & (1<<bitno))!=0){
               one=one^(i+1);
            }
            else{
                zero=zero^(i+1);
            }
        }
        int count=0;
        
        for(auto it:nums){
            if(it==zero)count++;
        }
        
        if(count==2){
            return {zero,one};
        }
        
        return {one,zero};
    }
};