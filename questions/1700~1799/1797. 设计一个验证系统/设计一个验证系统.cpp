/* 设计一个验证系统.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
你需要设计一个包含验证码的验证系统。每一次验证中，用户会收到一个新的验证码，这个验证码在 currentTime 时刻之后 timeToLive 秒过期。如果验证码被更新了，那么它会在 currentTime （可能与之前的 currentTime 不同）时刻延长 timeToLive 秒。

请你实现 AuthenticationManager 类：

AuthenticationManager(int timeToLive) 构造 AuthenticationManager 并设置 timeToLive 参数。
generate(string tokenId, int currentTime) 给定 tokenId ，在当前时间 currentTime 生成一个新的验证码。
renew(string tokenId, int currentTime) 将给定 tokenId 且 未过期 的验证码在 currentTime 时刻更新。如果给定 tokenId 对应的验证码不存在或已过期，请你忽略该操作，不会有任何更新操作发生。
countUnexpiredTokens(int currentTime) 请返回在给定 currentTime 时刻，未过期 的验证码数目。
如果一个验证码在时刻 t 过期，且另一个操作恰好在时刻 t 发生（renew 或者 countUnexpiredTokens 操作），过期事件 优先于 其他操作。

 

示例 1：


输入：
["AuthenticationManager", "renew", "generate", "countUnexpiredTokens", "generate", "renew", "renew", "countUnexpiredTokens"]
[[5], ["aaa", 1], ["aaa", 2], [6], ["bbb", 7], ["aaa", 8], ["bbb", 10], [15]]
输出：
[null, null, null, 1, null, null, null, 0]

解释：
AuthenticationManager authenticationManager = new AuthenticationManager(5); // 构造 AuthenticationManager ，设置 timeToLive = 5 秒。
authenticationManager.renew("aaa", 1); // 时刻 1 时，没有验证码的 tokenId 为 "aaa" ，没有验证码被更新。
authenticationManager.generate("aaa", 2); // 时刻 2 时，生成一个 tokenId 为 "aaa" 的新验证码。
authenticationManager.countUnexpiredTokens(6); // 时刻 6 时，只有 tokenId 为 "aaa" 的验证码未过期，所以返回 1 。
authenticationManager.generate("bbb", 7); // 时刻 7 时，生成一个 tokenId 为 "bbb" 的新验证码。
authenticationManager.renew("aaa", 8); // tokenId 为 "aaa" 的验证码在时刻 7 过期，且 8 >= 7 ，所以时刻 8 的renew 操作被忽略，没有验证码被更新。
authenticationManager.renew("bbb", 10); // tokenId 为 "bbb" 的验证码在时刻 10 没有过期，所以 renew 操作会执行，该 token 将在时刻 15 过期。
authenticationManager.countUnexpiredTokens(15); // tokenId 为 "bbb" 的验证码在时刻 15 过期，tokenId 为 "aaa" 的验证码在时刻 7 过期，所有验证码均已过期，所以返回 0 。
 

提示：

1 <= timeToLive <= 108
1 <= currentTime <= 108
1 <= tokenId.length <= 5
tokenId 只包含小写英文字母。
所有 generate 函数的调用都会包含独一无二的 tokenId 值。
所有函数调用中，currentTime 的值 严格递增 。
所有函数的调用次数总共不超过 2000 次。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/design-authentication-manager
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <map>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

class AuthenticationManager {
public:
    AuthenticationManager(int timeToLive) {
        liveTime = timeToLive;
    }

    void generate(string tokenId, int currentTime) {
        int expiredTime = currentTime + liveTime;
        tokenTimes[tokenId] = expiredTime;
        timeTokens[expiredTime] = tokenId;
    }

    void renew(string tokenId, int currentTime) {
        removeExpired(currentTime);

        if (tokenTimes.count(tokenId) != 0) {
            timeTokens.erase(tokenTimes[tokenId]);
            tokenTimes.erase(tokenId);
            generate(tokenId, currentTime);
        }
    }

    int countUnexpiredTokens(int currentTime) {
        removeExpired(currentTime);

        return timeTokens.size();
    }

    void removeExpired(int currentTime) {
        auto iter = timeTokens.begin();

        while (iter != timeTokens.end()) {
            if (iter->first > currentTime) {
                break;
            }

            tokenTimes.erase(iter->second);
            iter = timeTokens.erase(iter);
        }
    }

private:
    map<int, string> timeTokens;
    unordered_map<string, int> tokenTimes;
    int liveTime;
};

int main()
{
    CheckResult check;

    AuthenticationManager o1(5);
    o1.renew("aaa", 1);
    o1.generate("aaa", 2);
    check.checkInt(1, o1.countUnexpiredTokens(6));
    o1.generate("bbb", 7);
    o1.renew("aaa", 8);
    o1.renew("bbb", 10);
    check.checkInt(0, o1.countUnexpiredTokens(15));
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
