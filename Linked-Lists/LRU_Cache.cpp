class Node{
    public:
        int key,value;
        Node* next, *prev;
        Node(int k,int v){
            key = k;
            value = v;
            next = prev = NULL;
        }
        Node(){
            next = prev =NULL;
        }
};
class LRUCache {
    Node *left, *right;
    map<int,Node*> mp;
    int capacity;
    int current;
public:
    LRUCache(int capacity) {
        current = 0;
        left = new Node(0,0);
        right = new Node(0,0);
        this->capacity = capacity;
        left->next = right;
        right->prev =left;
    }
    
    void deleteNode(Node* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    void insertNode(Node* node){
        right->prev->next = node;
        node->prev = right->prev;
        right->prev = node;
        node->next = right;
    }
    int get(int key) {
        if(mp[key]){
            Node* temp =mp[key];
            cout<<temp->key;
            deleteNode(temp);
            insertNode(temp);
            return temp->value;
        }else{
            return -1;
        }
    }
    void put(int key, int value) {
        if(mp[key]){
            mp[key]->value = value;
            Node* temp = mp[key];
            deleteNode(temp);
            insertNode(temp);
            return;
        }else{
            if(current >= capacity){
                Node* temp = left->next;
                mp[temp->key] = NULL;
                deleteNode(temp);
                current--;
            }
            Node* newNode = new Node(key,value);
            insertNode(newNode);
            mp[key] = newNode;
            current++;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
