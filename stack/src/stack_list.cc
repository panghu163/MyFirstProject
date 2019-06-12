#include <iostream>

/**与数组栈不同，list栈不需要首先固定大小。**/

template<typename T>
struct Node {
    T data;
    Node* next;
    
    Node(T v) : data(v), next(NULL) {}
};


template<typename T>
class Stack {
public:
    Stack() : size_(0), top_(NULL) {}
    ~Stack() {
        if (!top_) { return; }
        Node<T>* temp = top_;
        Node<T>* next = NULL;
        while (temp) {
            next = temp->next;
            delete temp;
            temp = next;
        }
    }
    int Size() { return size_; }
    int Empty() { return size_ == 0; }
    Node<T>* Top() { return top_; }
    void Pop() {
        Node<T>* temp = top_->next;
        delete top_;
        top_ = temp;
        size_--;
    }
    void Push(T value) {
        Node<T>* new_node = new Node<T>(value);
        new_node->next = top_;
        top_ = new_node;
    }
    void Print() {
        while (top_) {
            std::cout << top_->data << std::endl;
            top_ = top_->next;
        }
        std::cout << std::endl;
    }
private:
    Node<T>* top_;
    int size_;
};

int main() {
    Stack<int> s;
    for (int i = 0; i < 10; ++i) {
        s.Push(i);
    }
    s.Print();
    return 0;
}