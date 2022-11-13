#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <complex>

using namespace std;


// 基本数据类（实数）（加、减、乘、除、乘方、开方）
class BaseData {
public:
	string GetNumber();
	void SetNumber(string number);
	bool IsNumber(string str);
	BaseData operator + (BaseData& c);
	BaseData operator - (BaseData& c);
	BaseData operator * (BaseData& c);
	BaseData operator / (BaseData& c);
	// 乘方
	//BaseData operator ^ (BaseData& c);
	// 开方
	//BaseData Sqrt(BaseData& num);
private:
	long double number;
};


// 高精度数据类型（整数）（加、减、乘、除、求模）
class AccNumber {
public:
	string GetNumber();
	void SetNumber(string number);
	bool IsNumber(string str);
	AccNumber operator + (AccNumber& c);
	AccNumber operator - (AccNumber& c);
	AccNumber operator * (AccNumber& c);
	AccNumber operator / (AccNumber& c);
	AccNumber operator % (AccNumber& c);
private:
	string number;
	bool isMinus;
	void ReverseOrder();
};


// 复数数据类型（整数）（加、减、乘、除）
class Complex : public complex<long double> {
public:
	string GetNumber();
	void SetNumber(string number);
	bool IsNumber(string str);
	
	Complex operator + (Complex& c);
	Complex operator - (Complex& c);
	Complex operator * (Complex& c);
	Complex operator / (Complex& c);
};
