/* 拆炸弹.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
你有一个炸弹需要拆除，时间紧迫！你的情报员会给你一个长度为 n 的 循环 数组 code 以及一个密钥 k 。

为了获得正确的密码，你需要替换掉每一个数字。所有数字会 同时 被替换。

如果 k > 0 ，将第 i 个数字用 接下来 k 个数字之和替换。
如果 k < 0 ，将第 i 个数字用 之前 k 个数字之和替换。
如果 k == 0 ，将第 i 个数字用 0 替换。
由于 code 是循环的， code[n-1] 下一个元素是 code[0] ，且 code[0] 前一个元素是 code[n-1] 。

给你 循环 数组 code 和整数密钥 k ，请你返回解密后的结果来拆除炸弹！

 

示例 1：

输入：code = [5,7,1,4], k = 3
输出：[12,10,16,13]
解释：每个数字都被接下来 3 个数字之和替换。解密后的密码为 [7+1+4, 1+4+5, 4+5+7, 5+7+1]。注意到数组是循环连接的。
示例 2：

输入：code = [1,2,3,4], k = 0
输出：[0,0,0,0]
解释：当 k 为 0 时，所有数字都被 0 替换。
示例 3：

输入：code = [2,4,9,3], k = -2
输出：[12,5,6,13]
解释：解密后的密码为 [3+9, 2+3, 4+2, 9+4] 。注意到数组是循环连接的。如果 k 是负数，那么和为 之前 的数字。
 

提示：

n == code.length
1 <= n <= 100
1 <= code[i] <= 100
-(n - 1) <= k <= n - 1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/defuse-the-bomb
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int size = code.size();
        vector<int> password(size, 0);

        if (k == 0) {
            return password;
        }

        int i = k > 0 ? 1 : size + k, j, sum = 0;
        k = abs(k);

        for (j = 0; j < k; ++j) {
            sum += code[i + j];
        }

        password[0] = sum;

        for (j = i + k, i = 1; i < size; ++i, ++j) {
            sum = sum - code[(j - k) % size] + code[j % size];
            password[i] = sum;
        }

        return password;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> code = { 5,7,1,4 };
    vector<int> actual = o.decrypt(code, 3);
    vector<int> expected = { 12,10,16,13 };
    check.checkIntVector(expected, actual);

    code = { 1,2,3,4 };
    actual = o.decrypt(code, 0);
    expected = { 0,0,0,0 };
    check.checkIntVector(expected, actual);

    code = { 2,4,9,3 };
    actual = o.decrypt(code, -2);
    expected = { 12,5,6,13 };
    check.checkIntVector(expected, actual);

    code = { 5 };
    actual = o.decrypt(code, 0);
    expected = { 0 };
    check.checkIntVector(expected, actual);
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
