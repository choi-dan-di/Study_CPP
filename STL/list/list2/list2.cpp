#include <iostream>
#include <list>
using namespace std;

// list
// 리스트 구현해보기

// 노드 만들기
template<typename T>
class Node {
public:
    Node() : _next(nullptr), _prev(nullptr), _data(T()) {

    }

    Node(const T& value) : _next(nullptr), _prev(nullptr), _data(value) {

    }

public:
    Node* _next;
    Node* _prev;
    T _data;
};

// Iterator 만들기
template<typename T>
class Iterator {
public:
    Iterator() : _node(nullptr) {

    }

    Iterator(Node<T>* node) : _node(node) {

    }

    // 연산자 오버로딩
    Iterator& operator++() {
        _node = _node->_next;
        return *this;
    }

    Iterator operator++(int) {
        Iterator temp = *this;
        _node = _node->_next;
        return temp;
    }

    Iterator& operator--() {
        _node = _node->_prev;
        return *this;
    }

    Iterator operator--(int) {
        Iterator temp = *this;
        _node = _node->_prev;
        return temp;
    }

    T& operator*() {
        return _node->_data;
    }

    bool operator==(const Iterator& right) {
        return _node == right._node;
    }

    bool operator!=(const Iterator& right) {
        return _node != right._node;
    }
public:
    Node<T>* _node;
};

// 리스트 만들기
// [header]
// 값이 없어도 기본적으로 존재해야하고 자기 자신을 연결한다.
template<typename T>
class List {
public:
    List() : _size(0) {
        // <-> [header] <-> 상태
        _header = new Node<T>();
        _header->_next = _header;
        _header->_prev = _header;
    }

    ~List() {
        // 데이터 날리기 (모든 노드의 메모리 할당 해제)
        while (_size > 0)
            pop_back();

        delete _header;
    }

    // AddNode로 push_back과 insert 기능 합치기
    void push_back(const T& value) {
        AddNode(_header, value);
    }

    // 넣어줄 위치의 바로 다음 위치를 인자로 받음 -> before의 바로 앞에 추가된다.
    Node<T>* AddNode(Node<T>* before, const T& value) {
        Node<T>* node = new Node<T>(value);

        // 이전 노드
        Node<T>* prevNode = before->_prev;
        prevNode->_next = node;

        // 현재 노드 (삽입될 노드)
        node->_prev = prevNode;
        node->_next = before;

        // 이후 노드
        before->_prev = node;

        _size++;

        return node;
    }

    // RemoveNode로 pop_back과 erase 기능 합치기
    void pop_back() {
        RemoveNode(_header->_prev);
    }

    Node<T>* RemoveNode(Node<T>* node) {
        Node<T>* prevNode = node->_prev;
        Node<T>* nextNode = node->_next;

        // 이전 노드
        prevNode->_next = nextNode;

        // 이후 노드
        nextNode->_prev = prevNode;

        delete node;
        _size--;

        return nextNode;
    }

    int size() { return _size; };

public:
    typedef Iterator<T> iterator;

    iterator begin() { return iterator(_header->_next); }
    iterator end() { return iterator(_header); }

    iterator insert(iterator it, const T& value) {
        return iterator(AddNode(it._node, value));
    }

    iterator erase(iterator it) {
        return iterator(RemoveNode(it._node));
    }
public:
    // 더미 노드 만들기
    Node<T>* _header;
    int _size;
};

int main()
{
    // list<int> li;
    List<int> li;

    // list<int>::iterator eraseIt;
    List<int>::iterator eraseIt;

    for (int i = 0; i < 10; i++) {
        if (i == 5) eraseIt = li.insert(li.end(), i);
        else li.push_back(i);
    }

    li.pop_back();

    li.erase(eraseIt);

    // for (list<int>::iterator it = li.begin(); it != li.end(); ++it)
    for (List<int>::iterator it = li.begin(); it != li.end(); ++it)
        cout << (*it) << endl;

    return 0;
}