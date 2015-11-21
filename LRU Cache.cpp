/*
    Design and implement a data structure for Least Recently 
        Used (LRU) cache. It should support the following 
        operations: get and set.

    get(key) - Get the value (will always be positive) of the 
        key if the key exists in the cache, otherwise return -1.

    set(key, value) - Set or insert the value if the key is 
        not already present. When the cache reached its capacity, 
        it should invalidate the least recently used item before 
        inserting a new item.
*/
/*
    Please google LRU cache for more information
*/
class LRUCache
{
public:
    LRUCache(int capacity):max_size(capacity) {}
    
    int get(int key) 
    {
    	if(cache.find(key) != cache.end())
    	{
    		int value = cache[key]->second;
    		lst.erase(cache[key]);
    		cache[key] = lst.insert(lst.begin(), {key, value});
    		return value;
    	}
    	else
    		return -1;
    }
    
    void set(int key, int value) 
    {
    	if(cache.find(key) != cache.end())
    	{   
    		lst.erase(cache[key]);
    		cache[key] = lst.insert(lst.begin(), {key, value});  		
    	}
    	else
    	{
    		if(cache.size() == max_size)
    		{
    			cache.erase(lst.back().first);
    			lst.erase(--lst.end());			//lst.end() is the iterator one past the end
    			//lst.pop_back();
    		}    		
    		cache[key] = lst.insert(lst.begin(), {key, value});
    	}
    }
private:
    //I use pair as the element of list so the map and the list
    //  can map to each other.
    //  Or we can keep all key-value pair in the map, and use 
    //  the list only as an indicator to delete the key. Thus we can
    //  make it as
    //
    //  unordered_map<unsigned, pair<int, list<unsigned>::iterator>>
    //  list<unsigned> lst
	unordered_map<unsigned, list<pair<unsigned, int>>::iterator> cache;
	list<pair<unsigned, int>> lst;		//key-value pair, so when we erase it from the list
	int max_size;						//	we can also get the key to erase it from the map
};


int main()
{
    LRUCache myCache(4);
    myCache.set(1, 11);
    myCache.set(2, 12);
    myCache.set(3, 13);
    myCache.set(4, 14);
    cout << myCache.get(1) << endl; 
    cout << myCache.get(2) << endl;
    cout << myCache.get(3) << endl;
    cout << myCache.get(4) << endl;
    myCache.set(5, 15);
    cout << myCache.get(1) << endl;
    return 0;
}