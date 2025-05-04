class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        // simple approach i got to know after seeing solution , is that you can see you can have only 6 option for every tile so you can simply check 
        int ans=INT_MAX;
        for(int i=1;i<7;i++){
            int rot=0;
            bool flag=true;
            for(int j=0;j<tops.size();j++){
                if(tops[j]==i){
                    continue;
                }
                else{
                    if(bottoms[j]==i){
                        rot++;
                    }
                    else{
                        flag=false;
                        break;
                    }
                }
            }
            if(flag){
                ans=min(ans,rot);
            }
        }

        for(int i=1;i<7;i++){
            int rot=0;
            bool flag=true;
            for(int j=0;j<bottoms.size();j++){
                if(bottoms[j]==i){
                    continue;
                }
                else{
                    if(tops[j]==i){
                        rot++;
                    }
                    else{
                        flag=false;
                        break;
                    }
                }
            }
            if(flag){
                ans=min(ans,rot);
            }
        }


        if(ans==INT_MAX)return -1;

        return ans;
    }
};