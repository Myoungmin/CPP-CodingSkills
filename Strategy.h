#pragma once

class Board {

};


// AI 추상 인터페이스
class AI {
public:
	virtual ~AI(){}
	// 사고
	virtual void think(Board& board) = 0;
};


// 쉬움 모드 AI
class EasyAI : public AI {
public:
	virtual void think(Board& board) override {
		// 쉬움 모드의 사고 알고리즘 구현
	}
};


// 보통 모드 AI
class NoramlAI : public AI {
public:
	virtual void think(Board& board) override {
		// 보통 모드의 사고 알고리즘 구현
	}
};


// 어려움 모드 AI
class HardAI : public AI {
	virtual void think(Board& board) override {
		// 어려움 모드의 사고 알고리즘 구현
	}
};


// Strategy 패턴 : 알고리즘이 변화하는 부분을 클래스화해서 교환할 수 있게 하는 패턴.
// 교환할 수 있는 알고리즘을 구현한 클래스가 바로 '전략'에 해당하고 이 실습에서는 AI 클래스들이다.
// 추상 인터페이스화한 AI 클래스를 사용하는 ComPlayer
class ComPlayer {
public:
	// 생성자로 추상화된 AI를 주입받는다.
	ComPlayer(AI* ai) : ai_(ai) {

	}

	// 소멸자
	virtual ~ComPlayer() {
		delete ai_;
	}

	// 사고
	// Strategy 패턴이 적용되는 부분, switch 조건문 없이 추상 인터페이스를 사용해서 구현 부분을 교환한다.
	void think(Board& board) {
		// 전략에 따라 알고리즘이 변경되어 동작이 달라진다.
		ai_->think(board);
	}

private:
	AI* ai_;	// AI 알고리즘
};