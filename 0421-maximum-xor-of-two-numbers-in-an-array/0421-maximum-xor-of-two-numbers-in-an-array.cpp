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
    int findMaximumXOR(vector<int>& nums) {
      Trie T;

      for(auto it : nums){
        T.insert(it);
      }

      int ans=0;

      for(auto it:nums){
        ans=max(ans,T.getmax(it));
      }

      return ans;
    }
};