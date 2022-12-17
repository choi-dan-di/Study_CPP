#include <iostream>
#include <vector>
using namespace std;

// 연습 문제

int main()
{
    srand(static_cast<unsigned int>(time(nullptr)));

    vector<int> v;

    for (int i = 0; i < 100; i++) {
        int num = rand() % 100;
        v.push_back(num);
    }

    // Q1) number라는 숫자가 벡터에 있는지 체크하는 기능 (return type : bool or 첫 등장 iterator)
    {
        int number = 50;

        bool found = false;
        vector<int>::iterator it;

        // TODO
        // 약간 아쉬운 코드.. 분석하는 데 시간이 많이 걸림 => 알고리즘 사용하여 보다 효율적으로 작성함이 권장됨
        for (unsigned int i = 0; i < v.size(); i++) {
            if (v[i] == number) {
                found = true;
                it = v.begin() + i;
                break;
            }
        }

        cout << "A1) " << (found == 1 ? "true" : "false") << endl;
    }

    cout << "------------------------------------\n";

    // Q2) 11로 나뉘는 숫자가 벡터에 있는지 체크하는 기능 (return type : bool or 첫 등장 iterator)
    {
        bool found = false;
        vector<int>::iterator it;

        // TODO
        for (unsigned int i = 0; i < v.size(); i++) {
            if (v[i] % 11 == 0) {
                found = true;
                it = v.begin() + i;
                break;
            }
        }

        cout << "A2) " << (found == 1 ? "true" : "false") << endl;
    }

    cout << "------------------------------------\n";

    // Q3) 홀수인 숫자의 개수는? (count)
    {
        int count = 0;

        // TODO
        for (unsigned int i = 0; i < v.size(); i++) {
            if (v[i] % 2 != 0) count++;
        }

        cout << "A3) " << count << endl;
    }

    cout << "------------------------------------\n";

    // Q4) 벡터에 들어가 있는 모든 숫자들에 3을 곱해주세요!
    {
        for (unsigned int i = 0; i < v.size(); i++)
            v[i] *= 3;

        cout << "A4) " << endl;

        for (vector<int>::iterator it = v.begin(); it != v.end(); ++it)
            cout << (*it) << endl;
    }

    return 0;
}