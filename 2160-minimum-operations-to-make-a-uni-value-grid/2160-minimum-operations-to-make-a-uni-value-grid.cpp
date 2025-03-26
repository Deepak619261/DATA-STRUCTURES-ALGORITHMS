class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        // rule number 1 -> whenever see the 2-d matrix except traversal thing -> start thinking by taking them as linear 1d array 
        // thought process ,lets thought about optimization later first see all the number as 1 1D array 

        vector<int>arr;
        int rem=grid[0][0]%x;

        for(auto it:grid){
            for(auto it2:it){
                if(it2%x!=rem)return -1;
                arr.push_back(it2);
            }
        }
        // thing is we want to make all the numbers equal then we must have a comman target(among the numbers) so that we can reach , -> median defintion is that if we find a number which minimizes the absolute difference between that median and all the dataset -> median -> for odd len -> its mid -> for even -> mid and mid-1 avg 
        // if lets suppose that median is T -> we want that for every integer it should be valid abs(T-ai)%x should be either zero (T-ai)%x is only zero when T%x and ai%x must be equal 
        // other observation we want all numbers to be same , and we have the fixed x to add/subtract in that case its very important that remainder should be same ,else we won;t we able to do so 

        sort(arr.begin(),arr.end());
        int len=arr.size();

        int median=0;

        
        median=arr[len/2];
        
    

        int ans=0;

        for(auto it:arr){
            ans+=abs(median-it)/x;
        }

        return ans;

    }
};