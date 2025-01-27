class LRUCache {
  private:
  int capacity;
  list<pair<int,int>> cache;
  unordered_map<int,list<pair<int,int>> ::iterator> map;
  public:
    // Constructor for initializing the cache capacity with the given value.
    LRUCache(int cap) {
        capacity = cap;       
    }

    // Function to return value corresponding to the key.
    int get(int key) {
        if(map.find(key) == map.end()) return -1;
        auto it = map[key];
        int value = it->second;
        cache.erase(it);
        cache.push_front({key,value});
        map[key] = cache.begin();
        return value;
    }

    // Function for storing key-value pair.
    void put(int key, int value) {
        if(map.find(key) != map.end()){
            auto it = map[key];
            cache.erase(it);
        }else if(cache.size() == capacity){
            auto lru = cache.back();
            map.erase(lru.first);
            cache.pop_back();
        }
        cache.push_front({key , value});
        map[key] = cache.begin();
        
   }
};
