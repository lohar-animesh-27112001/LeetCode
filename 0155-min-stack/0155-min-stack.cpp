// Implementation of Singly Linked List
class Node {
public:
    int val;
    Node* next = NULL;
    Node(): val(0) {};
    Node(int num): val(num) {};
};
class Stack {
public:
    Node* head;
    Stack(int val) {
        Node* node = new Node(val);
        head = node;
    }
    Stack(Node* node): head(node) {};
    Stack() {
        head = NULL;
    }
    void push(Node* node) {
        if(head == NULL) {
            head = node;
            return;
        }
        Node* temp = head;
        head = node;
        head->next = temp;
    }
    void pop() {
        if(head == NULL) return;
        Node* temp = head;
        head = head->next;
        delete temp;
    }
};
class MinStack {
private:
    Stack* main_stack;
    Stack* min_stack;
public:
    MinStack() {
        main_stack = new Stack();
        min_stack = new Stack();
    }
    
    void push(int val) {
        Node* node = new Node(val);
        main_stack->push(node);
        Node* min_node = new Node(val);
        if(min_stack->head == NULL) {
            min_stack->push(min_node);
            return;
        }
        int num = min_stack->head->val;
        if(num < val) {
            min_node->val = num;
            min_stack->push(min_node);
        } else {
            min_stack->push(min_node);
        }
    }
    
    void pop() {
        if(main_stack->head == NULL) return;
        main_stack->pop();
        min_stack->pop();
    }
    
    int top() {
        if(main_stack->head == NULL) return -1;
        return main_stack->head->val;
    }
    
    int getMin() {
        if(min_stack->head == NULL) return -1;
        return min_stack->head->val;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */