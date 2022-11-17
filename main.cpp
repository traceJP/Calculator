#include "Calculate.cpp"
#include "BaseData.h"

string CheckTypeAndCalculate(vector<string> words);

int main() {
	vector<string> keywords;
	string word;
	cout << "请输入计算公式：";
	while (cin >> word) {
		if (word == "=") {
			break;
		}
		keywords.push_back(word);
	}
	// cout << CheckTypeAndCalculate(keywords);
	Calculate<AccNumber>* optor = new Calculate<AccNumber>();
	cout << optor->OnStack(keywords).GetNumber();
}


string CheckTypeAndCalculate(vector<string> words) {
	for (string item : words) {
		// 复数运算
		if (item.front() == '(' && item.back() == ')') {
			Calculate<Complex>* optor = new Calculate<Complex>();
			return optor->OnStack(words).GetNumber();
		}
		// 高精度运算
		if (item.size() > 999) {
			Calculate<AccNumber>* optor = new Calculate<AccNumber>();
			return optor->OnStack(words).GetNumber();
		}
	}
	// 普通运算
	Calculate<BaseData>* optor = new Calculate<BaseData>();
	return optor->OnStack(words).GetNumber();
}

// 测试样例：
// -1.5 * 2 + 3 / ( 4 - 1 ) = -2
// (2+3i) + (1+2i) = 3+5i
// 11111111111111111111111111111111111111111111111111111111111111111
// +
// 11111111111111111111111111111111111111111111111111111111111111111
// =
// 22222222222222222222222222222222222222222222222222222222222222222
