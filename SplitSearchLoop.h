#pragma once
#include <stdio.h>
#include <vector>
#include "Vector2.h"



/////////////////////////////////////////////////////////////////////

/******************** ���� ã�� ���� ���� ********************/

// ���� ���� : expression must have arithmetic or pointer type

// ���� : ���ڸ� ��ȯ�ؾ��ϴ� �Լ��� ��ȯ���� void�� �����ؼ� �߻��ߴ� ����


//////////////////////////////////////////////////////////////////////






/****************************************************************************************************************/

/******************** �˻� �ݺ��� �и� ********************/

class Actor {
public:
	// ...����	
	// �̵�
	virtual void move() = 0;
	// ������
	virtual void draw() = 0;
	// �Ÿ�
	// �� �κ� ��ȯ���� void�� �ؼ� ���� �� �� ã�µ� �ð��� ��û ���....
	virtual float distance(const Vector2& postion) = 0;
};

std::vector<Actor*> actors;

void attack(Actor* actor) {

}


///////////////////////////////////////////////////////////

/* '�� �������� �ݺ�'�Ѵٴ� �ݺ����� ��Ģ�� ���� */

void Before(const Vector2& position) {
	// ���� ���� ���ο� �ִ� ĳ���͸� �˻��ϰ� ����
	for (std::vector<Actor*>::iterator i = actors.begin(); i != actors.end(); i++)
	{
		if ((*i)->distance(position) <= 5) {
			attack(*i);
			break;
		}
	}
}

///////////////////////////////////////////////////////////


/* �˻� �κ��� �и��ϸ� STL�� find_if �Լ��� ����� �� �ִ�. */

void Step1(const Vector2& position){
	// ���� ���� ���ο� �ִ� ĳ���� �˻�
	auto target = std::find_if(actors.begin(), actors.end(),
		[&](Actor* actor) {return actor->distance(position) <= 5; });

	// ���� ���� ���ο� �ִٸ� ����
	if (target != actors.end()) {
		// ����
		attack(*target);
	}
}

/* �˻� �κ� �Լ�ȭ */

// ���� ���� ���ο� �ִ� ĳ���� ����
Actor* findTarget(const Vector2& position, float range) {
	auto target = std::find_if(actors.begin(), actors.end(),
		[&](Actor* actor) {return actor->distance(position) <= range; });

	return (target != actors.end()) ? *target : nullptr;
}

///////////////////////////////////////////////////////////

/* �˻� �ݺ����� �и��ؼ� �Լ�ȭ�� ��� */
void Result() {
	const Vector2 position;
	auto target = findTarget(position, 5);

	if (target != nullptr) {
		attack(target);
	}
}

///////////////////////////////////////////////////////////

/****************************************************************************************************************/