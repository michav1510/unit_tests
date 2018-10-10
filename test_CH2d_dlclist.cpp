#include "test_CH2d_dlclist.hpp"

#include <iostream>
#include <fstream>
#include "../cgfunctionality/datastructs/CH2d_dlclist.hpp"
#include "../cgfunctionality/basic/Point2d.hpp"

void test_CH2d_dlclist::test_param_constr_case1()
{
	std::vector<Point2d> vec1;
	vec1.push_back(Point2d(0, 0));
	CH2d_dlclist ch1(vec1, "Jarvis");

	CPPUNIT_ASSERT(*ch1.begin() == Point2d(0, 0));
	CPPUNIT_ASSERT(*ch1.begin() == *ch1.end());
	CPPUNIT_ASSERT(ch1.size() == 1 && ch1.area() == 0);
}

void test_CH2d_dlclist::test_param_constr_case2()
{
	std::vector<Point2d> vec2;
	vec2.push_back(Point2d(2, 0));
	vec2.push_back(Point2d(2, 1));

	CH2d_dlclist ch2(vec2, "Jarvis");
	CPPUNIT_ASSERT(*ch2.begin() == Point2d(2, 0));

	CPPUNIT_ASSERT(*ch2.end() == Point2d(2, 1));

	CH2d_dlclist::ch_iterator it2(ch2.begin());
	CPPUNIT_ASSERT(*(it2 + 1) == Point2d(2, 1) && *(it2 - 1) == Point2d(2, 1) && *(it2 + 2) == Point2d(2, 0) && *(it2 - 2) == Point2d(2, 0));
	CPPUNIT_ASSERT(ch2.size() == 2 && ch2.area() == 0);
}

void test_CH2d_dlclist::test_param_constr_case3()
{
	std::vector<Point2d> vec3;
	vec3.push_back(Point2d(0, 0));
	vec3.push_back(Point2d(1, 1));
	vec3.push_back(Point2d(1, 0));

	CH2d_dlclist ch3(vec3, "Jarvis");
	CPPUNIT_ASSERT(*ch3.begin() == Point2d(0, 0));
	CPPUNIT_ASSERT(*ch3.end() == Point2d(1, 0));

	CH2d_dlclist::ch_iterator iter3(ch3.begin());
	CPPUNIT_ASSERT(*(iter3) == Point2d(0, 0) && *(iter3 + 1) == Point2d(1, 1) && *(iter3 + 2) == Point2d(1, 0) && *(iter3 + 3) == Point2d(0, 0) && *(iter3 - 1) == Point2d(1, 0) && *(iter3 - 2) == Point2d(1, 1) && *(iter3 - 3) == Point2d(0, 0));

	CPPUNIT_ASSERT(ch3.size() == 3 && ch3.area() == 0.5);
}

void test_CH2d_dlclist::test_param_constr_case4()
{
	std::vector<Point2d> vec4;
	vec4.push_back(Point2d(0, 0));
	vec4.push_back(Point2d(1, 1));
	vec4.push_back(Point2d(2, 1));
	vec4.push_back(Point2d(3, 0));

	CH2d_dlclist ch4(vec4, "Jarvis");
	CPPUNIT_ASSERT(*ch4.begin() == Point2d(0, 0));
	CPPUNIT_ASSERT(*ch4.end() == Point2d(3, 0));

	CH2d_dlclist::ch_iterator iter4(ch4.begin());
	CPPUNIT_ASSERT(*iter4 == Point2d(0, 0) && *(iter4 + 1) == Point2d(1, 1) && *(iter4 + 2) == Point2d(2, 1) &&
				   *(iter4 + 3) == Point2d(3, 0) && *(iter4 + 4) == Point2d(0, 0) && *(iter4 - 1) == Point2d(3, 0) && *(iter4 - 2) == Point2d(2, 1) && *(iter4 - 3) == Point2d(1, 1) && *(iter4 - 4) == Point2d(0, 0));
	CPPUNIT_ASSERT(ch4.size() == 4 && ch4.area() == 2);
}

void test_CH2d_dlclist::test_param_constr_case5()
{
	std::vector<Point2d> vec;
	vec.push_back(Point2d(0, 0));
	vec.push_back(Point2d(1, 1));
	vec.push_back(Point2d(2, 2));
	vec.push_back(Point2d(3, 1));
	vec.push_back(Point2d(2, 0));

	CH2d_dlclist ch5(vec, "Jarvis");

	CPPUNIT_ASSERT(*ch5.begin() == Point2d(0, 0));
	CPPUNIT_ASSERT(*ch5.end() == Point2d(3, 1));

	CH2d_dlclist::ch_iterator iter5(ch5.begin());
	CPPUNIT_ASSERT(*iter5 == Point2d(0, 0) && *(iter5 + 1) == Point2d(2, 2) && *(iter5 + 2) == Point2d(3, 1) &&
				   *(iter5 + 3) == Point2d(2, 0) && *(iter5 + 4) == Point2d(0, 0) && *(iter5 - 1) == Point2d(2, 0) && *(iter5 - 2) == Point2d(3, 1) && *(iter5 - 3) == Point2d(2, 2) && *(iter5 - 4) == Point2d(0, 0));

	CPPUNIT_ASSERT(ch5.size() == 4 && ch5.area() == 3);
}

void test_CH2d_dlclist::test_param_constr_case6()
{
	std::vector<Point2d> vec6;

	CH2d_dlclist ch6(vec6);
	CPPUNIT_ASSERT(ch6.size() == 0 && ch6.area() == 0);
}

void test_CH2d_dlclist::test_push_case1()
{
	std::vector<Point2d> vec1;

	CH2d_dlclist ch1(vec1, "Jarvis");

	CPPUNIT_ASSERT(ch1.push(Point2d(0, 0)) == 1);
	CPPUNIT_ASSERT(*ch1.begin() == Point2d(0, 0));
	CPPUNIT_ASSERT(*ch1.end() == Point2d(0, 0));

	CH2d_dlclist::ch_iterator it1 = ch1.begin();
	CPPUNIT_ASSERT(*it1 == Point2d(0, 0) && *(it1 + 1) == Point2d(0, 0) && *(it1 - 1) == Point2d(0, 0));

	CPPUNIT_ASSERT(ch1.size() == 1 && ch1.area() == 0);
}

void test_CH2d_dlclist::test_push_case2()
{
	std::vector<Point2d> vec2;
	vec2.push_back(Point2d(5, 1));

	CH2d_dlclist ch2(vec2, "Jarvis");

	CPPUNIT_ASSERT(ch2.push(Point2d(10, 2)) == 1);
	CPPUNIT_ASSERT(*ch2.begin() == Point2d(5, 1));
	CPPUNIT_ASSERT(*ch2.end() == Point2d(10, 2));

	CH2d_dlclist::ch_iterator it2(ch2.begin());
	CPPUNIT_ASSERT(*it2 == Point2d(5, 1) && *(it2 + 1) == Point2d(10, 2) && *(it2 + 2) == Point2d(5, 1) &&
				   *(it2 - 1) == Point2d(10, 2) && *(it2 - 2) == Point2d(5, 1));

	CPPUNIT_ASSERT(ch2.size() == 2 && ch2.area() == 0);
}

void test_CH2d_dlclist::test_push_case3()
{
	std::vector<Point2d> vec3;
	vec3.push_back(Point2d(5, 1));

	CH2d_dlclist ch3(vec3, "Jarvis");

	CPPUNIT_ASSERT(ch3.push(Point2d(5, 0)) == 1);
	CPPUNIT_ASSERT(*ch3.begin() == Point2d(5, 0));
	CPPUNIT_ASSERT(*ch3.end() == Point2d(5, 1));

	CH2d_dlclist::ch_iterator it3(ch3.begin());
	CPPUNIT_ASSERT(*it3 == Point2d(5, 0) && *(it3 + 1) == Point2d(5, 1) && *(it3 + 2) == Point2d(5, 0) &&
				   *(it3 - 1) == Point2d(5, 1) && *(it3 - 2) == Point2d(5, 0));

	CPPUNIT_ASSERT(ch3.size() == 2 && ch3.area() == 0);
}

void test_CH2d_dlclist::test_push_case4()
{
	std::vector<Point2d> vec4;
	vec4.push_back(Point2d(5, 1));

	CH2d_dlclist ch4(vec4, "Jarvis");

	CPPUNIT_ASSERT(ch4.push(Point2d(5, 10)) == 1);
	CPPUNIT_ASSERT(*ch4.begin() == Point2d(5, 1));
	CPPUNIT_ASSERT(*ch4.end() == Point2d(5, 10));

	CH2d_dlclist::ch_iterator it4 = ch4.begin();
	CPPUNIT_ASSERT(*it4 == Point2d(5, 1) && *(it4 + 1) == Point2d(5, 10) && *(it4 + 2) == Point2d(5, 1) && *(it4 - 1) == Point2d(5, 10) && *(it4 - 2) == Point2d(5, 1));

	CPPUNIT_ASSERT(ch4.size() == 2 && ch4.area() == 0);
}

void test_CH2d_dlclist::test_push_case5()
{
	std::vector<Point2d> vec5;
	vec5.push_back(Point2d(5, 1));
	vec5.push_back(Point2d(3, 2));

	CH2d_dlclist ch5(vec5, "Jarvis");

	CPPUNIT_ASSERT(ch5.push(Point2d(3, 2)) == -1);
	CPPUNIT_ASSERT(*ch5.begin() == Point2d(3, 2));
	CPPUNIT_ASSERT(*ch5.end() == Point2d(5, 1));

	CH2d_dlclist::ch_iterator it5 = ch5.begin();
	CPPUNIT_ASSERT(*it5 == Point2d(3, 2) && *(it5 + 1) == Point2d(5, 1) && *(it5 + 2) == Point2d(3, 2) && *(it5 - 1) == Point2d(5, 1) && *(it5 - 2) == Point2d(3, 2));

	CPPUNIT_ASSERT(ch5.size() == 2 && ch5.area() == 0);
}

void test_CH2d_dlclist::test_push_case6()
{
	std::vector<Point2d> vec6;
	vec6.push_back(Point2d(5, 1));
	vec6.push_back(Point2d(3, 2));

	CH2d_dlclist ch6(vec6, "Jarvis");

	CPPUNIT_ASSERT(ch6.push(Point2d(5, 1)) == -1);
	CPPUNIT_ASSERT(*ch6.begin() == Point2d(3, 2));
	CPPUNIT_ASSERT(*ch6.end() == Point2d(5, 1));

	CH2d_dlclist::ch_iterator it6 = ch6.begin();
	CPPUNIT_ASSERT(*it6 == Point2d(3, 2) && *(it6 + 1) == Point2d(5, 1) && *(it6 + 2) == Point2d(3, 2) && *(it6 - 1) == Point2d(5, 1) && *(it6 - 2) == Point2d(3, 2));

	CPPUNIT_ASSERT(ch6.size() == 2 && ch6.area() == 0);
}

