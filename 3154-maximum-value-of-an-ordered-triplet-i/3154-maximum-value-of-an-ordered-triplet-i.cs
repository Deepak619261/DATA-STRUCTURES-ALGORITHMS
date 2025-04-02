public class Solution {
    public long MaximumTripletValue(int[] nums) {
        long ans=0;
        int n=nums.Length;

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    long check=(nums[i] - nums[j]);
                    check=check*(nums[k]);
                    if(check>0){
                        ans=Math.Max(ans,check);
                    }
                }
            }
        }
    return ans;
    }
}