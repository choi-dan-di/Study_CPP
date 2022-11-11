#include <iostream>
using namespace std;

int main()
{
#pragma region 내가 만든 코드
    // 조금만 수정해주기
    srand(time(0));

    const int SCISSORS = 1;
    const int ROCK = 2;
    const int PAPER = 3;

    int round = 0;
    int win = 0;

    while(true)
    {

        // 1 2 3
        int comInput = (rand() % 3) + 1;

        int userInput;

        cout << "Round : " << round << ", win : " << win << endl;

        cout << "가위(1) 바위(2) 보(3) 골라주세요!" << endl;
        
        float winrate = 0;
        if (round > 0)
            winrate = (win / (float)round) * 100;

        cout << "> 현재 승률 : " << winrate << "%" << endl;
        cout << "> ";
        cin >> userInput;

        if (userInput > 3)
            break;

        switch (userInput)
        {
            case SCISSORS:
                cout << "가위(유저)";
                break;
            case ROCK:
                cout << "바위(유저)";
                break;
            case PAPER:
                cout << "보(유저)";
                break;
        }

        cout << " vs ";

        switch (comInput)
        {
            case SCISSORS:
                cout << "가위(컴퓨터)";
                break;
            case ROCK:
                cout << "바위(컴퓨터)";
                break;
            case PAPER:
                cout << "보(컴퓨터)";
                break;
        }

        cout << " 결과 : ";

        // 1, 2 -> 2    // -1 패
        // 1, 3 -> 1    // -2 승
        // 2, 1 -> 2    // 1 승
        // 2, 3 -> 3    // -1 패
        // 3, 1 -> 1    // 2 패
        // 3, 2 -> 3    // 1 승
        if (userInput == comInput)
        {
            cout << "무승부입니다!" << endl;
        }
        else
        {
            int diff = userInput - comInput;
            if (diff == -1 || diff == 2)
                cout << "졌습니다!" << endl;
            else
            {
                cout << "이겼습니다!" << endl;
                win++;
            }
            cout << endl;

            round++;
        }
    }
#pragma endregion

#pragma region 강사님 코드
    /*
    srand(time(0));

    const int SCISSORS = 1;
    const int ROCK = 2;
    const int PAPER = 3;

    while (true)
    {
        cout << "가위(1) 바위(2) 보(3) 골라주세요!" << endl;
        cout << "> ";

        // 컴퓨터
        int comInput = (rand() % 3) + 1;

        // 유저
        int userInput;
        cin >> userInput;

        if (userInput == SCISSORS)
        {
            switch (comInput)
            {
            case SCISSORS:
                cout << "가위(유저) vs 가위(컴퓨터) 결과 : 무승부입니다!" << endl;
                break;
            case ROCK:
                cout << "가위(유저) vs 바위(컴퓨터) 결과 : 졌습니다!" << endl;
                break;
            case PAPER:
                cout << "가위(유저) vs 보(컴퓨터) 결과 : 이겼습니다!" << endl;
                break;
            }
        }
        else if (userInput == ROCK)
        {
            switch (comInput)
            {
            case SCISSORS:
                cout << "바위(유저) vs 가위(컴퓨터) 결과 : 이겼습니다!" << endl;
                break;
            case ROCK:
                cout << "바위(유저) vs 바위(컴퓨터) 결과 : 무승부입니다!" << endl;
                break;
            case PAPER:
                cout << "바위(유저) vs 보(컴퓨터) 결과 : 졌습니다!" << endl;
                break;
            }
        }
        else if (userInput == PAPER)
        {
            switch (comInput)
            {
            case SCISSORS:
                cout << "보(유저) vs 가위(컴퓨터) 결과 : 졌습니다!" << endl;
                break;
            case ROCK:
                cout << "보(유저) vs 바위(컴퓨터) 결과 : 이겼습니다!" << endl;
                break;
            case PAPER:
                cout << "보(유저) vs 보(컴퓨터) 결과 : 무승부입니다!" << endl;
                break;
            }
        }
        else
        {
            // 예외의 값이 나오면 반복문(while(true)) 탈출
            break;
        }
    }
    */
#pragma endregion
}