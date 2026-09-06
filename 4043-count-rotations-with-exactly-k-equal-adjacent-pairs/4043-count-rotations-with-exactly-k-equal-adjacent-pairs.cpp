class Solution {
    int score(string s){
        int n=s.size();
        int count=0;
        for(int i=0;i<n-1;i++){
            if(s[i]==s[i+1]){
                count++;
            }
        }
        return count;
    }
public:
    int countRotations(string s, int k) {
        int ans=0;
        int n=s.size();
        string temp=s;

        for(int i=0;i<n;i++){
            // pop from 0 to i and put into the back of the temp 
            rotate(temp.begin(),temp.begin()+i,temp.end());
            if(score(temp)==k)ans++;
            rotate(temp.begin(),temp.begin()+n-i,temp.end());
            // check the score and increment if score is equals to k 
        }
        // brute force O(N^2) which is fine 10^6

        return ans;
        
    }
};