void test_CH2d_dlclist::test_push_case7()
{
	std::vector<Point2d> vec7;
	vec7.push_back(Point2d(0, 0));
	vec7.push_back(Point2d(1, 1));

	CH2d_dlclist ch7(vec7);

	CPPUNIT_ASSERT(ch7.push(Point2d(0.1, 0.1)) == -1);
	CPPUNIT_ASSERT(*ch7.begin() == Point2d(0, 0));
	CPPUNIT_ASSERT(*ch7.end() == Point2d(1, 1));

	CH2d_dlclist::ch_iterator it7 = ch7.begin();
	CPPUNIT_ASSERT(*it7 == Point2d(0, 0) && *(it7 + 1) == Point2d(1, 1) && *(it7 + 2) == Point2d(0, 0) && *(it7 - 1) == Point2d(1, 1) && *(it7 - 2) == Point2d(0, 0));

	CPPUNIT_ASSERT(ch7.size() == 2 && ch7.area() == 0);
}

void test_CH2d_dlclist::test_push_case8()
{
	std::vector<Point2d> vec8;
	vec8.push_back(Point2d(0, 0));
	vec8.push_back(Point2d(1, 1));

	CH2d_dlclist ch8(vec8);

	CPPUNIT_ASSERT(ch8.push(Point2d(-1, -1)) == 1);
	CPPUNIT_ASSERT(*ch8.begin() == Point2d(-1, -1));
	CPPUNIT_ASSERT(*ch8.end() == Point2d(1, 1));

	CH2d_dlclist::ch_iterator it8 = ch8.begin();
	CPPUNIT_ASSERT(*it8 == Point2d(-1, -1) && *(it8 + 1) == Point2d(1, 1) && *(it8 + 2) == Point2d(-1, -1) && *(it8 - 1) == Point2d(1, 1) && *(it8 - 2) == Point2d(-1, -1));

	CPPUNIT_ASSERT(ch8.size() == 2 && ch8.area() == 0);
}

void test_CH2d_dlclist::test_push_case9()
{
	std::vector<Point2d> vec9;
	vec9.push_back(Point2d(0, 0));
	vec9.push_back(Point2d(1, 1));

	CH2d_dlclist ch9(vec9);

	CPPUNIT_ASSERT(ch9.push(Point2d(2, 2)) == 1);
	CPPUNIT_ASSERT(*ch9.begin() == Point2d(0, 0));
	CPPUNIT_ASSERT(*ch9.end() == Point2d(2, 2));

	CH2d_dlclist::ch_iterator it9 = ch9.begin();
	CPPUNIT_ASSERT(*it9 == Point2d(0, 0) && *(it9 + 1) == Point2d(2, 2) && *(it9 + 2) == Point2d(0, 0) && *(it9 - 1) == Point2d(2, 2) && *(it9 - 2) == Point2d(0, 0));

	CPPUNIT_ASSERT(ch9.size() == 2 && ch9.area() == 0);
}

void test_CH2d_dlclist::test_push_case10()
{
	std::vector<Point2d> vec10;
	vec10.push_back(Point2d(1, 0));
	vec10.push_back(Point2d(1, 1));

	CH2d_dlclist ch10(vec10);

	CPPUNIT_ASSERT(ch10.push(Point2d(1, -1)) == 1);
	CPPUNIT_ASSERT(*ch10.begin() == Point2d(1, -1));
	CPPUNIT_ASSERT(*ch10.end() == Point2d(1, 1));

	CH2d_dlclist::ch_iterator it10 = ch10.begin();
	CPPUNIT_ASSERT(*it10 == Point2d(1, -1) && *(it10 + 1) == Point2d(1, 1) && *(it10 + 2) == Point2d(1, -1) && *(it10 - 1) == Point2d(1, 1) && *(it10 - 2) == Point2d(1, -1));

	CPPUNIT_ASSERT(ch10.size() == 2 && ch10.area() == 0);
}

void test_CH2d_dlclist::test_push_case11()
{
	std::vector<Point2d> vec11;
	vec11.push_back(Point2d(1, 0));
	vec11.push_back(Point2d(1, 1));

	CH2d_dlclist ch11(vec11);

	CPPUNIT_ASSERT(ch11.push(Point2d(1, 2)) == 1);
	CPPUNIT_ASSERT(*ch11.begin() == Point2d(1, 0));

	CPPUNIT_ASSERT(*ch11.end() == Point2d(1, 2));

	CH2d_dlclist::ch_iterator it11 = ch11.begin();
	CPPUNIT_ASSERT(*it11 == Point2d(1, 0) && *(it11 + 1) == Point2d(1, 2) && *(it11 + 2) == Point2d(1, 0) && *(it11 - 1) == Point2d(1, 2) && *(it11 - 2) == Point2d(1, 0));

	CPPUNIT_ASSERT(ch11.size() == 2 && ch11.area() == 0);
}

void test_CH2d_dlclist::test_push_case12()
{
	std::vector<Point2d> vec12;
	Point2d a12(1, 0);
	Point2d b12(1, 1);
	vec12.push_back(a12);
	vec12.push_back(b12);

	CH2d_dlclist ch12(vec12);
	Point2d c12(-1, 0);

	CPPUNIT_ASSERT(ch12.push(c12) == 1);
	CPPUNIT_ASSERT(*ch12.begin() == c12);
	CPPUNIT_ASSERT(*ch12.end() == a12);

	CH2d_dlclist::ch_iterator it12 = ch12.begin();
	CPPUNIT_ASSERT(*it12 == c12 && *(it12 + 1) == b12 && *(it12 + 2) == a12 && *(it12 + 3) == c12 && *(it12 - 1) == a12 && *(it12 - 2) == b12 && *(it12 - 3) == c12);

	CPPUNIT_ASSERT(ch12.size() == 3 && ch12.area() == 1);
}

void test_CH2d_dlclist::test_push_case13()
{
	std::vector<Point2d> vec13;
	Point2d a13(0, 0);
	Point2d b13(1, 1);
	vec13.push_back(a13);
	vec13.push_back(b13);

	CH2d_dlclist ch13(vec13);

	Point2d c13(-1, 0);
	CPPUNIT_ASSERT(ch13.push(c13) == 1);
	CPPUNIT_ASSERT(*ch13.begin() == c13);

	CPPUNIT_ASSERT(*ch13.end() == b13);

	CH2d_dlclist::ch_iterator it13 = ch13.begin();
	CPPUNIT_ASSERT(*it13 == c13 && *(it13 + 1) == b13 && *(it13 + 2) == a13 && *(it13 + 3) == c13 && *(it13 - 1) == a13 && *(it13 - 2) == b13 && *(it13 - 3) == c13);

	CPPUNIT_ASSERT(ch13.size() == 3 && ch13.area() == 0.5);
}

void test_CH2d_dlclist::test_push_case14()
{
	std::vector<Point2d> vec14;
	vec14.push_back(Point2d(0, 1));
	vec14.push_back(Point2d(1, 0));

	CH2d_dlclist ch14(vec14);

	CPPUNIT_ASSERT(ch14.push(Point2d(-1, 0)) == 1);
	CPPUNIT_ASSERT(*ch14.begin() == Point2d(-1, 0));
	CPPUNIT_ASSERT(*ch14.end() == Point2d(1, 0));

	CH2d_dlclist::ch_iterator it14 = ch14.begin();
	CPPUNIT_ASSERT(*it14 == Point2d(-1, 0) && *(it14 + 1) == Point2d(0, 1) && *(it14 + 2) == Point2d(1, 0) && *(it14 + 3) == Point2d(-1, 0) && *(it14 - 1) == Point2d(1, 0) && *(it14 - 2) == Point2d(0, 1) && *(it14 - 3) == Point2d(-1, 0));

	CPPUNIT_ASSERT(ch14.size() == 3 && ch14.area() == 1);
}

void test_CH2d_dlclist::test_push_case15()
{
	std::vector<Point2d> vec15;
	vec15.push_back(Point2d(-1, 0));
	vec15.push_back(Point2d(0, 1));

	CH2d_dlclist ch15(vec15);

	CPPUNIT_ASSERT(ch15.push(Point2d(1, 0)) == 1);
	CPPUNIT_ASSERT(*ch15.begin() == Point2d(-1, 0));
	CPPUNIT_ASSERT(*ch15.end() == Point2d(1, 0));

	CH2d_dlclist::ch_iterator it15 = ch15.begin();
	CPPUNIT_ASSERT(*it15 == Point2d(-1, 0) && *(it15 + 1) == Point2d(0, 1) && *(it15 + 2) == Point2d(1, 0) && *(it15 + 3) == Point2d(-1, 0) && *(it15 - 1) == Point2d(1, 0) && *(it15 - 2) == Point2d(0, 1) && *(it15 - 3) == Point2d(-1, 0));

	CPPUNIT_ASSERT(ch15.size() == 3 && ch15.area() == 1);
}

void test_CH2d_dlclist::test_push_case16()
{
	std::vector<Point2d> vec16;
	vec16.push_back(Point2d(-1, 0));
	vec16.push_back(Point2d(0, -1));

	CH2d_dlclist ch16(vec16);

	CPPUNIT_ASSERT(ch16.push(Point2d(1, 0)) == 1);
	CPPUNIT_ASSERT(*ch16.begin() == Point2d(-1, 0));
	CPPUNIT_ASSERT(*ch16.end() == Point2d(1, 0));

	CH2d_dlclist::ch_iterator it16 = ch16.begin();
	CPPUNIT_ASSERT(*it16 == Point2d(-1, 0) && *(it16 + 1) == Point2d(1, 0) && *(it16 + 2) == Point2d(0, -1) && *(it16 + 3) == Point2d(-1, 0) && *(it16 - 1) == Point2d(0, -1) && *(it16 - 2) == Point2d(1, 0) && *(it16 - 3) == Point2d(-1, 0));

	CPPUNIT_ASSERT(ch16.size() == 3 && ch16.area() == 1);
}

void test_CH2d_dlclist::test_push_case17()
{
	std::vector<Point2d> vec17;
	vec17.push_back(Point2d(-1, 0));
	vec17.push_back(Point2d(1, 0));

	CH2d_dlclist ch17(vec17);

	CPPUNIT_ASSERT(ch17.push(Point2d(0, 1)) == 1);
	CPPUNIT_ASSERT(*ch17.begin() == Point2d(-1, 0));
	CPPUNIT_ASSERT(*ch17.end() == Point2d(1, 0));

	CH2d_dlclist::ch_iterator it17 = ch17.begin();
	CPPUNIT_ASSERT(*it17 == Point2d(-1, 0) && *(it17 + 1) == Point2d(0, 1) && *(it17 + 2) == Point2d(1, 0) && *(it17 + 3) == Point2d(-1, 0) && *(it17 - 1) == Point2d(1, 0) && *(it17 - 2) == Point2d(0, 1) && *(it17 - 3) == Point2d(-1, 0));

	CPPUNIT_ASSERT(ch17.size() == 3 && ch17.area() == 1);
}

void test_CH2d_dlclist::test_push_case18()
{
	std::vector<Point2d> vec18;
	vec18.push_back(Point2d(-1, 0));
	vec18.push_back(Point2d(1, 0));

	CH2d_dlclist ch18(vec18);

	CPPUNIT_ASSERT(ch18.push(Point2d(0, -1)) == 1);
	CPPUNIT_ASSERT(*ch18.begin() == Point2d(-1, 0));
	CPPUNIT_ASSERT(*ch18.end() == Point2d(1, 0));

	CH2d_dlclist::ch_iterator it18 = ch18.begin();
	CPPUNIT_ASSERT(*it18 == Point2d(-1, 0) && *(it18 + 1) == Point2d(1, 0) && *(it18 + 2) == Point2d(0, -1) && *(it18 + 3) == Point2d(-1, 0) && *(it18 - 1) == Point2d(0, -1) && *(it18 - 2) == Point2d(1, 0) && *(it18 - 3) == Point2d(-1, 0));

	CPPUNIT_ASSERT(ch18.size() == 3 && ch18.area() == 1);
}

