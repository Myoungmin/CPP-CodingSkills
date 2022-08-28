#pragma once

// ���� : https://m.blog.naver.com/PostView.naver?isHttpsRedirect=true&blogId=egohim&logNo=70172856878
#define _USE_MATH_DEFINES
#include <cmath>

#include <iostream>

#include "Vector2.h"



class Circle {
public:
	// Circle ���� ������ �������̽�
	// ���� Ŭ������ Circle Ŭ������ �ܺ��� �׸��� ���� Ŭ������ ���� �������� �ʰ� ���ش�.
	// '���� ���� ���� ��Ģ' ����
	class Renderer {
	public:
		virtual ~Renderer() {}
		// ������
		virtual void draw(const Vector2& center, double radius) = 0;
	};

	// ������
	Circle(const Vector2& center, double radius) : center_(center), radius_(radius) {

	}

	// ������
	void draw(Renderer& renderer) {
		renderer.draw(center_, radius_);
	}

	// ���� ���
	double area() const {
		return radius_ * radius_ * M_PI;
	}

private:
	Vector2 center_;	// �߽�
	double radius_;		// ������
};



// �߻� �������̽��� ����ϸ� ��ü���� ���� ���ܰ��� ���� ���踦 Ŭ���� �ܺη� ���� �� �ִ�.
// �׿� ���� ���� ������ �ٸ� ȯ�濡���� ������ �� �ִ� Ŭ������ ���� �� �ִ�.

// �ܼ� ȭ�� ����
class ConsoleRenderer : public Circle::Renderer {
public:
	virtual void draw(const Vector2& center, double radius) override {
		std::cout << "x:" << center.x << " y:" << center.y
			<< " r:" << radius << std::endl;
	}
};

// �׷��� ȭ���� ���� ������ ������ Ŭ����
class Graphics {
public:
	void drawCircle(const Vector2& center, double radius) {
		// �׷��� ȭ�鿡 ���� �׸��� ���� ����
	}
};

// �׷��� ȭ�� ����
class GraphicsRenderer : public Circle::Renderer {
public:
	GraphicsRenderer(Graphics& renderer) : renderer_(&renderer){

	}

	virtual void draw(const Vector2& center, double radius) override {
		renderer_->drawCircle(center, radius);
	}

private:
	Graphics* renderer_;	// �׷��� ȭ�� ���� ������
};