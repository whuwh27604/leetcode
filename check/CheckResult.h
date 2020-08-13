#ifndef __CHECKRESULT_H__
#define __CHECKRESULT_H__

#include <string>
#include <vector>
#include "../header/ListNode.h"

using namespace std;

class CheckResult {
public:
	void checkInt(int expected, int actual);
	void checkIntVector(vector<int>& expected, vector<int>& actual);
	void checkIntVectorInNums(vector<int>& expected, vector<int>& actual, unsigned int nums);
	void checkIntVectorVector(vector<vector<int>>& expected, vector<vector<int>>& actual);
	void checkIntVectorVectorRandomOrder(vector<vector<int>>& expected, vector<vector<int>>& actual);
	void checkIntDoubleVector(vector<vector<int>>& expected, vector<vector<int>>& actual);
	void checkUint(unsigned int expected, unsigned int actual);
	void checkDouble(double expected, double actual);
	void checkDoubleVector(vector<double>& expected, vector<double>& actual);
	void checkBool(bool expected, bool actual);
	void checkBoolVector(vector<bool>& expected, vector<bool>& actual);
	void checkString(string expected, string actual);
	void checkStringVector(vector<string>& expected, vector<string>& actual);
	void checkStringVectorVector(vector<vector<string>>& expected, vector<vector<string>>& actual);
	void checkChar(char expected, char actual);
	void checkCharVector(vector<char>& expected, vector<char>& actual);
	void checkCharVectorVector(vector<vector<char>>& expected, vector<vector<char>>& actual);
	void checkSingleList(ListNode* expected, ListNode* actual);
	void checkPoint(void* expected, void* actual);
};

#endif