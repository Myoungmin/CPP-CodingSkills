#pragma once
#include <functional>


// Observer 패턴 : 어떤 객체의 상태 변화를 다른 객체에 통지해주는 패턴.
// GUI 버튼의 이벤트 통지 등에 많이 사용된다.
// C++11의 람다식과 STL의 function 클래스를 사용하면 간단하게 구현할 수 있다.


// 버튼 클래스(Observer에 통지하는 역할)
class Button {
public:
	//// Observer 단일 등록
	//void attachListener(std::function<void(void)> listener) {
	//	listener_ = listener;
	//}

	// Observer를 여러 개 등록
	// 람다식으로 function 클래스를 합성하면 Observer를 여러 명으로 만들 수도 있다.
	void attachListener(std::function<void(void)> listener) {
		// 현재 Observer
		const auto& current = listener_;
		// 람다식으로 새로운 관측자 추가
		listener_ = [=] {current(); listener(); };
	}

	// 클릭
	void click() {
		// 버튼이 클릭되었을 때 관측자에 통지
		listener_();
	}

private:
	// 이벤트를 통지 받을 Observer
	// 이벤트 통지를 받는 처리는 람다식 내부에 직접 작성할 수 있다.
	std::function<void(void)> listener_ = [] {};	// 빈 람다식

	// ...생략
};


// 타이틀 씬 클래스
class TitleScene {
public:
	void initialize() {
		// 버튼에 리스너 등록
		startButton_.attachListener([=] {changeScene(); });
	}

	void changeScene() {

	}

	void buttonClick() {
		startButton_.click();
	}

private:
	Button startButton_;
};