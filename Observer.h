#pragma once
#include <functional>


// Observer ���� : � ��ü�� ���� ��ȭ�� �ٸ� ��ü�� �������ִ� ����.
// GUI ��ư�� �̺�Ʈ ���� � ���� ���ȴ�.
// C++11�� ���ٽİ� STL�� function Ŭ������ ����ϸ� �����ϰ� ������ �� �ִ�.


// ��ư Ŭ����(Observer�� �����ϴ� ����)
class Button {
public:
	//// Observer ���� ���
	//void attachListener(std::function<void(void)> listener) {
	//	listener_ = listener;
	//}

	// Observer�� ���� �� ���
	// ���ٽ����� function Ŭ������ �ռ��ϸ� Observer�� ���� ������ ���� ���� �ִ�.
	void attachListener(std::function<void(void)> listener) {
		// ���� Observer
		const auto& current = listener_;
		// ���ٽ����� ���ο� ������ �߰�
		listener_ = [=] {current(); listener(); };
	}

	// Ŭ��
	void click() {
		// ��ư�� Ŭ���Ǿ��� �� �����ڿ� ����
		listener_();
	}

private:
	// �̺�Ʈ�� ���� ���� Observer
	// �̺�Ʈ ������ �޴� ó���� ���ٽ� ���ο� ���� �ۼ��� �� �ִ�.
	std::function<void(void)> listener_ = [] {};	// �� ���ٽ�

	// ...����
};


// Ÿ��Ʋ �� Ŭ����
class TitleScene {
public:
	void initialize() {
		// ��ư�� ������ ���
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