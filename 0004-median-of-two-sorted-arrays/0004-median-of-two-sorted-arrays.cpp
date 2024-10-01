class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        //  we are considering the very first array as shorter array 
       
        if(nums1.size()>nums2.size()){
            return findMedianSortedArrays(nums2,nums1);
        }

        //  define the search space that will be the 0 to n1
        int low=0;
        int high=nums1.size();
        int n=nums1.size()+nums2.size();

        int left=(n+1)/2;

        

        while(low<=high){
            int mid1=(low+high)/2;
            int mid2=left-mid1;
            int l1=INT_MIN;
            int l2=INT_MIN;

            if(mid1-1>=0) l1=nums1[mid1-1];
            if(mid2-1>=0) l2=nums2[mid2-1];
            
            int r1=INT_MAX;
            int r2=INT_MAX;
            

            if(mid1<nums1.size()) r1=nums1[mid1];
            if(mid2<nums2.size()) r2=nums2[mid2];

            if(l1<=r2 && l2<=r1){
                if(n%2!=0){
                    return max(l1,l2);
                }
                else{
                    return  (double)(max(l1,l2)+min(r1,r2))/2.0;
                }
            }
            else if(l2>r1){
                low=mid1+1;
            }
            else{
                high=mid1-1;
            }

        }

        return 0;

    }
};