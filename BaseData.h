#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <complex>

using namespace std;


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
	// �˷�
	//BaseData operator ^ (BaseData& c);
	// ����
	//BaseData Sqrt(BaseData& num);
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
private:
	string number;
	bool isMinus;
	void ReverseOrder();
};


// �����������ͣ����������ӡ������ˡ�����
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
