#pragma once
#include <utility>


//////// 작은 클래스를 만드는 실습 //////////////////////////////////////////////////////////////////////////////////

/********************* Timer 클래스 *********************/

// timer_ 변수는 시간을 측정하기 위한 float 자료형의 멤버 변수

/* Before */

//timer_ += deltaTime;	// 타이머 업데이트
//if(timer_ >= 60.0f) {	// 타임아웃이 되었는지 확인
	// 일정 시간마다 처리
	// ... 생략
	//timer_ = 0;	// 타이머 리셋
//}


// timer_ 변수를 Timer 클래스로 작성
class Timer {
public:
	// 생성자
	Timer(float limitTime) : time_(0), limitTime_(limitTime){}

	// 업데이트
	void update(float deltaTime) {
		time_ = std::min(time_ + deltaTime, limitTime_);
	}

	// 리셋
	void reset() {
		time_ = 0;
	}

	// 타임아웃 되었는지 확인
	bool isTimeout() const {
		return time_ >= limitTime_;
	}

private:
	float time_;	// 현재 시각
	float limitTime_;	// 제한 시간
};

// 위 Timer 클래스를 사용하여 코드 변경 형태
// 코드의 양은 변화가 없지만, 주석으로 따로 설명해야 했던 것을 클래스로 표현할 수 있다.

/* After */

//timer_.update(deltaTime);
//if(timer_.isTimeout()) {
	// 일정 시간마다 처리
	// ... 생략
	//timer_.reset();
//}

// 플롯 자료형은 범용적인 데이터 자료형이다.
// 따라서 이 변수는 시간 제어와 관련된 용도 이외에도 사용할 수 있다.
// 반면 타이머 클래스 인스턴스는 시간 제어 용도로만 사용한다.
// 코드의 의도가 더 명확해 지는 것이다.

// 변수를 클래스화해서 의도를 명확하게 전달해주자!