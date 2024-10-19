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
public:
    int maximalRectangle(vector<vector<char>>& matrix) {

        vector<int>temp(matrix[0].size(),0);

        for(int i=0;i<matrix[0].size();i++){
            if(matrix[0][i]=='1'){
                temp[i]=1;
            }
        }

        int ans=INT_MIN;
        ans=max(ans,largestRectangleArea(temp));
        
        for(int i=1;i<matrix.size();i++){
            
            for(int j=0;j<matrix[i].size();j++){
                if(matrix[i][j]=='0'){
                    temp[j]=0;
                }
                else{
                    char ch=matrix[i][j];
                    if(ch=='1'){
                        temp[j]+=1;
                    }
                }
            }
            cout<<"row number"<<i<<endl;
            for(auto it:temp){
                cout<<it<<"";
            }

            ans=max(ans,largestRectangleArea(temp));
        }

        return ans;
    }
};