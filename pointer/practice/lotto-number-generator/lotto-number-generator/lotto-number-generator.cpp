#include <iostream>
using namespace std;

// 로또 번호 생성기 만들어보기
bool CheckDuplication(int numbers[]);

// 1. Swap 함수 만들기
void Swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// 2. 정렬 함수 만들기 (작은 숫자가 먼저 오도록 정렬)
void Sort(int numbers[], int count) {
    int temp = 0;
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (numbers[i] > numbers[j]) {
                Swap(numbers[i], numbers[j]);
            }
        }
    }
}

// 3. 로또 번호 생성기
void ChooseLotto(int numbers[]) {
    // TODO : 랜덤으로 1~45 사이의 숫자 6개 골라서 numbers에 넣기 (단, 중복이 없어야 함)
    srand((unsigned)time(0));
    
    bool hasDuplication = false;
    for (int i = 0; i < 6; i++) {
        numbers[i] = (rand() % 45) + 1;
    }

    hasDuplication = CheckDuplication(numbers);

    // 중복 체크
    while (hasDuplication) {
        for (int i = 0; i < 6; i++) {
            if (numbers[i] == 0) numbers[i] = (rand() % 45) + 1;
        }

        hasDuplication = CheckDuplication(numbers);
    }

    // 정렬
    Sort(numbers, 6);
}

// 중복 체크 함수 만들기
bool CheckDuplication(int numbers[]) {
    bool ret = false;
    for (int i = 0; i < 5; i++) {
        for (int j = i + 1; j < 6; j++) {
            if (numbers[i] == numbers[j]) {
                // 중복 있으면 뒤 숫자 0으로 바꿈
                numbers[j] = 0;
                ret = true;
            }
        }
    }

    return ret;
}

int main()
{
    // 1. Swap 함수 만들기
    int a = 1;
    int b = 2;
    Swap(a, b);
    cout << a << " " << b << endl;

    // 2. 정렬 함수 만들기 (작은 숫자가 먼저 오도록 정렬)
    int numbers[6] = {1, 42, 3, 15, 5, 6};
    Sort(numbers, sizeof(numbers) / sizeof(int));
    // 1, 3, 5, 6, 15, 42
    for (int i : numbers) cout << i << " ";

    cout << endl;
    cout << "--------------------------\n";

    // 3. 로또 번호 생성기
    int numbers2[6] = {0, 0, 0, 0, 0, 0};
    ChooseLotto(numbers2);
    for (int i : numbers2) cout << i << " ";

    return 0;
}