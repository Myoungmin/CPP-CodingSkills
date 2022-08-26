#pragma once

// State 패턴 : 객체가 가지는 여러 가지 상태를 클래스화하는 패턴.
// 스테이트 패턴은 각각의 스테이트에서 현재 상태를 업데이트할 때, 스스로 상태를 변경하여 특정 상태로 전환되어야 하는 상황일 때 사용하게 된다.
// 스테이트 패턴과 스트래티지 패턴에서 알 수 있듯이, 지오에프의 디자인 패턴은 구현 방법만으로 패턴을 구분한게 아니다.

// 상태 추상 인터페이스
class ActorState {
public:
	virtual ~ActorState() {}
	// 업데이트
	virtual void update(float time) = 0;
};


// 대기 상태
class WaitState : public ActorState {
public:
	// 생성자
	WaitState(Actor* owner) : owner_(owner) {
		// 대기 상태의 초기화 처리
	}
	// 소멸자
	virtual ~WaitState() {
		// 대기 상태의 종료 처리
	}

	virtual void update(float time) override {
		// 대기 상태의 구현
		// 전투 중인지 확인
		if (owner_->isAttack()) {
			// 공격 상태로 변경
			owner_->changeState(new AttackState(owner_));
		}
	}

private:
	Actor* owner_;	// 상태의 소유자
};

// 걷기 상태
class WalkState : public ActorState {
	// ...생략
};

// 공격 상태
class AttackState : public ActorState {
public:
	// 생성자
	AttackState(Actor* owner) : owner_(owner) {
		// 전투 상태의 초기화 처리
	}
	// 소멸자
	virtual ~AttackState() {
		// 전투 상태의 종료 처리
	}

	virtual void update(float time) override {
		// 전투 상태의 구현
	}

private:
	Actor* owner_;	// 상태의 소유자
};

// 데미지 상태
class DamageState : public ActorState {
	// ...생략
};


// 스테이트 패턴을 적용하면, 클라이언트 현재 상태만 갖고, 스위치 조건문은 더 이상 필요 없다.
class Actor {
public:
	Actor() : state_(nullptr) {
		// 대기 상태에서 시작
		changeState(new WaitState(this));
	}
	~Actor() {
		delete state_;
	}

	// 상태 업데이트
	void update(float time) {
		state_->update(time);	// 현재 상태의 업데이트 실행
	}

	// 상태 변경
	void changeState(ActorState* state) {
		delete state_;	// 이전 상태 제거
		state_ = state;	// 새로운 상태 설정
	}

	bool isAttack() {
		bool ret;

		// 공격 여부 판별 구현

		return ret;
	}

	// ... 생략

private:
	ActorState* state_;	// 현재 상태 클래스
};