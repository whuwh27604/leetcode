/* 黑盒光线反射.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
秋日市集上有个奇怪的黑盒，黑盒的主视图为 n*m 的矩形。从黑盒的主视图来看，黑盒的上面和下面各均匀分布有 m 个小孔，黑盒的左面和右面各均匀分布有 n 个小孔。黑盒左上角小孔序号为 0，按顺时针编号，总共有 2*(m+n) 个小孔。每个小孔均可以打开或者关闭，初始时，所有小孔均处于关闭状态。每个小孔上的盖子均为镜面材质。例如一个 2*3 的黑盒主视图与其小孔分布如图所示:

image.png

店长告诉小扣，这里是「几何学的快问快答」，店长可能有两种操作：

open(int index, int direction) - 若小孔处于关闭状态，则打开小孔，照入光线；否则直接照入光线；
close(int index) - 关闭处于打开状态小孔，店长保证不会关闭已处于关闭状态的小孔；
其中：

index： 表示小孔序号
direction：1 表示光线沿
�
=
�
y=x 方向，-1 表示光线沿
�
=
−
�
y=−x 方向。
image.png

当光线照至边界时：若边界上的小孔为开启状态，则光线会射出；否则，光线会在小孔之间进行反射。特别地：

若光线射向未打开的拐角（黑盒顶点），则光线会原路反射回去；
光线自拐角处的小孔照入时，只有一种入射方向（如自序号为 0 的小孔照入方向只能为 -1）
image.png

请帮助小扣判断并返回店长每次照入的光线从几号小孔射出。

示例 1：

输入： ["BlackBox","open","open","open","close","open"] [[2,3],[6,-1],[4,-1],[0,-1],[6],[0,-1]]

输出：[null,6,4,6,null,4]

解释： BlackBox b = BlackBox(2,3); // 新建一个 2x3 的黑盒 b.open(6,-1) // 打开 6 号小孔，并沿 y=-x 方向照入光线，光线至 0 号小孔反射，从 6 号小孔射出 b.open(4,-1) // 打开 4 号小孔，并沿 y=-x 方向照入光线，光线轨迹为 4-2-8-2-4，从 4 号小孔射出 b.open(0,-1) // 打开 0 号小孔，并沿 y=-x 方向照入光线，由于 6 号小孔为开启状态，光线从 6 号小孔射出 b.close(6) // 关闭 6 号小孔 b.shoot(0,-1) // 从 0 号小孔沿 y=-x 方向照入光线，由于 6 号小孔为关闭状态，4 号小孔为开启状态，光线轨迹为 0-6-4，从 4 号小孔射出

示例 2：

输入： ["BlackBox","open","open","open","open","close","open","close","open"] [[3,3],[1,-1],[5,1],[11,-1],[11,1],[1],[11,1],[5],[11,-1]]

输出：[null,1,1,5,1,null,5,null,11]

解释：

image.png

BlackBox b = BlackBox(3,3); // 新建一个 3x3 的黑盒 b.open(1,-1) // 打开 1 号小孔，并沿 y=-x 方向照入光线，光线轨迹为 1-5-7-11-1，从 1 号小孔射出 b.open(5,1) // 打开 5 号小孔，并沿 y=x 方向照入光线，光线轨迹为 5-7-11-1，从 1 号小孔射出 b.open(11,-1) // 打开 11 号小孔，并沿逆 y=-x 方向照入光线，光线轨迹为 11-7-5，从 5 号小孔射出 b.open(11,1) // 从 11 号小孔沿 y=x 方向照入光线，光线轨迹为 11-1，从 1 号小孔射出 b.close(1) // 关闭 1 号小孔 b.open(11,1) // 从 11 号小孔沿 y=x 方向照入光线，光线轨迹为 11-1-5，从 5 号小孔射出 b.close(5) // 关闭 5 号小孔 b.open(11,-1) // 从 11 号小孔沿 y=-x 方向照入光线，光线轨迹为 11-1-5-7-11，从 11 号小孔射出

提示：

1 <= n, m <= 10000
1 <= 操作次数 <= 10000
direction 仅为 1 或 -1
0 <= index < 2*(m+n)
*/

#include <iostream>
#include <unordered_map>
#include <set>
#include "../check/CheckResult.h"

using namespace std;

const int DIRECTION0 = 0;  // y = x
const int DIRECTION1 = 1;  // y = -x

class Node {
public:
    int index;
    int dir;
    int id;

    Node() : index(0), dir(0), id(0) {}
    Node(int i, int d, int shifting) {
        index = i;
        dir = d;
        id = i;

        if (dir == DIRECTION1) {
            id += shifting;
        }
    }

    bool operator!=(const Node& o) const {
        return index != o.index || dir != o.dir;
    }
};

class Loop {  // 全部关闭时，一条光线的循环路径
public:
    unordered_map<int, Node> keyNodes;  // { key, node }
    unordered_map<int, int> node2Key;  // { nodeid, key }
    set<int> openKeys;
    int key = 0;  // 按照该路径经过的node，依次编号

    void addNode(Node& node) {
        keyNodes[key] = node;
        node2Key[node.id] = key++;
    }

