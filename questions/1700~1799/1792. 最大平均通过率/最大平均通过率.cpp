// 最大平均通过率.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <queue>
#include "../check/CheckResult.h"

using namespace std;

class Classroom {
public:
    double pass;
    double total;
    double ratio;

    Classroom(int _pass, int _total) {
        pass = _pass;
        total = _total;
        ratio = pass / total;
    }

    bool operator< (const Classroom& c) const {  // 按照添加一个人，通过率增加最大的顺序排序
        return (pass + 1) / (total + 1) - ratio < (c.pass + 1) / (c.total + 1) - c.ratio;
    }

    void addOne() {
        pass += 1;
        total += 1;
        ratio = pass / total;
    }
};

class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<Classroom> classrooms;
        double totalRatio = 0;

        for (auto& classroom : classes) {
            classrooms.push(Classroom(classroom[0], classroom[1]));
        }

        for (int i = 0; i < extraStudents; ++i) {
            Classroom maxIncrease = classrooms.top();
            classrooms.pop();

            maxIncrease.addOne();  // 每一次，贪心的选择ratio增加最多的班添加一个聪明学生
            classrooms.push(maxIncrease);
        }

        while (!classrooms.empty()) {
            totalRatio += classrooms.top().ratio;
            classrooms.pop();
        }

        return totalRatio / classes.size();
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> classes = { {1,2},{3,5},{2,2} };
    check.checkDouble(0.783333, o.maxAverageRatio(classes, 2));

    classes = { {2,4},{3,9},{4,5},{2,10} };
    check.checkDouble(0.534848, o.maxAverageRatio(classes, 4));

    classes = { {2,4} };
    check.checkDouble(0.75, o.maxAverageRatio(classes, 4));
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
