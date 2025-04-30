class Solution {
    int getdigits(int num){
        int count=0;

        while(num){
            num=num/10;
            count++;
        }
        return count;
    }
public:
    int findNumbers(vector<int>& nums) {
        // the very brute force way is to just count the number of every digit one by one 
        int ans=0;

        for(auto it:nums){
            if(getdigits(it)%2==0)ans++;
        }

        return ans;
    }
};