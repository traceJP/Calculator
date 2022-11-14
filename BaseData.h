#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

#ifndef BASEDATA_CPP
#define BASEDATA_CPP

// ���������ࣨʵ�������ӡ������ˡ������˷���������
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
	// �˷�
	BaseData Sqre(BaseData& c);
	// ����
	BaseData Sqrt(BaseData& c);
private:
	long double number;
};


// �߾����������ͣ����������ӡ������ˡ�������ģ��
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


// �����������ͣ����������ӡ������ˡ�����
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
	// �˷�
	Complex Sqre(Complex& c) {
		return *new Complex();
	}
	// ����
	Complex Sqrt(Complex& c) {
		return *new Complex();
	}
private:
	long double real;
	long double imag;
};

#endif
