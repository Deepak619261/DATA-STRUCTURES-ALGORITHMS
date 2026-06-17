class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(n==0)return; 
        

        int fnp=m+n-1;
        int sp=n-1;
        // if(sp<0)sp=0;
        int fp=m-1;
        // if(fp<0)fp=0;

        while(fnp>=0 && sp>=0){
            if(fp>=0 && nums1[fp]>nums2[sp]){
                nums1[fnp--]=nums1[fp--];
            }
            else{
                nums1[fnp--]=nums2[sp--];
            }
        }
    }
};