class MyHashMap {
public:
    vector<list<pair<int,int>>>bucket;
    int SIZE = 1000;
    MyHashMap() {
        bucket.resize(SIZE);
    }
    int hash(int key){
        return key%SIZE;
    }
    void put(int key, int value) {
        int indx = hash(key);
        for(auto &val : bucket[indx]){
            if(val.first == key){ 
                 val.second =  value;
                 return;
            }
        }
        bucket[indx].push_back(make_pair(key,value));
    }
    
    int get(int key) {
        int indx = hash(key);
        for(auto val : bucket[indx]){
            if(val.first == key) return val.second;
        }
        return -1;
    }
    
    void remove(int key) {
        int indx = hash(key);
        for(auto it = bucket[indx].begin(); it!=bucket[indx].end();it++){
            if(it->first == key){
             bucket[indx].erase(it);
             return;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */