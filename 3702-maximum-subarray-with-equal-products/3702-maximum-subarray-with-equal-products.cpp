class Solution {
    int gcd(int a, int b){
        int GCD=1;
        int x=a;
        int y=b;

        if(b>a){
            x=b;
            y=a;
        }

        while(x!=1 && y!=1){
            if(x%y==0){
                GCD=y;
                return GCD;
            }
            else{
                int res=x-y;
                if(res>y){
                    x=res;
                }
                else{
                    x=y;
                    y=res;
                }
            }
        }


        return GCD;
    }

    int lcm(int a, int b){
        return (a*b)/gcd(a,b);
    }

   

   
    


    pair<int,int> getgcdlcm(vector<int>&nums,int a, int b){
        if(a==b){
            return {nums[a],nums[a]};
        }
        int ans=nums[a];
        int ans2=lcm(nums[a],nums[a+1]);
        

    
    
        for(int i=a;i<=b;i++){
            ans=gcd(ans,nums[i]); 
            if(i-a>1){
                ans2=lcm(ans2,nums[i]);
            }
        }

        return {ans,ans2};
        
    }
public:
    int maxLength(vector<int>& nums) {
        unsigned long long prod=1;

        int ans=INT_MIN;

        //  check every subarray 
        for(int i=0;i<nums.size();i++){
            prod=1;
            for(int j=i;j<nums.size();j++){
                prod*=nums[j];
                int gcd=getgcdlcm(nums,i,j).first;
                int lcm=getgcdlcm(nums,i,j).second;
                cout<<gcd<<" ";
                cout<<lcm<<" ";
                if(prod==(gcd*lcm)){
                    ans=max(ans,j-i+1);
                }
            }
        }

        return ans;
    }
};