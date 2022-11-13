#include "BaseData.h"

/// ---------------------------------------------------------------------------------
/// BaseData
/// ---------------------------------------------------------------------------------
string BaseData::GetNumber() {
	return to_string(this->number);
}

void BaseData::SetNumber(string number) {
	this->number = stold(number);
}

bool BaseData::IsNumber(string str) {
	if (str.size() == 1 && str == "-") {
		return false;
	}
	for (int i = 0; i < str.size(); i++) {
		int tem = (int)str[i];
		if (!(tem >= 48 && tem <= 57 || tem == 45 || tem == 46)) {
			return false;
		}
	}
	return true;
}

BaseData BaseData::operator + (BaseData& c) {
	BaseData* res = new BaseData();
	res->number = this->number + c.number;
	return *res;
}

BaseData BaseData::operator - (BaseData& c) {
	BaseData* res = new BaseData();
	res->number = this->number - c.number;
	return *res;
}

BaseData BaseData::operator * (BaseData& c) {
	BaseData* res = new BaseData();
	res->number = this->number * c.number;
	return *res;
}

BaseData BaseData::operator / (BaseData& c) {
	BaseData* res = new BaseData();
	res->number = this->number / c.number;
	return *res;
}

//BaseData BaseData::operator ^ (BaseData& c) {
//	BaseData res;
//	res.number = powl(this->number, c.number)
//	return res;
//}
//
//BaseData BaseData::Sqrt(BaseData& num) {
//	BaseData<T> res;
//	return res;
//}



/// ---------------------------------------------------------------------------------
/// AccNumber
/// ---------------------------------------------------------------------------------
string AccNumber::GetNumber() {
	if (this->isMinus) {
		return "-" + this->number;
	}
	return this->number;
}

void AccNumber::SetNumber(string number) {
	if (number.front() == '-') {
		this->isMinus = true;
		number.erase(0, 1);
	}
	this->number = number;
}

bool AccNumber::IsNumber(string str) {
	if (str.size() == 1 && str == "-") {
		return false;
	}
	for (int i = 0; i < str.size(); i++) {
		int tem = (int)str[i];
		if (!(tem >= 48 && tem <= 57 || tem == 45)) {
			return false;
		}
	}
	return true;
}

AccNumber AccNumber::operator + (AccNumber& c) {
	AccNumber* acc = new AccNumber();

	// 负数处理
	if (this->isMinus && c.isMinus) {    // (-1) + (-1)
		acc->isMinus = true;
	} 
	else if (this->isMinus) {    // (-1) + 1
		this->isMinus = false;
		return c - *this;
	}
	else if (c.isMinus) {    // 1 + (-1)
		c.isMinus = false;
		return *this - c;
	}

	// 计算
	this->ReverseOrder();
	c.ReverseOrder();
	string res, num = this->number, numd = c.number;
	int temp = 0;
	for (auto i = 0; i < num.size() || i < numd.size(); i++) {
		if (i < num.size()) {
			temp += num[i] - '0';
		}
		if (i < numd.size()) {
			temp += numd[i] - '0';
		}
		res += to_string(temp % 10);
		temp /= 10;    // 余数
	}
	if (temp > 0) {
		res += to_string(temp);
	}

	acc->SetNumber(res);
	acc->ReverseOrder();
	return *acc;
}

AccNumber AccNumber::operator - (AccNumber& c) {
	AccNumber* acc = new AccNumber();

	// 负数处理
	if (this->isMinus && c.isMinus) {    // (-1) - (-1)
		c.isMinus = false;
		return *this + c;
	}
	else if (this->isMinus) {    // (-1) - 1
		c.isMinus = true;
		return *this + c;
	}
	else if (c.isMinus) {    // 1 - (-1)
		c.isMinus = false;
		return *this + c;
	}

	this->ReverseOrder();
	c.ReverseOrder();

	string res, num = this->number, numd = c.number;
	// 减数大于被减数，结果为负（交换两数并结果置负）（比较两数）
	bool resIsMinus = false;
	if (num.size() == numd.size()) {
		for (size_t i = num.size() - 1; i >= 0;i--) {
			if (num[i] != numd[i]) {
				resIsMinus = num[i] < numd[i];
				break;
			}
		}
	}
	else {
		resIsMinus = num.size() < numd.size();
	}
	if (resIsMinus) {
		acc->isMinus = true;
		num = c.number, numd = this->number;
	}

	// 计算
	int temp = 0;
	for (auto i = 0; i < num.size(); i++) {    // 这里 num 一定比 numd 要大
		temp = num[i] - '0' - temp;
		if (i < numd.size()) {
			temp -= numd[i] - '0';
		}
		res += to_string((temp + 10) % 10);
		temp = temp < 0 ? 1 : 0;
	}
	while (res.back() == '0' && res.size() > 1) {
		res.pop_back();
	}
	
	acc->SetNumber(res);
	acc->ReverseOrder();
	return *acc;
}

