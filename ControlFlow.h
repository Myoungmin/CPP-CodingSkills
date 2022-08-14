#pragma once
#include <cassert>
#include <utility>

// if 조건문을 줄이는 스킬.
// min 함수와 max 함수를 함께 사용하면 if, else if를 사용하지 않고도 상한값과 하한값을 모두 체크하고 보정할 수 있다.
// 상한값과 하한값을 보정하는 코드는 자주 사용하는 패턴이기 때문에 min 함수, max 함수를 이용하여 clamp 함수를 정의.
int clamp(int x, int low, int high)
{
	assert(low <= high);
	return std::min(std::max(x, low), high);
}