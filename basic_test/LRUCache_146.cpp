#include <unordered_map>
#include <iostream>
using namespace std;

struct Node {
    int key;
    int val;
    Node* next;
    Node(int k, int v): key{k}, val{v}, next{nullptr} {}
    Node(): key{0},val{0},next{nullptr} {}
};
class LRUCache {
private:
    int cap;
    int size;
    unordered_map<int, Node*> maps;
    Node* head;
    Node* tail;
    void move_to_tail(Node* iter) {
        if(iter->next == tail) {
            return;
        }
        auto cur_node = iter->next;
        maps[cur_node->next->key] = iter;
        iter->next = cur_node->next;
        cur_node->next = nullptr;
        tail->next = cur_node;
        maps[cur_node->key] = tail;
        tail = cur_node;     
    }
public:
    LRUCache(int capacity) {
        this->cap = capacity;
        this->size = 0;
        head = tail = new Node();
    }    
    int get(int key) {
        auto iter = maps.find(key);
        if(iter == maps.end()) {
            return -1;
        }
        move_to_tail(maps[key]);
        return maps[key]->next->val;
    } 
    void put(int key, int val) {
        if(maps.find(key) != maps.end()) {
            maps[key]->next->val = val;
            move_to_tail(maps[key]);
        } else {   //新建节点
            ++size;
            auto new_node = new Node(key, val);
            tail->next = new_node;
            maps[key] = tail;
            tail = tail->next; 
            if(size > cap) {
                --size;
                maps.erase(head->next->key);
                head->next = head->next->next;    
                maps[head->next->key] = head;  
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */