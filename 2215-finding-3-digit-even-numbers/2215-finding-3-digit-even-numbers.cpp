class Solution {
    bool valid(int x, int y , int z , unordered_map<int,int>mpp){
        if(mpp[x]<=0)return false;
        else{
            mpp[x]--;
        }
        if(mpp[y]<=0)return false;
        else{
            mpp[y]--;
        }
        if(mpp[z]<=0)return false;
        else{
            mpp[z]--;
        }

        return true;

    }
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int>ans;

        unordered_map<int,int>mpp;

        for(auto it:digits){
            mpp[it]++;
        }
        
        for(int i=100;i<=999;i++){
           int num=i;
           int x=num%10;
           num=num/10;
           int y=num%10;
           num=num/10;
           int z=num%10;
           if(valid(x,y,z,mpp) && i%2==0)ans.push_back(i);

        }

        return ans;
    }
};