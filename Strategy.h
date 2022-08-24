#pragma once

class Board {

};


// AI �߻� �������̽�
class AI {
public:
	virtual ~AI(){}
	// ���
	virtual void think(Board& board) = 0;
};


// ���� ��� AI
class EasyAI : public AI {
public:
	virtual void think(Board& board) override {
		// ���� ����� ��� �˰��� ����
	}
};


// ���� ��� AI
class NoramlAI : public AI {
public:
	virtual void think(Board& board) override {
		// ���� ����� ��� �˰��� ����
	}
};


// ����� ��� AI
class HardAI : public AI {
	virtual void think(Board& board) override {
		// ����� ����� ��� �˰��� ����
	}
};


// Strategy ���� : �˰����� ��ȭ�ϴ� �κ��� Ŭ����ȭ�ؼ� ��ȯ�� �� �ְ� �ϴ� ����.
// ��ȯ�� �� �ִ� �˰����� ������ Ŭ������ �ٷ� '����'�� �ش��ϰ� �� �ǽ������� AI Ŭ�������̴�.
// �߻� �������̽�ȭ�� AI Ŭ������ ����ϴ� ComPlayer
class ComPlayer {
public:
	// �����ڷ� �߻�ȭ�� AI�� ���Թ޴´�.
	ComPlayer(AI* ai) : ai_(ai) {

	}

	// �Ҹ���
	virtual ~ComPlayer() {
		delete ai_;
	}

	// ���
	// Strategy ������ ����Ǵ� �κ�, switch ���ǹ� ���� �߻� �������̽��� ����ؼ� ���� �κ��� ��ȯ�Ѵ�.
	void think(Board& board) {
		// ������ ���� �˰����� ����Ǿ� ������ �޶�����.
		ai_->think(board);
	}

private:
	AI* ai_;	// AI �˰���
};