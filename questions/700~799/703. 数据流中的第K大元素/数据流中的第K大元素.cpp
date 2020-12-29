/* 数据流中的第K大元素.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
设计一个找到数据流中第K大元素的类（class）。注意是排序后的第K大元素，不是第K个不同的元素。

你的 KthLargest 类需要一个同时接收整数 k 和整数数组nums 的构造器，它包含数据流中的初始元素。每次调用 KthLargest.add，返回当前数据流中第K大的元素。

示例:

int k = 3;
int[] arr = [4,5,8,2];
KthLargest kthLargest = new KthLargest(3, arr);
kthLargest.add(3);   // returns 4
kthLargest.add(5);   // returns 5
kthLargest.add(10);  // returns 5
kthLargest.add(9);   // returns 8
kthLargest.add(4);   // returns 8
说明:
你可以假设 nums 的长度≥ k-1 且k ≥ 1。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/kth-largest-element-in-a-stream
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <set>
#include "../check/CheckResult.h"

using namespace std;

class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        Kth = k;
        for (unsigned int i = 0; i < nums.size(); i++) {
            orderNums.insert(nums[i]);
            if (orderNums.size() > Kth) {
                orderNums.erase(orderNums.begin());
            }
        }
    }

    int add(int val) {
        orderNums.insert(val);
        if (orderNums.size() > Kth) {
            orderNums.erase(orderNums.begin());
        }

        return *orderNums.begin();
    }

    unsigned int Kth;
    multiset<int> orderNums;
};

int main()
{
    vector<int> nums = { 4,5,8,2 };
    KthLargest o(3, nums);
    CheckResult check;
    check.checkInt(4, o.add(3));
    check.checkInt(5, o.add(5));
    check.checkInt(5, o.add(10));
    check.checkInt(8, o.add(9));
    check.checkInt(8, o.add(4));
    check.checkInt(9, o.add(10));

    nums = {  };
    KthLargest o1(1, nums);
    check.checkInt(3, o1.add(3));
    check.checkInt(3, o1.add(2));
    check.checkInt(4, o1.add(4));

    nums = { 1 };
    KthLargest o2(2, nums);
    check.checkInt(0, o2.add(0));
    check.checkInt(1, o2.add(2));
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