AccNumber AccNumber::operator * (AccNumber& c) {
	AccNumber* acc = new AccNumber();

	// 负数处理
	if (this->isMinus || c.isMinus) {    // (-1) * 1  ||  1 * (-1)
		acc->isMinus = true;
	}

	// 计算
	//https://blog.csdn.net/PYcharmRoot/article/details/122682074
	this->ReverseOrder();
	c.ReverseOrder();
	string res, num = this->number, numd = c.number;

	/*
vector<int> res;
	for (int i = 0; i < num.size(); i++) {
		for (int j = 0; j < numd.size(); j++) {
			res[i + j] += (num[i] - '0') * (numd[j] - '0');
		}
	}
	for (int i = 0;i < num.size() + numd.size();i++) {    // 处理进位
		res[i] = res[i - 1] / 10;
		res[i - 1] %= 10;
	}
	while (res.back() == '0' && res.size() > 1) {
		res.pop_back();
	}
	string resfor;
	for (int i = 0; i < res.size(); i++) {
		resfor += to_string(res[i]);
	}
	*/
	// vector<int> 转 string
	acc->SetNumber(res);
	acc->ReverseOrder();
	return *acc;
}

AccNumber AccNumber::operator / (AccNumber& c) {
	AccNumber* acc = new AccNumber();
	return *acc;
}

AccNumber AccNumber::operator % (AccNumber& c) {
	AccNumber* acc = new AccNumber();
	return *acc;
}

void AccNumber::ReverseOrder() {
	string res;
	for (size_t i = number.size() - 1; i >= 0; i--) {
		res.push_back(number[i]);
	}
	number = res;
}


/// ---------------------------------------------------------------------------------
/// Complex
/// ---------------------------------------------------------------------------------
string Complex::GetNumber() {
	return to_string(this->real()) + "+" + to_string(this->imag()) + "i";
}

void Complex::SetNumber(string number) {

	// (-1+2i) (-1-2i) (1+2i) (1-2i)
	number.pop_back(); number.erase(0, 1);
	if (number.back() == 'i') {    // (1+2i)  ||  (2i)
		number.pop_back();    // 弹掉i符号

		size_t indexAdd = number.find('+');
		size_t indexSub = number.find_last_of('-');
		

		if (indexAdd == string::npos && indexSub == string::npos) {
			this->real(0);
			this->imag(stold(number));
		}
		else {
			//this->real(stold(number.substr(0, index)));
			//this->imag(stold(number.substr(index)));
		}
	}
	else {    // (1)
		this->real(stold(number));
		this->imag(0);
	}
}

bool Complex::IsNumber(string str) {
	if (str.front() != '(' && str.back() != ')') {
		return false;
	}
	for (int i = 1; i < str.size() - 1; i++) {
		int tem = (int)str[i];
		if (!(tem >= 48 && tem <= 57 || tem == 43 || tem == 45 || tem == 46)) {
			return false;
		}
	}
	return true;
}

Complex Complex::operator + (Complex& c) {
	Complex* res = new Complex();
	return *res;
}

Complex Complex::operator - (Complex& c) {
	Complex* res = new Complex();
	return *res;
}

Complex Complex::operator * (Complex& c) {
	Complex* res = new Complex();
	return *res;
}

Complex Complex::operator / (Complex& c) {
	Complex* res = new Complex();
	return *res;
}

