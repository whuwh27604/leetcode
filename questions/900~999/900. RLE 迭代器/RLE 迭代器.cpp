/* RLE 迭代器.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
编写一个遍历游程编码序列的迭代器。

迭代器由 RLEIterator(int[] A) 初始化，其中 A 是某个序列的游程编码。更具体地，对于所有偶数 i，A[i] 告诉我们在序列中重复非负整数值 A[i + 1] 的次数。

迭代器支持一个函数：next(int n)，它耗尽接下来的  n 个元素（n >= 1）并返回以这种方式耗去的最后一个元素。如果没有剩余的元素可供耗尽，则  next 返回 -1 。

例如，我们以 A = [3,8,0,9,2,5] 开始，这是序列 [8,8,8,5,5] 的游程编码。这是因为该序列可以读作 “三个八，零个九，两个五”。

 

示例：

输入：["RLEIterator","next","next","next","next"], [[[3,8,0,9,2,5]],[2],[1],[1],[2]]
输出：[null,8,8,5,-1]
解释：
RLEIterator 由 RLEIterator([3,8,0,9,2,5]) 初始化。
这映射到序列 [8,8,8,5,5]。
然后调用 RLEIterator.next 4次。

.next(2) 耗去序列的 2 个项，返回 8。现在剩下的序列是 [8, 5, 5]。

.next(1) 耗去序列的 1 个项，返回 8。现在剩下的序列是 [5, 5]。

.next(1) 耗去序列的 1 个项，返回 5。现在剩下的序列是 [5]。

.next(2) 耗去序列的 2 个项，返回 -1。 这是由于第一个被耗去的项是 5，
但第二个项并不存在。由于最后一个要耗去的项不存在，我们返回 -1。
 

提示：

0 <= A.length <= 1000
A.length 是偶数。
0 <= A[i] <= 10^9
每个测试用例最多调用 1000 次 RLEIterator.next(int n)。
每次调用 RLEIterator.next(int n) 都有 1 <= n <= 10^9 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/rle-iterator
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class RLEIterator {
public:
    RLEIterator(vector<int>& A) {
        data = A;
        index = 0;
        size = A.size();
        left = A.empty() ? 0 : A[0];
    }

    int next(int n) {
        while (left < n && index < size - 2) {
            index += 2;
            left += data[index];
        }

        if (left < n) {
            left = 0;
            return -1;
        }

        left -= n;
        return data[index + 1];
    }

private:
    vector<int> data;
    int index;
    int size;
    int left;
};

int main()
{
    CheckResult check;

    vector<int> A = { 3,8,0,9,2,5 };
    RLEIterator o1(A);
    check.checkInt(8, o1.next(2));
    check.checkInt(8, o1.next(1));
    check.checkInt(5, o1.next(1));
    check.checkInt(-1, o1.next(2));

    A = {  };
    RLEIterator o2(A);
    check.checkInt(-1, o2.next(1));

    A = { 635,606,576,391,370,981,36,21,961,185,124,210,801,937,22,426,101,260,221,647,350,180,504,39,101,989,199,358,732,839,919,169,673,967,58,676,846,342,250,597,442,174,472,410,569,509,311,357,838,251 };
    RLEIterator o3(A);
    check.checkInt(839, o3.next(5039));
    check.checkInt(839, o3.next(62));
    check.checkInt(174, o3.next(3640));
    check.checkInt(509, o3.next(671));
    check.checkInt(509, o3.next(67));
    check.checkInt(509, o3.next(395));
    check.checkInt(357, o3.next(262));
    check.checkInt(251, o3.next(839));
    check.checkInt(251, o3.next(74));
    check.checkInt(251, o3.next(43));
    check.checkInt(-1, o3.next(42));
    check.checkInt(-1, o3.next(77));
    check.checkInt(-1, o3.next(13));
    check.checkInt(-1, o3.next(6));
    check.checkInt(-1, o3.next(3));
    check.checkInt(-1, o3.next(1));
    check.checkInt(-1, o3.next(1));
    check.checkInt(-1, o3.next(1));

    A = { 2,3 };
    RLEIterator o4(A);
    check.checkInt(3, o4.next(1));
    check.checkInt(3, o4.next(1));
    check.checkInt(-1, o4.next(1));
    check.checkInt(-1, o4.next(1));

    A = { 2,3 };
    RLEIterator o5(A);
    check.checkInt(-1, o5.next(3));
    check.checkInt(-1, o5.next(1));
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
