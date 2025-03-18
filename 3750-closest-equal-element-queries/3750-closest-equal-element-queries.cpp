class Solution {
   // int getmin(int ind , int it , int size){
   //     return ;
   // }
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        unordered_map<int,vector<int>>mpp;
        

        for(int i=0;i<nums.size();i++){
            mpp[nums[i]].push_back(i);
        }

        int n=queries.size();
        // vector<int>ans(n,0);

        int size=nums.size();

// the problem with this approach is that if we consider the worst case possible then it may take O(n^2) as the constraints are the same for the query length and array length , instead we will traverse the map's entries because think logically it may take at most O(N) because unique elements will be there only so i am going with the another appraoch i have seen from the solutions 
    /*    for(int i=0;i<n;i++){
            int ind=queries[i];
            int ele=nums[ind];
            if(mpp[ele].size()==1){
                ans[i]=-1;
            }
            else{
                int dist=INT_MAX;
                // cout<<ind<<endl;
                for(auto it:mpp[ele]){
                    
                    if(it==ind)continue;
                    
                   
                    
                    dist=min(dist,min(abs(ind-it),min(size-ind+it,size-it+ind)));
                }
                // cout<<endl;
                ans[i]=dist;
            }
        }

        return ans;*/

        vector<int>dist(size,0);
        for(auto it:mpp){
            vector<int>temp=it.second;
            if(temp.size()==1){
                dist[temp[0]]=-1;
            }
            else{
                // there may exist the min distance in only two ways , between the very next index or the very last considering the circular nature of the array
                int len=temp.size(); 
                for(int i=0;i<len;i++){
                    int next_ind=temp[(i+1+len)%len];
                    int prev_ind=temp[(i-1+len)%len];
                    int forward_dist=min(abs(temp[i]-next_ind),size-temp[i]-1+next_ind+1);
                    int backward_dist=min(abs(temp[i]-prev_ind),temp[i]+(size-prev_ind)); // here we are taking minimum of the both distance calculated  , one is we can take the direct back calculation or we can go circulary and take the min of both as in diff cases , diff minimum will be there 
                    dist[temp[i]]=min(forward_dist,backward_dist);
                }
            }
        }


        vector<int>ans(n,0);

       for(int i=0;i<n;i++){
          ans[i]=dist[queries[i]];
       }

       return ans;


    }
};