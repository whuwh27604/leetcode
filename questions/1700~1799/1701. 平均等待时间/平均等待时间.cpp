/* 平均等待时间.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
有一个餐厅，只有一位厨师。你有一个顾客数组 customers ，其中 customers[i] = [arrivali, timei] ：

arrivali 是第 i 位顾客到达的时间，到达时间按 非递减 顺序排列。
timei 是给第 i 位顾客做菜需要的时间。
当一位顾客到达时，他将他的订单给厨师，厨师一旦空闲的时候就开始做这位顾客的菜。每位顾客会一直等待到厨师完成他的订单。厨师同时只能做一个人的订单。厨师会严格按照 订单给他的顺序 做菜。

请你返回所有顾客需要等待的 平均 时间。与标准答案误差在 10-5 范围以内，都视为正确结果。

 

示例 1：

输入：customers = [[1,2],[2,5],[4,3]]
输出：5.00000
解释：
1) 第一位顾客在时刻 1 到达，厨师拿到他的订单并在时刻 1 立马开始做菜，并在时刻 3 完成，第一位顾客等待时间为 3 - 1 = 2 。
2) 第二位顾客在时刻 2 到达，厨师在时刻 3 开始为他做菜，并在时刻 8 完成，第二位顾客等待时间为 8 - 2 = 6 。
3) 第三位顾客在时刻 4 到达，厨师在时刻 8 开始为他做菜，并在时刻 11 完成，第三位顾客等待时间为 11 - 4 = 7 。
平均等待时间为 (2 + 6 + 7) / 3 = 5 。
示例 2：

输入：customers = [[5,2],[5,4],[10,3],[20,1]]
输出：3.25000
解释：
1) 第一位顾客在时刻 5 到达，厨师拿到他的订单并在时刻 5 立马开始做菜，并在时刻 7 完成，第一位顾客等待时间为 7 - 5 = 2 。
2) 第二位顾客在时刻 5 到达，厨师在时刻 7 开始为他做菜，并在时刻 11 完成，第二位顾客等待时间为 11 - 5 = 6 。
3) 第三位顾客在时刻 10 到达，厨师在时刻 11 开始为他做菜，并在时刻 14 完成，第三位顾客等待时间为 14 - 10 = 4 。
4) 第四位顾客在时刻 20 到达，厨师拿到他的订单并在时刻 20 立马开始做菜，并在时刻 21 完成，第四位顾客等待时间为 21 - 20 = 1 。
平均等待时间为 (2 + 6 + 4 + 1) / 4 = 3.25 。
 

提示：

1 <= customers.length <= 105
1 <= arrivali, timei <= 104
arrivali <= arrivali+1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/average-waiting-time
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double endTime = 0, waitTime = 0;

        for (auto& customer : customers) {
            double startTime = customer[0] > endTime ? customer[0] : endTime;
            endTime = startTime + customer[1];
            waitTime += (endTime - customer[0]);
        }

        return waitTime / customers.size();
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> customers = { {1,2},{2,5},{4,3} };
    check.checkDouble(5, o.averageWaitingTime(customers));

    customers = { {5,2},{5,4},{10,3},{20,1} };
    check.checkDouble(3.25, o.averageWaitingTime(customers));

    customers = { {5,2} };
    check.checkDouble(2, o.averageWaitingTime(customers));
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
