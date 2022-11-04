#include <iostream>
using namespace std;

// 주석!

// Ctrl+K+C, Ctrl+K+U 단축키

/*
여러줄
주석은
이렇게
달아요
*/

// 프로그래밍을 단순하게 생각하면 적절한 데이터를 저장하고 가공하는 것으로 볼 수 있다.
// ㄴ> 데이터 + 로직

// 정수 변수 선언 방법
// [타입] [이름];
// [타입] [이름] = [초기값];

// 0이 아닌 초기화 값이 있으면 .data 영역
int hp = 100;

// 초기값이 0이거나 초기값이 없는 변수라면 .bss 영역

char a; // 1바이트 (-128~127)
short b; // 2바이트 (-32768~32767)
int c; // 4바이트 (-21.4억~21.4억)
__int64 d; // 8바이트(long long) (어마어마하게 큼)

unsigned char ua; // 1바이트 (0~255)
unsigned short ub; // 2바이트 (0~65536)
unsigned int uc; // 4바이트 (0~42.9억)
unsigned __int64 ud; // 8바이트(long long) (0~어마어마하게 큼)

int main()
{
    // cout << "체력이" << hp << " 남았습니다" << endl;
    b = 32767; // 최대값
    b = b + 1;
    cout << b << endl;  // 결과값은 32768이 아닌 -32768

    ub = 0;
    ub = ub - 1;
    cout << ub << endl; // 결과값은 65535
}
