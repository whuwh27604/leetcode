/* 设计地铁系统.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
请你实现一个类 UndergroundSystem ，它支持以下 3 种方法：

1. checkIn(int id, string stationName, int t)

编号为 id 的乘客在 t 时刻进入地铁站 stationName 。
一个乘客在同一时间只能在一个地铁站进入或者离开。
2. checkOut(int id, string stationName, int t)

编号为 id 的乘客在 t 时刻离开地铁站 stationName 。
3. getAverageTime(string startStation, string endStation) 

返回从地铁站 startStation 到地铁站 endStation 的平均花费时间。
平均时间计算的行程包括当前为止所有从 startStation 直接到达 endStation 的行程。
调用 getAverageTime 时，询问的路线至少包含一趟行程。
你可以假设所有对 checkIn 和 checkOut 的调用都是符合逻辑的。也就是说，如果一个顾客在 t1 时刻到达某个地铁站，那么他离开的时间 t2 一定满足 t2 > t1 。所有的事件都按时间顺序给出。

 

示例：

输入：
["UndergroundSystem","checkIn","checkIn","checkIn","checkOut","checkOut","checkOut","getAverageTime","getAverageTime","checkIn","getAverageTime","checkOut","getAverageTime"]
[[],[45,"Leyton",3],[32,"Paradise",8],[27,"Leyton",10],[45,"Waterloo",15],[27,"Waterloo",20],[32,"Cambridge",22],["Paradise","Cambridge"],["Leyton","Waterloo"],[10,"Leyton",24],["Leyton","Waterloo"],[10,"Waterloo",38],["Leyton","Waterloo"]]

输出：
[null,null,null,null,null,null,null,14.0,11.0,null,11.0,null,12.0]

解释：
UndergroundSystem undergroundSystem = new UndergroundSystem();
undergroundSystem.checkIn(45, "Leyton", 3);
undergroundSystem.checkIn(32, "Paradise", 8);
undergroundSystem.checkIn(27, "Leyton", 10);
undergroundSystem.checkOut(45, "Waterloo", 15);
undergroundSystem.checkOut(27, "Waterloo", 20);
undergroundSystem.checkOut(32, "Cambridge", 22);
undergroundSystem.getAverageTime("Paradise", "Cambridge");       // 返回 14.0。从 "Paradise"（时刻 8）到 "Cambridge"(时刻 22)的行程只有一趟
undergroundSystem.getAverageTime("Leyton", "Waterloo");          // 返回 11.0。总共有 2 躺从 "Leyton" 到 "Waterloo" 的行程，编号为 id=45 的乘客出发于 time=3 到达于 time=15，编号为 id=27 的乘客于 time=10 出发于 time=20 到达。所以平均时间为 ( (15-3) + (20-10) ) / 2 = 11.0
undergroundSystem.checkIn(10, "Leyton", 24);
undergroundSystem.getAverageTime("Leyton", "Waterloo");          // 返回 11.0
undergroundSystem.checkOut(10, "Waterloo", 38);
undergroundSystem.getAverageTime("Leyton", "Waterloo");          // 返回 12.0
 

提示：

总共最多有 20000 次操作。
1 <= id, t <= 10^6
所有的字符串包含大写字母，小写字母和数字。
1 <= stationName.length <= 10
与标准答案误差在 10^-5 以内的结果都视为正确结果。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/design-underground-system
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

class UndergroundSystem {
public:
    UndergroundSystem() {

    }

    void checkIn(int id, string stationName, int t) {
        customerCheckInTimes[id] = { stationName, t };
    }

    void checkOut(int id, string stationName, int t) {
        string travelStation = customerCheckInTimes[id].first + '$' + stationName;
        travelings[travelStation].first += ((double)t - customerCheckInTimes[id].second);
        ++travelings[travelStation].second;
    }

    double getAverageTime(string startStation, string endStation) {
        string travelStation = startStation + '$' + endStation;
        return travelings[travelStation].first / travelings[travelStation].second;
    }

private:
    unordered_map<int, pair<string, int>> customerCheckInTimes;
    unordered_map<string, pair<double, int>> travelings;  // string=startStation+endStation, double=sumTimes, int=travelingsCount
};

int main()
{
    CheckResult check;

    UndergroundSystem o1;
    o1.checkIn(45, "Leyton", 3);
    o1.checkIn(32, "Paradise", 8);
    o1.checkIn(27, "Leyton", 10);
    o1.checkOut(45, "Waterloo", 15);
    o1.checkOut(27, "Waterloo", 20);
    o1.checkOut(32, "Cambridge", 22);
    check.checkDouble(14, o1.getAverageTime("Paradise", "Cambridge"));
    check.checkDouble(11, o1.getAverageTime("Leyton", "Waterloo"));
    o1.checkIn(10, "Leyton", 24);
    check.checkDouble(11, o1.getAverageTime("Leyton", "Waterloo"));
    o1.checkOut(10, "Waterloo", 38);
    check.checkDouble(12, o1.getAverageTime("Leyton", "Waterloo"));

    UndergroundSystem o2;
    o2.checkIn(1, "A", 3);
    o2.checkIn(2, "A", 4);
    o2.checkIn(3, "A", 5);
    o2.checkIn(4, "A", 6);
    o2.checkOut(4, "A", 15);
    o2.checkOut(3, "A", 16);
    o2.checkOut(2, "A", 17);
    o2.checkOut(1, "A", 18);
    check.checkDouble(12, o2.getAverageTime("A", "A"));
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
