/* 找出 3 位偶数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数数组 digits ，其中每个元素是一个数字（0 - 9）。数组中可能存在重复元素。

你需要找出 所有 满足下述条件且 互不相同 的整数：

该整数由 digits 中的三个元素按 任意 顺序 依次连接 组成。
该整数不含 前导零
该整数是一个 偶数
例如，给定的 digits 是 [1, 2, 3] ，整数 132 和 312 满足上面列出的全部条件。

将找出的所有互不相同的整数按 递增顺序 排列，并以数组形式返回。

 

示例 1：

输入：digits = [2,1,3,0]
输出：[102,120,130,132,210,230,302,310,312,320]
解释：
所有满足题目条件的整数都在输出数组中列出。
注意，答案数组中不含有 奇数 或带 前导零 的整数。
示例 2：

输入：digits = [2,2,8,8,2]
输出：[222,228,282,288,822,828,882]
解释：
同样的数字（0 - 9）在构造整数时可以重复多次，重复次数最多与其在 digits 中出现的次数一样。
在这个例子中，数字 8 在构造 288、828 和 882 时都重复了两次。
示例 3：

输入：digits = [3,7,5]
输出：[]
解释：
使用给定的 digits 无法构造偶数。
示例 4：

输入：digits = [0,2,0,0]
输出：[200]
解释：
唯一一个不含 前导零 且满足全部条件的整数是 200 。
示例 5：

输入：digits = [0,0,0]
输出：[]
解释：
构造的所有整数都会有 前导零 。因此，不存在满足题目条件的整数。
 

提示：

3 <= digits.length <= 100
0 <= digits[i] <= 9

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/finding-3-digit-even-numbers
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        int size = digits.size(), prev1 = -1;
        vector<int> evenNumbers;

        sort(digits.begin(), digits.end());  // 排序保证输出顺序

        for (int current1 = 0; current1 < size; ++current1) {
            if (digits[current1] == prev1) {
                continue;
            }

            prev1 = digits[current1];
            if (digits[current1] == 0) {  // 第一个数不能有前导0
                continue;
            }

            int prev2 = -1;
            for (int current2 = 0; current2 < size; ++current2) {
                if (current2 == current1 || digits[current2] == prev2) {  // 第二个数可以任意选
                    continue;
                }

                prev2 = digits[current2];
                int prev3 = -1;

                for (int current3 = 0; current3 < size; ++current3) {
                    if (current3 == current1 || current3 == current2 || digits[current3] == prev3 || (digits[current3] & 1) == 1) {  // 第三个数必须是偶数
                        continue;
                    }

                    prev3 = digits[current3];
                    evenNumbers.push_back(digits[current1] * 100 + digits[current2] * 10 + digits[current3]);
                }
            }
        }

        return evenNumbers;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> digits = { 2,1,3,0 };
    vector<int> actual = o.findEvenNumbers(digits);
    vector<int> expected = { 102,120,130,132,210,230,302,310,312,320 };
    check.checkIntVector(expected, actual);

    digits = { 2,2,8,8,2 };
    actual = o.findEvenNumbers(digits);
    expected = { 222,228,282,288,822,828,882 };
    check.checkIntVector(expected, actual);
    check.checkIntVector(expected, actual);

    digits = { 3,7,5 };
    actual = o.findEvenNumbers(digits);
    expected = {  };
    check.checkIntVector(expected, actual);
    check.checkIntVector(expected, actual);

    digits = { 0,2,0,0 };
    actual = o.findEvenNumbers(digits);
    expected = { 200 };
    check.checkIntVector(expected, actual);
    check.checkIntVector(expected, actual);

    digits = { 0,0,0 };
    actual = o.findEvenNumbers(digits);
    expected = {  };
    check.checkIntVector(expected, actual);

    digits = { 9,9,8,8,7,7,6,6,5,5,0,0 };
    actual = o.findEvenNumbers(digits);
    expected = { 500,506,508,550,556,558,560,566,568,570,576,578,580,586,588,590,596,598,600,606,608,650,656,658,660,668,670,676,678,680,686,688,690,696,698,700,706,708,750,756,758,760,766,768,770,776,778,780,786,788,790,796,798,800,806,808,850,856,858,860,866,868,870,876,878,880,886,890,896,898,900,906,908,950,956,958,960,966,968,970,976,978,980,986,988,990,996,998 };
    check.checkIntVector(expected, actual);

    digits = { 9,8,7,6,5,4,3,0 };
    actual = o.findEvenNumbers(digits);
    expected = { 304,306,308,340,346,348,350,354,356,358,360,364,368,370,374,376,378,380,384,386,390,394,396,398,406,408,430,436,438,450,456,458,460,468,470,476,478,480,486,490,496,498,504,506,508,530,534,536,538,540,546,548,560,564,568,570,574,576,578,580,584,586,590,594,596,598,604,608,630,634,638,640,648,650,654,658,670,674,678,680,684,690,694,698,704,706,708,730,734,736,738,740,746,748,750,754,756,758,760,764,768,780,784,786,790,794,796,798,804,806,830,834,836,840,846,850,854,856,860,864,870,874,876,890,894,896,904,906,908,930,934,936,938,940,946,948,950,954,956,958,960,964,968,970,974,976,978,980,984,986 };
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
