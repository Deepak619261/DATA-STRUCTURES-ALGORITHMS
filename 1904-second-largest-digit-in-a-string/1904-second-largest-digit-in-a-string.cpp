class Solution {
public:
    int secondHighest(string s) {
        int maxi=-1;
        int maxi_s=-1;

        for(auto it:s){
            if(isdigit(it)){
                int num=it-'0';
                if(num>maxi){
                    maxi_s=max(maxi_s,maxi);
                    maxi=num;
                }
                else if(num<maxi && num>maxi_s){
                    maxi_s=num;
                }
            }
        }
        return maxi_s;
    }
};