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
    int countServers(vector<vector<int>>& grid) {
        // we will store the nodes in form of i*m+j that will assign a numbr to the grids 
        // we will initiate a disjoint set of maximum node size 
        // once created the disjoint set then we will iterate over the every server and we will just find its ultimate parent and if its size is greater than 1 than we will just , increment oour count 

        int m=grid.size();
        int n=grid[0].size();
        int total=0;

        DisjointSet ds(m+n);

        map<int,int>mpp;
    
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]){
                   total++;
                   mpp[i]=1;
                   mpp[j+m]=1;
                   ds.unionbySize(i,j+m);      
                }
            }
        }

        int cnt=0;

        for(auto it : ds.size){
            cout<<it<<" ";
        }


        for(auto it:mpp){
           int ultimate_parent=ds.findPar(it.first);
           if(ds.size[ultimate_parent]==2){
            cnt++;
            // cout<<"hhhh"<<endl;
           }
        }

        return total-(cnt/2);
    }
};