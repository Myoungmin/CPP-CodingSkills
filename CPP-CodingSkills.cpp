#include <iostream>
#include "ControlFlow.h"
#include "Functionalization.h"
using namespace std;

void ClampExample()
{
    int x = 10;
    // 8 출력
    cout << clamp(x, 5, 8) << endl;
    // 11 출력
    cout << clamp(x, 11, 15) << endl;
    // 10 출력
    cout << clamp(x, 7, 12) << endl;
    // clamp 함수의 assert 테스트
    cout << clamp(x, 12, 7) << endl;
}

void WrapExample()
{
    int x = 8;
    // 3 출력
    cout << wrap(x, 0, 5) << endl;
}

void JudgementExample()
{
    // Win : 0 출력
    cout << judgement(Rock, Scissors) << endl;
    // Lose : 1 출력
    cout << judgement(Rock, Paper) << endl;
    // Draw : 2 출력
    cout << judgement(Rock, Rock) << endl;
}

void WeekToNameAndNameToWeekExample()
{
    // "Sat" 출력
    cout << to_String(Week::Saturday) << endl;
    // "Sun" 출력, enum class로 변경했다가 다시 문자열로 변경
    cout << to_String(to_week("Sun")) << endl;
}



/* case에 반드시 일치해야 하는 경우, default에 assert를 적어 부정확한 상태를 방지하는 실습 */

void SwitchDefaultAssert()
{
    enum STATE {
        STATE_RUN,
        STATE_JUMP,
        STATE_DAMAGE,
        STATE_ERROR
    };

    STATE state = STATE_ERROR;

    switch (state) {
    case STATE_RUN:
        // RUN 로직 생략
        break;
    case STATE_JUMP:
        // JUMP 로직 생략
        break;
    case STATE_DAMAGE:
        // DAMAGE 로직 생략
        break;
    default:
        // 부정확한 상태일 때 assert가 실행되어 아래와 같은 메시지가 표시된다.
        // Assertion failed: !"부정확한 상태", file CPP-CodingSkills.cpp, line 67
        // 문자열에 !(논리 부정 연산자)를 붙이면 true가 반전되어 false로 평가되어 assert가 오류라고 판단하게 된다.
        assert(!"부정확한 상태");
        break;
    }
}

int main()
{
    //ClampExample();
    //WrapExample();
    //JudgementExample();
    //WeekToNameAndNameToWeekExample();
    SwitchDefaultAssert();
}