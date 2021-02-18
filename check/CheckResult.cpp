#include <iostream>
#include <iomanip>
#include <algorithm>
#include <queue>
#include "CheckResult.h"

using namespace std;

void CheckResult::checkInt(int expected, int actual) {
	cout << "result : " << (expected == actual ? "success," : "fail   ,")
		<< " expected : " << left << setw(10) << expected << ",  actual : " << setw(10) << actual << endl;
}

void CheckResult::checkIntVector(vector<int>& expected, vector<int>& actual) {
	cout << "result : " << (expected == actual ? "success" : "fail fail fail fail fail fail fail fail fail fail fail fail") << endl << "    expected : { ";
	for (unsigned int i = 0; i < expected.size(); ++i) {
		if (i == expected.size() - 1) {
			cout << expected[i];
		}
		else {
			cout << expected[i] << ",";
		}
	}
	cout << " }" << endl << "    actual   : { ";
	for (unsigned int i = 0; i < actual.size(); ++i) {
		if (i == actual.size() - 1) {
			cout << actual[i];
		}
		else {
			cout << actual[i] << ",";
		}
	}
	cout << " }" << endl << endl;
}

void CheckResult::checkIntVectorInNums(vector<int>& expected, vector<int>& actual, unsigned int nums) {
	bool result = true;
	if ((expected.size() < nums) || (actual.size() < nums)) {
		cout << "result : fail   , nums invalid!" << endl;
		return;
	}

	for (unsigned int i = 0; i < nums; ++i) {
		if (expected[i] != actual[i]) {
			result = false;
			break;
		}
	}

	cout << "result : " << (result ? "success," : "fail   ,") << " expected : ";
	for (unsigned int i = 0; i < nums; ++i) {
		cout << expected[i] << " ";
	}
	cout << ",  actual : ";
	for (unsigned int i = 0; i < nums; ++i) {
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
	cout << "result : " << (expected == actual ? "success" : "fail fail fail fail fail fail fail fail fail fail fail fail") << endl << "    expected : { ";
	for (unsigned int i = 0; i < expected.size(); ++i) {
		cout << "{";
		for (unsigned int j = 0; j < expected[i].size(); ++j) {
			if (j == expected[i].size() - 1) {
				cout << expected[i][j];
			}
			else {
				cout << expected[i][j] << ",";
			}
		}
		if (i == expected.size() - 1) {
			cout << "}";
		}
		else {
			cout << "}, ";
		}
	}

	cout << " }" << endl << "    actual   : { ";
	for (unsigned int i = 0; i < actual.size(); ++i) {
		cout << "{";
		for (unsigned int j = 0; j < actual[i].size(); ++j) {
			if (j == actual[i].size() - 1) {
				cout << actual[i][j];
			}
			else {
				cout << actual[i][j] << ",";
			}
		}
		if (i == actual.size() - 1) {
			cout << "}";
		}
		else {
			cout << "}, ";
		}
	}
	cout << " }" << endl << endl;
}

void CheckResult::checkIntVectorVectorRandomOrder(vector<vector<int>>& expected, vector<vector<int>>& actual) {
	for (vector<int>& v : expected) {
		sort(v.begin(), v.end());
	}
	for (vector<int>& v : actual) {
		sort(v.begin(), v.end());
	}
	checkIntVectorVector(expected, actual);
}

void CheckResult::checkIntVectorRandomOrderVector(vector<vector<int>>& expected, vector<vector<int>>& actual) {
	sort(expected.begin(), expected.end());
	sort(actual.begin(), actual.end());
	checkIntVectorVector(expected, actual);
}

void CheckResult::checkIntVectorRandomVectorRandomOrder(vector<vector<int>>& expected, vector<vector<int>>& actual) {
	for (vector<int>& v : expected) {
		sort(v.begin(), v.end());
	}
	for (vector<int>& v : actual) {
		sort(v.begin(), v.end());
	}
	sort(expected.begin(), expected.end());
	sort(actual.begin(), actual.end());
	checkIntVectorVector(expected, actual);
}

void CheckResult::checkIntDoubleVector(vector<vector<int>>& expected, vector<vector<int>>& actual) {
	bool result = false;
	if (expected.size() != actual.size()) {
		goto output;
	}
	for (unsigned int i = 0; i < expected.size(); ++i) {
		if (expected[i] != actual[i]) {
			goto output;
		}
	}
	result = true;

output:
	cout << "result : " << (result ? "success" : "fail") << endl;
	cout << "expected : ";
	for (unsigned int i = 0; i < expected.size(); ++i) {
		vector<int> tmp = expected[i];
		for (unsigned int j = 0; j < tmp.size(); ++j) {
			cout << tmp[j] << " ";
		}
		cout << "  ";
	}
	cout << endl << "actual   : ";
	for (unsigned int i = 0; i < actual.size(); ++i) {
		vector<int> tmp = actual[i];
		for (unsigned int j = 0; j < tmp.size(); ++j) {
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
	cout << "result : " << ((fabs(expected - actual) < 1e-6) ? "success," : "fail   ,")
		<< " expected : " << setiosflags(ios::fixed) << setprecision(6) << expected << ",  actual : " << actual << endl;
}

void CheckResult::checkDoubleVector(vector<double>& expected, vector<double>& actual) {
	bool result = true;
	if (expected.size() != actual.size()) {
		result = false;
	}

	if (result) {
		for (unsigned int i = 0; i < expected.size(); ++i) {
			if (fabs(expected[i] - actual[i]) > 1e-6) {
				result = false;
				break;
			}
		}
	}

	cout << "result : " << (result ? "success," : "fail   ,") << " expected : { ";
	for (unsigned int i = 0; i < expected.size(); ++i) {
		if (i == expected.size() - 1) {
			cout << expected[i];
		}
		else {
			cout << expected[i] << ",";
		}
	}
	cout << " },  actual : { ";
	for (unsigned int i = 0; i < actual.size(); ++i) {
		if (i == actual.size() - 1) {
			cout << actual[i];
		}
		else {
			cout << actual[i] << ",";
		}
	}
	cout << " }" << endl;
}

void CheckResult::checkBool(bool expected, bool actual) {
	cout << "result : " << (expected == actual ? "success," : "fail   ,")
		<< " expected : " << (expected ? "true " : "false") << ",  actual : " << (actual ? "true " : "false") << endl;
}

void CheckResult::checkBoolVector(vector<bool>& expected, vector<bool>& actual) {
	cout << "result : " << (expected == actual ? "success" : "fail fail fail fail fail fail fail fail fail fail fail fail") << endl << "    expected : { ";
	for (unsigned int i = 0; i < expected.size() - 1; ++i) {
		cout << (expected[i] ? "true," : "false,");
	}
	if (!expected.empty()) {
		cout << (expected.back() ? "true" : "false");
	}
	cout << " }" << endl << "    actual   : { ";
	for (unsigned int i = 0; i < actual.size() - 1; ++i) {
		cout << (actual[i] ? "true," : "false,");
	}
	if (!expected.empty()) {
		cout << (actual.back() ? "true" : "false");
	}
	cout << " }" << endl << endl;
}

void CheckResult::checkString(string expected, string actual) {
	cout << "result : " << (expected == actual ? "success" : "fail fail fail fail fail fail fail fail fail fail fail fail") 
		<< endl << "    expected : \"" << expected << '"' << endl << "    actual   : \"" << actual << '"' << endl << endl;
}

void CheckResult::checkStringVector(vector<string>& expected, vector<string>& actual) {
	cout << "result : " << (expected == actual ? "success" : "fail fail fail fail fail fail fail fail fail fail fail fail") << endl << "    expected : { ";
	for (unsigned int i = 0; i < expected.size(); ++i) {
		if (i == expected.size() - 1) {
			cout << '"' << expected[i]  << '"';
		}
		else {
			cout << '"' << expected[i] << "\",";
		}
	}
	cout << " }" << endl << "    actual   : { ";
	for (unsigned int i = 0; i < actual.size(); ++i) {
		if (i == actual.size() - 1) {
			cout << '"' << actual[i] << '"';
		}
		else {
			cout << '"' << actual[i] << "\",";
		}
	}
	cout << " }" << endl << endl;
}

void CheckResult::checkStringVectorRandomOrder(vector<string>& expected, vector<string>& actual) {
	sort(expected.begin(), expected.end());
	sort(actual.begin(), actual.end());
	checkStringVector(expected, actual);
}

void CheckResult::checkStringVectorVector(vector<vector<string>>& expected, vector<vector<string>>& actual) {
	cout << "result : " << (expected == actual ? "success" : "fail fail fail fail fail fail fail fail fail fail fail fail") << endl << "    expected : { ";
	for (unsigned int i = 0; i < expected.size(); ++i) {
		cout << "{";
		for (unsigned int j = 0; j < expected[i].size(); ++j) {
			if (j == expected[i].size() - 1) {
				cout << "\"" << expected[i][j] << "\"";
			}
			else {
				cout << "\"" << expected[i][j] << "\",";
			}
		}
		if (i == expected.size() - 1) {
			cout << "}";
		}
		else {
			cout << "}, ";
		}
	}
	cout << " }" << endl << "    actual   : { ";
	for (unsigned int i = 0; i < actual.size(); ++i) {
		cout << "{";
		for (unsigned int j = 0; j < actual[i].size(); ++j) {
			if (j == actual[i].size() - 1) {
				cout << "\"" << actual[i][j] << "\"";
			}
			else {
				cout << "\"" << actual[i][j] << "\",";
			}
		}
		if (i == actual.size() - 1) {
			cout << "}";
		}
		else {
			cout << "}, ";
		}
	}
	cout << " }" << endl << endl;
}

void CheckResult::checkStringVectorRandomOrderVector(vector<vector<string>>& expected, vector<vector<string>>& actual) {
	sort(expected.begin(), expected.end());
	sort(actual.begin(), actual.end());
	checkStringVectorVector(expected, actual);
}

void CheckResult::checkStringVectorRandomVectorRandomOrder(vector<vector<string>>& expected, vector<vector<string>>& actual) {
	for (vector<string>& v : expected) {
		sort(v.begin(), v.end());
	}
	for (vector<string>& v : actual) {
		sort(v.begin(), v.end());
	}
	sort(expected.begin(), expected.end());
	sort(actual.begin(), actual.end());
	checkStringVectorVector(expected, actual);
}

void CheckResult::checkChar(char expected, char actual) {
	cout << "result : " << (expected == actual ? "success," : "fail   ,") << " expected : " << expected << ",  actual : " << actual << endl;
}

void CheckResult::checkCharVector(vector<char>& expected, vector<char>& actual) {
	cout << "result : " << (expected == actual ? "success," : "fail   ,") << " expected : ";
	for (unsigned int i = 0; i < expected.size(); ++i) {
		cout << expected[i] << " ";
	}
	cout << ",  actual : ";
	for (unsigned int i = 0; i < actual.size(); ++i) {
		cout << actual[i] << " ";
	}
	cout << endl;
}

void CheckResult::checkCharVectorVector(vector<vector<char>>& expected, vector<vector<char>>& actual) {
	cout << "result : " << (expected == actual ? "success" : "fail") << endl << "expected : ";
	for (unsigned int i = 0; i < expected.size(); ++i) {
		for (unsigned int j = 0; j < expected[i].size(); ++j) {
			cout << expected[i][j] << " ";
		}
		cout << "   ";
	}
	cout << endl << "actual   : ";
	for (unsigned int i = 0; i < actual.size(); ++i) {
		for (unsigned int j = 0; j < actual[i].size(); ++j) {
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
	cout << "result : " << (result ? "success" : "fail fail fail fail fail fail fail fail fail fail fail fail") << endl << "    expected : { ";
	tmpEx = expected;
	if (tmpEx != NULL) {
		cout << tmpEx->val;
		tmpEx = tmpEx->next;
	}
	while (tmpEx != NULL) {
		cout << "," << tmpEx->val;
		tmpEx = tmpEx->next;
	}

	cout << " }" << endl << "    actual   : { ";

	tmpAc = actual;
	if (tmpAc != NULL) {
		cout << tmpAc->val;
		tmpAc = tmpAc->next;
	}
	while (tmpAc != NULL) {
		cout << "," << tmpAc->val;
		tmpAc = tmpAc->next;
	}
	cout << " }" << endl << endl;
}

void CheckResult::checkPoint(void* expected, void* actual) {
	cout << "result : " << (expected == actual ? "success," : "fail   ,") << " expected : " << expected << ",  actual : " << actual << endl;
}

void CheckResult::outputTree(TreeNode* root, string& output) {
	queue<TreeNode*> bfs;
	bfs.push(root);

	while (!bfs.empty()) {
		TreeNode* node = bfs.front();
		bfs.pop();

		if (node == NULL) {
			output += "null,";
		}
		else {
			output += to_string(node->val);
			output += ',';
			bfs.push(node->left);
			bfs.push(node->right);
		}
	}

	while (output.size() >= 5 && output[output.size() - 5] == 'n') {
		output.erase(output.end() - 5, output.end());
	}

	if (!output.empty() && output.back() == ',') {
		output.pop_back();
	}
}

void CheckResult::checkTree(TreeNode* expected, TreeNode* actual) {
	string outputE, outputA;
	outputTree(expected, outputE);
	outputTree(actual, outputA);
	cout << "result : " << ((outputE == outputA) ? "success" : "fail fail fail fail fail fail fail fail fail fail fail fail") << endl;
	cout << "    expected : { " << outputE << " }" << endl;
	cout << "    actual   : { " << outputA << " }" << endl << endl;
}
