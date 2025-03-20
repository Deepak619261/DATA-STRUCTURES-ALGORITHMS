class Solution {
    int diff=INT_MAX;
    int ans=INT_MAX;
    // declare the global varialbe to consider every and each possibility 

    void explore(int b ,int index,vector<int>&toppingCosts,int target){
                if(abs(b-target)<diff){
                    diff=abs(b-target);
                    ans=b;
                }
                else if(abs(b-target)==diff){
                    ans=min(ans,b);
                }

                if(index==toppingCosts.size()){
                    return;
                }

                // there exists only three possibility either we take one topping , we can take two toppings , or we can leave every toppings 
                explore(b,index+1,toppingCosts,target);
                explore(b+toppingCosts[index],index+1,toppingCosts,target);
                explore(b+2*toppingCosts[index],index+1,toppingCosts,target);
                
    }
public:
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        
            for(int i=0;i<baseCosts.size();i++){
                int b=baseCosts[i];
                if(abs(b-target)<diff){
                    diff=abs(b-target);
                    ans=b;
                }
                else if(abs(b-target)==diff){
                    ans=min(ans,b);
                }
                explore(b,0,toppingCosts,target);
            }

            return ans;

            // mistake , didn't understood the problem correcttly -> read the question correctly , understand it throughly 
    }
};