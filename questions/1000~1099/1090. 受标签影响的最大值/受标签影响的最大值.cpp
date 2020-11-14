/* 受标签影响的最大值.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
我们有一个项的集合，其中第 i 项的值为 values[i]，标签为 labels[i]。

我们从这些项中选出一个子集 S，这样一来：

|S| <= num_wanted
对于任意的标签 L，子集 S 中标签为 L 的项的数目总满足 <= use_limit。
返回子集 S 的最大可能的 和。

 

示例 1：

输入：values = [5,4,3,2,1], labels = [1,1,2,2,3], num_wanted = 3, use_limit = 1
输出：9
解释：选出的子集是第一项，第三项和第五项。
示例 2：

输入：values = [5,4,3,2,1], labels = [1,3,3,3,2], num_wanted = 3, use_limit = 2
输出：12
解释：选出的子集是第一项，第二项和第三项。
示例 3：

输入：values = [9,8,8,7,6], labels = [0,0,0,1,1], num_wanted = 3, use_limit = 1
输出：16
解释：选出的子集是第一项和第四项。
示例 4：

输入：values = [9,8,8,7,6], labels = [0,0,0,1,1], num_wanted = 3, use_limit = 2
输出：24
解释：选出的子集是第一项，第二项和第四项。
 

提示：

1 <= values.length == labels.length <= 20000
0 <= values[i], labels[i] <= 20000
1 <= num_wanted, use_limit <= values.length

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/largest-values-from-labels
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

bool vectorCompare(pair<int, int>& v1, pair<int, int>& v2) {
    return v1.first > v2.first;
}

class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int num_wanted, int use_limit) {
        vector<pair<int, int>> valueLabels(values.size(), pair<int, int>{0, 0});
        unionValueLabels(values, labels, valueLabels);
        sort(valueLabels.begin(), valueLabels.end(), vectorCompare);

        int sum = 0, count = 0;
        unordered_map<int, int> labelTimes;

        for (pair<int, int>& valueLabel : valueLabels) {
            if (++labelTimes[valueLabel.second] <= use_limit) {
                sum += valueLabel.first;
                ++count;
            }

            if (count == num_wanted) {
                break;
            }
        }

        return sum;
    }

    void unionValueLabels(vector<int>& values, vector<int>& labels, vector<pair<int, int>>& valueLabels) {
        for (unsigned int i = 0; i < values.size(); ++i) {
            valueLabels[i] = { values[i], labels[i] };
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> values = { 5,4,3,2,1 };
    vector<int> labels = { 1,1,2,2,3 };
    check.checkInt(9, o.largestValsFromLabels(values, labels, 3, 1));

    values = { 5,4,3,2,1 };
    labels = { 1,3,3,3,2 };
    check.checkInt(12, o.largestValsFromLabels(values, labels, 3, 2));

    values = { 9,8,8,7,6 };
    labels = { 0,0,0,1,1 };
    check.checkInt(16, o.largestValsFromLabels(values, labels, 3, 1));

    values = { 9,8,8,7,6 };
    labels = { 0,0,0,1,1 };
    check.checkInt(24, o.largestValsFromLabels(values, labels, 3, 2));
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
