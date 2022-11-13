#include "Calculate.cpp"
#include "BaseData.h"

int main() {
	// BaseData AccNumber Complex
	Calculate<BaseData>* optor = new Calculate<BaseData>();
	vector<string> keywords;
	string word;
	cout << "请输入计算公式：";
	while (cin >> word) {
		if (word == "=") {
			break;
		}
		keywords.push_back(word);
	}
	cout << optor->OnStack(keywords).GetNumber();
	return 0;
}

// 测试样例：
// -1.5 * 2 + 3 / ( 4 - 1 ) = -2
// (2+3i) + (1+2i) = 3+5i
// 11111111111111111111111111111111111111111111111111111111111111111
// +
// 11111111111111111111111111111111111111111111111111111111111111111
// =
// 22222222222222222222222222222222222222222222222222222222222222222
