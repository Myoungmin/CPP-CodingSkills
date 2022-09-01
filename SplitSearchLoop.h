#pragma once
#include <stdio.h>
#include <vector>
#include "Vector2.h"



/////////////////////////////////////////////////////////////////////

/******************** 오류 찾는 시행 착오 ********************/

// 오류 내용 : expression must have arithmetic or pointer type

// 원인 : 숫자를 반환해야하는 함수의 반환값을 void로 정의해서 발생했던 문제


//////////////////////////////////////////////////////////////////////






/****************************************************************************************************************/

/******************** 검색 반복문 분리 ********************/

class Actor {
public:
	// ...생략	
	// 이동
	virtual void move() = 0;
	// 렌더링
	virtual void draw() = 0;
	// 거리
	// 이 부분 반환값을 void로 해서 에러 난 것 찾는데 시간을 엄청 썼다....
	virtual float distance(const Vector2& postion) = 0;
};

std::vector<Actor*> actors;

void attack(Actor* actor) {

}


///////////////////////////////////////////////////////////

/* '한 가지만을 반복'한다는 반복문의 원칙을 위반 */

void Before(const Vector2& position) {
	// 공격 범위 내부에 있는 캐릭터를 검색하고 공격
	for (std::vector<Actor*>::iterator i = actors.begin(); i != actors.end(); i++)
	{
		if ((*i)->distance(position) <= 5) {
			attack(*i);
			break;
		}
	}
}

///////////////////////////////////////////////////////////


/* 검색 부분을 분리하면 STL의 find_if 함수를 사용할 수 있다. */

void Step1(const Vector2& position){
	// 공격 범위 내부에 있는 캐릭터 검색
	auto target = std::find_if(actors.begin(), actors.end(),
		[&](Actor* actor) {return actor->distance(position) <= 5; });

	// 공격 범위 내부에 있다면 공격
	if (target != actors.end()) {
		// 공격
		attack(*target);
	}
}

/* 검색 부분 함수화 */

// 공격 범위 내부에 있는 캐릭터 공격
Actor* findTarget(const Vector2& position, float range) {
	auto target = std::find_if(actors.begin(), actors.end(),
		[&](Actor* actor) {return actor->distance(position) <= range; });

	return (target != actors.end()) ? *target : nullptr;
}

///////////////////////////////////////////////////////////

/* 검색 반복문을 분리해서 함수화한 결과 */
void Result() {
	const Vector2 position;
	auto target = findTarget(position, 5);

	if (target != nullptr) {
		attack(target);
	}
}

///////////////////////////////////////////////////////////

/****************************************************************************************************************/