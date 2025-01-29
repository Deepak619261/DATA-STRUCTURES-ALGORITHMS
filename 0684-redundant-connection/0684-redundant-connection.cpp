class DisjointSet{
     public:
     vector<int>parent,size;
     DisjointSet(int n){
        parent.resize(n+1,1);
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
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        // refers to the dynamic graph , so we can use here Disjoint set
        int n=edges.size();
        DisjointSet DS(n);
        vector<int>ans;

        for(auto it:edges){
            if(DS.findPar(it[0])==DS.findPar(it[1]))return it;
            DS.unionBYsize(it[0],it[1]);
        }

        return ans;
    }
};