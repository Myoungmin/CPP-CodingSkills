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

int main()
{
    //ClampExample();
    //WrapExample();
    //JudgementExample();
    WeekToNameAndNameToWeekExample();
}