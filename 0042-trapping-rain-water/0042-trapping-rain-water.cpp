class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();

        //  two pointer apporaoch 
        int left=0;
        int right=n-1;

        int leftmax=0;
        int rightmax=0;
        //  the whole idea resolves around the idea of water trapped as min(nums[left],nums[right])-nums[i]
        int ans=0;


        while(left<=right){
            if(height[left]<=height[right]){
                //  means min will be on the left side which is needed to calcuate the answer
                if(leftmax<=height[left]){
                    leftmax=height[left];
                }
                else{
                    ans+=leftmax-height[left];
                }
                left++;
            }
            else{
                if(rightmax<=height[right]){
                    rightmax=height[right];
                }
                else{
                    ans+=rightmax-height[right];
                }
                right--;
            }
        }


        return ans;

        
    }
};