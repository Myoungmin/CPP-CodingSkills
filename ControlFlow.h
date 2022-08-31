#pragma once
#include <cassert>
#include <utility>

//////// if 조건문을 줄이는 스킬. //////////////////////////////////////////////////////////////////////////////////

/* 하한값, 상한값 체크 단순화 */

// min 함수와 max 함수를 함께 사용하면 if, else if를 사용하지 않고도 상한값과 하한값을 모두 체크하고 보정할 수 있다.
// 상한값과 하한값을 보정하는 코드는 자주 사용하는 패턴이기 때문에 min 함수, max 함수를 이용하여 clamp 함수를 정의.
int clamp(int x, int low, int high)
{
	assert(low <= high);
	return std::min(std::max(x, low), high);
}

/* 랩 어라운드의 함수화 */

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

/* 결정표를 사용한 if 조건문 제거 */

enum Hand {
	Rock,
	Scissors,
	Paper,
};
enum Result {
	Win,
	Lose,
	Draw,
};

// 결정표는 판정 조건의 조합과 그에 대응하는 결과를 정리한 표를 말한다.
// 코드의 보수성을 높이려면 이프 조건문을 사용하지 않고 해결할 방법을 생각하는 것이 중요하다.
// 결정표와 같은 자료 구조를 사용하는 방법은 코드를 단순하게 만들어주고 실수도 줄여준다.
Result judgement(Hand my, Hand target)
{
	// 가위바위보 판정
	static const Result result[3][3] = {
		// 바위 가위 보 (상대방)
		{Draw, Win, Lose}, // 바위 (자신)
		{Lose, Draw, Win}, // 가위
		{Win, Lose, Draw}, // 보
	};
	return result[my][target];
}


/****************************************************************************************************************/

/* 조건식이 직접적으로 관련된 부분을 국소화하는 과정에 대한 단계별 변화 */

bool isDash()
{
	return true;
}

float position;
float direction;

const float SPEED_DASH = 10.0f;
const float SPEED_Normal = 5.0f;

//////////////////////////////////////////////////

/* 변경 전 */
void Before() {
	if (isDash) {	// 대시 중인지 확인
		position += direction * 10.0f;	// 대시 중에는 속도가 2배
	}
	else {
		position += direction * 5.0f;
	}
}

//////////////////////////////////////////////////

/* 속도 변화 부분만 따로 빼서 국소화 */
void Step1() {
	float speed = 5.0f;
	if (isDash()) {	// 대시 중인지 확인
		speed = 10.0f;	// 대시 중에는 속도가 2배
	}
	position += direction * speed;
}

/* speed 연산 부분 함수화 */
float speed() {
	//// if문 사용
	//if (isDash()) return 10.0f;
	//return 5.0f;

	//// 삼항 연산자 사용
	//return isDash() ? 10.0f : 5.0f;

	// 삼항 연산자와 매직 넘버 사용
	return isDash() ? SPEED_DASH : SPEED_Normal;
}


//////////////////////////////////////////////////

/* if 조건문을 없애고 중복된 계산식이 없어진 결과 */
void Result() {
	position += direction * speed();
}

//////////////////////////////////////////////////

/****************************************************************************************************************/