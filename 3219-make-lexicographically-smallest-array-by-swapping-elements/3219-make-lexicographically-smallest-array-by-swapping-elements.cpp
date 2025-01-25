class DisjointSet{
   public: 
   vector<int>parent,size;
   DisjointSet(int n){
    parent.resize(n+1);
    size.resize(n+1);

    for(int i=0;i<=n;i++){
        parent[i]=i;
    }
   }

   int findPar(int node){
    if(node==parent[node])return node;

    return parent[node]=findPar(parent[node]);
   }


   void unionBYsize(int a, int b){
    int ulp_a=findPar(a);
    int ulp_b=findPar(b);

    if(ulp_a==ulp_b)return;

    if(size[ulp_a]>size[ulp_b]){
        parent[ulp_b]=ulp_a;
        size[ulp_a]+=size[ulp_b];
    }
    else{
        parent[ulp_a]=ulp_b;
        size[ulp_b]+=size[ulp_a];
    }
   }
};

class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
           vector<pair<int,int>>temp;

           for(int i=0;i<nums.size();i++){
              temp.push_back({nums[i],i});
           } 

           sort(temp.begin(),temp.end());

           DisjointSet DS(nums.size());

           for(int i=1;i<temp.size();i++){
              if(abs(temp[i].first-temp[i-1].first)<=limit){
                DS.unionBYsize(temp[i].second,temp[i-1].second);
              }
           }

           map<int,priority_queue <int, vector<int>, greater<int>>>mpp;

           for(int i=0;i<nums.size();i++){
               mpp[DS.findPar(i)].push(nums[i]);
           }

           for(int i=0;i<nums.size();i++){
              nums[i]=mpp[DS.findPar(i)].top();
              mpp[DS.findPar(i)].pop();
           }

           return nums;
    }
};