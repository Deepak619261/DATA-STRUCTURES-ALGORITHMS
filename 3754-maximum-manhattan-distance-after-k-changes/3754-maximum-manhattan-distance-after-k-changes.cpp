class Solution {
public:
    int maxDistance(string s, int k) {
        // one of the approach is that see , if we want to maximize the distance than we would like to change the just opposite of the most occuring character , lets say N is a lot of time then we would like to spend our k on characters containing S , if second largest element is lets say is E then we would like to spend the k on characteres like W to reduce the distance because manhatten distance basically absolute sum of x and y coordinate , so we want out dist to be maximum , we are being greedy here 
        // although the approach i saw is something different it says trying all the combinations of selecting two combinations of direction and maximize each time take the maximum answer stored 
        // that will take if we are selecting 2 elements out of 4 element 
        // we can take any two with any two 
        // although i understood the solution but didn't get the intution , i was thinking about every possibilty and going towards DP (recursion )
        int ans=INT_MIN;

        vector<char>one={'N','S'};
        vector<char>two={'E','W'};

        

        for(auto it1:one){
            for(auto it2:two){
                // reset coordinates for every iteration 
                int K=k;
                int xi=0;
                int yi=0;
                int curr=0;
                for(int i=0;i<s.size();i++){
                   if(s[i]==it1 || s[i]==it2){
                    curr++;
                   }
                   else{
                    if(K>0){
                       curr++;
                       K--;
                    }
                    else{
                        curr--;
                    }
                   }
                   ans=max(curr,ans);
                }

            }
        }

        return ans;
    }
};