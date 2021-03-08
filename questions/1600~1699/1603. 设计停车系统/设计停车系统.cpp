/* 设计停车系统.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
请你给一个停车场设计一个停车系统。停车场总共有三种不同大小的车位：大，中和小，每种尺寸分别有固定数目的车位。

请你实现 ParkingSystem 类：

ParkingSystem(int big, int medium, int small) 初始化 ParkingSystem 类，三个参数分别对应每种停车位的数目。
bool addCar(int carType) 检查是否有 carType 对应的停车位。 carType 有三种类型：大，中，小，分别用数字 1， 2 和 3 表示。一辆车只能停在  carType 对应尺寸的停车位中。如果没有空车位，请返回 false ，否则将该车停入车位并返回 true 。
 

示例 1：

输入：
["ParkingSystem", "addCar", "addCar", "addCar", "addCar"]
[[1, 1, 0], [1], [2], [3], [1]]
输出：
[null, true, true, false, false]

解释：
ParkingSystem parkingSystem = new ParkingSystem(1, 1, 0);
parkingSystem.addCar(1); // 返回 true ，因为有 1 个空的大车位
parkingSystem.addCar(2); // 返回 true ，因为有 1 个空的中车位
parkingSystem.addCar(3); // 返回 false ，因为没有空的小车位
parkingSystem.addCar(1); // 返回 false ，因为没有空的大车位，唯一一个大车位已经被占据了
 

提示：

0 <= big, medium, small <= 1000
carType 取值为 1， 2 或 3
最多会调用 addCar 函数 1000 次

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/design-parking-system
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class ParkingSystem {
public:
    ParkingSystem(int big, int medium, int small) {
        spaces = { 0,big,medium,small };
        cars = { 0,0,0,0 };
    }

    bool addCar(int carType) {
        if (cars[carType] == spaces[carType]) {
            return false;
        }

        ++cars[carType];
        return true;
    }

private:
    vector<int> spaces;
    vector<int> cars;
};

int main()
{
    CheckResult check;

    ParkingSystem o1(1, 1, 0);
    check.checkBool(true, o1.addCar(1));
    check.checkBool(true, o1.addCar(2));
    check.checkBool(false, o1.addCar(3));
    check.checkBool(false, o1.addCar(1));

    ParkingSystem o2(0, 0, 0);
    check.checkBool(false, o2.addCar(1));
    check.checkBool(false, o2.addCar(2));
    check.checkBool(false, o2.addCar(3));

    ParkingSystem o3(1, 2, 3);
    check.checkBool(true, o3.addCar(1));
    check.checkBool(false, o3.addCar(1));
    check.checkBool(true, o3.addCar(2));
    check.checkBool(true, o3.addCar(2));
    check.checkBool(false, o3.addCar(2));
    check.checkBool(true, o3.addCar(3));
    check.checkBool(true, o3.addCar(3));
    check.checkBool(true, o3.addCar(3));
    check.checkBool(false, o3.addCar(3));
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
