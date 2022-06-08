/* 以组为单位订音乐会的门票.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
一个音乐会总共有 n 排座位，编号从 0 到 n - 1 ，每一排有 m 个座椅，编号为 0 到 m - 1 。你需要设计一个买票系统，针对以下情况进行座位安排：

同一组的 k 位观众坐在 同一排座位，且座位连续 。
k 位观众中 每一位 都有座位坐，但他们 不一定 坐在一起。
由于观众非常挑剔，所以：

只有当一个组里所有成员座位的排数都 小于等于 maxRow ，这个组才能订座位。每一组的 maxRow 可能 不同 。
如果有多排座位可以选择，优先选择 最小 的排数。如果同一排中有多个座位可以坐，优先选择号码 最小 的。
请你实现 BookMyShow 类：

BookMyShow(int n, int m) ，初始化对象，n 是排数，m 是每一排的座位数。
int[] gather(int k, int maxRow) 返回长度为 2 的数组，表示 k 个成员中 第一个座位 的排数和座位编号，这 k 位成员必须坐在 同一排座位，且座位连续 。换言之，返回最小可能的 r 和 c 满足第 r 排中 [c, c + k - 1] 的座位都是空的，且 r <= maxRow 。如果 无法 安排座位，返回 [] 。
boolean scatter(int k, int maxRow) 如果组里所有 k 个成员 不一定 要坐在一起的前提下，都能在第 0 排到第 maxRow 排之间找到座位，那么请返回 true 。这种情况下，每个成员都优先找排数 最小 ，然后是座位编号最小的座位。如果不能安排所有 k 个成员的座位，请返回 false 。
 

示例 1：

输入：
["BookMyShow", "gather", "gather", "scatter", "scatter"]
[[2, 5], [4, 0], [2, 0], [5, 1], [5, 1]]
输出：
[null, [0, 0], [], true, false]

解释：
BookMyShow bms = new BookMyShow(2, 5); // 总共有 2 排，每排 5 个座位。
bms.gather(4, 0); // 返回 [0, 0]
                  // 这一组安排第 0 排 [0, 3] 的座位。
bms.gather(2, 0); // 返回 []
                  // 第 0 排只剩下 1 个座位。
                  // 所以无法安排 2 个连续座位。
bms.scatter(5, 1); // 返回 True
                   // 这一组安排第 0 排第 4 个座位和第 1 排 [0, 3] 的座位。
bms.scatter(5, 1); // 返回 False
                   // 总共只剩下 2 个座位。
 

提示：

1 <= n <= 5 * 104
1 <= m, k <= 109
0 <= maxRow <= n - 1
gather 和 scatter 总 调用次数不超过 5 * 104 次。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/booking-concert-tickets-in-groups
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class SegmentTree {
public:
    SegmentTree(int size) {
        minimum.resize(4 * size, 0);  // 区间内观众人数的最小值
        sum.resize(4 * size, 0);  // 区间内观众人数之和
    }

    void add(int segment, int left, int right, int index, int val) {  // 将index位置的值增加val
        if (left == right) {
            minimum[segment] += val;
            sum[segment] += val;
        }
        else {
            int mid = (left + right) / 2, leftSegment = 2 * segment, rightSegment = leftSegment + 1;

            if (mid >= index) {
                add(leftSegment, left, mid, index, val);
            }
            else {
                add(rightSegment, mid + 1, right, index, val);
            }

            minimum[segment] = min(minimum[leftSegment], minimum[rightSegment]);
            sum[segment] = sum[leftSegment] + sum[rightSegment];
        }
    }

    long long querySum(int segment, int left, int right, int start, int end) {  // 查询区间[start, end]的和
        if (left >= start && right <= end) {
            return sum[segment];
        }

        long long intervalSum = 0;
        int mid = (left + right) / 2, leftSegment = 2 * segment, rightSegment = leftSegment + 1;

        if (mid >= start) {
            intervalSum += querySum(leftSegment, left, mid, start, end);
        }

        if (mid < end) {
            intervalSum += querySum(rightSegment, mid + 1, right, start, end);
        }

        return intervalSum;
    }

    int queryMin(int segment, int left, int right, int end, int val) {  // 查询第一个 <= val 的位置
        if (minimum[segment] > val) {  // 整个区间都大于val
            return 0;
        }

        if (left == right) {
            return left;
        }

        int mid = (left + right) / 2, leftSegment = 2 * segment, rightSegment = leftSegment + 1;

        if (minimum[leftSegment] <= val) {  // 优先查看左半部分
            return queryMin(leftSegment, left, mid, end, val);
        }

        if (mid < end) {
            return queryMin(rightSegment, mid + 1, right, end, val);
        }

        return 0;
    }

private:
    vector<int> minimum;
    vector<long long> sum;
};

class BookMyShow {
public:
    BookMyShow(int n, int m) : row(n), column(m), tree(n) {}

    vector<int> gather(int k, int maxRow) {
        int r = tree.queryMin(1, 1, row, maxRow + 1, column - k);

        if (r == 0) {
            return {};
        }

        int spectators = (int)tree.querySum(1, 1, row, r, r);  // 查询第r排已经有多少人
        tree.add(1, 1, row, r, k);  // 将第r排安排k个人

        return { r - 1, spectators };
    }

    bool scatter(int k, int maxRow) {
        long long spectators = tree.querySum(1, 1, row, 1, maxRow + 1);  // 查询前maxRow排已经坐了多少人

        if ((((long long)maxRow + 1) * column - spectators) < k) {  // 剩余座位不够了
            return false;
        }

        int r = tree.queryMin(1, 1, row, maxRow + 1, column - 1);  // 查询第一个有空位的排

        while (k != 0) {
            int seatsLeft = column - (int)tree.querySum(1, 1, row, r, r);
            int assign = min(seatsLeft, k);
            tree.add(1, 1, row, r, assign);
            k -= assign;
            r += 1;
        }

        return true;
    }

private:
    int row;
    int column;
    SegmentTree tree;
};

int main()
{
    CheckResult check;

    BookMyShow o1(2, 5);
    vector<int> actual = o1.gather(4, 0);
    vector<int> expected = { 0,0 };
    check.checkIntVector(expected, actual);
    actual = o1.gather(2, 0);
    expected = {  };
    check.checkIntVector(expected, actual);
    check.checkBool(true, o1.scatter(5, 1));
    check.checkBool(false, o1.scatter(5, 1));

    BookMyShow o2(25, 941);
    actual = o2.gather(34, 1);
    expected = { 0,0 };
    check.checkIntVector(expected, actual);
    actual = o2.gather(296, 21);
    expected = { 0,34 };
    check.checkIntVector(expected, actual);
    actual = o2.gather(927, 18);
    expected = { 1,0 };
    check.checkIntVector(expected, actual);
    actual = o2.gather(695, 15);
    expected = { 2,0 };
    check.checkIntVector(expected, actual);
    actual = o2.gather(830, 22);
    expected = { 3,0 };
    check.checkIntVector(expected, actual);
    actual = o2.gather(638, 2);
    expected = {  };
    check.checkIntVector(expected, actual);
    actual = o2.gather(169, 15);
    expected = { 0,330 };
    check.checkIntVector(expected, actual);
    check.checkBool(true, o2.scatter(623, 16));
    check.checkBool(true, o2.scatter(268, 6));
    actual = o2.gather(160, 16);
    expected = { 4,78 };
    check.checkIntVector(expected, actual);
    actual = o2.gather(342, 5);
    expected = { 4,238 };
    check.checkIntVector(expected, actual);
    actual = o2.gather(22, 8);
    expected = { 4,580 };
    check.checkIntVector(expected, actual);
    actual = o2.gather(187, 11);
    expected = { 4,602 };
    check.checkIntVector(expected, actual);
    actual = o2.gather(332, 24);
    expected = { 5,0 };
    check.checkIntVector(expected, actual);
    check.checkBool(true, o2.scatter(589, 14));
    actual = o2.gather(87, 14);
    expected = { 5,769 };
    check.checkIntVector(expected, actual);
    actual = o2.gather(581, 4);
    expected = {  };
    check.checkIntVector(expected, actual);
    check.checkBool(true, o2.scatter(334, 14));
    actual = o2.gather(322, 0);
    expected = {  };
    check.checkIntVector(expected, actual);
    check.checkBool(false, o2.scatter(511, 4));
    check.checkBool(false, o2.scatter(1000, 3));
    check.checkBool(true, o2.scatter(938, 9));
    actual = o2.gather(19, 5);
    expected = {  };
    check.checkIntVector(expected, actual);
    check.checkBool(false, o2.scatter(672, 5));
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
