#include <iostream>
using namespace std;

// 스마트 포인터 (smart pointer)

// 스마트 포인터가 필요한 이유?
// 우리가 배웠던 포인터는 물론 잘 사용하면 편리하게 사용할 수 있지만
// 엉뚱한 메모리를 건드릴 수도 있다는 위험성이 있다. -> 치명적!!!!

// 일반 포인터 대신에 스마트 포인터를 사용하는 것이 훨씬 효율적이고 안전하다.

class Knight {
public:
    Knight() { cout << "Knight 생성" << endl; }
    ~Knight() { cout << "Knight 소멸" << endl; }

    // shared_ptr
    /*
    void Attack() {
        if (_target) {
            _target->_hp -= _damage;
            cout << "HP : " << _target->_hp << endl;
        }
    }
    */

    // weak_ptr
    void Attack() {
        if (_target.expired() == false) {
            shared_ptr<Knight> sptr = _target.lock();

            sptr->_hp -= _damage;
            cout << "HP : " << sptr->_hp << endl;
        }
    }
public:
    int _hp = 100;
    int _damage = 10;
    // Knight* _target = nullptr;
    // shared_ptr<Knight> _target = nullptr;
    weak_ptr<Knight> _target;
};

// shared_ptr 구현해보기
// reference count 관리 -> 참조를 얼마나 하고있는지 확인하기 위해
// 참조를 아무도 하지 않을 때 삭제
class RefCountBlock {
public:
    int _refCount = 1;
    // int _weakCount = 1;  // weak_ptr
};

template<typename T>
class SharedPtr {
public:
    SharedPtr() { }
    SharedPtr(T* ptr) : _ptr(ptr) {
        if (_ptr != nullptr) {
            _block = new RefCountBlock();
            cout << "RefCount : " << _block->_refCount << endl;
        }
    }

    SharedPtr(const SharedPtr& sptr) : _ptr(sptr._ptr), _block(sptr._block) {
        if (_ptr != nullptr) {
            _block->_refCount++;
            cout << "RefCount : " << _block->_refCount << endl;
        }
    }

    void operator=(const SharedPtr& sptr) {
        _ptr = sptr._ptr;
        _block = sptr._block;

        if (_ptr != nullptr) {
            _block->_refCount++;
            cout << "RefCount : " << _block->_refCount << endl;
        }
    }

    ~SharedPtr() {
        if (_ptr != nullptr) {
            _block->_refCount--;
            cout << "RefCount : " << _block->_refCount << endl;

            if (_block->_refCount == 0) {
                delete _ptr;
                delete _block;
                // weak_ptr에서는 _block 삭제 X
                cout << "Delete Data" << endl;
            }
        }
    }
public:
    T* _ptr = nullptr;    // 원본 객체의 포인터
    RefCountBlock* _block = nullptr;
};

int main()
{
    // Knight* k1 = new Knight();
    // Knight* k2 = new Knight();

    // k1->_target = k2;

    // delete k2;

    // k1->Attack();

    // 스마트 포인터 : 포인터를 알맞은 정책에 따라 관리하는 객체 (포인터를 래핑해서 사용)
    // shared_ptr, weak_ptr, unique_ptr     // 언리얼 엔진에도 똑같이 들어가있음
    // 스마트 포인터를 사용하면 알아서 메모리를 날려준다. -> delete 할 필요 없음
    
    // shared_ptr (대표적)
    // 참조 정보를 관리해서 아무도 참조하고 있지 않을 때에만 삭제를 가능하게 해준다.
    // 객체의 생명 주기를 자동으로 관리
    SharedPtr<Knight> k4;
    {
        SharedPtr<Knight> k3(new Knight());
        k4 = k3;
    }

    // make_shared : 메모리 블록을 한 번에 만들어줘서 new 객체 생성보다 훨씬 성능이 좋다.
    // k5(new Knight()); 와 같은 의미
    shared_ptr<Knight> k5 = make_shared<Knight>();
    {
        shared_ptr<Knight> k6 = make_shared<Knight>();
        k5->_target = k6;
        // k6->_target = k5;    // 사이클 발생시 삭제가 되지 않는 문제 발생
        
        // 소멸 전에 nullptr로 밀어주는 부분이 필요하다.
        // k5->_target = nullptr;
        // k6->_target = nullptr;
    }
    // k6가 사라지지 않고 남아있다. -> k5가 가리키고 있기 때문

    // weak_ptr : 객체가 날라갔는지 유무를 확인 .expired() == false면 유효
    // .lock() -> shared_ptr 반환

    // unique_ptr : 나만 가지고 있어야한다. 나만 가리켜야 한다.
    unique_ptr<Knight> uptr = make_unique<Knight>();
    // unique_ptr<Knight> uptr2 = uptr; // 불가능
    unique_ptr<Knight> uptr2 = move(uptr);  // 오른값 참조 캐스팅

    return 0;
}