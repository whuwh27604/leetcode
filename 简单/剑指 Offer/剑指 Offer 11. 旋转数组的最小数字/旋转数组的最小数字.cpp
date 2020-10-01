/* 旋转数组的最小数字.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。例如，数组 [3,4,5,1,2] 为 [1,2,3,4,5] 的一个旋转，该数组的最小值为1。  

示例 1：

输入：[3,4,5,1,2]
输出：1
示例 2：

输入：[2,2,2,0,1]
输出：0
注意：本题与主站 154 题相同：https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array-ii/

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/xuan-zhuan-shu-zu-de-zui-xiao-shu-zi-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minArray(vector<int>& numbers) {
        int left = 0, right = numbers.size() - 1;

        while (left < right) {
            int middle = (right - left) / 2 + left;
            if (numbers[middle] < numbers[right]) {
                right = middle;
            }
            else if (numbers[middle] == numbers[right]) {
                right -= 1;
            }
            else {
                left = middle + 1;
            }
        }

        return numbers[left];
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> numbers = { 3,4,5,1,2 };
    check.checkInt(1, o.minArray(numbers));
    
    numbers = { 2,2,2,0,1 };
    check.checkInt(0, o.minArray(numbers));

    numbers = { 2,2,2,2,2 };
    check.checkInt(2, o.minArray(numbers));

    numbers = { 1,2,3,4,5 };
    check.checkInt(1, o.minArray(numbers));

    numbers = { 2,2,2,0,1,2 };
    check.checkInt(0, o.minArray(numbers));

    numbers = { 2,3,1,2 };
    check.checkInt(1, o.minArray(numbers));

    numbers = { 2,2,2,3,4,2,2 };
    check.checkInt(2, o.minArray(numbers));

    numbers = { 1 };
    check.checkInt(1, o.minArray(numbers));

    numbers = { 1,2 };
    check.checkInt(1, o.minArray(numbers));

    numbers = { 2,1 };
    check.checkInt(1, o.minArray(numbers));

    numbers = { 10,1,10,10,10 };
    check.checkInt(1, o.minArray(numbers));

    numbers = { 2,2,2,3,1 };
    check.checkInt(1, o.minArray(numbers));
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
