#pragma once

// 참고 : https://m.blog.naver.com/PostView.naver?isHttpsRedirect=true&blogId=egohim&logNo=70172856878
#define _USE_MATH_DEFINES
#include <cmath>

#include <iostream>

#include "Vector2.h"



class Circle {
public:
	// Circle 전용 렌더링 인터페이스
	// 내부 클래스로 Circle 클래스가 외부의 그리기 관련 클래스와 직접 결합하지 않게 해준다.
	// '의존 관계 역전 법칙' 적용
	class Renderer {
	public:
		virtual ~Renderer() {}
		// 렌더링
		virtual void draw(const Vector2& center, double radius) = 0;
	};

	// 생성자
	Circle(const Vector2& center, double radius) : center_(center), radius_(radius) {

	}

	// 렌더링
	void draw(Renderer& renderer) {
		renderer.draw(center_, radius_);
	}

	// 면적 계산
	double area() const {
		return radius_ * radius_ * M_PI;
	}

private:
	Vector2 center_;	// 중심
	double radius_;		// 반지름
};



// 추상 인터페이스를 사용하면 구체적인 구현 수단과의 의존 관계를 클래스 외부로 빼낼 수 있다.
// 그에 따라 구현 수단이 다른 환경에서도 재사용할 수 있는 클래스를 만들 수 있다.

// 콘솔 화면 전용
class ConsoleRenderer : public Circle::Renderer {
public:
	virtual void draw(const Vector2& center, double radius) override {
		std::cout << "x:" << center.x << " y:" << center.y
			<< " r:" << radius << std::endl;
	}
};

// 그래픽 화면을 위한 로직이 구현된 클래스
class Graphics {
public:
	void drawCircle(const Vector2& center, double radius) {
		// 그래픽 화면에 원을 그리기 위한 로직
	}
};

// 그래픽 화면 전용
class GraphicsRenderer : public Circle::Renderer {
public:
	GraphicsRenderer(Graphics& renderer) : renderer_(&renderer){

	}

	virtual void draw(const Vector2& center, double radius) override {
		renderer_->drawCircle(center, radius);
	}

private:
	Graphics* renderer_;	// 그래픽 화면 전용 렌더러
};