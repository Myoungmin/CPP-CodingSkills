#pragma once

// State ���� : ��ü�� ������ ���� ���� ���¸� Ŭ����ȭ�ϴ� ����.
// ������Ʈ ������ ������ ������Ʈ���� ���� ���¸� ������Ʈ�� ��, ������ ���¸� �����Ͽ� Ư�� ���·� ��ȯ�Ǿ�� �ϴ� ��Ȳ�� �� ����ϰ� �ȴ�.
// ������Ʈ ���ϰ� ��Ʈ��Ƽ�� ���Ͽ��� �� �� �ֵ���, ���������� ������ ������ ���� ��������� ������ �����Ѱ� �ƴϴ�.

// ���� �߻� �������̽�
class ActorState {
public:
	virtual ~ActorState() {}
	// ������Ʈ
	virtual void update(float time) = 0;
};


// ��� ����
class WaitState : public ActorState {
public:
	// ������
	WaitState(Actor* owner) : owner_(owner) {
		// ��� ������ �ʱ�ȭ ó��
	}
	// �Ҹ���
	virtual ~WaitState() {
		// ��� ������ ���� ó��
	}

	virtual void update(float time) override {
		// ��� ������ ����
		// ���� ������ Ȯ��
		if (owner_->isAttack()) {
			// ���� ���·� ����
			owner_->changeState(new AttackState(owner_));
		}
	}

private:
	Actor* owner_;	// ������ ������
};

// �ȱ� ����
class WalkState : public ActorState {
	// ...����
};

// ���� ����
class AttackState : public ActorState {
public:
	// ������
	AttackState(Actor* owner) : owner_(owner) {
		// ���� ������ �ʱ�ȭ ó��
	}
	// �Ҹ���
	virtual ~AttackState() {
		// ���� ������ ���� ó��
	}

	virtual void update(float time) override {
		// ���� ������ ����
	}

private:
	Actor* owner_;	// ������ ������
};

// ������ ����
class DamageState : public ActorState {
	// ...����
};


// ������Ʈ ������ �����ϸ�, Ŭ���̾�Ʈ ���� ���¸� ����, ����ġ ���ǹ��� �� �̻� �ʿ� ����.
class Actor {
public:
	Actor() : state_(nullptr) {
		// ��� ���¿��� ����
		changeState(new WaitState(this));
	}
	~Actor() {
		delete state_;
	}

	// ���� ������Ʈ
	void update(float time) {
		state_->update(time);	// ���� ������ ������Ʈ ����
	}

	// ���� ����
	void changeState(ActorState* state) {
		delete state_;	// ���� ���� ����
		state_ = state;	// ���ο� ���� ����
	}

	bool isAttack() {
		bool ret;

		// ���� ���� �Ǻ� ����

		return ret;
	}

	// ... ����

private:
	ActorState* state_;	// ���� ���� Ŭ����
};