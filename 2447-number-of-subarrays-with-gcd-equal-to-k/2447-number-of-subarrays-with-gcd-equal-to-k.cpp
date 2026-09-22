class Solution {
    int gcd(int a, int b){
        while(a>0 && b>0){
            if(a>b){
                a=a%b;
            }
            else{
                b=b%a;
            }
        }
        if(a==0)return b;
        return a;
    }
public:
    int subarrayGCD(vector<int>& nums, int k) {
        

        int n=nums.size();
        if(n==1){
            if(nums[0]==k)return 1;
            return 0;
        }
        
        int count=0;
        
        for(int i=0;i<n;i++){
            int g=-1;
                // cout<<"subarray starting from :  "<<i<<endl;
            for(int j=i;j<n;j++){
                if(g==-1){
                    g=nums[j];
                }
                else{
                    g=gcd(nums[j],g);
                }
                // cout<<" at element "<<nums[j]<<" the gcd is "<<g<<endl;
                if(g==k)count++;
            }
        }

        return count;


    }
};