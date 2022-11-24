#include <iostream>
using namespace std;

// 다중 포인터 vs 이차원 배열
// 포인터, 참조 사용 시 주의사항

int& TestRef() {
    int a = 1;
    return a;
}

int* TestPointer() {
    int a = 1;
    return &a;
}

void TestWrong(int* ptr) {
    int a[100] = {};
    a[99] = 0xAAAAAAAA;
    *ptr = 0x12341234;
}

int main()
{
    // 배열의 이름은 배열의 시작 주소값을 가리키는 TYPE* 포인터로 변환이 가능하다.
    int* p;
    int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8 };

    p = arr;

    // TYPE형 1차원 배열과 TYPE*형 포인터는 완전히 호환된다.
    cout << p[0] << endl; // 1
    cout << arr[0] << endl; // 1
    cout << *p << endl; // 1
    cout << *arr << endl; // 1
    cout << *(p + 3) << endl; // 4
    cout << *(arr + 3) << endl; // 4

    int arr2[2][2] = { { 1, 2 }, { 3, 4 } };

    int(*pp)[2] = arr2;
    cout << endl;
    cout << (*pp)[0] << endl;
    cout << (*pp)[1] << endl;
    cout << (*(pp + 1))[0] << endl;
    cout << (*(pp + 1))[1] << endl;

    cout << pp[0][0] << endl;
    cout << pp[0][1] << endl;
    cout << pp[1][0] << endl;
    cout << pp[1][1] << endl;

    // 포인터, 참조 사용 시 주의사항
    int* pointer = TestPointer();
    TestWrong(pointer);

    return 0;
}