// 完成所有任务的最少时间.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

bool vectorCompare(const vector<int>& v1, const vector<int>& v2) {
    return v1[1] < v2[1];
}

class Solution {
public:
    int findMinimumTime(vector<vector<int>>& tasks) {
        int maxTime = 2000, minTime = 0;
        vector<int> chosen(maxTime + 1, 0);

        sort(tasks.begin(), tasks.end(), vectorCompare);

        for (auto& task : tasks) {
            int count = 0;
            for (int time = task[0]; time <= task[1]; ++time) {
                count += chosen[time];
            }

            if (count < task[2]) {
                int additional = task[2] - count;
                minTime += additional;

                for (int time = task[1]; additional != 0; --time) {
                    if (chosen[time] == 0) {
                        chosen[time] = 1;
                        --additional;
                    }
                }
            }
        }

        return minTime;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> tasks = { {2,3,1},{4,5,1},{1,5,2} };
    check.checkInt(2, o.findMinimumTime(tasks));

    tasks = { {1,3,2},{2,5,3},{5,6,2} };
    check.checkInt(4, o.findMinimumTime(tasks));
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
