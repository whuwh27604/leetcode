#include <iostream>
#include <iomanip>
#include <algorithm>
#include "CheckResult.h"

using namespace std;

void CheckResult::checkInt(int expected, int actual) {
	cout << "result : " << (expected == actual ? "success," : "fail   ,")
		<< " expected : " << left << setw(10) << expected << ",  actual : " << setw(10) << actual << endl;
}

void CheckResult::checkIntVector(vector<int>& expected, vector<int>& actual) {
	cout << "result : " << (expected == actual ? "success," : "fail   ,") << " expected : ";
	for (unsigned int i = 0; i < expected.size(); i++) {
		cout << expected[i] << " ";
	}
	cout << ",  actual : ";
	for (unsigned int i = 0; i < actual.size(); i++) {
		cout << actual[i] << " ";
	}
	cout << endl;
}

void CheckResult::checkIntVectorInNums(vector<int>& expected, vector<int>& actual, unsigned int nums) {
	bool result = true;
	if ((expected.size() < nums) || (actual.size() < nums)) {
		cout << "result : fail   , nums invalid!" << endl;
		return;
	}

	for (unsigned int i = 0; i < nums; i++) {
		if (expected[i] != actual[i]) {
			result = false;
			break;
		}
	}

	cout << "result : " << (result ? "success," : "fail   ,") << " expected : ";
	for (unsigned int i = 0; i < nums; i++) {
		cout << expected[i] << " ";
	}
	cout << ",  actual : ";
	for (unsigned int i = 0; i < nums; i++) {
		cout << actual[i] << " ";
	}
	cout << endl;
}

void CheckResult::checkIntVectorRandomOrder(vector<int>& expected, vector<int>& actual) {
	sort(expected.begin(), expected.end());
	sort(actual.begin(), actual.end());
	checkIntVector(expected, actual);
}

void CheckResult::checkIntVectorVector(vector<vector<int>>& expected, vector<vector<int>>& actual) {
	cout << "result : " << (expected == actual ? "success" : "fail") << endl << "expected : ";
	for (unsigned int i = 0; i < expected.size(); i++) {
		for (unsigned int j = 0; j < expected[i].size(); j++) {
			cout << expected[i][j] << " ";
		}
		cout << "   ";
	}
	cout << endl << "actual   : ";
	for (unsigned int i = 0; i < actual.size(); i++) {
		for (unsigned int j = 0; j < actual[i].size(); j++) {
			cout << actual[i][j] << " ";
		}
		cout << "   ";
	}
	cout << endl << endl;
}

void CheckResult::checkIntVectorVectorRandomOrder(vector<vector<int>>& expected, vector<vector<int>>& actual) {
	sort(expected.begin(), expected.end());
	sort(actual.begin(), actual.end());
	checkIntVectorVector(expected, actual);
}

void CheckResult::checkIntDoubleVector(vector<vector<int>>& expected, vector<vector<int>>& actual) {
	bool result = false;
	if (expected.size() != actual.size()) {
		goto output;
	}
	for (unsigned int i = 0; i < expected.size(); i++) {
		if (expected[i] != actual[i]) {
			goto output;
		}
	}
	result = true;

output:
	cout << "result : " << (result ? "success" : "fail") << endl;
	cout << "expected : ";
	for (unsigned int i = 0; i < expected.size(); i++) {
		vector<int> tmp = expected[i];
		for (unsigned int j = 0; j < tmp.size(); j++) {
			cout << tmp[j] << " ";
		}
		cout << "  ";
	}
	cout << endl << "actual   : ";
	for (unsigned int i = 0; i < actual.size(); i++) {
		vector<int> tmp = actual[i];
		for (unsigned int j = 0; j < tmp.size(); j++) {
			cout << tmp[j] << " ";
		}
		cout << "  ";
	}
	cout << endl << endl;
}

void CheckResult::checkUint(unsigned int expected, unsigned int actual) {
	cout << "result : " << (expected == actual ? "success," : "fail   ,")
		<< " expected : " << left << setw(10) << expected << ",  actual : " << setw(10) << actual << endl;
}

void CheckResult::checkDouble(double expected, double actual) {
	cout << "result : " << ((abs(expected - actual) < 1e-6) ? "success," : "fail   ,")
		<< " expected : " << left << setw(10) << expected << ",  actual : " << setw(10) << actual << endl;
}

void CheckResult::checkDoubleVector(vector<double>& expected, vector<double>& actual) {
	bool result = false;
	if (expected.size() != actual.size()) {
		goto output;
	}
	for (unsigned int i = 0; i < expected.size(); i++) {
		if (abs(expected[i] - actual[i]) >= 1e-6) {
			goto output;
		}
	}
	result = true;

output:
	cout << "result : " << (result ? "success," : "fail   ,") << " expected : ";
	for (unsigned int i = 0; i < expected.size(); i++) {
		cout << expected[i] << " ";
	}
	cout << ",  actual : ";
	for (unsigned int i = 0; i < actual.size(); i++) {
		cout << actual[i] << " ";
	}
	cout << endl;
}

void CheckResult::checkBool(bool expected, bool actual) {
	cout << "result : " << (expected == actual ? "success," : "fail   ,")
		<< " expected : " << (expected ? "true " : "false") << ",  actual : " << (actual ? "true " : "false") << endl;
}

void CheckResult::checkBoolVector(vector<bool>& expected, vector<bool>& actual) {
	cout << "result : " << (expected == actual ? "success," : "fail   ,") << " expected : ";
	for (unsigned int i = 0; i < expected.size(); i++) {
		cout << expected[i] << " ";
	}
	cout << ",  actual : ";
	for (unsigned int i = 0; i < actual.size(); i++) {
		cout << actual[i] << " ";
	}
	cout << endl;
}

void CheckResult::checkString(string expected, string actual) {
	cout << "result : " << (expected == actual ? "success," : "fail   ,")
		<< " expected : " << left << setw(20) << expected << ",  actual : " << setw(20) << actual << endl;
}

void CheckResult::checkStringVector(vector<string>& expected, vector<string>& actual) {
	cout << "result : " << (expected == actual ? "success," : "fail   ,") << " expected : ";
	for (unsigned int i = 0; i < expected.size(); i++) {
		cout << expected[i] << " ";
	}
	cout << ",  actual : ";
	for (unsigned int i = 0; i < actual.size(); i++) {
		cout << actual[i] << " ";
	}
	cout << endl << endl;
}

void CheckResult::checkStringVectorVector(vector<vector<string>>& expected, vector<vector<string>>& actual) {
	cout << "result : " << (expected == actual ? "success," : "fail   ,") << endl << "expected : ";
	for (unsigned int i = 0; i < expected.size(); i++) {
		for (unsigned int j = 0; j < expected[i].size(); j++) {
			cout << expected[i][j] << " ";
		}
		cout << "   ";
	}
	cout << endl << "actual   : ";
	for (unsigned int i = 0; i < actual.size(); i++) {
		for (unsigned int j = 0; j < actual[i].size(); j++) {
			cout << actual[i][j] << " ";
		}
		cout << "   ";
	}
	cout << endl << endl;
}

void CheckResult::checkChar(char expected, char actual) {
	cout << "result : " << (expected == actual ? "success," : "fail   ,") << " expected : " << expected << ",  actual : " << actual << endl;
}

void CheckResult::checkCharVector(vector<char>& expected, vector<char>& actual) {
	cout << "result : " << (expected == actual ? "success," : "fail   ,") << " expected : ";
	for (unsigned int i = 0; i < expected.size(); i++) {
		cout << expected[i] << " ";
	}
	cout << ",  actual : ";
	for (unsigned int i = 0; i < actual.size(); i++) {
		cout << actual[i] << " ";
	}
	cout << endl;
}

void CheckResult::checkCharVectorVector(vector<vector<char>>& expected, vector<vector<char>>& actual) {
	cout << "result : " << (expected == actual ? "success" : "fail") << endl << "expected : ";
	for (unsigned int i = 0; i < expected.size(); i++) {
		for (unsigned int j = 0; j < expected[i].size(); j++) {
			cout << expected[i][j] << " ";
		}
		cout << "   ";
	}
	cout << endl << "actual   : ";
	for (unsigned int i = 0; i < actual.size(); i++) {
		for (unsigned int j = 0; j < actual[i].size(); j++) {
			cout << actual[i][j] << " ";
		}
		cout << "   ";
	}
	cout << endl << endl;
}

void CheckResult::checkSingleList(ListNode* expected, ListNode* actual) {
	bool result = true;
	ListNode* tmpEx = expected;
	ListNode* tmpAc = actual;
	if ((tmpEx == NULL) && (tmpAc == NULL)) {
		goto output;
	}

	result = false;
	while ((tmpEx != NULL) && (tmpAc != NULL)) {
		if (tmpEx->val != tmpAc->val) {
			break;
		}

		tmpEx = tmpEx->next;
		tmpAc = tmpAc->next;
		if ((tmpEx == NULL) && (tmpAc == NULL)) {
			result = true;
		}
	}

output:
	cout << "result : " << (result ? "success," : "fail   ,") << " expected : ";
	tmpEx = expected;
	while (tmpEx != NULL) {
		cout << tmpEx->val << " ";
		tmpEx = tmpEx->next;
	}
	cout << ",  actual : ";
	tmpAc = actual;
	while (tmpAc != NULL) {
		cout << tmpAc->val << " ";
		tmpAc = tmpAc->next;
	}
	cout << endl;
}

void CheckResult::checkPoint(void* expected, void* actual) {
	cout << "result : " << (expected == actual ? "success," : "fail   ,") << " expected : " << expected << ",  actual : " << actual << endl;
}