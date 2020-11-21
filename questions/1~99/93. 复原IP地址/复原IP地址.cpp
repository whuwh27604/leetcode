/* 复原IP地址.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个只包含数字的字符串，复原它并返回所有可能的 IP 地址格式。

有效的 IP 地址 正好由四个整数（每个整数位于 0 到 255 之间组成，且不能含有前导 0），整数之间用 '.' 分隔。

例如："0.1.2.201" 和 "192.168.1.1" 是 有效的 IP 地址，但是 "0.011.255.245"、"192.168.1.312" 和 "192.168@1.1" 是 无效的 IP 地址。

 

示例 1：

输入：s = "25525511135"
输出：["255.255.11.135","255.255.111.35"]
示例 2：

输入：s = "0000"
输出：["0.0.0.0"]
示例 3：

输入：s = "1111"
输出：["1.1.1.1"]
示例 4：

输入：s = "010010"
输出：["0.10.0.10","0.100.1.0"]
示例 5：

输入：s = "101023"
输出：["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]
 

提示：

0 <= s.length <= 3000
s 仅由数字组成

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/restore-ip-addresses
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        int size = s.size();
        if (size < 4 || size > 12) {
            return {};
        }

        vector<string> nums;
        vector<string> ipAddresses;

        DFS(s, 0, nums, ipAddresses);

        return ipAddresses;
    }

    void DFS(string& s, int start, vector<string>& nums, vector<string>& ipAddresses) {
        int size = s.size();
        if (start == size) {
            if (isValidIpaddress(nums)) {
                ipAddresses.push_back(nums[0] + '.' + nums[1] + '.' + nums[2] + '.' + nums[3]);
            }
            return;
        }

        if (nums.size() == 4) {
            return;
        }

        for (int i = 1; i < 4 && start + i <= size; ++i) {
            string num(s, start, i);
            nums.push_back(num);
            DFS(s, start + i, nums, ipAddresses);
            nums.pop_back();
        }
    }

    bool isValidIpaddress(vector<string>& nums) {
        if (nums.size() != 4) {
            return false;
        }

        for (string& num : nums) {
            int n = stoi(num);
            if (n > 255 || (num[0] == '0' && num.size() != 1)) {
                return false;
            }
        }

        return true;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<string> actual = o.restoreIpAddresses("25525511135");
    vector<string> expected = { "255.255.11.135","255.255.111.35" };
    check.checkStringVectorRandomOrder(expected, actual);

    actual = o.restoreIpAddresses("0000");
    expected = { "0.0.0.0" };
    check.checkStringVectorRandomOrder(expected, actual);

    actual = o.restoreIpAddresses("1111");
    expected = { "1.1.1.1" };
    check.checkStringVectorRandomOrder(expected, actual);

    actual = o.restoreIpAddresses("010010");
    expected = { "0.10.0.10","0.100.1.0" };
    check.checkStringVectorRandomOrder(expected, actual);

    actual = o.restoreIpAddresses("101023");
    expected = { "1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3" };
    check.checkStringVectorRandomOrder(expected, actual);
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
