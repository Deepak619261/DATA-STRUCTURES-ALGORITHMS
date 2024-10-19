class Solution {
    vector<int>nextsmallerelement(vector<int>nums){
        int n=nums.size();


        stack<int>st;

        vector<int>ans(n,-1);



        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[i]<=nums[st.top()]){
                st.pop();
            }

            int val=i;

            if(!st.empty()){
                ans[i]=st.top();
            }
            else{
                ans[i]=-1;
            }


            st.push(i);
        }



        return ans;
    }

    vector<int>prevsmallerelement(vector<int>nums){
        int n=nums.size();


        stack<int>st;

        vector<int>ans(n,-1);



        for(int i=0;i<n;i++){
            while(!st.empty() && nums[i]<=nums[st.top()]){
                st.pop();
            }

            int val=i;

            if(!st.empty()){
                ans[i]=st.top();
            }
            else{
                ans[i]=-1;
            }


            st.push(i);
        }



        return ans;
    }
    
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int>indices=nextsmallerelement(heights);
        vector<int>prev=prevsmallerelement(heights);

        int ans=INT_MIN;
        int n=heights.size();

        for(int i=0;i<heights.size();i++){
            int lastind=indices[i];
            int firstind=prev[i];

            if(lastind==-1){
                lastind=n;
            }

            ans=max(ans,heights[i]*(lastind-firstind-1));
        }
        
        return ans;
    }
};