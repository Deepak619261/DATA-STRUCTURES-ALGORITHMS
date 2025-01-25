class DisjointSet{
    public:
    vector<int>parent,size;
    DisjointSet(int n){
        parent.resize(n+1);
        size.resize(n+1,1);

        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }

    int findPar(int node){
        if(node==parent[node]){
            return node;
        }

        return parent[node]=findPar(parent[node]);
    }

    void unionBysize(int u , int v){
        int ulp_u=findPar(u);
        int ulp_v=findPar(v);

        if(ulp_u==ulp_v)return;

        if(size[ulp_u]>size[ulp_v]){
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
        else{
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
    }
};

class Solution {
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        DisjointSet DS(source.size());

        for(auto it:allowedSwaps){
            DS.unionBysize(it[0],it[1]);
        }

        unordered_map<int,unordered_map<int,int>>mpp;

        for(int i=0;i<source.size();i++){
            mpp[DS.findPar(i)][source[i]]++;
        }

        int count=0;

        for(int i=0;i<target.size();i++){
            int num=target[i];
            if(mpp[DS.findPar(i)].find(num)==mpp[DS.findPar(i)].end()){
                count++;
            }
            else{
                mpp[DS.findPar(i)][num]--;
                if(mpp[DS.findPar(i)][num]==0){
                    mpp[DS.findPar(i)].erase(num);
                }
            }
        }

        return count;
    }
};