class RandomizedSet {
private:
    map<int,int> m;
    vector<int> arr;
public:
    RandomizedSet() {
        m=map<int,int>();
        arr=vector<int>();
    }
    
    bool insert(int val) {
        if(m.find(val)==m.end()){
            m[val]=m.size();
            arr.push_back(val);
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if(m.find(val)!=m.end()){
            int idx=m[val];
            m[arr[m.size()-1]]=idx;
            swap(arr[m.size()-1],arr[idx]); //O(1)
            arr.pop_back();
            m.erase(val);
            return true;
        }
        return false;
    }
    
    int getRandom() {
        int idx=rand()%m.size();
        return arr[idx];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */