#include "Calculate.h"

template<class T>
T Calculate<T>::OnStack(vector<string> formula) {
	for (string item : formula) {
		T* number = new T();
		if (number->IsNumber(item)) {
			number->SetNumber(item);
			nums.push(*number);
		}
		else {
			CheckOps(item[0]);
		}
	}

	// 普通表达式全部计算即可	
	while (!ops.empty()) {
		Operate();
	}
	return nums.top();
}

template<class T>
void Calculate<T>::Operate() {
	T va, vb, res;
	va = nums.top(); nums.pop();    // 被除数
	vb = nums.top(); nums.pop();    // 除数
	const char op = ops.top(); ops.pop();

	switch (op) {
	case '+':
		res = vb + va;
		break;
	case '-':
		res = vb - va;
		break;
	case '*':
		res = vb * va;
		break;
	case '/':
		res = vb / va;
		break;
	case '^':
		break;
	case '#':
		break;
	default:
		throw new exception();
	}

	nums.push(res);
}

template<class T>
void Calculate<T>::CheckOps(char op) {
	switch (op) {
	case '(':
		ops.push(op);
		break;
	case ')':
		while (ops.top() != '(') {
			Operate();
		}
		ops.pop();
		break;
	default:
		if (!ops.empty() && PriorWeight(op) < PriorWeight(ops.top())) {
			do {
				Operate();
			} while (!ops.empty() && PriorWeight(op) > PriorWeight(ops.top()));
		}
		ops.push(op);
	}

}

template<class T>
int Calculate<T>::PriorWeight(char op) {
	switch (op) {
	case '+':
	case '-':
		return 1;
	case '*':
	case '/':
	case '%':
		return 2;
	default:
		return -1;
	}
}
