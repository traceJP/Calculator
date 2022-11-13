#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

template<class T>
class Calculate {
public:
	T OnStack(vector<string> formula);
	void Operate();

private:
	stack<T> nums;
	stack<char> ops;

	void CheckOps(char op);
	int PriorWeight(char op);

};