void test_CH2d_dlclist::test_push_case19()
{
	std::vector<Point2d> vec;
	vec.push_back(Point2d(0, 0));
	vec.push_back(Point2d(0, 1));
	vec.push_back(Point2d(1, 2));
	vec.push_back(Point2d(2, 2));
	vec.push_back(Point2d(3, 1));
	vec.push_back(Point2d(3, 0));
	vec.push_back(Point2d(2, -1));
	vec.push_back(Point2d(1, -1));

	CH2d_dlclist ch(vec);

	CPPUNIT_ASSERT(ch.push(Point2d(-4, 0.5)) == 1);
	CPPUNIT_ASSERT(*ch.begin() == Point2d(-4, 0.5));
	CPPUNIT_ASSERT(*ch.end() == Point2d(3, 0));

	CH2d_dlclist::ch_iterator it = ch.begin();
	CPPUNIT_ASSERT(*it == Point2d(-4, 0.5) && *(it + 1) == Point2d(1, 2) && *(it + 2) == Point2d(2, 2) && *(it + 3) == Point2d(3, 1) && *(it + 4) == Point2d(3, 0) && *(it + 5) == Point2d(2, -1) && *(it + 6) == Point2d(1, -1) && *(it + 7) == Point2d(-4, 0.5) && *(it - 1) == Point2d(1, -1) && *(it - 2) == Point2d(2, -1) && *(it - 3) == Point2d(3, 0) && *(it - 4) == Point2d(3, 1) && *(it - 5) == Point2d(2, 2) && *(it - 6) == Point2d(1, 2) && *(it - 7) == Point2d(-4, 0.5));

	CPPUNIT_ASSERT(ch.size() == 7 && ch.area() == 12.5);
}

void test_CH2d_dlclist::test_push_case20()
{
	std::vector<Point2d> vec;
	vec.push_back(Point2d(0, 0));
	vec.push_back(Point2d(0, 1));
	vec.push_back(Point2d(1, 2));
	vec.push_back(Point2d(2, 2));
	vec.push_back(Point2d(3, 1));
	vec.push_back(Point2d(3, 0));
	vec.push_back(Point2d(2, -1));
	vec.push_back(Point2d(1, -1));

	CH2d_dlclist ch(vec);

	CPPUNIT_ASSERT(ch.push(Point2d(0, 2)) == 1);
	CPPUNIT_ASSERT(*ch.begin() == Point2d(0, 0));
	CPPUNIT_ASSERT(*ch.end() == Point2d(3, 0));

	CH2d_dlclist::ch_iterator it = ch.begin();
	CPPUNIT_ASSERT(*it == Point2d(0, 0) && *(it + 1) == Point2d(0, 2) && *(it + 2) == Point2d(2, 2) && *(it + 3) == Point2d(3, 1) && *(it + 4) == Point2d(3, 0) && *(it + 5) == Point2d(2, -1) && *(it + 6) == Point2d(1, -1) && *(it + 7) == Point2d(0, 0) && *(it - 1) == Point2d(1, -1) && *(it - 2) == Point2d(2, -1) && *(it - 3) == Point2d(3, 0) && *(it - 4) == Point2d(3, 1) && *(it - 5) == Point2d(2, 2) && *(it - 6) == Point2d(0, 2) && *(it - 7) == Point2d(0, 0));

	CPPUNIT_ASSERT(ch.size() == 7 && ch.area() == 7.5);
}

void test_CH2d_dlclist::test_push_case21()
{
	std::vector<Point2d> vec;
	vec.push_back(Point2d(0, 0));
	vec.push_back(Point2d(0, 1));
	vec.push_back(Point2d(1, 2));
	vec.push_back(Point2d(2, 2));
	vec.push_back(Point2d(3, 1));
	vec.push_back(Point2d(3, 0));
	vec.push_back(Point2d(2, -1));
	vec.push_back(Point2d(1, -1));

	CH2d_dlclist ch(vec);

	CPPUNIT_ASSERT(ch.push(Point2d(0, 0.5)) == -1);
	CPPUNIT_ASSERT(*ch.begin() == Point2d(0, 0));
	CPPUNIT_ASSERT(*ch.end() == Point2d(3, 0));

	CH2d_dlclist::ch_iterator it = ch.begin();
	CPPUNIT_ASSERT(*it == Point2d(0, 0) && *(it + 1) == Point2d(0, 1) && *(it + 2) == Point2d(1, 2) && *(it + 3) == Point2d(2, 2) && *(it + 4) == Point2d(3, 1) && *(it + 5) == Point2d(3, 0) && *(it + 6) == Point2d(2, -1) && *(it + 7) == Point2d(1, -1) && *(it + 8) == Point2d(0, 0) && *(it - 1) == Point2d(1, -1) && *(it - 2) == Point2d(2, -1) && *(it - 3) == Point2d(3, 0) && *(it - 4) == Point2d(3, 1) && *(it - 5) == Point2d(2, 2) && *(it - 6) == Point2d(1, 2) && *(it - 7) == Point2d(0, 1) && *(it - 8) == Point2d(0, 0));

	CPPUNIT_ASSERT(ch.size() == 8 && ch.area() == 7);
}

