#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

#ifndef BASEDATA_CPP
#define BASEDATA_CPP

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
	BaseData operator % (BaseData& c) {
		return *new BaseData();
	}
	// 乘方
	BaseData Sqre(BaseData& c);
	// 开方
	BaseData Sqrt(BaseData& c);
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


	AccNumber Sqre(AccNumber& c) {
		return *new AccNumber();
	}
	AccNumber Sqrt(AccNumber& c) {
		return *new AccNumber();
	}
private:
	string number;
	bool isMinus;
	void ReverseOrder();
};


// 复数数据类型（整数）（加、减、乘、除）
class Complex {
public:
	string GetNumber();
	void SetNumber(string number);
	bool IsNumber(string str);
	Complex operator + (Complex& c);
	Complex operator - (Complex& c);
	Complex operator * (Complex& c);
	Complex operator / (Complex& c);
	Complex operator % (Complex& c) {
		return *new Complex();
	}
	// 乘方
	Complex Sqre(Complex& c) {
		return *new Complex();
	}
	// 开方
	Complex Sqrt(Complex& c) {
		return *new Complex();
	}
private:
	long double real;
	long double imag;
};

#endif
