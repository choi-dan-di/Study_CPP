#include <iostream>
using namespace std;

// 문자열 관련 함수 만들어보기

// 1. 문자열의 길이를 반환해주는 함수
int StrLen(const char* str) {
    int ret = 0;

    while (str[ret]) {
        ret++;
    }

    return ret;
}

// 2. 문자열 복사 함수
void StrCpy(char* dest, char* src) {
    // src -> dest
    int i = 0;
    while (src[i]) {
        dest[i] = src[i];
        i++;
    }

    dest[i] = '\0';
}

// 포인터 사용 버전
void StrCpyByPtr(char* dest, char* src) {
    // src -> dest
    char* ret = dest;

    while (*src) {
        *dest = *src;
        dest++;
        src++;
    }

    *dest = '\0';

    // 반환 타입이 있을 경우
    //return ret;
}

// 3. 문자열 덧붙이는 함수
void StrCat(char* dest, char* src) {
    // dest 뒤에 src 붙이기
    int i = 0;
    int len = StrLen(dest);
    while (src[i]) {
        dest[len + i] = src[i];
        i++;
    }

    dest[len + i] = '\0';
}

// 포인터 사용 버전
void StrCatByPtr(char* dest, char* src) {
    // dest 뒤에 src 붙이기
    while (*dest) dest++;
    while (*src) *dest++ = *src++;
    *dest = '\0';
}

// 4. 두 개의 문자열 비교
int StrCmp(char* a, char* b) {
    int aLen = StrLen(a);
    int bLen = StrLen(b);

    if (aLen > bLen) return 1;
    else if (aLen < bLen) return -1;

    // 길이 같으면
    for (int i = 0; i < aLen; i++) {
        if (a[i] > b[i]) return 1;
        else if (a[i] < b[i]) return -1;
    }

    return 0;
}

// 포인터 사용 버전
int StrCmpByPtr(char* a, char* b) {
    int aLen = StrLen(a);
    int bLen = StrLen(b);

    if (aLen > bLen) return 1;
    else if (aLen < bLen) return -1;

    // 길이 같으면
    while (*a) {
        if (*a > *b) return 1;
        else if (*a < *b) return -1;

        a++;
        b++;
    }

    return 0;
}

// 5. 문자열을 뒤집는 함수
void ReverseStr(char* str) {
    // Hello World -> dlroW olleH
    int len = StrLen(str);

    for (int i = 0; i < len / 2; i++) {
        int temp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = temp;
    }
}

// 포인터 사용 버전
void ReverseStrByPtr(char* str) {
    // Hello World -> dlroW olleH
    int len = StrLen(str);

    for (int i = 0; i < len / 2; i++) {
        char temp = *(str + i);
        *(str + i) = *(str + len - 1 - i);
        *(str + len - 1 - i) = temp;
    }
}

#pragma warning(disable: 4996)
int main()
{
    const int BUF_SIZE = 100;

    char a[BUF_SIZE] = "Hello World";
    char b[BUF_SIZE] = "Hello";

    //int len = strlen(a);
    //int len2 = sizeof(a);
    int len = StrLen(a);
    cout << len << endl;
    //cout << a;

    // strcpy(b, a);
    // StrCpy(b, a);
    // StrCpyByPtr(b, a);
    // for (char it : b) cout << it << " ";

    // strcat(a, b);
    // StrCat(a, b);
    // for (char it : a) cout << it << " ";

    // strcmp(a, b);
    // int ret = StrCmp(a, b);
    // int ret = StrCmpByPtr(a, b);
    // cout << ret << endl;

    ReverseStr(a);
    cout << a << endl;

    return 0;
}