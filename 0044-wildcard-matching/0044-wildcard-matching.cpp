class Solution {

    bool isallstars(int index, string str){

        for(int i=index;i>=0;i--){
            if(str[i]!='*'){
                return false;
            }
        }

        return true;
    }
    int solve(string s,string p , int index1, int index2 , vector<vector<int>>&dp){
        //  base case 
        if(index2<0 && index1<0){
            return true;
        }

        if(index1>=0 && index2<0){
            return false;
        }

        if(index2>=0 && index1<0){
            return isallstars(index2,p);
        }


        if(dp[index1][index2]!=-1){
            return dp[index1][index2];
        }


       
       if(s[index1]==p[index2] || p[index2]=='?'){
        //  means character can be matches 
          return dp[index1][index2]=solve(s,p,index1-1,index2-1,dp);
       }
       else{
        //  if character's don't match -> there may be case of * 
        if(p[index2]=='*'){
            return dp[index1][index2]=solve(s,p,index1-1,index2,dp) || solve(s,p,index1,index2-1,dp);
        }
        else{
            return dp[index1][index2]=false;
        }
       }
    }
public:
    bool isMatch(string s, string p) {
        int n1=s.size();
        int n2=p.size();


        vector<vector<bool>>dp(n1+1,vector<bool>(n2+1,false));
        //  let's do tabulation 

        dp[0][0]=true;

        for(int j=1;j<=n2;j++){
           dp[0][j]=isallstars(j-1,p);
        }

        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){

            if(s[i-1]==p[j-1] || p[j-1]=='?'){
        //  means character can be matches 
        dp[i][j]=dp[i-1][j-1];
       }
       else{
        //  if character's don't match -> there may be case of * 
        if(p[j-1]=='*'){
            dp[i][j]=dp[i-1][j] || dp[i][j-1];
        }
        else{
            dp[i][j]=false;
        }
       }
          
            }
        }

        



        return dp[n1][n2];
        
    }
};