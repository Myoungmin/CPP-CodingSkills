#pragma once
#include <unordered_map>
#include <string>
#include <cassert>

//////// �Լ�ȭ ��ų. //////////////////////////////////////////////////////////////////////////////////

/********************* ������ ��ȯ �Լ�ȭ *********************/

// �ڷ� ������ ����� ��ȯ �� (C++11�� unordered_map Ŭ����)
// ������ ��Ÿ���� �������� ���ڿ��� ��ȯ�ϴ� �κ��� �Լ�ȭ

// ���� ������
enum class Week
{
	Sunday,
	Monday,
	Tuesday,
	Wednesday,
	Thursday,
	Friday,
	Saturday,
};

// �������� ���ڿ��� ��ȯ�ϴ� �ڷ� ����
const std::unordered_map<Week, std::string> WeekToName = {
	{Week::Sunday, "Sun"},
	{Week::Monday, "Mon"},
	{Week::Tuesday, "Tue"},
	{Week::Wednesday, "Wed"},
	{Week::Thursday, "Thu"},
	{Week::Friday, "Fri"},
	{Week::Saturday, "Sat"},
};

// ���� �ڷ����� ���ڿ��� ��ȯ
std::string to_String(Week week)
{
	assert(WeekToName.find(week) != WeekToName.end());
	return WeekToName.at(week);
}

// ���ڿ��� ���������� ��ȯ�ϴ� �ڷ� ����
const std::unordered_map<std::string, Week> NameToWeek = {
	{"Sun", Week::Sunday},
	{"Mon", Week::Monday},
	{"Tue", Week::Tuesday},
	{"Wed", Week::Wednesday},
	{"Thu", Week::Thursday},
	{"Fri", Week::Friday},
	{"Sat", Week::Saturday},
};

// ���ڿ��� ���� �ڷ������� ��ȯ
Week to_week(const std::string& name)
{
	assert(NameToWeek.find(name) != NameToWeek.end());
	return NameToWeek.at(name);
}

/***************************************************************/