void test_CH2d_dlclist::test_push_case22()
{
	std::vector<Point2d> vec;
	vec.push_back(Point2d(0, 0));
	vec.push_back(Point2d(0, 1));
	vec.push_back(Point2d(1, 2));
	vec.push_back(Point2d(2, 2));
	vec.push_back(Point2d(3, 1));
	vec.push_back(Point2d(3, 0));
	vec.push_back(Point2d(2, -1));
	vec.push_back(Point2d(1, -1));

	CH2d_dlclist ch(vec);

	CPPUNIT_ASSERT(ch.push(Point2d(0, -1)) == 1);
	CPPUNIT_ASSERT(*ch.begin() == Point2d(0, -1));
	CPPUNIT_ASSERT(*ch.end() == Point2d(3, 0));

	CH2d_dlclist::ch_iterator it = ch.begin();
	CPPUNIT_ASSERT(*it == Point2d(0, -1) && *(it + 1) == Point2d(0, 1) && *(it + 2) == Point2d(1, 2) && *(it + 3) == Point2d(2, 2) && *(it + 4) == Point2d(3, 1) && *(it + 5) == Point2d(3, 0) && *(it + 6) == Point2d(2, -1) && *(it + 7) == Point2d(0, -1) && *(it - 1) == Point2d(2, -1) && *(it - 2) == Point2d(3, 0) && *(it - 3) == Point2d(3, 1) && *(it - 4) == Point2d(2, 2) && *(it - 5) == Point2d(1, 2) && *(it - 6) == Point2d(0, 1) && *(it - 7) == Point2d(0, -1));

	CPPUNIT_ASSERT(ch.size() == 7 && ch.area() == 7.5);
}

void test_CH2d_dlclist::test_push_case23()
{
	std::vector<Point2d> vec;
	vec.push_back(Point2d(0, 0));
	vec.push_back(Point2d(0, 1));
	vec.push_back(Point2d(1, 2));
	vec.push_back(Point2d(2, 2));
	vec.push_back(Point2d(3, 1));
	vec.push_back(Point2d(3, 0));
	vec.push_back(Point2d(2, -1));
	vec.push_back(Point2d(1, -1));

	CH2d_dlclist ch(vec);

	CPPUNIT_ASSERT(ch.push(Point2d(0, -1)) == 1);
	CPPUNIT_ASSERT(*ch.begin() == Point2d(0, -1));
	CPPUNIT_ASSERT(*ch.end() == Point2d(3, 0));

	CH2d_dlclist::ch_iterator it = ch.begin();
	CPPUNIT_ASSERT(*it == Point2d(0, -1) && *(it + 1) == Point2d(0, 1) && *(it + 2) == Point2d(1, 2) && *(it + 3) == Point2d(2, 2) && *(it + 4) == Point2d(3, 1) && *(it + 5) == Point2d(3, 0) && *(it + 6) == Point2d(2, -1) && *(it + 7) == Point2d(0, -1) && *(it - 1) == Point2d(2, -1) && *(it - 2) == Point2d(3, 0) && *(it - 3) == Point2d(3, 1) && *(it - 4) == Point2d(2, 2) && *(it - 5) == Point2d(1, 2) && *(it - 6) == Point2d(0, 1) && *(it - 7) == Point2d(0, -1));

	CPPUNIT_ASSERT(ch.size() == 7 && ch.area() == 7.5);
}

void test_CH2d_dlclist::test_push_case24()
{
	std::vector<Point2d> vec;
	vec.push_back(Point2d(0, 0));
	vec.push_back(Point2d(0, 1));
	vec.push_back(Point2d(1, 2));
	vec.push_back(Point2d(2, 2));
	vec.push_back(Point2d(3, 1));
	vec.push_back(Point2d(3, 0));
	vec.push_back(Point2d(2, -1));
	vec.push_back(Point2d(1, -1));

	CH2d_dlclist ch(vec);

	CPPUNIT_ASSERT(ch.push(Point2d(1.5, 2.5)) == 1);
	CPPUNIT_ASSERT(*ch.begin() == Point2d(0, 0));
	CPPUNIT_ASSERT(*ch.end() == Point2d(3, 0));
	CH2d_dlclist::ch_iterator it = ch.begin();
	CPPUNIT_ASSERT(*it == Point2d(0, 0) && *(it + 1) == Point2d(0, 1) && *(it + 2) == Point2d(1.5, 2.5) && *(it + 3) == Point2d(3, 1) && *(it + 4) == Point2d(3, 0) && *(it + 5) == Point2d(2, -1) && *(it + 6) == Point2d(1, -1) && *(it + 7) == Point2d(0, 0) && *(it - 1) == Point2d(1, -1) && *(it - 2) == Point2d(2, -1) && *(it - 3) == Point2d(3, 0) && *(it - 4) == Point2d(3, 1) && *(it - 5) == Point2d(1.5, 2.5) && *(it - 6) == Point2d(0, 1) && *(it - 7) == Point2d(0, 0));

	CPPUNIT_ASSERT(ch.size() == 7 && ch.area() == 7.25);
}

