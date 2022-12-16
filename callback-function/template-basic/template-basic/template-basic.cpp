#include <iostream>
using namespace std;

// 템플릿(Template) 기초

//void Print(int a)
//{
//    cout << a << endl;
//}
//
//// 다른 타입의 인자를 받고 싶은 경우 -> 함수 오버로딩
//void Print(float a)
//{
//    cout << a << endl;
//}
//
//void Print(double a)
//{
//    cout << a << endl;
//}
//
//void Print(const char* a)
//{
//    cout << a << endl;
//}

class Knight
{
public:

public:
    int _hp = 100;
};

// 템플릿 사용
template<typename T>
void Print(T a)
{
    cout << a << endl;
}

// 템플릿 특수화
template<>
void Print(Knight a)
{
    cout << "Knight !!!!!!!!" << endl;
    cout << a._hp << endl;
}

template<typename T1, typename T2>
void Print(T1 a, T2 b)
{
    cout << a << " " << b << endl;
}

template<typename T>
T Add(T a, T b)
{
    return a + b;
}

// 연산자 오버로딩 (전역함수 버전)
/*
ostream& operator<<(ostream& os, const Knight& k)
{
    os << k._hp;
    return os;
}
*/

// 클래스 템플릿
// typename T를 붙이면 '조커카드' (어떤 타입도 다 넣을 수 있음)
// 그런데 무조건 typename을 붙여야 하는 것은 아니다.
// template 꺽쇠(< >) 안에 들어가는 건 골라줘야 하는 목록이라고 볼 수 있다.
template<typename T, int SIZE>
class RandomBox
{
public:
    T GetRandomData()
    {
        int idx = rand() % SIZE;
        return _data[idx];
    }
public:
    T _data[SIZE];
};

// 템플릿 특수화
template<int SIZE>
class RandomBox<double, SIZE>
{
public:
    double GetRandomData()
    {
        cout << "RandomBox Double" << endl;
        int idx = rand() % SIZE;
        return _data[idx];
    }
public:
    double _data[SIZE];
};

int main()
{
    // 템플릿이란? 함수나 클래스를 찍어내는 틀
    // 1) 함수 템플릿
    Print(50);
    Print(50.0f);
    Print(50.0);
    Print("Hello World!");

    // Print<int>(50.0f);

    Print("Hello", 100);

    // 함수 오버로딩을 하면 코드가 길어지게 된다. -> 중복되는 비슷한 코드가 많아진다고도 볼 수 있다.
    // -> 이럴 때 템플릿을 사용하면 유용하다.

    int result1 = Add(1, 2);
    float result2 = Add<float>(1.11f, 2.22f);

    Knight k1;
    Print(k1);  // 에러. << 연산자 오버로딩, 혹은 템플릿 특수화가 필요하다.

    cout << "-------------- 클래스 템플릿 --------------" << endl;

    // 2) 클래스 템플릿
    srand(static_cast<unsigned int>(time(nullptr)));

    RandomBox<int, 10> rb1;
    for (int i = 0; i < 10; i++)
        rb1._data[i] = i;

    int value1 = rb1.GetRandomData();
    cout << value1 << endl;

    RandomBox<float, 20> rb2;
    for (int i = 0; i < 20; i++)
        rb2._data[i] = i + 0.5f;

    float value2 = rb2.GetRandomData();
    cout << value2 << endl;

    // rb1 = rb2;   // 성립하지 않음.

    RandomBox<double, 20> rb3;
    for (int i = 0; i < 20; i++)
    {
        rb3._data[i] = i + 0.5;
    }
    double value3 = rb3.GetRandomData();
    cout << value3 << endl;

    return 0;
}