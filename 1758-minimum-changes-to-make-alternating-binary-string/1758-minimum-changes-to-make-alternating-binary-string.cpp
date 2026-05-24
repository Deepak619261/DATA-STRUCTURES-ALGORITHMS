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
           cost+=s[i]-'0';
        }
        else{
           cost+='1'-s[i];
        }
    }
    ans=min(ans,cost);
    int n=s.size();
    ans=min(ans,n-ans);
    return ans;
        
    }
};