#pragma once

// 2D 벡터 클래스
class Vector2 {
public:
	float x;	// x 좌표
	float y;	// y 좌표

	// 생성자
	Vector2(float x = 0, float y = 0) : x(x), y(y) {}

	// 내적 계산
	float dot(const Vector2& other) const {
		return (x * other.x) + (y * other.y);
	}

	// 외적 계산
	float cross(const Vector2& other) const {
		return (x * other.y) - (y * other.x);
	}

	// 길이 계산
	float length() const {
		return std::sqrt(dot(*this));
	}

	// 거리 계산
	float distance(const Vector2& other) const {
		return (*this - other).length();
	}

	// 정규화
	Vector2 normalize() const {
		const float len = length();
		if (len < FLT_EPSILON) {
			return Vector2::ZERO;
		}
		return *this / len;
	}

	// 제로 벡터인지 확인
	bool isZero() const {
		return *this == Vector2::ZERO;
	}


	// 연산자 오버로드
	Vector2& operator += (const Vector2& other) {
		return *this = *this + other;
	}

	Vector2& operator -= (const Vector2& other) {
		return *this = *this - other;
	}

	Vector2& operator *= (float scalar) {
		return *this = *this * scalar;
	}

	Vector2& operator /= (float scalar) {
		return *this = *this / scalar;
	}

	const Vector2 operator + (const Vector2& other) const {
		return Vector2(x + other.x, y + other.y);
	}

	const Vector2 operator - (const Vector2& other) const {
		return Vector2(x - other.x, y - other.y);
	}

	const Vector2 operator * (float scalar) const {
		return Vector2(x * scalar, y * scalar);
	}

	const Vector2 operator / (float scalar) const {
		return Vector2(x / scalar, y / scalar);
	}

	const Vector2 operator - () const {
		return Vector2(-x, -y);
	}

	bool operator == (const Vector2& other) const {
		return (x == other.x) && (y == other.y);
	}

	bool operator != (const Vector2& other) const {
		return !(*this == other);
	}

	bool operator < (const Vector2& other) const {
		if (x != other.x) return x < other.x;
		if (y != other.y) return y < other.y;
		return false;
	}

	// 상수
	static const Vector2 ZERO;	// 제로 벡터
	static const Vector2 LEFT;	// 왼쪽
	static const Vector2 RIGHT;	// 오른쪽
	static const Vector2 DOWN;	// 아래
	static const Vector2 UP;	// 위
};