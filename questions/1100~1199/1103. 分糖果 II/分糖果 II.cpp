/* 分糖果 II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
排排坐，分糖果。

我们买了一些糖果 candies，打算把它们分给排好队的 n = num_people 个小朋友。

给第一个小朋友 1 颗糖果，第二个小朋友 2 颗，依此类推，直到给最后一个小朋友 n 颗糖果。

然后，我们再回到队伍的起点，给第一个小朋友 n + 1 颗糖果，第二个小朋友 n + 2 颗，依此类推，直到给最后一个小朋友 2 * n 颗糖果。

重复上述过程（每次都比上一次多给出一颗糖果，当到达队伍终点后再次从队伍起点开始），直到我们分完所有的糖果。注意，就算我们手中的剩下糖果数不够（不比前一次发出的糖果多），这些糖果也会全部发给当前的小朋友。

返回一个长度为 num_people、元素之和为 candies 的数组，以表示糖果的最终分发情况（即 ans[i] 表示第 i 个小朋友分到的糖果数）。

 

示例 1：

输入：candies = 7, num_people = 4
输出：[1,2,3,1]
解释：
第一次，ans[0] += 1，数组变为 [1,0,0,0]。
第二次，ans[1] += 2，数组变为 [1,2,0,0]。
第三次，ans[2] += 3，数组变为 [1,2,3,0]。
第四次，ans[3] += 1（因为此时只剩下 1 颗糖果），最终数组变为 [1,2,3,1]。
示例 2：

输入：candies = 10, num_people = 3
输出：[5,2,3]
解释：
第一次，ans[0] += 1，数组变为 [1,0,0]。
第二次，ans[1] += 2，数组变为 [1,2,0]。
第三次，ans[2] += 3，数组变为 [1,2,3]。
第四次，ans[0] += 4，最终数组变为 [5,2,3]。
 

提示：

1 <= candies <= 10^9
1 <= num_people <= 1000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/distribute-candies-to-people
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

/*
第一轮  1    2    ... n      = (1+n)*n/2
第二轮  n+1  n+2  ... 2n     = (1+n)*n/2+n*n
第k+1轮 kn+1 kn+2 ... kn+n   = (1+n)*n/2+k*n*n
sum = (k+1)*(1+n)*n/2+(1+k)*k/2*n*n = n*n*k*k/2+(n*n+(n/2))k+(n*n+n)/2 = candies
带入求根公式ak*k+bk+c=0, k=(-b(+/-)root(b*b-4ac))/2a
*/
class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        double n = num_people;
        double a = n * n / 2;
        double b = n * n + n / 2;
        double c = (n * n + n) / 2 - candies;
        int k = (int)((sqrt(b * b - 4 * a * c) - b) / 2 / a);

        vector<int> ans;
        ans.reserve(num_people);
        int peopleCandies = (k + 1) * k * num_people / 2 + (k + 1);
        int leftCandies = candies;

        for (int i = 0; i < num_people; i++) {
            if (leftCandies < peopleCandies) {
                ans.push_back(leftCandies);
                leftCandies = 0;
            }
            else {
                ans.push_back(peopleCandies);
                leftCandies -= peopleCandies;
            }

            peopleCandies += (k + 1);
        }

        peopleCandies = (k + 1) * num_people + 1;
        for (int i = 0; i < num_people; i++) {
            if (leftCandies < peopleCandies) {
                ans[i] += leftCandies;
                break;
            }

            ans[i] += peopleCandies;
            leftCandies -= peopleCandies;
            peopleCandies++;
        }

        return ans;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> actual = o.distributeCandies(7, 4);
    vector<int> expected = { 1,2,3,1 };
    check.checkIntVector(expected, actual);

    actual = o.distributeCandies(10, 3);
    expected = { 5,2,3 };
    check.checkIntVector(expected, actual);

    actual = o.distributeCandies(1, 1);
    expected = { 1 };
    check.checkIntVector(expected, actual);

    actual = o.distributeCandies(10, 1);
    expected = { 10 };
    check.checkIntVector(expected, actual);

    actual = o.distributeCandies(1, 2);
    expected = { 1,0 };
    check.checkIntVector(expected, actual);

    actual = o.distributeCandies(16, 2);
    expected = { 9,7 };
    check.checkIntVector(expected, actual);

    actual = o.distributeCandies(1, 3);
    expected = { 1,0,0 };
    check.checkIntVector(expected, actual);

    actual = o.distributeCandies(6, 3);
    expected = { 1,2,3 };
    check.checkIntVector(expected, actual);

    actual = o.distributeCandies(50, 3);
    expected = { 17,15,18 };
    check.checkIntVector(expected, actual);

    actual = o.distributeCandies(5, 4);
    expected = { 1,2,2,0 };
    check.checkIntVector(expected, actual);

    actual = o.distributeCandies(110, 4);
    expected = { 28,32,26,24 };
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
