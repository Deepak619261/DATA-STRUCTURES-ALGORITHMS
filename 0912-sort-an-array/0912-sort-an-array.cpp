class Solution {
    void mergeSort(vector<int>&nums , int l , int r){
        if(l>=r)return; 
        int mid=(l+r)/2;

        mergeSort(nums,l,mid);
        mergeSort(nums,mid+1,r);
        merge(nums,l,mid,r);
    }
    void merge(vector<int>&nums,int l , int m , int r){
        int left=l;
        int right=m+1;
        vector<int>temp;

        while(left<=m && right<=r){
            if(nums[left]<nums[right]){
                temp.push_back(nums[left++]);
            }
            else{
                temp.push_back(nums[right++]);
            }
        }

        while(left<=m){
            temp.push_back(nums[left++]);
        }

        while(right<=r){
            temp.push_back(nums[right++]);
        }

        for(int i=l;i<=r;i++){
            nums[i]=temp[i-l];
        }
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        int l=0;
        int r=nums.size()-1;
        mergeSort(nums,l,r);
        return nums;
    }
};