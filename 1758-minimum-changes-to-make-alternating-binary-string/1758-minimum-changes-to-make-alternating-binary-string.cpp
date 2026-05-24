class Solution {
public:
    int minOperations(string s) {

        // this is the sibling of the question 3937
    //    pairs will be -> (0,1) or (1,0)
    int ans=INT_MAX;
    //(0,1)
        int cost=0;
    for(int i=0;i<s.size();i++){
        if(i%2==0){
           int diff=abs(s[i]-'0');
           cost+=min(diff,2-diff);
        }
        else{
           int diff=abs(s[i]-'1');
           cost+=min(diff,2-diff);
        }
    }
    ans=min(ans,cost);
    cost=0;

      for(int i=0;i<s.size();i++){
        if(i%2==0){
           int diff=abs(s[i]-'1');
           cost+=min(diff,2-diff);
        }
        else{
           int diff=abs(s[i]-'0');
           cost+=min(diff,2-diff);
        }
    }

    ans=min(ans,cost);
    return ans;
        
    }
};