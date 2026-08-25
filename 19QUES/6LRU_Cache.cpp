//lc 146

//mik
// https://youtu.be/81h8O-0U5oo?si=PNt_8mbNiEz8cPPE

//bruteforce

class LRUCache {
public:
    
    vector<pair<int, int>> cache;
    int n;
    
    LRUCache(int capacity) {
        n = capacity;
    }
    
    int get(int key) {
        
        for(int i = 0; i<cache.size(); i++) {
            
            if(cache[i].first == key) {
                int val = cache[i].second;
                
                pair<int, int> temp = cache[i];
                cache.erase(cache.begin()+i);
                cache.push_back(temp);
                
                return val;
            }
            
        }
        
        return -1;
        
    }
    
    void put(int key, int value) {
        
        for(int i = 0; i<cache.size(); i++) {
            
            if(cache[i].first == key) {
                cache.erase(cache.begin()+i);
                cache.push_back({key, value});
                return;
            }
        }
        
        if(cache.size() == n) {
            cache.erase(cache.begin());
            cache.push_back({key, value});
        } else {
            cache.push_back({key, value});
        }
        
    }
};

//optimal

list in C++ STL is a doubly linked list.

Function / Operation              Time Complexity
-------------------------------------------------
push_front()                      O(1)
push_back()                       O(1)
pop_front()                       O(1)
pop_back()                        O(1)

insert(iterator, value)           O(1)
erase(iterator)                   O(1)

front()                           O(1)
back()                            O(1)

begin()                           O(1)
end()                             O(1)

size()                            O(1)
empty()                           O(1)

find()                            O(N)
search for a value                O(N)

Access by index list[i]           NOT supported
Random access                     O(N) if traversing

clear()                           O(N)

remove(value)                     O(N)
reverse()                         O(N)
sort()                            O(N log N)

class LRUCache {
public:
    list<int> dll; //it contains the key
    map<int, pair<list<int>::iterator, int>> cache; //key->(list_node, value)
    int capacity;
    
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    void makeMostRecentlyUsed(int key) {
        dll.erase(cache[key].first);
        dll.push_front(key);
        cache[key].first = dll.begin();
    }
    
    int get(int key) {
        if(!cache.count(key))
            return -1;
        
        makeMostRecentlyUsed(key);
        return cache[key].second;
    }
    
    void put(int key, int value) {
        if(cache.count(key)) {
            cache[key].second = value;
            makeMostRecentlyUsed(key);
        } else {
            dll.push_front(key);
            cache[key] = {dll.begin(), value};
            capacity--;
        }
        
        if(capacity < 0) {
            cache.erase(dll.back());
            dll.pop_back();
            capacity++;
        }
    }
};

// or
//list mein hi key,value store krlo

class LRUCache {
public:
    list<pair<int, int>> dll; // stores (key, value)
    unordered_map<int, list<pair<int, int>>::iterator> cache; // key -> iterator
    int capacity;

    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    void makeMostRecentlyUsed(int key) {
        auto node = *cache[key];      // Copy (key, value)
        dll.erase(cache[key]);        // Remove old node
        dll.push_front(node);         // Insert at front
        cache[key] = dll.begin();     // Update iterator
    }

    int get(int key) {
        if (!cache.count(key))
            return -1;

        makeMostRecentlyUsed(key);
        return cache[key]->second;
    }

    void put(int key, int value) {

        if (cache.count(key)) {
            cache[key]->second = value; // Update value
            makeMostRecentlyUsed(key);
        } else {
            dll.push_front({key, value});
            cache[key] = dll.begin();
            capacity--;
        }

        if (capacity < 0) {
            cache.erase(dll.back().first);
            dll.pop_back();
            capacity++;
        }
    }
};

Implementation                      get()          put()          Space
----------------------------------------------------------------
Vector                              O(N)           O(N)           O(N)
Map + DLL                          O(log N)       O(log N)       O(N)
Unordered Map + DLL                O(1) avg       O(1) avg       O(N)


//striver
// https://youtu.be/z9bJUPxzFOw?si=HIWgqf3UbIzAj_iT

class LRUCache {
  public:
    class node {
      public:
        int key;
      int val;
      node * next;
      node * prev;
      node(int _key, int _val) {
        key = _key;
        val = _val;
      }
    };

  node * head = new node(-1, -1);
  node * tail = new node(-1, -1);

  int cap;
  unordered_map < int, node * > m;

  LRUCache(int capacity) {
    cap = capacity;
    head -> next = tail;
    tail -> prev = head;
  }

  void addnode(node * newnode) {
    node * temp = head -> next;
    newnode -> next = temp;
    newnode -> prev = head;
    head -> next = newnode;
    temp -> prev = newnode;
  }

  void deletenode(node * delnode) {
    node * delprev = delnode -> prev;
    node * delnext = delnode -> next;
    delprev -> next = delnext;
    delnext -> prev = delprev;
  }

  int get(int key_) {
    if (m.find(key_) != m.end()) {
      node * resnode = m[key_];
      int res = resnode -> val;
      m.erase(key_);
      deletenode(resnode);
      addnode(resnode);
      m[key_] = head -> next;
      return res;
    }

    return -1;
  }

  void put(int key_, int value) {
    if (m.find(key_) != m.end()) {
      node * existingnode = m[key_];
      m.erase(key_);
      deletenode(existingnode);
    }
    if (m.size() == cap) {
      m.erase(tail -> prev -> key);
      deletenode(tail -> prev);
    }

    addnode(new node(key_, value));
    m[key_] = head -> next;
  }
};


Function / Operation             Time Complexity
-------------------------------------------------
LRUCache(capacity)               O(1)

addnode(node*)                   O(1)
deletenode(node*)                O(1)

get(key)                         O(1) average
put(key, value)                  O(1) average

unordered_map::find()            O(1) average
unordered_map::erase()           O(1) average
unordered_map::operator[]        O(1) average

Space Complexity                 O(N)
-------------------------------------------------

Why get() = O(1)?
- unordered_map finds node        → O(1) avg
- erase from DLL                  → O(1)
- add to front of DLL             → O(1)
- update map                      → O(1) avg

Why put() = O(1)?
- find existing key               → O(1) avg
- delete existing node             → O(1)
- remove LRU node if full          → O(1)
- add new node to front            → O(1)
- update map                       → O(1) avg
