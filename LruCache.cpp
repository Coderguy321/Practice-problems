class LRU{
public:
	List <int> que;
	std::map<int, List<int>::iterator> map;
	// std::map<int, int> kp;
	int capac;
}obj;
LRUCache::LRUCache(int capacity) {
	obj.capac  = capacity;
}

int LRUCache::get(int key) {

	if (obj.map.find(key)== map.end())	{
		return -1;
	}
	else{
		
		obj.que.push_front(*(obj.map[key]));
		obj.que.erase(obj.map[key]);
		obj.map[key] = obj.que.begin();

		return *(obj.que.begin());
	}
}

void LRUCache::set(int key, int value) {
	if (obj.que.size() == capac) {
    		que.pop_back();
    		map.erase(key);
    }
	obj.que.push_front(value);
	obj.map[key] = obj.que.begin();
}
