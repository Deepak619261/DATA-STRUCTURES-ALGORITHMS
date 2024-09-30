class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        //  extreme brute force
        vector<int>sortedArr;
        int first=0;
        int second=0;

        while(first<nums1.size() && second<nums2.size()){
            if(nums1[first]<=nums2[second]){
                sortedArr.push_back(nums1[first++]);
            }
            else{
                sortedArr.push_back(nums2[second++]);
            }
        }

        while(first<nums1.size()){
            sortedArr.push_back(nums1[first++]);
        }

        while(second<nums2.size()){
            sortedArr.push_back(nums2[second++]);
        }


        int n=sortedArr.size();
        if(n%2!=0){
            return (double)sortedArr[n/2];
        }


        double sum=sortedArr[n/2]+sortedArr[(n/2)-1];
        sum=sum/(double)2;
        return sum;
    }
};