class Solution {

    void solve(string num, int target , vector<string>&ans,string store,long long sum , long long prev,int index){
        if(index==num.size()){
            if(sum==target){
                ans.push_back(store);
            }

            return ;
        }

        for(int i=index;i<num.size();i++){
        
            if (i > index && num[index] == '0') break;

            long long  number=stoll(num.substr(index,i-index+1));
            string temppath=num.substr(index,i-index+1);

            if(index==0){
                 solve(num,target,ans,temppath,number,number,i+1);
            }
            else{
            solve(num,target,ans,store+'+'+temppath,sum+number,number,i+1);
            solve(num,target,ans,store+'-'+temppath,sum-number,-number,i+1);
            solve(num,target,ans,store+'*'+temppath,(sum-prev)+prev*number,prev*number,i+1);
            }
           
        }
    }
public:
    vector<string> addOperators(string num, int target) {
        vector<string>ans;
        solve(num,target,ans,"",0,0,0);
        return ans;
    }
};