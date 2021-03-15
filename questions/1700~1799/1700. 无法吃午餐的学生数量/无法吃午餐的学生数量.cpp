/* 无法吃午餐的学生数量.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
学校的自助午餐提供圆形和方形的三明治，分别用数字 0 和 1 表示。所有学生站在一个队列里，每个学生要么喜欢圆形的要么喜欢方形的。
餐厅里三明治的数量与学生的数量相同。所有三明治都放在一个 栈 里，每一轮：

如果队列最前面的学生 喜欢 栈顶的三明治，那么会 拿走它 并离开队列。
否则，这名学生会 放弃这个三明治 并回到队列的尾部。
这个过程会一直持续到队列里所有学生都不喜欢栈顶的三明治为止。

给你两个整数数组 students 和 sandwiches ，其中 sandwiches[i] 是栈里面第 i​​​​​​ 个三明治的类型（i = 0 是栈的顶部）， students[j] 是初始队列里第 j​​​​​​ 名学生对三明治的喜好（j = 0 是队列的最开始位置）。请你返回无法吃午餐的学生数量。

 

示例 1：

输入：students = [1,1,0,0], sandwiches = [0,1,0,1]
输出：0
解释：
- 最前面的学生放弃最顶上的三明治，并回到队列的末尾，学生队列变为 students = [1,0,0,1]。
- 最前面的学生放弃最顶上的三明治，并回到队列的末尾，学生队列变为 students = [0,0,1,1]。
- 最前面的学生拿走最顶上的三明治，剩余学生队列为 students = [0,1,1]，三明治栈为 sandwiches = [1,0,1]。
- 最前面的学生放弃最顶上的三明治，并回到队列的末尾，学生队列变为 students = [1,1,0]。
- 最前面的学生拿走最顶上的三明治，剩余学生队列为 students = [1,0]，三明治栈为 sandwiches = [0,1]。
- 最前面的学生放弃最顶上的三明治，并回到队列的末尾，学生队列变为 students = [0,1]。
- 最前面的学生拿走最顶上的三明治，剩余学生队列为 students = [1]，三明治栈为 sandwiches = [1]。
- 最前面的学生拿走最顶上的三明治，剩余学生队列为 students = []，三明治栈为 sandwiches = []。
所以所有学生都有三明治吃。
示例 2：

输入：students = [1,1,1,0,0,1], sandwiches = [1,0,0,0,1,1]
输出：3
 

提示：

1 <= students.length, sandwiches.length <= 100
students.length == sandwiches.length
sandwiches[i] 要么是 0 ，要么是 1 。
students[i] 要么是 0 ，要么是 1 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/number-of-students-unable-to-eat-lunch
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int circular = 0, square = 0;

        for (int student : students) {
            if (student == 0) {
                ++circular;
            }
            else {
                ++square;
            }
        }

        for (int sandwich : sandwiches) {
            if (sandwich == 0) {
                if (circular == 0) {
                    break;
                }
                --circular;
            }
            else {
                if (square == 0) {
                    break;
                }
                --square;
            }
        }

        return circular + square;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> students = { 1,1,0,0 };
    vector<int> sandwiches = { 0,1,0,1 };
    check.checkInt(0, o.countStudents(students, sandwiches));

    students = { 1,1,1,0,0,1 };
    sandwiches = { 1,0,0,0,1,1 };
    check.checkInt(3, o.countStudents(students, sandwiches));

    students = { 1 };
    sandwiches = { 0 };
    check.checkInt(1, o.countStudents(students, sandwiches));

    students = { 1 };
    sandwiches = { 1 };
    check.checkInt(0, o.countStudents(students, sandwiches));
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