void test_CH2d_dlclist::test_push_case25()
{
	std::vector<Point2d> vec;
	vec.push_back(Point2d(0, 0));
	vec.push_back(Point2d(0, 1));
	vec.push_back(Point2d(1, 2));
	vec.push_back(Point2d(2, 2));
	vec.push_back(Point2d(3, 1));
	vec.push_back(Point2d(3, 0));
	vec.push_back(Point2d(2, -1));
	vec.push_back(Point2d(1, -1));

	CH2d_dlclist ch(vec);

	CPPUNIT_ASSERT(ch.push(Point2d(2.5, -0.5)) == -1);
	CPPUNIT_ASSERT(*ch.begin() == Point2d(0, 0));
	CPPUNIT_ASSERT(*ch.end() == Point2d(3, 0));

	CH2d_dlclist::ch_iterator it = ch.begin();
	CPPUNIT_ASSERT(*it == Point2d(0, 0) && *(it + 1) == Point2d(0, 1) && *(it + 2) == Point2d(1, 2) && *(it + 3) == Point2d(2, 2) && *(it + 4) == Point2d(3, 1) && *(it + 5) == Point2d(3, 0) && *(it + 6) == Point2d(2, -1) && *(it + 7) == Point2d(1, -1) && *(it + 8) == Point2d(0, 0) && *(it - 1) == Point2d(1, -1) && *(it - 2) == Point2d(2, -1) && *(it - 3) == Point2d(3, 0) && *(it - 4) == Point2d(3, 1) && *(it - 5) == Point2d(2, 2) && *(it - 6) == Point2d(1, 2) && *(it - 7) == Point2d(0, 1) && *(it - 8) == Point2d(0, 0));

	CPPUNIT_ASSERT(ch.size() == 8 && ch.area() == 7);
}

void test_CH2d_dlclist::test_push_case26()
{
	std::vector<Point2d> vec;
	vec.push_back(Point2d(0, 0));
	vec.push_back(Point2d(0, 1));
	vec.push_back(Point2d(1, 2));
	vec.push_back(Point2d(2, 2));
	vec.push_back(Point2d(3, 1));
	vec.push_back(Point2d(3, 0));
	vec.push_back(Point2d(2, -1));
	vec.push_back(Point2d(1, -1));

	CH2d_dlclist ch(vec);

	CPPUNIT_ASSERT(ch.push(Point2d(1.5, -5)) == 1);
	CPPUNIT_ASSERT(*ch.begin() == Point2d(0, 0));
	CPPUNIT_ASSERT(*ch.end() == Point2d(3, 0));

	CH2d_dlclist::ch_iterator it = ch.begin();
	CPPUNIT_ASSERT(*it == Point2d(0, 0) && *(it + 1) == Point2d(0, 1) && *(it + 2) == Point2d(1, 2) && *(it + 3) == Point2d(2, 2) && *(it + 4) == Point2d(3, 1) && *(it + 5) == Point2d(3, 0) && *(it + 6) == Point2d(1.5, -5) && *(it + 7) == Point2d(0, 0) && *(it - 1) == Point2d(1.5, -5) && *(it - 2) == Point2d(3, 0) && *(it - 3) == Point2d(3, 1) && *(it - 4) == Point2d(2, 2) && *(it - 5) == Point2d(1, 2) && *(it - 6) == Point2d(0, 1) && *(it - 7) == Point2d(0, 0));

	CPPUNIT_ASSERT(ch.size() == 7 && ch.area() == 12.5);
}

void test_CH2d_dlclist::test_push_case27()
{
	std::vector<Point2d> vec;
	vec.push_back(Point2d(0, 0));
	vec.push_back(Point2d(0, 1));
	vec.push_back(Point2d(1, 2));
	vec.push_back(Point2d(2, 2));
	vec.push_back(Point2d(3, 1));
	vec.push_back(Point2d(3, 0));
	vec.push_back(Point2d(2, -1));
	vec.push_back(Point2d(1, -1));

	CH2d_dlclist ch(vec);

	CPPUNIT_ASSERT(ch.push(Point2d(3, 0.5)) == -1);
	CPPUNIT_ASSERT(*ch.begin() == Point2d(0, 0));
	CPPUNIT_ASSERT(*ch.end() == Point2d(3, 0));

	CH2d_dlclist::ch_iterator it = ch.begin();
	CPPUNIT_ASSERT(*it == Point2d(0, 0) && *(it + 1) == Point2d(0, 1) && *(it + 2) == Point2d(1, 2) && *(it + 3) == Point2d(2, 2) && *(it + 4) == Point2d(3, 1) && *(it + 5) == Point2d(3, 0) && *(it + 6) == Point2d(2, -1) && *(it + 7) == Point2d(1, -1) && *(it + 8) == Point2d(0, 0) && *(it - 1) == Point2d(1, -1) && *(it - 2) == Point2d(2, -1) && *(it - 3) == Point2d(3, 0) && *(it - 4) == Point2d(3, 1) && *(it - 5) == Point2d(2, 2) && *(it - 6) == Point2d(1, 2) && *(it - 7) == Point2d(0, 1) && *(it - 8) == Point2d(0, 0));

	CPPUNIT_ASSERT(ch.size() == 8 && ch.area() == 7);
}

void test_CH2d_dlclist::test_push_case28()
{
	std::vector<Point2d> vec;
	vec.push_back(Point2d(0, 0));
	vec.push_back(Point2d(0, 1));
	vec.push_back(Point2d(1, 2));
	vec.push_back(Point2d(2, 2));
	vec.push_back(Point2d(3, 1));
	vec.push_back(Point2d(3, 0));
	vec.push_back(Point2d(2, -1));
	vec.push_back(Point2d(1, -1));

	CH2d_dlclist ch(vec);

	CPPUNIT_ASSERT(ch.push(Point2d(10, 0.5)) == 1);
	CPPUNIT_ASSERT(*ch.begin() == Point2d(0, 0));
	CPPUNIT_ASSERT(*ch.end() == Point2d(10, 0.5));

	CH2d_dlclist::ch_iterator it = ch.begin();
	CPPUNIT_ASSERT(*it == Point2d(0, 0) && *(it + 1) == Point2d(0, 1) && *(it + 2) == Point2d(1, 2) && *(it + 3) == Point2d(2, 2) && *(it + 4) == Point2d(10, 0.5) && *(it + 5) == Point2d(2, -1) && *(it + 6) == Point2d(1, -1) && *(it + 7) == Point2d(0, 0) && *(it - 1) == Point2d(1, -1) && *(it - 2) == Point2d(2, -1) && *(it - 3) == Point2d(10, 0.5) && *(it - 4) == Point2d(2, 2) && *(it - 5) == Point2d(1, 2) && *(it - 6) == Point2d(0, 1) && *(it - 7) == Point2d(0, 0));

	CPPUNIT_ASSERT(ch.size() == 7 && ch.area() == 17);
}

