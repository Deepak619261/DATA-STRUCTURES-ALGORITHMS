class DisjointSet{

    public:
    vector<int>parent,size;
    DisjointSet(int n){
        parent.resize(n+1,0);
        size.resize(n+1,1);


        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }

    // find parent fucntion 
    int findPar(int node){
        if(node==parent[node]){
            return node;
        }

        // else do the backtracking with path compression 
        return parent[node]=findPar(parent[node]);
    }


    void unionbySize(int a , int b){
        // first of all find their ultimate parent 
        int ulp_a=findPar(a);
        int ulp_b=findPar(b);

        if(ulp_a==ulp_b){
            // they are already connected , we don't need to union them 
            return ;
        }

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
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        
        DisjointSet DS(s.size());

        for(auto it:pairs){
            DS.unionbySize(it[0],it[1]);
        }


        map<int,priority_queue<char>>mpp;

        for(int i=0;i<s.size();i++){
            mpp[DS.findPar(i)].push(s[i]);
        }

        for(int i=s.size()-1;i>=0;i--){
            s[i]=mpp[DS.findPar(i)].top();
            mpp[DS.findPar(i)].pop();
        }

        return s;
    }
};