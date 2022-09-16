/* 优惠活动系统.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
「云闪付」作为各方联手打造的全新移动端统一入口，致力成为消费者省钱省心的移动支付管家。
请你设计一个「云闪付」优惠活动管理系统 DiscountSystem，具体功能如下：

AddActivity(int actId, int priceLimit, int discount, int number, int userLimit) -- 表示创建编号为 actId 的优惠减免活动：

单笔消费的原价不小于 priceLimit 时，可享受 discount 的减免
每个用户最多参与该优惠活动 userLimit 次
该优惠活动共有 number 数量的参加名额
RemoveActivity(actId) -- 表示结束编号为 actId 的优惠活动

Consume(int userId, int cost) -- 表示用户 userId 产生了一笔原价为 cost 的消费。请返回用户的实际支付金额。

单次消费最多可参加一份优惠活动
若可享受优惠减免，则 「支付金额 = 原价 - 优惠减免」
若同时满足多个优惠活动时，则优先参加优惠减免最大的活动
注：若有多个优惠减免最大的活动，优先参加 actId 最小的活动

注意：

actId 全局唯一
示例 1：

输入：
["DiscountSystem","addActivity","consume","removeActivity","consume"]
[[],[1,15,5,7,2],[101,16],[1],[102,19]]

输出：[null,null,11,null,19]

解释：
DiscountSystem obj = DiscountSystem(); // 初始化系统
obj.addActicity(1,15,5,7,2); //创建编号 1 的优惠活动，单笔消费原价不小于 15 时，
可享受 5 的减免，优惠活动共有 7 个名额，每个用户最多参与该活动 2 次
obj.consume(101,16); //用户 101 消费了 16，满足优惠活动 1 条件，返回实际支付 16 - 5 = 11
obj.removeActivity(1); // 结束编号为 1 的优惠活动
obj.consume(102,19); //用户 101 消费了 19，目前不存在任何优惠活动，需按原价支付，返回 19

示例 2：

输入：
["DiscountSystem","addActivity","addActivity","consume","removeActivity","consume","consume","consume","consume"]
[[],[1,10,6,3,2],[2,15,8,8,2],[101,13],[2],[101,17],[101,11],[102,16],[102,21]]

输出：[null,null,null,7,null,11,11,10,21]

解释：
DiscountSystem obj = DiscountSystem(); // 初始化系统
obj.addActivity(1,10,6,3,2); // 创建编号 1 的优惠活动，单笔消费原价不小于 10 时，
可享受 6 的减免，优惠活动共有 3 个名额，每个用户最多参与该活动 2 次
obj.addActivity(2,15,8,8,2); // 创建编号 2 的优惠活动，单笔消费原价不小于 15 时，
可享受 8 的减免，优惠活动共有 8 个名额，每个用户最多参与该活动 2 次
obj.consume(101,13); // 用户 101 消费了 13，仅满足优惠活动 1 条件，返回实际支付 13 - 6 = 7
用户 101 参加 1 次活动 1，活动 1 剩余 2 个名额
obj.consume(101,8); // 用户 101 消费了 8，不满足任何活动，返回支付原价 8
obj.removeActivity(2); // 结束编号为 2 的活动
obj.consume(101,17); // 用户 101 消费了 17，满足优惠活动 1 条件，返回实际支付 17 - 6 = 11
用户 101 参加 2 次活动 1，活动 1 剩余 1 个名额
obj.consume(101,11); // 用户 101 消费了 11，满足优惠活动 1 条件，但已达到参加次数限制，返回支付原价 11
obj.consume(102,16); // 用户 102 消费了 16，满足优惠活动 1 条件，返回实际支付 16 - 6 = 10
用户 102 参加 1 次活动 1，活动 1 无剩余名额
obj.consume(102,21); // 用户 102 消费了 21，满足优惠活动 1 条件，但活动 1 已无剩余名额，返回支付原价 21

提示：

1 <= addActicity, removeActivity, consume 累计操作数 <= 10^3
0 <= actId, userId <= 1000
1 <= discount < priceLimit <= 10^5
1 <= cost <= 10^5
1 <= number <= 1000
1 <= userLimit <= 10
*/

#include <iostream>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

class Activity {
public:
    int priceLimit;
    int discount;
    int numberLimit;
    int num;
    int userLimit;
    unordered_map<int, int> users;

    Activity() : priceLimit(0), discount(0), numberLimit(0), num(0), userLimit(0) {}

    Activity(int priceLimit_, int discount_, int numberLimit_, int userLimit_) {
        priceLimit = priceLimit_;
        discount = discount_;
        numberLimit = numberLimit_;
        num = 0;
        userLimit = userLimit_;
    }
};

class DiscountSystem {
public:
    DiscountSystem() {

    }

    void addActivity(int actId, int priceLimit, int discount, int number, int userLimit) {
        activities[actId] = Activity(priceLimit, discount, number, userLimit);
    }

    void removeActivity(int actId) {
        activities.erase(actId);
    }

    int consume(int userId, int cost) {
        int maxDiscount = 0, id = INT_MAX;

        for (auto& activity : activities) {
            if (cost < activity.second.priceLimit) {
                continue;
            }

            if (activity.second.num == activity.second.numberLimit) {
                continue;
            }

            if (activity.second.users.count(userId) != 0 && activity.second.users[userId] == activity.second.userLimit) {
                continue;
            }

            if (activity.second.discount == maxDiscount) {
                if (activity.first < id) {
                    id = activity.first;
                }
            }
            else if (activity.second.discount > maxDiscount) {
                maxDiscount = activity.second.discount;
                id = activity.first;
            }
        }

        if (id == INT_MAX) {
            return cost;
        }

        ++activities[id].num;
        ++activities[id].users[userId];

        return cost - maxDiscount;
    }

private:
    unordered_map<int, Activity> activities;
};

int main()
{
    CheckResult check;

    DiscountSystem o1;
    o1.addActivity(1, 15, 5, 7, 2);
    check.checkInt(11, o1.consume(101, 16));
    o1.removeActivity(1);
    check.checkInt(19, o1.consume(102, 19));

    DiscountSystem o2;
    o2.addActivity(1, 10, 6, 3, 2);
    o2.addActivity(2, 15, 8, 8, 2);
    check.checkInt(7, o2.consume(101, 13));
    o2.removeActivity(2);
    check.checkInt(11, o2.consume(101, 17));
    check.checkInt(11, o2.consume(101, 11));
    check.checkInt(10, o2.consume(102, 16));
    check.checkInt(21, o2.consume(102, 21));
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
