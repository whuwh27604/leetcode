/* 重新排序得到 2 的幂.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定正整数 N ，我们按任何顺序（包括原始顺序）将数字重新排序，注意其前导数字不能为零。

如果我们可以通过上述方式得到 2 的幂，返回 true；否则，返回 false。

 

示例 1：

输入：1
输出：true
示例 2：

输入：10
输出：false
示例 3：

输入：16
输出：true
示例 4：

输入：24
输出：false
示例 5：

输入：46
输出：true
 

提示：

1 <= N <= 10^9

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reordered-power-of-2
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_set>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool reorderedPowerOf2(int N) {
        unordered_set<string> powerTwo = { "1","2","4","8","16","23","46","128","256","125","0124","0248","0469","1289","13468","23678","35566","011237",
            "122446","224588","0145678","0122579","0134449","0368888","11266777","23334455","01466788","112234778","234455668","012356789","0112344778" };

        string num = to_string(N);
        sort(num.begin(), num.end());

        return powerTwo.count(num) == 1;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkBool(true, o.reorderedPowerOf2(1));
    check.checkBool(false, o.reorderedPowerOf2(10));
    check.checkBool(true, o.reorderedPowerOf2(16));
    check.checkBool(false, o.reorderedPowerOf2(24));
    check.checkBool(true, o.reorderedPowerOf2(46));
    check.checkBool(true, o.reorderedPowerOf2(1073741824));
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
