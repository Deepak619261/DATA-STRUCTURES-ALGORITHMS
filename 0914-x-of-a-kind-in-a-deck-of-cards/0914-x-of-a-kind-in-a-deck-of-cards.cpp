class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int,int>mpp;
        // for(auto it:deck){
        //     mpp[it]++;
        // }

        for(auto it:deck){
            mpp[it]++;
        }

        for(int i=2;i<1e4;i++){
            bool flag=true;
            for(auto it:mpp){
                if(it.second%i!=0){
                   flag=false;
                   continue;
                }
            }
            if(flag)return true;
        }

        return false;


    }
};