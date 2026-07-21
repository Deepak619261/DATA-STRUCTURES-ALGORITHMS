class Solution {
public:
    int trap(vector<int>& height) {
        //  just maintain the two array representing the max of prefix and max suffix 

        int n=height.size();

        vector<int>prefix(n,0);
        vector<int>suffix(n,0);
        prefix[0]=height[0];
        suffix[n-1]=height[n-1];

        for(int i=1;i<height.size();i++){
            prefix[i]=max(height[i],prefix[i-1]);
        }

        for(int i=n-2;i>=0;i--){
            suffix[i]=max(height[i],suffix[i+1]);
        } 

        // for(auto it:suffix){
        //     cout<<it<<" ";
        // }

        int answer=0;

        for(int i=1;i<n-1;i++){
            int leftmax=prefix[i];
            int rightmax=suffix[i];

            // cout<<"for index "<<i<<" the leftmax is"<<leftmax<<" and rightmax is "<<rightmax<<endl;

            if(height[i]<leftmax && height[i]<rightmax){
                answer+=(min(leftmax,rightmax)-height[i]);
            // cout<<" the answer we are adding is "<<(min(leftmax,rightmax)-height[i])<<endl;
            }
        }

        return answer;
    }
};