void test_CH2d_dlclist::test_push_case29()
{
	std::vector<Point2d> vec;
	vec.push_back(Point2d(0, 0));
	vec.push_back(Point2d(0, 1));
	vec.push_back(Point2d(1, 2));
	vec.push_back(Point2d(2, 2));
	vec.push_back(Point2d(3, 1));
	vec.push_back(Point2d(3, 0));
	vec.push_back(Point2d(2, -1));
	vec.push_back(Point2d(1, -1));

	CH2d_dlclist ch(vec);

	CPPUNIT_ASSERT(ch.push(Point2d(3, 2)) == 1);
	CPPUNIT_ASSERT(*ch.begin() == Point2d(0, 0));
	CPPUNIT_ASSERT(*ch.end() == Point2d(3, 0));

	CH2d_dlclist::ch_iterator it = ch.begin();
	CPPUNIT_ASSERT(*it == Point2d(0, 0) && *(it + 1) == Point2d(0, 1) && *(it + 2) == Point2d(1, 2) && *(it + 3) == Point2d(3, 2) && *(it + 4) == Point2d(3, 0) && *(it + 5) == Point2d(2, -1) && *(it + 6) == Point2d(1, -1) && *(it + 7) == Point2d(0, 0) && *(it - 1) == Point2d(1, -1) && *(it - 2) == Point2d(2, -1) && *(it - 3) == Point2d(3, 0) && *(it - 4) == Point2d(3, 2) && *(it - 5) == Point2d(1, 2) && *(it - 6) == Point2d(0, 1) && *(it - 7) == Point2d(0, 0));

	CPPUNIT_ASSERT(ch.size() == 7 && ch.area() == 7.5);
}

void test_CH2d_dlclist::test_push_case30()
{
	std::vector<Point2d> vec;
	vec.push_back(Point2d(0, 0));
	vec.push_back(Point2d(0, 1));
	vec.push_back(Point2d(1, 2));
	vec.push_back(Point2d(2, 2));
	vec.push_back(Point2d(3, 1));
	vec.push_back(Point2d(3, 0));
	vec.push_back(Point2d(2, -1));
	vec.push_back(Point2d(1, -1));

	CH2d_dlclist ch(vec);

	CPPUNIT_ASSERT(ch.push(Point2d(3, -0.5)) == 1);
	CPPUNIT_ASSERT(*ch.begin() == Point2d(0, 0));
	CPPUNIT_ASSERT(*ch.end() == Point2d(3, -0.5));

	CH2d_dlclist::ch_iterator it = ch.begin();
	CPPUNIT_ASSERT(*it == Point2d(0, 0) && *(it + 1) == Point2d(0, 1) && *(it + 2) == Point2d(1, 2) && *(it + 3) == Point2d(2, 2) && *(it + 4) == Point2d(3, 1) && *(it + 5) == Point2d(3, -0.5) && *(it + 6) == Point2d(2, -1) && *(it + 7) == Point2d(1, -1) && *(it + 8) == Point2d(0, 0) && *(it - 1) == Point2d(1, -1) && *(it - 2) == Point2d(2, -1) && *(it - 3) == Point2d(3, -0.5) && *(it - 4) == Point2d(3, 1) && *(it - 5) == Point2d(2, 2) && *(it - 6) == Point2d(1, 2) && *(it - 7) == Point2d(0, 1) && *(it - 8) == Point2d(0, 0));

	CPPUNIT_ASSERT(ch.size() == 8 && ch.area() == 7.25);
}

void test_CH2d_dlclist::test_push_case31()
{
	std::vector<Point2d> vec;
	vec.push_back(Point2d(0, 0));
	vec.push_back(Point2d(0, 1));
	vec.push_back(Point2d(1, 2));
	vec.push_back(Point2d(2, 2));
	vec.push_back(Point2d(3, 1));
	vec.push_back(Point2d(3, 0));
	vec.push_back(Point2d(2, -1));
	vec.push_back(Point2d(1, -1));

	CH2d_dlclist ch(vec);

	CPPUNIT_ASSERT(ch.push(Point2d(-0.5, 0.5)) == 1);
	CPPUNIT_ASSERT(*ch.begin() == Point2d(-0.5, 0.5));
	CPPUNIT_ASSERT(*ch.end() == Point2d(3, 0));

	CH2d_dlclist::ch_iterator it = ch.begin();
	CPPUNIT_ASSERT(*it == Point2d(-0.5, 0.5) && *(it + 1) == Point2d(1, 2) && *(it + 2) == Point2d(2, 2) && *(it + 3) == Point2d(3, 1) && *(it + 4) == Point2d(3, 0) && *(it + 5) == Point2d(2, -1) && *(it + 6) == Point2d(1, -1) && *(it + 7) == Point2d(-0.5, 0.5) && *(it - 1) == Point2d(1, -1) && *(it - 2) == Point2d(2, -1) && *(it - 3) == Point2d(3, 0) && *(it - 4) == Point2d(3, 1) && *(it - 5) == Point2d(2, 2) && *(it - 6) == Point2d(1, 2) && *(it - 7) == Point2d(-0.5, 0.5));

	CPPUNIT_ASSERT(ch.size() == 7 && ch.area() == 7.25);
}