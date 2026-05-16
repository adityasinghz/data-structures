class MyHashSet {
public:
    vector<list<int>>bucket;
    const int SIZE = 1000;
    MyHashSet() {
       bucket.resize(SIZE);
    }
    
    void add(int key) {
        int indx = key%SIZE;
        for(auto num : bucket[indx]){
            if(num == key) return;
        }
        bucket[key%SIZE].push_back(key);
    }
    
    void remove(int key) {
        int indx = key%SIZE;
        bucket[indx].remove(key);
    }
    
    bool contains(int key) {
        int indx = key%SIZE;

        for(auto num : bucket[indx]){
            if(num==key) return true;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */