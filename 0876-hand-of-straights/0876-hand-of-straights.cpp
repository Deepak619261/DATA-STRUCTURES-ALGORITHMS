class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size()%groupSize!=0){
            return false;
        }

        map<int,int>mpp;

        for(int h:hand){
            mpp[h]++;
        }

        while(!mpp.empty()){
            auto start=mpp.begin();
            int firstelement=start->first;

            for(int i=0;i<groupSize;i++){
                int num=firstelement+i;
                if(mpp[num]==0){
                    return false;
                }
                mpp[num]--;
                if(mpp[num]==0){
                    mpp.erase(num);
                }
            }
        }

        return true;
    }
};