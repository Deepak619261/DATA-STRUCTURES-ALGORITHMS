class Solution {
public:
    int maxScore(string s) {
        // just trying the random appraoch came in my mind after seeing this problem 
        vector<int>presum;

        int cnt=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='0'){
                cnt++;
            }
            presum.push_back(cnt);
        }

        cnt=0;

        int ans=INT_MIN;

        for(int i=s.size()-1;i>0;i--){
            if(s[i]=='1')cnt++;

            ans=max(ans,cnt+presum[i-1]);
        }

        return ans;

        
    }
};