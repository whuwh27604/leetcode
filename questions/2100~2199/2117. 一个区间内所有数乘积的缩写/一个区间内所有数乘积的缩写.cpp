/* 一个区间内所有数乘积的缩写.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你两个正整数 left 和 right ，满足 left <= right 。请你计算 闭区间 [left, right] 中所有整数的 乘积 。

由于乘积可能非常大，你需要将它按照以下步骤 缩写 ：

统计乘积中 后缀 0 的数目，将这个数目记为 C 。
比方说，1000 中有 3 个后缀 0 ，546 中没有后缀 0 。
将乘积中剩余数字记为 d 。如果 d > 10 ，那么将乘积表示为 <pre>...<suf> 的形式，其中 <pre> 表示乘积最 开始 的 5 个数位，<suf> 表示删除后缀 0 之后 结尾的 5 个数位。如果 d <= 10 ，我们不对它做修改。
比方说，我们将 1234567654321 表示为 12345...54321 ，但是 1234567 仍然表示为 1234567 。
最后，将乘积表示为 字符串 "<pre>...<suf>eC" 。
比方说，12345678987600000 被表示为 "12345...89876e5" 。
请你返回一个字符串，表示 闭区间 [left, right] 中所有整数 乘积 的 缩写 。

 

示例 1：

输入：left = 1, right = 4
输出："24e0"
解释：
乘积为 1 × 2 × 3 × 4 = 24 。
由于没有后缀 0 ，所以 24 保持不变，缩写的结尾为 "e0" 。
因为乘积的结果是 2 位数，小于 10 ，所欲我们不进一步将它缩写。
所以，最终将乘积表示为 "24e0" 。
示例 2：

输入：left = 2, right = 11
输出："399168e2"
解释：
乘积为 39916800 。
有 2 个后缀 0 ，删除后得到 399168 。缩写的结尾为 "e2" 。
删除后缀 0 后是 6 位数，不需要进一步缩写。
所以，最终将乘积表示为 "399168e2" 。
示例 3：



输入：left = 999998, right = 1000000
输出："99999...00002e6"
解释：
上图展示了如何得到乘积的缩写 "99999...00002e6" 。
- 总共有 6 个后缀 0 。缩写的结尾为 "e6" 。
- 开头 5 个数位是 99999 。
- 删除后缀 0 后结尾 5 个数字为 00002 。
示例 4：

输入：left = 256, right = 65535
输出："23510...78528e16317"
解释：
乘积是一个非常大的数字：
- 总共有 16317 个后缀 0 。缩写结尾为 "e16317" 。
- 开头 5 个数字为 23510 。
- 删除后缀 0 后，结尾 5 个数字为 78528 。
所以，乘积的缩写为 "23510...78528e16317" 。
 

提示：

1 <= left <= right <= 106

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/abbreviating-the-product-of-a-range
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    string abbreviateProduct(int left, int right) {
        long long M = 10000000000, MOD = 1000000000000;
        long long suff = 1, pref = 1;
        int cnt0 = 0;
        bool ok10 = false;

        for (int x = left; x <= right; x++) {  // 计算后缀
            suff *= x;

            while (suff % 10 == 0) {
                ++cnt0;
                suff /= 10;
            }

            suff %= MOD;
        }

        for (int x = left; x < right + 1; x++) {  //  计算前缀  
            pref *= x;

            while (pref >= 10 && pref % 10 == 0) {
                pref /= 10;
            }

            if (pref >= M) {
                ok10 = true;
            }

            while (pref >= MOD) {
                pref /= 10;
            }
        }

        if (ok10) {
            while (pref >= 100000) {
                pref /= 10;
            }

            string res = to_string(pref);
            res += "...";
            string b = to_string(suff % 100000);

            for (int i = 0; i < 5 - (int)b.size(); i++) {
                res.push_back('0');
            }

            res += b;
            res.push_back('e');
            res += to_string(cnt0);
            return res;
        }
        else {
            return to_string(pref) + "e" + to_string(cnt0);
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkString("24e0", o.abbreviateProduct(1, 4));
    check.checkString("399168e2", o.abbreviateProduct(2, 11));
    check.checkString("99999...00002e6", o.abbreviateProduct(999998, 1000000));
    check.checkString("23510...78528e16317", o.abbreviateProduct(256, 65535));
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
