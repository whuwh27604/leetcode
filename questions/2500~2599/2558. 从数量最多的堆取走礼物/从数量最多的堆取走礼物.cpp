/* 从数量最多的堆取走礼物.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数数组 gifts ，表示各堆礼物的数量。每一秒，你需要执行以下操作：

选择礼物数量最多的那一堆。
如果不止一堆都符合礼物数量最多，从中选择任一堆即可。
选中的那一堆留下平方根数量的礼物（向下取整），取走其他的礼物。
返回在 k 秒后剩下的礼物数量。



示例 1：

输入：gifts = [25,64,9,4,100], k = 4
输出：29
解释：
按下述方式取走礼物：
- 在第一秒，选中最后一堆，剩下 10 个礼物。
- 接着第二秒选中第二堆礼物，剩下 8 个礼物。
- 然后选中第一堆礼物，剩下 5 个礼物。
- 最后，再次选中最后一堆礼物，剩下 3 个礼物。
最后剩下的礼物数量分别是 [5,8,9,4,3] ，所以，剩下礼物的总数量是 29 。
示例 2：

输入：gifts = [1,1,1,1], k = 4
输出：4
解释：
在本例中，不管选中哪一堆礼物，都必须剩下 1 个礼物。
也就是说，你无法获取任一堆中的礼物。
所以，剩下礼物的总数量是 4 。


提示：

1 <= gifts.length <= 103
1 <= gifts[i] <= 109
1 <= k <= 103
*/

#include <iostream>
#include <queue>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<long long> q;
        long long total = 0, pick = 0;

        for (int num : gifts) {
            q.push(num);
            total += num;
        }

        for (int i = 0; i < k; ++i) {
            long long num = q.top();
            q.pop();
            long long root = (long long)sqrt(num);
            q.push(root);
            pick += (num - root);
        }

        return total - pick;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> gifts = { 25,64,9,4,100 };
    check.checkLongLong(29, o.pickGifts(gifts, 4));

    gifts = { 1,1,1,1 };
    check.checkLongLong(4, o.pickGifts(gifts, 4));

    gifts = { 1 };
    check.checkLongLong(1, o.pickGifts(gifts, 3));
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
