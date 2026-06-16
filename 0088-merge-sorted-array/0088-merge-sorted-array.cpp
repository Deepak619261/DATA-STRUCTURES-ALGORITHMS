class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        //  the very brute force is just fill up the array and just sort it 
        int j=0;
        for(int i=m;i<m+n;i++){
            nums1[i]=nums2[j++];
        }
        sort(nums1.begin(),nums1.end());
    }
};