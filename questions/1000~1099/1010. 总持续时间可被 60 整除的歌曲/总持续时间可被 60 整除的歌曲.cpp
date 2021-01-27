/* 总持续时间可被 60 整除的歌曲.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
在歌曲列表中，第 i 首歌曲的持续时间为 time[i] 秒。

返回其总持续时间（以秒为单位）可被 60 整除的歌曲对的数量。形式上，我们希望索引的数字 i 和 j 满足  i < j 且有 (time[i] + time[j]) % 60 == 0。

 

示例 1：

输入：[30,20,150,100,40]
输出：3
解释：这三对的总持续时间可被 60 整数：
(time[0] = 30, time[2] = 150): 总持续时间 180
(time[1] = 20, time[3] = 100): 总持续时间 120
(time[1] = 20, time[4] = 40): 总持续时间 60
示例 2：

输入：[60,60,60]
输出：3
解释：所有三对的总持续时间都是 120，可以被 60 整数。
 

提示：

1 <= time.length <= 60000
1 <= time[i] <= 500

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/pairs-of-songs-with-total-durations-divisible-by-60
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int remainderCount[60] = { 0 };
        int numberPairs = 0;

        for (unsigned int i = 0; i < time.size(); i++) {
            int remainder = (time[i] % 60);
            int pair = (60 - remainder);
            if (pair == 60) {
                pair = 0;
            }
            numberPairs += remainderCount[pair];
            remainderCount[remainder]++;
        }

        return numberPairs;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> time = { 30,20,150,100,40 };
    check.checkInt(3, o.numPairsDivisibleBy60(time));

    time = { 30,150,100,160,20,40,220,100 };
    check.checkInt(6, o.numPairsDivisibleBy60(time));

    time = { 60,60,60 };
    check.checkInt(3, o.numPairsDivisibleBy60(time));

    time = { 60 };
    check.checkInt(0, o.numPairsDivisibleBy60(time));

    time = { 30,30 };
    check.checkInt(1, o.numPairsDivisibleBy60(time));

    time = { 60,121,59,122,58,123,57,124,56,125,55 };
    check.checkInt(5, o.numPairsDivisibleBy60(time));
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
