#pragma once
#include <unordered_map>
#include <string>
#include <cassert>

//////// 함수화 스킬. //////////////////////////////////////////////////////////////////////////////////

/********************* 데이터 변환 함수화 *********************/

// 자료 구조를 사용한 변환 예 (C++11의 unordered_map 클래스)
// 요일을 나타내는 열거형을 문자열로 변환하는 부분을 함수화

// 요일 열거형
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

// 열거형을 문자열로 변환하는 자료 구조
const std::unordered_map<Week, std::string> WeekToName = {
	{Week::Sunday, "Sun"},
	{Week::Monday, "Mon"},
	{Week::Tuesday, "Tue"},
	{Week::Wednesday, "Wed"},
	{Week::Thursday, "Thu"},
	{Week::Friday, "Fri"},
	{Week::Saturday, "Sat"},
};

// 요일 자료형을 문자열로 변환
std::string to_String(Week week)
{
	assert(WeekToName.find(week) != WeekToName.end());
	return WeekToName.at(week);
}

// 문자열을 열거형으로 변환하는 자료 구조
const std::unordered_map<std::string, Week> NameToWeek = {
	{"Sun", Week::Sunday},
	{"Mon", Week::Monday},
	{"Tue", Week::Tuesday},
	{"Wed", Week::Wednesday},
	{"Thu", Week::Thursday},
	{"Fri", Week::Friday},
	{"Sat", Week::Saturday},
};

// 문자열을 요일 자료형으로 변환
Week to_week(const std::string& name)
{
	assert(NameToWeek.find(name) != NameToWeek.end());
	return NameToWeek.at(name);
}

/***************************************************************/



