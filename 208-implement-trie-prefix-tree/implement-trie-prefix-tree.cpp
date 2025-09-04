class Trie 
{
private:
    struct Node{
        char val;
        int flag;
        vector<Node*> children;
        Node(char val_){
            val=val_;
            flag=0;
            children=vector<Node*>(26,nullptr);
        }
    };
    Node* trie;
public:
    Trie() 
    {
        trie=new Node('#');
    }
    
    void insert(string word) 
    {
        Node* temp=trie;
        for(char c : word)
        {
            if(!temp->children[c-'a'])
                temp->children[c-'a']=new Node(c);
            temp=temp->children[c-'a'];
        }
        temp->flag=1;
        return;
    }
    
    bool search(string word) 
    {
        Node* temp=trie;
        for(char c : word)
        {
            if(!temp->children[c-'a'])
                return false;
            
            temp=temp->children[c-'a'];
        }
        return temp->flag==1; //word ends here, then only it's a valid word
    }
    
    bool startsWith(string prefix) 
    {
        Node* temp=trie;
        for(char c : prefix)
        {
            if(!temp->children[c-'a'])
                return false;
            
            temp=temp->children[c-'a'];
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