/* 合作开发.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
为了不断提高用户使用的体验，开发团队正在对产品进行全方位的开发和优化。
已知开发团队共有若干名成员，skills[i] 表示第 i 名开发人员掌握技能列表。如果两名成员各自拥有至少一门对方未拥有的技能，则这两名成员可以「合作开发」。
请返回当前有多少对开发成员满足「合作开发」的条件。由于答案可能很大，请你返回答案对 10^9 + 7 取余的结果。

注意：

对于任意 skills[i] 均升序排列。
示例 1：

输入：
skills = [[1,2,3],[3],[2,4]]

输出: 2

解释：
开发成员 [1,2,3] 和成员 [2,4] 满足「合作开发」的条件，技能 1 和 4 分别是对方未拥有的技术
开发成员 [3] 和成员 [2,4] 满足「合作开发」的条件，技能 3 和 4 分别是对方未拥有的技术
开发成员 [1,2,3] 和成员 [3] 不满足「合作开发」的条件，由于开发成员 [3] 没有对方未拥有的技术
因此有 2 对开发成员满足「合作开发」的条件。

示例 2：

输入：
skills = [[3],[6]]

输出: 1

解释：
开发成员 [3] 和成员 [6] 满足「合作开发」的条件
因此有 1 对开发成员满足「合作开发」的条件。

提示：

2 <= skills.length <= 10^5
1 <= skills[i].length <= 4
1 <= skills[i][j] <= 1000
skills[i] 中不包含重复元素
*/

#include <iostream>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int coopDevelop(vector<vector<int>>& skills) {
        unordered_map<long long, int> count;
        vector<vector<int>> skills1, skills2, skills3, skills4;
        long long nonCoops = 0, size = skills.size();

        classify(skills, skills1, skills2, skills3, skills4);  // 按照skills长度从大到小的顺序求解
        getNonCoop(skills4, count, nonCoops);
        getNonCoop(skills3, count, nonCoops);
        getNonCoop(skills2, count, nonCoops);
        getNonCoop(skills1, count, nonCoops);

        return (int)((size * (size - 1) / 2 - nonCoops) % 1000000007);
    }

    void classify(vector<vector<int>>& skills, vector<vector<int>>& skills1, vector<vector<int>>& skills2, vector<vector<int>>& skills3, vector<vector<int>>& skills4) {
        for (auto& skill : skills) {
            int size = skill.size();

            if (size == 1) {
                skills1.push_back(skill);
            }
            else if (size == 2) {
                skills2.push_back(skill);
            }
            else if (size == 3) {
                skills3.push_back(skill);
            }
            else {
                skills4.push_back(skill);
            }
        }
    }

    void getNonCoop(vector<vector<int>>& skills, unordered_map<long long, int>& count, long long& nonCoops) {
        for (auto& skill : skills) {
            getNonCoop(skill, count, nonCoops);
        }
    }

    void getNonCoop(vector<int>& skills, unordered_map<long long, int>& count, long long& nonCoops) {
        int size = skills.size(), maxMask = (1 << size);
        long long skillSubset = 0;

        for (int mask = 1; mask < maxMask; ++mask) {  // 枚举skills的所有子集，后续的skills如果刚好是某个子集，那么这两个skills无法合作
            skillSubset = 0;

            for (int i = 0, bit = 1; i < size; ++i, bit <<= 1) {
                if ((bit & mask) != 0) {
                    skillSubset = ((skillSubset << 10) | skills[i]);
                }
            }

            ++count[skillSubset];  // 将子集压缩到skillSubset并计数
        }

        nonCoops += ((long long)count[skillSubset] - 1);  // 当前skills的全集是skillSubset，它在前面作为某个skills的子集已经出现count[skillSubset]次，排除自己的这一次
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> skills = { {1,2,3},{3},{2,4} };
    check.checkInt(2, o.coopDevelop(skills));

    skills = { {3},{6} };
    check.checkInt(1, o.coopDevelop(skills));
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
