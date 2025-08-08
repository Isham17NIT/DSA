class LRUCache {
private:
    struct ListNode{
        int key,val;
        ListNode* prev, *next;
        ListNode(int _key,int _val){
            key=_key;
            val=_val;
            prev=next=nullptr;
        }
    };
    int capacity;
    map<int, ListNode*> m;
    ListNode* head, *tail; //we'll take dummy head and dummy tail in order to handle edge cases correctly
public:
    LRUCache(int capacity){
        this->capacity=capacity;
        m = map<int,ListNode*>();
        head = new ListNode(-1,-1);
        tail=new ListNode(-1,-1);
        head->next=tail;
        tail->prev=head;
    }
    
    int get(int key) {
        if(m.find(key)==m.end())
            return -1;
        ListNode* node = m[key];
        int ans=node->val;
        node->prev->next = node->next;
        node->next->prev = node->prev;
        node->next=head->next;
        head->next->prev=node;
        node->prev=head;
        head->next=node;
        return ans;
    }
    
    void put(int key, int value) {
        ListNode* node;
        if(m.find(key)!=m.end())
        {
            node=m[key];
            node->val=value;
            node->prev->next=node->next;
            node->next->prev=node->prev;
            m[key]=node;
            //insert at first posn
        }
        else //key not found in map
        {
            if(m.size()==capacity) //remove the last node
            {
                node=tail->prev;
                node->prev->next = tail;
                tail->prev=node->prev;
                m.erase(node->key);
                // we're reusing the old nodes
                node->key=key;
                node->val=value;
            }
            else{
                node=new ListNode(key,value);
            }
            m[key]=node;
            //insert at first posn
        }
        node->next=head->next;
        node->next->prev=node;
        head->next=node;
        node->prev=head;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */