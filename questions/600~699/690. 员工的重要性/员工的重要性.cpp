/* 员工的重要性.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个保存员工信息的数据结构，它包含了员工唯一的id，重要度 和 直系下属的id。

比如，员工1是员工2的领导，员工2是员工3的领导。他们相应的重要度为15, 10, 5。那么员工1的数据结构是[1, 15, [2]]，员工2的数据结构是[2, 10, [3]]，员工3的数据结构是[3, 5, []]。注意虽然员工3也是员工1的一个下属，但是由于并不是直系下属，因此没有体现在员工1的数据结构中。

现在输入一个公司的所有员工信息，以及单个员工id，返回这个员工和他所有下属的重要度之和。

示例 1:

输入: [[1, 5, [2, 3]], [2, 3, []], [3, 3, []]], 1
输出: 11
解释:
员工1自身的重要度是5，他有两个直系下属2和3，而且2和3的重要度均为3。因此员工1的总重要度是 5 + 3 + 3 = 11。
注意:

一个员工最多有一个直系领导，但是可以有多个直系下属
员工数量不超过2000。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/employee-importance
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, Employee*> employeesTable;
        for (unsigned int i = 0; i < employees.size(); i++) {
            employeesTable[employees[i]->id] = employees[i];
        }

        auto iter = employeesTable.find(id);
        if (iter == employeesTable.end()) {
            return 0;
        }

        Employee* oneEmployee = iter->second;
        list<Employee*> allSubordinates;
        allSubordinates.push_back(oneEmployee);
        int importanceSum = 0;

        while (!allSubordinates.empty()) {
            oneEmployee = allSubordinates.front();
            allSubordinates.pop_front();
            importanceSum += oneEmployee->importance;
            vector<int>& employeeSubordinates = oneEmployee->subordinates;

            for (unsigned int j = 0; j < employeeSubordinates.size(); j++) {
                iter = employeesTable.find(employeeSubordinates[j]);
                allSubordinates.push_back(iter->second);
            }
        }

        return importanceSum;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    Employee e1 = { 1,5,{2,3} };
    Employee e2 = { 2,3,{} };
    Employee e3 = { 3,3,{} };
    vector<Employee*> employees = { &e1, &e2, &e3 };
    check.checkInt(11, o.getImportance(employees, 1));
    check.checkInt(0, o.getImportance(employees, 4));
    check.checkInt(3, o.getImportance(employees, 2));
    check.checkInt(3, o.getImportance(employees, 3));

    e1 = { 1,5,{} };
    employees = { &e1 };
    check.checkInt(5, o.getImportance(employees, 1));
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
