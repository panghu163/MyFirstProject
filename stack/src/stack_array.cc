#include <iostream>

/**每次为栈申请固定size空间，如果空间不够，再增加同样size的空间**/

template<typename T>
class Stack{
public:
    enum FixedSize {
        kFixed = 10
    };

    Stack() {
        int top_ = 0;
        base_ = new T[kFixed];
    }
    ~Stack() { delete[] base_; }
    void Push(T value) {
        if ((top_ != 0) && (top_ % kFixed == 0)) {
            T* temp = new T[top_ + kFixed];
            for (int i = 0; i < (top_ + kFixed); ++i) { temp[i] = base_[i]; }
            delete[] base_;
            base_ = temp;
        }
        base_[top_++] = value;
    }
    void Pop() { top--; }
    T Top() { return base_[top_]; }
    int Size() { return top_ + 1; }
    bool Empty() { return top_ == 0; }
    //打印整个栈元素
    void Print() {
        while ( top_ != 0) {
            std::cout << base_[top_--] << std::" ";
        }
        std::cout << std::endl;
    }

private:
    T* base_; // 栈的数据结构-数组
    int top_; // 数组的index
};

int main() {
    Stack<int> s;
    for (int i = 0; i < 10; ++i) { s.Push(i); }
    s.Print();
    std::cout << s.Top() << std::endl;
    s.Pop();
    std::cout << s.Top() << std::endl;
    std::cout << s.Size() << std::endl;
    for (int i = 0; i < 10; ++i) { s.Push(i); }
    s.Print();
    std::cout << s.Top() << std::endl;
    s.Pop();
    std::cout << s.Top() << std::endl;
    std::cout << s.Size() << std::endl;

    return 0;
} 