#pragma once
#include <utility>


//////// ���� Ŭ������ ����� �ǽ� //////////////////////////////////////////////////////////////////////////////////

/********************* Timer Ŭ���� *********************/

// timer_ ������ �ð��� �����ϱ� ���� float �ڷ����� ��� ����

/* Before */

//timer_ += deltaTime;	// Ÿ�̸� ������Ʈ
//if(timer_ >= 60.0f) {	// Ÿ�Ӿƿ��� �Ǿ����� Ȯ��
	// ���� �ð����� ó��
	// ... ����
	//timer_ = 0;	// Ÿ�̸� ����
//}


// timer_ ������ Timer Ŭ������ �ۼ�
class Timer {
public:
	// ������
	Timer(float limitTime) : time_(0), limitTime_(limitTime){}

	// ������Ʈ
	void update(float deltaTime) {
		time_ = std::min(time_ + deltaTime, limitTime_);
	}

	// ����
	void reset() {
		time_ = 0;
	}

	// Ÿ�Ӿƿ� �Ǿ����� Ȯ��
	bool isTimeout() const {
		return time_ >= limitTime_;
	}

private:
	float time_;	// ���� �ð�
	float limitTime_;	// ���� �ð�
};

// �� Timer Ŭ������ ����Ͽ� �ڵ� ���� ����
// �ڵ��� ���� ��ȭ�� ������, �ּ����� ���� �����ؾ� �ߴ� ���� Ŭ������ ǥ���� �� �ִ�.

/* After */

//timer_.update(deltaTime);
//if(timer_.isTimeout()) {
	// ���� �ð����� ó��
	// ... ����
	//timer_.reset();
//}

// �÷� �ڷ����� �������� ������ �ڷ����̴�.
// ���� �� ������ �ð� ����� ���õ� �뵵 �̿ܿ��� ����� �� �ִ�.
// �ݸ� Ÿ�̸� Ŭ���� �ν��Ͻ��� �ð� ���� �뵵�θ� ����Ѵ�.
// �ڵ��� �ǵ��� �� ��Ȯ�� ���� ���̴�.

// ������ Ŭ����ȭ�ؼ� �ǵ��� ��Ȯ�ϰ� ����������!