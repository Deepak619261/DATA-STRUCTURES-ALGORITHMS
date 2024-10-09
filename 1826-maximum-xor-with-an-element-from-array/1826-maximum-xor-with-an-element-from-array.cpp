struct Node{
    Node* links[2];

    //  function to insert the bit 
    void put(int bit, Node* node){
        links[bit]=node;
    }

    Node* getnext(int bit){
        return links[bit];
    }

    bool containsKey(int bit){
        return (links[bit]!=NULL);
    }

};

class Trie{
    private: 
    Node* root;

    public:
    Trie(){
        root=new Node();
    }

    void insert(int num){
        Node* temp=root;

        for(int i=31;i>=0;i--){
            int bit=(num>>i)&1;
            if(!temp->containsKey(bit)){
                temp->put(bit,new Node());
            }
            temp=temp->getnext(bit);
        }

    }

    // get maxfunction 

    int getmax(int num){
        int ans=0;
        Node* temp=root;

        for(int i=31;i>=0;i--){
            int bit=(num>>i)&1;
            int dash_bit=1-bit;


            if(temp->containsKey(dash_bit)){
              int to_or=(1<<i);   // we are oring the xor of bit and dashbit 
              ans=ans|to_or;
              temp=temp->getnext(dash_bit);
            }
            else{
                temp=temp->getnext(bit);
            }
            
        }

        return ans;
    }
};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
     Trie T;
    
     sort(nums.begin(),nums.end());
     int n=queries.size();
     vector<int>ans(n);

     vector<pair<int,pair<int,int>>>off_Q;

     for(int i=0;i<n;i++){
         off_Q.push_back({queries[i][1],{queries[i][0],i}});
        //  mi xi index
     }
     
     sort(off_Q.begin(),off_Q.end());
     int j=0;

     for(int i=0;i<n;i++){
        int threshold=off_Q[i].first;
        int num=off_Q[i].second.first;
        int ind=off_Q[i].second.second;

        while(j<nums.size() && nums[j]<=threshold){
           T.insert(nums[j]);
           j++;
        }

        if(j==0){
            ans[ind]=-1;
        }
        else{
            ans[ind]=T.getmax(num);
        }

     }

     return ans;
        
    }
};