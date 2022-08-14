#pragma once
#include <cassert>
#include <utility>

//////// if 조건문을 줄이는 스킬. //////////////////////////////////////////////////////////////////////////////////


// min 함수와 max 함수를 함께 사용하면 if, else if를 사용하지 않고도 상한값과 하한값을 모두 체크하고 보정할 수 있다.
// 상한값과 하한값을 보정하는 코드는 자주 사용하는 패턴이기 때문에 min 함수, max 함수를 이용하여 clamp 함수를 정의.
int clamp(int x, int low, int high)
{
	assert(low <= high);
	return std::min(std::max(x, low), high);
}


// 랩 어라운드란, 어떤 숫자가 상한값에 이르면 하한값으로 돌려주고 다시 계산하는 것을 나타낸다.
// 하한값에서 상한값 사이의 숫자를 반복하고 싶을 때 사용한다.
// 조건문 대신 나머지 연산자를 사용하면 간단한 랩 어라운드를 사용할 수 있다.
// 부동소수점 자료형에 대응하려면 fmod 함수를 사용해야한다.
float wrap(float x, float low, float high)
{
	assert(low < high);
	const float n = std::fmod(x - low, high - low);
	return (n >= 0) ? (n + low) : (n + high);
}