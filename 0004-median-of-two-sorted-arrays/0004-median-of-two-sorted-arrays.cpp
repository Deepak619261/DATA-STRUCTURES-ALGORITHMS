class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int total=nums1.size()+nums2.size();
        int firstInd=total/2;
        int secondInd=firstInd-1;

        int i=0;
        int j=0;
        int cnt=0;
        double first=0;
        double second=0;

        while(i<nums1.size() && j<nums2.size()){
             if(nums1[i]<=nums2[j]){
                if(cnt==firstInd) first=nums1[i];
                if(cnt==secondInd) second=nums1[i];
                i++;
                cnt++;
             }
             else{
                if(cnt==firstInd) first=nums2[j];
                if(cnt==secondInd) second=nums2[j];
                j++;
                cnt++;
             }
        }

        while(i<nums1.size()){
              if(cnt==firstInd) first=nums1[i];
              if(cnt==secondInd) second=nums1[i];
              i++;
              cnt++;
        }

        while(j<nums2.size()){
             if(cnt==firstInd) first=nums2[j];
             if(cnt==secondInd) second=nums2[j];
             j++;
             cnt++;
        }

        if(total%2!=0){
            return first;
        }
        
        double ans=(double)(first+second)/2.00;
        return ans;
    }
};