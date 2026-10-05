class Solution {
public:
    long long maxScore(vector<int>& nums) {
        int n=nums.size();
        vector<long long>pregcd(n,1);
        vector<long long>prelcm(n,1);
        vector<long long>postgcd(n,1);
        vector<long long>postlcm(n,1);

        pregcd[0]=nums[0];
        prelcm[0]=nums[0];
        postgcd[n-1]=nums[n-1];
        postlcm[n-1]=nums[n-1];


        for(int i=1;i<n;i++){
            pregcd[i]=gcd(pregcd[i-1],nums[i]);
            prelcm[i]=lcm(prelcm[i-1],nums[i]);
        }

        for(int i=n-2;i>=0;i--){
            postgcd[i]=gcd(postgcd[i+1],nums[i]);
            postlcm[i]=lcm(postlcm[i+1],nums[i]);
        }
        long long maxi=postgcd[0]*postlcm[0];
        if(n==1)return maxi;


        for(int i=0;i<n;i++){
            if(i==0){
                maxi=max(maxi,postgcd[i+1]*postlcm[i+1]);
            }
            else if (i==n-1){
               maxi=max(maxi,pregcd[i-1]*prelcm[i-1]);
            }
            else{

                maxi=max(maxi,gcd(pregcd[i-1],postgcd[i+1])*lcm(prelcm[i-1],postlcm[i+1]));

            }
            
        }
        return maxi;
    }
};