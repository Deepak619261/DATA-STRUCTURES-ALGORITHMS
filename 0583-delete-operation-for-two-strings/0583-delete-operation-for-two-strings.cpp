class Solution {
    int findlcs(string str1, string str2){
        int n1=str1.size();
        int n2=str2.size();

        vector<int>prev(n2+1,0);

        for(int i=1;i<=n1;i++){
            vector<int>curr(n2+1,0);
            for(int j=1;j<=n2;j++){
                if(str1[i-1]==str2[j-1]){
                    curr[j]=1+prev[j-1];
                }
                else{
                    curr[j]=max(curr[j-1],prev[j]);
                }
            }
            prev=curr;
        }

        return prev[n2];
    }
public:
    int minDistance(string word1, string word2) {

        int lcslen=findlcs(word1,word2);
        cout<<lcslen;


        //  as we require number of deletion to make the string same
        return (word1.size()-lcslen)+(word2.size()-lcslen);
        
    }
};