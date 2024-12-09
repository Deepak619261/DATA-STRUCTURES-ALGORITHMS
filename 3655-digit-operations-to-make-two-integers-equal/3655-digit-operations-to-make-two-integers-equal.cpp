class Solution {
public:
    int minOperations(int n, int m) {
        //  approach is to use Dijkstra Algorithm 
        //  first generate a array to get prime check in one go 

        



        vector<int>isPrime(1e5+1,1);

        //  sieve of erastonese 
        isPrime[0]=isPrime[1]=0;

        for(int i=2;i*i<=1e5;i++){
            if(isPrime[i]==1){
                for(int j=i*i;j<=1e5;j+=i){
                    isPrime[j]=0;
                }
            }
        }

        if(isPrime[m] || isPrime[n])return -1;

        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>> >pq;
        map<int,int>mpp;
        pq.push({n,n});
        
        

        while(!pq.empty()){
            auto it=pq.top();
            int cost=it.first;
            int num=it.second;
            pq.pop();
            if(mpp.find(num)!=mpp.end())continue;
            mpp[num]++;

            if(num==m)return cost;

            string str=to_string(num);

            for(int i=0;i<str.size();i++){
                char original=str[i];

                if(str[i]<'9'){
                    str[i]++;
                    int next=stoi(str);
                    if(!isPrime[next] && mpp.find(next)==mpp.end()){
                        pq.push({cost+next,next});
                    }
                    str[i]=original;
                }

                if(str[i]>'0' && !(i == 0 && str[i] == '1')){
                    str[i]--;
                    int next=stoi(str);
                    if(!isPrime[next] && mpp.find(next)==mpp.end()){
                        pq.push({cost+next,next});
                    }
                    str[i]=original;                
                }

            }

        }











        return -1;
    }
};