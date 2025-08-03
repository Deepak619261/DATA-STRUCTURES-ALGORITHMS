class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        //  first lets check for the very first part 
        if(nums.size()<4)return false;
        bool first=false;
        int i=1;
        
        while(i<nums.size() && nums[i]>nums[i-1]){
              i++;
        }
        // cout<<"prev "<<prev<<","<<i<<endl;

        if(i<nums.size() && i>0)first=true;
        int p=i-1;
        if(p<=0)return false;
        cout<<p<<endl;
        cout<<first<<endl;

        while(i<nums.size() && nums[i-1]>nums[i])i++;

        int q=i-1;
        if(q<=p)return false;

       

        while(i<nums.size() && nums[i-1]<nums[i])i++;

        if(i!=nums.size())return false;

        return q<nums.size()-1;

    }
};