#include <iostream>
using namespace std;

// char : 알파벳 / 숫자 문자를 나타낸다
// wchar_t : 유니코드 문자를 나타낸다.

// '문자'의 의미로 작은 따옴표(') 사용
//char ch = 97;   // 결과값 : a
char ch = 'a';
char ch2 = '1';
char ch3 = 'a' + 1;

// 유니코드(unicode) : 전 세계 모든 문자에 대해 유일한 코드를 부여한 것이다.
// 유니코드 여러가지 표기 방식 중 UTF8, UTF16이 대표적이다.
// UTF 8
// - 알파벳, 숫자 1바이트 (ASCII 동일한 번호)
// - 유럽 지역의 문자는 2바이트
// - 한글, 한자 등은 3바이트

// UTF16
// - 알파벳, 숫자, 한글, 한자 등 거의 대부분 문자가 2바이트
// 매우 예외적인 고대 문자만 4바이트 (사실상 무시 가능)

// UTF16 문자를 나타내는 타입 wchar_t. 유니코드라는 것을 알리기 위해 문자 앞에 L을 붙인다.
wchar_t wch = L'안';
// 각 코드에 대응하는 문자만 생각해서 입력해줘도 가능
//wchar_t wch = 0xc548;

// 문자열
char str[] = { 'h', 'e', 'l', 'l', 'o' };
char str2[] = "Hello World";    // 마우스 오버하면 길이가 12인 걸 알 수 있음

int main()
{
    cout << ch << endl;
    cout << ch2 << endl;
    cout << ch3 << endl;

    // cout << wch << endl; // 값이 제대로 안 나옴. cout은 유니코드 문자를 출력할 수 없음. wcout으로 변경
    wcout.imbue(locale("kor"));
    wcout << wch << endl;   // 이 코드만 작성하면 한국어 인식 불가. 윗줄에 imbue 추가 필수

    //char str[] = { 'h', 'e', 'l', 'l', 'o' };   // 끝에 null을 넣어주지 않으면 뒤에 이상한 값이 따라온다.
    // char str[] = { 'h', 'e', 'l', 'l', 'o', '\0' };  // 값을 제대로 출력하고 싶다면 문자열 끝에 '\0(null)'을 추가해줘야 한다.
    cout << str << endl;
    cout << str2 << endl;
}