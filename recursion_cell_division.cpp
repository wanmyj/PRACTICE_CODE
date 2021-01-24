#include <iostream>
#include <array>
#include <algorithm>
#include <functional>
using namespace std;

// 先定义一个函数，明确这个函数的功能，由于递归的特点是问题和子问题都会调用函数自身，所以这个函数的功能一旦确定了， 之后只要找寻问题与子问题的递归关系即可
// 接下来寻找问题与子问题间的关系（即递推公式），这样由于问题与子问题具有相同解决思路，只要子问题调用步骤 1 定义好的函数，问题即可解决。所谓的关系最好能用一个公式表示出来，比如 f(n) = n * f(n-) 这样，如果暂时无法得出明确的公式，用伪代码表示也是可以的, 发现递推关系后，要寻找最终不可再分解的子问题的解，即（临界条件），确保子问题不会无限分解下去。由于第一步我们已经定义了这个函数的功能，所以当问题拆分成子问题时，子问题可以调用步骤 1 定义的函数，符合递归的条件（函数里调用自身）
// 将第二步的递推公式用代码表示出来补充到步骤 1 定义的函数中
// 最后也是很关键的一步，根据问题与子问题的关系，推导出时间复杂度,如果发现递归时间复杂度不可接受，则需转换思路对其进行改造，看下是否有更靠谱的解法

// 细胞分裂 有一个细胞 每一个小时分裂一次，一次分裂一个子细胞，第三个小时后会死亡。那么n个小时候有多少细胞？

// A B C D
//       A B
//         A
//     A B C
//         A
//       A B
//         A
//   A B C D
//         A
//       A B
//         A
//     A B C
//         A
//       A B
//         A
// f(n) = fa(n) + fb(n) + fc(n) + fd(n)
// fa(n) = fa(n-1) + fb(n-1) + fc(n-1)
// fb(n) = fa(n-1)
// fc(n) = fb(n-1)
// fd(n) = fc(n-1)
// f(n-1) = fa(n-1) + fb(n-1) + fc(n-1) + fd(n-1)
// f(n) = 2*f(n-1) - 2fd(n-1)
int f(int n)
{   
    std::function<int (int)> fa, fb, fc, fd;
    fa = [&fa, &fb, &fc](int na) -> int {
        if (na == 0) return 1;
        return fa(na-1) + fb(na-1) + fc(na-1);
    };
    fb = [&fb, &fa](int nb) -> int {
        if (nb == 1) return 1;
        if (nb == 0) return 0;
        return fa(nb-1);
    };
    fc = [&fb](int nc) -> int {
        if (nc == 2) return 1;
        if (nc <= 1) return 0;
        return fb(nc-1);
    };
    fd = [&fc](int nd) -> int {
        if (nd == 3) return 1;
        if (nd <= 3) return 0;
        return fc(nd-1);
    };
    return fa(n) + fb(n) + fc(n) + fd(n);
}
int main()
{
    cout << f(3) << endl;
    return 0;   
}