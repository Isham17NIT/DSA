class MyCalendar {
private:
    struct Node{
        pair<int,int> val;
        Node* next, *prev;
        Node(pair<int,int> val_){
            val=val_;
            next=prev=nullptr;
        }
    };
    Node* root;
public:
    MyCalendar() 
    {
        root=nullptr;
    }
    
    bool book(int startTime, int endTime) 
    {
        if(!root){
            root=new Node({startTime, endTime});
            return true;
        }
        Node* temp=root;
        while(temp)
        {
            int begin=temp->val.first;
            int end=temp->val.second;
            if(endTime<=begin || startTime>=end) // no overlapping
            {
                if(startTime > begin)
                {
                    if(temp->next){
                        temp=temp->next;
                        continue;
                    }
                    Node* newNode=new Node({startTime, endTime});
                    newNode->prev=temp;
                    temp->next=newNode;
                    return true;
                }
                Node* newNode=new Node({startTime, endTime});
                newNode->next=temp;
                if(temp->prev){
                    newNode->prev=temp->prev;
                    newNode->prev->next=newNode;
                }
                else{
                    root=newNode;
                }
                newNode->next=temp;
                temp->prev=newNode;
                return true;
            }
            else //overlapping
                return false;
        }
        return false;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */