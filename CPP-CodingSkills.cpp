#include <iostream>
#include "ControlFlow.h"
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


int main()
{
    ClampExample();
}