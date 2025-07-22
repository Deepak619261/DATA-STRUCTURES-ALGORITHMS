class Solution {
    int MOD=1e9+7;
public:
    int countTrapezoids(vector<vector<int>>& points) {
       
        unordered_map<int,vector<int>>mpp;

        long long ans=0;

        for(auto it:points){
            mpp[it[1]].push_back(it[0]);
        }
        
        
    vector<long long>prod;

    if(mpp.size()>1){  
        for(auto it:mpp){
            if(it.second.size()>1){
            long long n=it.second.size();
            long long segments=((long long)(n*(n-1))/2)%MOD;
            segments=segments%MOD;
            prod.push_back(segments);
            }
        }
    }

    if(prod.size()<=1)return 0;

    ans=0;

    for(auto it:prod)cout<<it<<" ";

    // for(int i=0;i<prod.size();i++){
    //     for(int j=i+1;j<prod.size();j++){
    //         // ans+=(prod[i]*prod[j])%MOD; -> this can overflow and overflow may lead to undefined behaviour thats why we are getting some negaitve value on large test cases
    //         ans = (ans + (prod[i] * prod[j]) % MOD) % MOD;
    //         // cout<<ans<<" -  "<<i<<j<<endl;
    //     }
    // }
    // long long total=0;
    long long sum = 0, sum_sq = 0;
for (long long val : prod) {
    sum = (sum + val) % MOD;
    sum_sq = (sum_sq + (val * val) % MOD) % MOD;
}
long long total = (sum * sum) % MOD;
total = (total - sum_sq + MOD) % MOD;
total = (total * ((MOD + 1) / 2)) % MOD;

    return (int)total;

    
    }
};