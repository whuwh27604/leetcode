/* 将数组拆分成斐波那契序列.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个数字字符串 S，比如 S = "123456579"，我们可以将它分成斐波那契式的序列 [123, 456, 579]。

形式上，斐波那契式序列是一个非负整数列表 F，且满足：

0 <= F[i] <= 2^31 - 1，（也就是说，每个整数都符合 32 位有符号整数类型）；
F.length >= 3；
对于所有的0 <= i < F.length - 2，都有 F[i] + F[i+1] = F[i+2] 成立。
另外，请注意，将字符串拆分成小块时，每个块的数字一定不要以零开头，除非这个块是数字 0 本身。

返回从 S 拆分出来的任意一组斐波那契式的序列块，如果不能拆分则返回 []。

 

示例 1：

输入："123456579"
输出：[123,456,579]
示例 2：

输入: "11235813"
输出: [1,1,2,3,5,8,13]
示例 3：

输入: "112358130"
输出: []
解释: 这项任务无法完成。
示例 4：

输入："0123"
输出：[]
解释：每个块的数字不能以零开头，因此 "01"，"2"，"3" 不是有效答案。
示例 5：

输入: "1101111"
输出: [110, 1, 111]
解释: 输出 [11,0,11,11] 也同样被接受。
 

提示：

1 <= S.length <= 200
字符串 S 中只含有数字。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/split-array-into-fibonacci-sequence
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <sstream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> splitIntoFibonacci(string S) {
        int i, j, size = S.size();
        vector<int> fibonacci;

        for (i = 0; (i < size / 2) && (i < 10); ++i) {
            string f1(S, 0, i + 1);
            if ((to_int(f1) == -1) || (f1[0] == '0' && f1.size() != 1)) {
                continue;
            }

            for (j = i + 1; (j <= i + (size - i - 1) / 2) && (j <= i + 10); ++j) {
                string f2(S, i + 1, j - i);
                if ((to_int(f2) == -1) || (f2[0] == '0' && f2.size() != 1)) {
                    continue;
                }

                if (check(S, f1, f2, fibonacci)) {
                    return fibonacci;
                }
            }
        }

        return {};
    }

    bool check(string& S, string& f1, string& f2, vector<int>& fibonacci) {
        int i = f1.size() + f2.size(), size = S.size();
        int num1 = to_int(f1), num2 = to_int(f2);
        fibonacci.push_back(num1);
        fibonacci.push_back(num2);

        while (i < size) {
            long long sum = (long long)num1 + num2;
            if (sum > INT_MAX) {
                break;
            }

            string next = to_string(sum);
            if (S.compare(i, next.size(), next) != 0) {
                break;
            }

            fibonacci.push_back((int)sum);
            num1 = num2;
            num2 = (int)sum;
            i += next.size();
        }

        if (i == size) {
            return true;
        }
        else {
            fibonacci.clear();
            return false;
        }
    }

    int to_int(string& s) {
        stringstream ss;
        ss << s;
        long long num;
        ss >> num;

        return num > INT_MAX ? -1 : (int)num;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> actual = o.splitIntoFibonacci("123456579");
    vector<int> expected = { 123,456,579 };
    check.checkIntVector(expected, actual);

    actual = o.splitIntoFibonacci("11235813");
    expected = { 1,1,2,3,5,8,13 };
    check.checkIntVector(expected, actual);

    actual = o.splitIntoFibonacci("112358130");
    expected = {  };
    check.checkIntVector(expected, actual);

    actual = o.splitIntoFibonacci("0123");
    expected = {  };
    check.checkIntVector(expected, actual);

    actual = o.splitIntoFibonacci("1101111");
    expected = { 11,0,11,11 };
    check.checkIntVector(expected, actual);

    actual = o.splitIntoFibonacci("121474836472147483648");
    expected = {  };
    check.checkIntVector(expected, actual);

    actual = o.splitIntoFibonacci("3611537383985343591834441270352104793375145479938855071433500231900737525076071514982402115895535257195564161509167334647108949738176284385285234123461518508746752631120827113919550237703163294909");
    expected = {  };
    check.checkIntVector(expected, actual);

    actual = o.splitIntoFibonacci("539834657215398346785398346991079669377161950407626991734534318677529701785098211336528511");
    expected = {  };
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
