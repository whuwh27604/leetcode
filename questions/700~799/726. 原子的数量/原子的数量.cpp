/* 原子的数量.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个化学式formula（作为字符串），返回每种原子的数量。

原子总是以一个大写字母开始，接着跟随0个或任意个小写字母，表示原子的名字。

如果数量大于 1，原子后会跟着数字表示原子的数量。如果数量等于 1 则不会跟数字。例如，H2O 和 H2O2 是可行的，但 H1O2 这个表达是不可行的。

两个化学式连在一起是新的化学式。例如 H2O2He3Mg4 也是化学式。

一个括号中的化学式和数字（可选择性添加）也是化学式。例如 (H2O2) 和 (H2O2)3 是化学式。

给定一个化学式，输出所有原子的数量。格式为：第一个（按字典序）原子的名子，跟着它的数量（如果数量大于 1），然后是第二个原子的名字（按字典序），跟着它的数量（如果数量大于 1），以此类推。

示例 1:

输入:
formula = "H2O"
输出: "H2O"
解释:
原子的数量是 {'H': 2, 'O': 1}。
示例 2:

输入:
formula = "Mg(OH)2"
输出: "H2MgO2"
解释:
原子的数量是 {'H': 2, 'Mg': 1, 'O': 2}。
示例 3:

输入:
formula = "K4(ON(SO3)2)2"
输出: "K4N2O14S4"
解释:
原子的数量是 {'K': 4, 'N': 2, 'O': 14, 'S': 4}。
注意:

所有原子的第一个字母为大写，剩余字母都是小写。
formula的长度在[1, 1000]之间。
formula只包含字母、数字和圆括号，并且题目中给定的是合法的化学式。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/number-of-atoms
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_map>
#include <map>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    string countOfAtoms(string formula) {
        int end;
        unordered_map<string, int> atoms = getAtoms(formula, formula.size(), 0, end);

        return output(atoms);
    }

    unordered_map<string, int> getAtoms(string& formula, int size, int start, int& end) {
        unordered_map<string, int> atoms, nextLayer;
        string atom;
        int i = start, times;

        for (; i < size && formula[i] != ')'; ++i) {
            if (formula[i] == '(') {
                nextLayer = getAtoms(formula, size, i + 1, end);
                times = getTimes(formula, size, end + 1, end);
                multiply(nextLayer, times);
                merge(atoms, nextLayer);
                i = end;
            }
            else {
                atom = getAtom(formula, size, i, end);
                times = getTimes(formula, size, end + 1, end);
                atoms[atom] += times;
                i = end;
            }
        }

        end = i;
        return atoms;
    }

    string getAtom(string& formula, int size, int start, int& end) {
        int i = start + 1;

        while (i < size && formula[i] >= 'a' && formula[i] <= 'z') {
            ++i;
        }

        end = i - 1;
        return string(formula, start, i - start);
    }

    int getTimes(string& formula, int size, int start, int& end) {
        int i = start, times = 0;

        while (i < size && formula[i] >= '0' && formula[i] <= '9') {
            times = times * 10 + formula[i] - '0';
            ++i;
        }

        end = i - 1;
        return times == 0 ? 1 : times;
    }

    void multiply(unordered_map<string, int>& atoms, int times) {
        for (auto& atom : atoms) {
            atom.second *= times;
        }
    }

    void merge(unordered_map<string, int>& atoms, unordered_map<string, int>& nextLayer) {
        for (auto& atom : nextLayer) {
            atoms[atom.first] += atom.second;
        }
    }

    string output(unordered_map<string, int>& atoms) {
        map<string, int> sorted;
        string ans;

        for (auto& atom : atoms) {
            sorted[atom.first] = atom.second;
        }

        for (auto iter = sorted.begin(); iter != sorted.end(); ++iter) {
            ans += iter->first;
            if (iter->second != 1) {
                ans += to_string(iter->second);
            }
        }

        return ans;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkString("H2O", o.countOfAtoms("H2O"));
    check.checkString("H2MgO2", o.countOfAtoms("Mg(OH)2"));
    check.checkString("K4N2O14S4", o.countOfAtoms("K4(ON(SO3)2)2"));
    check.checkString("H4", o.countOfAtoms("(H2)2"));
    check.checkString("Z", o.countOfAtoms("Z"));
    check.checkString("A5B2", o.countOfAtoms("A2B2A3"));
    check.checkString("Al252586Ar16422As30600At339456B200770Ba435047Be16813Bh396950Bi8075Bk20400Br12750Cd437138Cf627181Cl147798Cn394213Co212704Cr18275Cs584902Db20400Ds109480Dy99144Er656880Es624036Fe14467Fl16813Fm425Fr1564Ga120037H1275He18700Hg344862Ho737426Hs78676I641240In673302Ir353073K168912Kr920414La587197Li379950Lr17238Lu7922Lv17204Mc285821Mn142800Mt453934N538016Na186116Nd248880Ne538016Nh13294Np44200O225216Og1309P982600Pb3400Pd10931Pm100096Po448443Pt708883Pu16575Rb449650Re590750Rf2188410Rg19363Rh767975Rn22100S261970Sb249900Sc12750Se856800Sg312800Sr16813Ta108613Tb620976Tc612017Te1256640Th14467Ti35700Tl11356Ts16932W554829Xe470764Y31280Yb18275Zn1448655Zr30515", o.countOfAtoms("((Bi16LrSc30As49As23La13La(Ba21Re28BkRf40DbP29SeSe41La27Cn16)48(TcRn)49(Sb28Ti4Po35Mn16)21(Ta36Tl2Br5Dy21S41)6(Bh37Li36O20Tb48)24Cr43Pd11Pu39OgYb43Zr35FmHe44(Rh35BiLaCf4RnHLi10RgLuRg)3(Cn15PbS44Nd18)8)25((Hs11B41Rf46)20(At48Te45)32(Cs15Mt19OgHs34Ts5La33Ga23Np50Dy33O24)4)13((Po21ZnPdK27Pm16TlCo34Nd30Y4N)16(Nh2BaNa28Ga15LuAl38)17(Rb23ReRf2Rf33I32Te48Bh)50(Cf37Ne32W33BeRgIr21Cs34Mc17Zn43)43(Ho23ArEs38Er40Tb8DyIn41Tc36Hg21Cl9)42(Y8B25Ts16S10Fr2Lv22Po6)2(Zn46N34Ds7Sg20HoRf31P25ZrIHo22)40(FeRh50Kr9ThPt49)37(TaLrKr35Kr12SrCd26Xe28Mt26CnFl)43)23)17"));
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
