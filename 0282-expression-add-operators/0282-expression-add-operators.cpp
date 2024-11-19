class Solution {
    private:
    void solve(string num,int target ,string sumpath,long sum, long prev,int index, vector<string>&ans){
        if(index==num.size()){
            if(sum==target){
                ans.push_back(sumpath);
            }
            return;
        }


        // for every index we will go for every possiblity it may be start from 1 /2/3
        for(int i=index;i<num.size();i++){
            // there was leading zero case but i'm going without considering that case ..i'll later 
             if(i>index && num[index]=='0'){
                 break;
                //   avoid leading zeros here ..
             }
            // come to realise what it was 


                long number=stol(num.substr(index,i-index+1));
                // simaltaneously we will create string to store the path
                string temppath=num.substr(index,i-index+1);
            if(index==0){
                
                solve(num,target,temppath,number,number,i+1,ans);
            }
            else{
                // go for every possiblity possible 
                // the very first we can go for the plus opreation 
                solve(num,target,sumpath+'+'+temppath,sum+number,number,i+1,ans);

                // then we can go the minus opreation 
                solve(num, target,sumpath+'-'+temppath,sum-number,-number,i+1,ans);
            
                //  then we have to go to the case of multiplication but for that we have undo the previosus
                // opreation before doing further calculation 
                solve(num,target,sumpath+'*'+temppath,sum-prev+(prev*number),prev*number,i+1,ans);

            }
        }
    }
public:
    vector<string> addOperators(string num, int target) {
        // approach by watching the solution section ...
        // in this approach what we are doing is that we are ...creating a string simaltaneously and 
        // storing the result and passing it to the next function ...here is different two cases in case
        //  of when we are just taking the very first 
        vector<string>ans;
        solve(num,target,"",0,0,0,ans);
        return ans;
        
    }
};