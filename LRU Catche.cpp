
"""
https://leetcode.com/problems/lru-cache/
https://www.geeksforgeeks.org/lru-cache-implementation/
https://www.geeksforgeeks.org/least-frequently-used-lfu-cache-implementation/?ref=rp
https://leetcode.com/problems/lru-cache/

Applications/ Uses

http://www.primarydigit.com/blog/an-application-of-lru-least-recently-used-data-structure-your-phones-home-screen

    LRUCache ca(4); 
  
    ca.refer(1); 
    ca.refer(2); 
    ca.refer(3); 
    ca.refer(1); 
    ca.refer(4); 
    ca.refer(5); 
    ca.display(); 
    
 [5, 4, 1, 3]
 
 
LRUCache cache = new LRUCache( 2 /* capacity */ );

cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // returns 1
cache.put(3, 3);    // evicts key 2
cache.get(2);       // returns -1 (not found)
cache.put(4, 4);    // evicts key 1
cache.get(1);       // returns -1 (not found)
cache.get(3);       // returns 3
cache.get(4);       // returns 4

cache.put(1,1)
cache.put(2,2)
cache.get(1)
cache.put(3,3)
cache.get(2)
cache.put(4,4)
cache.get(1)
cache.get(3)
cache.get(4)


prev<-node->

[(4,4),(3,3)]
"""
class LRUCache {
    int cap;
    list<int> ls;
    unordered_map<int,pair<int,list<int>::iterator>> mp;
public:
    LRUCache(int capacity) {
        cap=capacity;
    }
    int get(int key) {
        if(mp.find(key)!=mp.end()){
            ls.erase(mp[key].second);
            ls.push_front(key);
            mp[key].second=ls.begin();
            return mp[key].first;
        }
        return -1;
    }
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            ls.erase(mp[key].second);
            ls.push_front(key);
            mp[key]={value,ls.begin()};
        }
        else{
            if(ls.size()==cap){
                mp.erase(ls.back());
                ls.pop_back();
            }
            ls.push_front(key);
            mp[key]={value,ls.begin()};
        }
    }
};








class dllNode:
  def __init__(self, key,val):
    self.key = key
    self.val = val
    self.next = None
    self.prev = None
    
    
class dLL:
  def __init__(self):
    self.head = dllNode(0,0)
    self.tail = dllNode(0,0)
    self.head.next = self.tail
    self.tail.prev = self.head
    
    
  def unlink(self,node):
    prevNode = node.prev
    nextNode = node.next
    node.prev = None
    node.next = None
    prevNode.next = nextNode
    nextNode.prev = prevNode
    
    
  def add_to_front(self, node):
    next_to_head = self.head.next
    node.next = next_to_head
    next_to_head.prev = node
    self.head.next = node
    node.prev = self.head
    
  def printList(self):
    curr = self.head.next
    lst = []
    while curr.key != 0:
      lst.append(curr.val)
      curr = curr.next
    print(lst)
      
    
    
    
class LRUCache:
  def __init__(self, capacity):
    self.capacity = capacity
    self.size = 0
    self.queue = dLL()
    self.hashmap = {}
    
  def get(self,key):
    if key in self.hashmap:
      node = self.hashmap[key]
      retval = node.val
      self.queue.unlink(node)
      self.queue.add_to_front(node) 
      print(retval)
      return retval
    
    print(-1)
    return -1
  
  
  def put(self,key, val):
    if key in self.hashmap:
      node = self.hashmap[key]
      node.val = val
      self.queue.unlink(node)
      self.queue.add_to_front(node)
      
    else:
      if self.size < self.capacity:
        node = dllNode(key,val)
        self.queue.add_to_front(node)
        self.hashmap[key] = node
        self.size += 1
        
      elif self.size == self.capacity:
        # remove lru node from dll
        # remove from map
        # add new node to front
        # add to add hashmap
        lastNode = self.queue.tail.prev
        self.queue.unlink(lastNode)
        del self.hashmap[lastNode.key]
        self.size -= 1
        
        newnode = dllNode(key,val)
        self.queue.add_to_front(newnode)
        self.hashmap[key] = newnode
        self.size += 1
        
    print('put done')
        
        # when adding new node
        # 1. add to dll
        # 2. add to map
        # 3. increment size
        
        # when remove
        # 1. dll, map and size --
    
    
cache = LRUCache(2)
cache.put(1,1)
cache.put(2,2)
cache.get(1)
cache.put(3,3)
cache.get(2)
cache.put(4,4)
cache.get(1)
cache.get(3)
cache.get(4)
cache.queue.printList()

"""
cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // returns 1
cache.put(3, 3);    // evicts key 2
cache.get(2);       // returns -1 (not found)
cache.put(4, 4);    // evicts key 1
cache.get(1);       // returns -1 (not found)
cache.get(3);       // returns 3
cache.get(4);       // returns 4

"""
