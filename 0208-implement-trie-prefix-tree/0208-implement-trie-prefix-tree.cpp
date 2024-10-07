struct Node{
    //  an array of nodes to store the every lowercase letter
    Node* Links[26];
    bool flag=false;

    bool containsKey(char ch){
        return (Links[ch-'a']!=NULL);
    }

    void put(char ch, Node* next){
        //  linked a new Node to the current node 
            Links[ch-'a']=next;
    }

    Node* getnextNode(char ch){
        return Links[ch-'a'];
    }
    
    void setendFlag(){
        flag=true;
    }

    bool isEndSet(){
        return flag;
    }
};
class Trie {
    private:
    Node* root;
public:
    Trie() {
        root=new Node();
    }
    
    void insert(string word) {
        Node* temp=root;

        for(int i=0;i<word.size();i++){
            if(!temp->containsKey(word[i])){
               temp->put(word[i],new Node());
            }

            temp=temp->getnextNode(word[i]);
        }

        //  when you reach the end kindly set the the flag 
        temp->setendFlag();
    }
    
    bool search(string word) {
        Node* temp=root;

        for(int i=0;i<word.size();i++){
            if(!temp->containsKey(word[i])){
                return false;
            }

            temp=temp->getnextNode(word[i]);
        }


        return temp->isEndSet();
        
    }
    
    bool startsWith(string prefix) {
        Node* temp=root;

        for(int i=0;i<prefix.size();i++){
            if(!temp->containsKey(prefix[i])){
                return false;
            }

            temp=temp->getnextNode(prefix[i]);
        }

        return true;
        
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */