#pragma once
#include <cassert>
#include <utility>

// if ���ǹ��� ���̴� ��ų.
// min �Լ��� max �Լ��� �Բ� ����ϸ� if, else if�� ������� �ʰ� ���Ѱ��� ���Ѱ��� ��� üũ�ϰ� ������ �� �ִ�.
// ���Ѱ��� ���Ѱ��� �����ϴ� �ڵ�� ���� ����ϴ� �����̱� ������ min �Լ�, max �Լ��� �̿��Ͽ� clamp �Լ��� ����.
int clamp(int x, int low, int high)
{
	assert(low <= high);
	return std::min(std::max(x, low), high);
}