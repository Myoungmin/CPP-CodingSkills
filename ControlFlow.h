#pragma once
#include <cassert>
#include <utility>

//////// if ���ǹ��� ���̴� ��ų. //////////////////////////////////////////////////////////////////////////////////


// min �Լ��� max �Լ��� �Բ� ����ϸ� if, else if�� ������� �ʰ� ���Ѱ��� ���Ѱ��� ��� üũ�ϰ� ������ �� �ִ�.
// ���Ѱ��� ���Ѱ��� �����ϴ� �ڵ�� ���� ����ϴ� �����̱� ������ min �Լ�, max �Լ��� �̿��Ͽ� clamp �Լ��� ����.
int clamp(int x, int low, int high)
{
	assert(low <= high);
	return std::min(std::max(x, low), high);
}


// �� ������, � ���ڰ� ���Ѱ��� �̸��� ���Ѱ����� �����ְ� �ٽ� ����ϴ� ���� ��Ÿ����.
// ���Ѱ����� ���Ѱ� ������ ���ڸ� �ݺ��ϰ� ���� �� ����Ѵ�.
// ���ǹ� ��� ������ �����ڸ� ����ϸ� ������ �� ����带 ����� �� �ִ�.
// �ε��Ҽ��� �ڷ����� �����Ϸ��� fmod �Լ��� ����ؾ��Ѵ�.
float wrap(float x, float low, float high)
{
	assert(low < high);
	const float n = std::fmod(x - low, high - low);
	return (n >= 0) ? (n + low) : (n + high);
}