    void open(Node& node) {
        int key = node2Key[node.id];

        if (openKeys.count(key) == 0) {
            openKeys.insert(key);
        }
    }

    void close(Node& node) {
        openKeys.erase(node2Key[node.id]);
    }

    int getOpenIndex(Node& node) {
        int key = node2Key[node.id];

        auto iter = openKeys.upper_bound(key);  // 二分查找当前node后第一个open的node
        if (iter == openKeys.end()) {  // 如果没找到，因为是循环路径，所以接下来会是第一个open的node
            iter = openKeys.begin();
        }

        return keyNodes[*iter].index;
    }
};

class BlackBox {
public:
    BlackBox(int n, int m) {
        row = n;
        column = m;
        holes = 2 * (n + m);
        totalLoopId = 0;
        node2LoopId.clear();
        node2LoopId.resize(2 * holes, -1);
        nextIndices.clear();
        nextIndices.resize(2, vector<int>(holes, -1));
        getNext();
        loops.clear();
        getALLLoop();
    }

    int open(int index, int direction) {  // open一个hole时，注意有2个方向的node都要打开
        direction = (direction == -1 ? DIRECTION1 : DIRECTION0);
        Node node(index, direction ^ 1, holes);
        int loopId = node2LoopId[node.id];
        if (loopId != -1) {
            loops[loopId].open(node);
        }

        node = Node(index, direction, holes);
        loopId = node2LoopId[node.id];
        if (loopId != -1) {
            loops[loopId].open(node);
        }

        return loops[loopId].getOpenIndex(node);
    }

    void close(int index) {  // 关闭两个方向的node
        Node node(index, DIRECTION0, holes);
        int loopId = node2LoopId[node.id];
        if (loopId != -1) {
            loops[loopId].close(node);
        }

        node = Node(index, DIRECTION1, holes);
        loopId = node2LoopId[node.id];
        if (loopId != -1) {
            loops[loopId].close(node);
        }
    }

    void getALLLoop() {
        for (int index = 0; index < holes; ++index) {
            Node node(index, DIRECTION0, holes);
            if (node2LoopId[node.id] == -1 && index != 0 && index != column + row) {  // 这2个位置没有DIRECTION0方向
                loops.push_back(Loop());
                getLoop(node, totalLoopId++);
            }

            node = Node(index, DIRECTION1, holes);
            if (node2LoopId[node.id] == -1 && index != column && index != 2 * column + row) {  // 这2个位置没有DIRECTION1方向
                loops.push_back(Loop());
                getLoop(node, totalLoopId++);
            }
        }
    }

    void getLoop(Node& head, int loopId) {
        Node node = head;

        do {
            loops[loopId].addNode(node);
            node2LoopId[node.id] = loopId;
            node = getNext(node);
        } while (node != head);
    }

    Node getNext(Node& node) {
        int index = node.index, dir = node.dir;
        int next = nextIndices[dir][index];

        if (next != 0 && next != column && next != column + row && next != 2 * column + row) {  // 4个角上的下一跳方向不变
            dir ^= 1;
        }

        return Node(next, dir, holes);
    }

    void getNext() {
        int index1 = holes - 1, index2 = 1;

        while (index1 != index2) {
            nextIndices[DIRECTION0][index1] = index2;
            nextIndices[DIRECTION0][index2] = index1;
            --index1, ++index2;
        }

        index1 = (2 * column + row + 1) % holes, index2 = 2 * column + row - 1;

        while (index1 != index2) {
            nextIndices[DIRECTION1][index1] = index2;
            nextIndices[DIRECTION1][index2] = index1;
            index1 = (index1 + 1) % holes;
            --index2;
        }
    }

    vector<int> node2LoopId;
    vector<Loop> loops;
    vector<vector<int>> nextIndices;
    int totalLoopId;
    int row;
    int column;
    int holes;
};

/**
 * Your BlackBox object will be instantiated and called as such:
 * BlackBox* obj = new BlackBox(n, m);
 * int param_1 = obj->open(index,direction);
 * obj->close(index);
 */

int main()
{
	CheckResult check;

    BlackBox o1(2, 3);
    check.checkInt(6, o1.open(6, -1));
    check.checkInt(4, o1.open(4, -1));
    check.checkInt(6, o1.open(0, -1));
    o1.close(6);
    check.checkInt(4, o1.open(0, -1));

    BlackBox o2(3, 3);
    check.checkInt(1, o2.open(1, -1));
    check.checkInt(1, o2.open(5, 1));
    check.checkInt(5, o2.open(11, -1));
    check.checkInt(1, o2.open(11, 1));
    o2.close(1);
    check.checkInt(5, o2.open(11, 1));
    o2.close(5);
    check.checkInt(11, o2.open(11, -1));

    BlackBox o3(1, 1);
    check.checkInt(0, o3.open(0, -1));
    check.checkInt(1, o3.open(1, 1));
    check.checkInt(0, o3.open(2, -1));
    check.checkInt(1, o3.open(3, 1));
    o3.close(1);
    check.checkInt(3, o3.open(3, 1));
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
