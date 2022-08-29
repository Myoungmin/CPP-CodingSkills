#pragma once

// 2D ���� Ŭ����
class Vector2 {
public:
	float x;	// x ��ǥ
	float y;	// y ��ǥ

	// ������
	Vector2(float x = 0, float y = 0) : x(x), y(y) {}

	// ���� ���
	float dot(const Vector2& other) const {
		return (x * other.x) + (y * other.y);
	}

	// ���� ���
	float cross(const Vector2& other) const {
		return (x * other.y) - (y * other.x);
	}

	// ���� ���
	float length() const {
		return std::sqrt(dot(*this));
	}

	// �Ÿ� ���
	float distance(const Vector2& other) const {
		return (*this - other).length();
	}

	// ����ȭ
	Vector2 normalize() const {
		const float len = length();
		if (len < FLT_EPSILON) {
			return Vector2::ZERO;
		}
		return *this / len;
	}

	// ���� �������� Ȯ��
	bool isZero() const {
		return *this == Vector2::ZERO;
	}


	// ������ �����ε�
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

	// ���
	static const Vector2 ZERO;	// ���� ����
	static const Vector2 LEFT;	// ����
	static const Vector2 RIGHT;	// ������
	static const Vector2 DOWN;	// �Ʒ�
	static const Vector2 UP;	// ��
};