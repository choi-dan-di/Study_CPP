#include <iostream>
using namespace std;

// 다중 포인터

void SetMessage(const char* a) {
	a = "Bye";
}

void SetMessage(const char** a) {
	*a = "Bye";
}

void SetMessage2(const char*& a) {
	a = "Ref Bye";
}

int main()
{
	const char* msg = "Hello";
	SetMessage(msg);
	cout << msg << endl;

	// const char* 타입의 변수를 넘겨줘야 한다.
	const char** pp = &msg;
	//*pp = "Bye";
	SetMessage(&msg);
	cout << msg << endl;

	SetMessage2(msg);
	cout << msg << endl;

	return 0;
}