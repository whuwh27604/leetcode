/* 基于时间的键值存储.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
创建一个基于时间的键值存储类 TimeMap，它支持下面两个操作：

1. set(string key, string value, int timestamp)

存储键 key、值 value，以及给定的时间戳 timestamp。
2. get(string key, int timestamp)

返回先前调用 set(key, value, timestamp_prev) 所存储的值，其中 timestamp_prev <= timestamp。
如果有多个这样的值，则返回对应最大的  timestamp_prev 的那个值。
如果没有值，则返回空字符串（""）。
 

示例 1：

输入：inputs = ["TimeMap","set","get","get","set","get","get"], inputs = [[],["foo","bar",1],["foo",1],["foo",3],["foo","bar2",4],["foo",4],["foo",5]]
输出：[null,null,"bar","bar",null,"bar2","bar2"]
解释： 
TimeMap kv;  
kv.set("foo", "bar", 1); // 存储键 "foo" 和值 "bar" 以及时间戳 timestamp = 1  
kv.get("foo", 1);  // 输出 "bar"  
kv.get("foo", 3); // 输出 "bar" 因为在时间戳 3 和时间戳 2 处没有对应 "foo" 的值，所以唯一的值位于时间戳 1 处（即 "bar"）  
kv.set("foo", "bar2", 4);  
kv.get("foo", 4); // 输出 "bar2"  
kv.get("foo", 5); // 输出 "bar2"  

示例 2：

输入：inputs = ["TimeMap","set","set","get","get","get","get","get"], inputs = [[],["love","high",10],["love","low",20],["love",5],["love",10],["love",15],["love",20],["love",25]]
输出：[null,null,null,"","high","high","low","low"]
 

提示：

所有的键/值字符串都是小写的。
所有的键/值字符串长度都在 [1, 100] 范围内。
所有 TimeMap.set 操作中的时间戳 timestamps 都是严格递增的。
1 <= timestamp <= 10^7
TimeMap.set 和 TimeMap.get 函数在每个测试用例中将（组合）调用总计 120000 次。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/time-based-key-value-store
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_map>
#include <map>
#include "../check/CheckResult.h"

using namespace std;

class TimeMap {
public:
    /** Initialize your data structure here. */
    TimeMap() {

    }

    void set(string key, string value, int timestamp) {
        if (keyValues.count(key) == 0) {
            keyValues[key] = { {timestamp, value} };
        }
        else {
            keyValues[key].insert({ timestamp, value });
        }
    }

    string get(string key, int timestamp) {
        auto iter = keyValues.find(key);
        if (iter == keyValues.end()) {
            return "";
        }

        auto it = iter->second.lower_bound(timestamp);
        if (it == iter->second.end()) {
            return (--it)->second;
        }

        if (it->first == timestamp) {
            return it->second;
        }

        if (it == iter->second.begin()) {
            return "";
        }

        return (--it)->second;
    }

private:
    unordered_map<string, map<int, string>> keyValues;
};

int main()
{
    CheckResult check;

    TimeMap o1;
    o1.set("foo", "bar", 1);
    check.checkString("bar", o1.get("foo", 1));
    check.checkString("bar", o1.get("foo", 3));
    o1.set("foo", "bar2", 4);
    check.checkString("bar2", o1.get("foo", 4));
    check.checkString("bar2", o1.get("foo", 5));

    TimeMap o2;
    o2.set("love", "high", 10);
    o2.set("love", "low", 20);
    check.checkString("", o2.get("love", 5));
    check.checkString("high", o2.get("love", 10));
    check.checkString("high", o2.get("love", 15));
    check.checkString("low", o2.get("love", 20));
    check.checkString("low", o2.get("love", 25));

    TimeMap o3;
    check.checkString("", o3.get("love", 5));
    o3.set("aa", "a", 10);
    check.checkString("", o3.get("love", 5));
    check.checkString("", o3.get("aa", 5));
    check.checkString("a", o3.get("aa", 10));
    check.checkString("a", o3.get("aa", 15));
    o3.set("aa", "b", 20);
    check.checkString("", o3.get("aa", 5));
    check.checkString("a", o3.get("aa", 10));
    check.checkString("a", o3.get("aa", 15));
    check.checkString("b", o3.get("aa", 20));
    check.checkString("b", o3.get("aa", 25));
    o3.set("bb", "a", 30);
    o3.set("bb", "b", 40);
    check.checkString("", o3.get("bb", 25));
    check.checkString("a", o3.get("bb", 30));
    check.checkString("a", o3.get("bb", 35));
    check.checkString("b", o3.get("bb", 40));
    check.checkString("b", o3.get("bb", 45));
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
