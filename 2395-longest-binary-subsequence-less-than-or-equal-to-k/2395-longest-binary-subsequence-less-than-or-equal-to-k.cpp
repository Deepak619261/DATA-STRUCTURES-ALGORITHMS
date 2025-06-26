class Solution {
public:
    int longestSubsequence(string s, int k) {
         // watched from the solution section 
         
         int count=0;

         int lastone=0;
         int num=k;
         int i=0;

         while(i<32){
            if((num>>i)&1){
                lastone=i;
            }
            i++;
         }
         cout <<lastone<<endl;
         int bits=lastone+1;
         int sm=0;

         for(int i=0;i<s.size();i++){
            char ch=s[s.size()-i-1];
            if(ch=='1'){
               if(i<bits && sm+(1<<i)<=k){
                count++;
                sm+=(1<<i);
               }

            }
            else{
                count++;
            }
         }



        return count;

    }
};