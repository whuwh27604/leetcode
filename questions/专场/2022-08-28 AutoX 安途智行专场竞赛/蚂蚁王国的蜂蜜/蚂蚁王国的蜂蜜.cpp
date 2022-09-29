/* 蚂蚁王国的蜂蜜.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
蚂蚁王国的蜂蜜专家旺财最近在研究蜂蜜的价格，为了估算出真实的蜂蜜价格，旺财以所有用有效报价的平均值作为蜂蜜均价，稳定的报价往往方差也比较小。因为情报具有时效性，所以每隔一段时间，旺财也会删除一些老旧报价。
因为计算平均值和方差对于蚂蚁是一个困难的问题，所以旺财希望你帮他设计一个系统，handle[i] = [type] 或 [type, value] 表示对于旺财的第 i 次的操作有：

若 type 为 1，表示获取了一份价格为 value 的报价
若 type 为 2，表示删除了一个价格为 value 的报价
若 type 为 3，表示计算当前蜂蜜的均价；若当前不存在任何有效报价，返回 -1
若 type 为 4，表示计算当前价格的方差；若当前不存在任何有效报价，返回 -1
请按操作的顺序，依次返回所有计算均价和方差的结果。

提示：

用例保证所有删除的报价都是有效的。
示例 1：

输入：handle = [[1,1],[1,2],[1,3],[1,2],[3],[4],[2,1],[2,2],[2,3],[3],[4]]

输出：[2.00000,0.50000,2.00000,0.00000]

解释：如下表所示
image.png

示例 2：

输入：handle = [[3],[1,10],[1,0],[3],[4],[2,10],[3]]

输出：[-1.00000,5.00000,25.00000,0.00000]

提示：

0 <= handle.length <=10^5
0 <= handle[i][1] <= 100
handle[i][0] 仅包含 1,2,3,4
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<double> honeyQuotes(vector<vector<int>>& handle) {
        double sum = 0, squareSum = 0;
        int count = 0;
        vector<double> ans;

        for (auto& request : handle) {
            if (request[0] == 1) {
                sum += request[1];
                squareSum += ((double)request[1] * request[1]);
                ++count;
            }
            else if (request[0] == 2) {
                sum -= request[1];
                squareSum -= ((double)request[1] * request[1]);
                --count;
            }
            else if (request[0] == 3) {
                if (count == 0) {
                    ans.push_back(-1);
                }
                else {
                    ans.push_back(sum / count);
                }
            }
            else {
                if (count == 0) {
                    ans.push_back(-1);
                }
                else {
                    double averge = sum / count;
                    ans.push_back((squareSum + averge * averge * count - 2 * sum * averge) / count);
                }
            }
        }

        return ans;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> handle = { {1,1},{1,2},{1,3},{1,2},{3},{4},{2,1},{2,2},{2,3},{3},{4} };
    vector<double> actual = o.honeyQuotes(handle);
    vector<double> expected = { 2.00000,0.50000,2.00000,0.00000 };
    check.checkDoubleVector(expected, actual);

    handle = { {3},{1,10},{1,0},{3},{4},{2,10},{3} };
    actual = o.honeyQuotes(handle);
    expected = { -1.00000,5.00000,25.00000,0.00000 };
    check.checkDoubleVector(expected, actual);

    handle = {  };
    actual = o.honeyQuotes(handle);
    expected = {  };
    check.checkDoubleVector(expected, actual);
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
