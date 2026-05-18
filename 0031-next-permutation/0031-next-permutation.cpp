class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int ind=-1;
        
        int n=nums.size();

        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                cout<<nums[i]<<" < "<<nums[i+1];
                ind=i;
                break;
            }
        }

        if(ind==-1){
            reverse(nums.begin(),nums.end());
            return;
        }
        cout<<"ind := "<<ind<<endl;

        for(int i=n-1;i>ind;i--){
            cout<<"if "<<nums[ind]<<" < "<<nums[i]<<endl;
            if(nums[i]>nums[ind]){
                swap(nums[i],nums[ind]);
                cout<<"swapping index "<<i<<endl;
                break;
            }
        }
        cout<<endl;

        cout<<"nums after swap  ";
        for(auto it:nums){
            cout<<it<<" ";
        }
        cout<<endl;

        reverse(nums.begin()+ind+1,nums.end());
        
        
    }
};