class Solution {
    int count=0;
    // void countPair(int s, int mid ,int e , vector<int>&nums){
      
    // }
    void MergeSort(int s,int e,vector<int>&nums){
        if(s>=e)return;
        int mid=(s+e)/2;

        MergeSort(s,mid,nums);
        MergeSort(mid+1,e,nums);
        // countPair(s,mid,e,nums);
        Merge(s,mid,e,nums);
    }

    void Merge(int s, int mid , int e, vector<int>&nums){
        vector<int>temp;

        int first=s;
        int second=mid+1;

        int right=mid+1;
        for(int i=s;i<=mid;i++){
            while(right<=e && (long long)nums[i]>(long long)2*(long long)nums[right]){
                right++;
            }
            count+=(right-(mid+1));
         }

        while(first<=mid && second<=e){
            // if((long long)nums[first]>(long long)2*(long long)nums[second])count++;
            if(nums[first]<nums[second]){
                temp.push_back(nums[first]);
                first++;
            }
            else{
                temp.push_back(nums[second]);
                second++;
            }
        }

        while(first<=mid){
            temp.push_back(nums[first]);
            first++;
        }

        while(second<=e){
            temp.push_back(nums[second]);
            second++;
        }

        for(int i=s;i<=e;i++){
            nums[i]=temp[i-s];
        }
    }
public:
    int reversePairs(vector<int>& nums) {
        //  the most brute force that comes to th emind is 
      

        MergeSort(0,nums.size()-1,nums);

        return count;
    }
};