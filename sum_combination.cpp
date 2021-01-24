 /************************************************************************
 * 一个正整数n可以写为几个正整数的和
 * 4=4
 * 4=3+1
 * 4=2+2
 * 4=2+1+1
 * 4=1+1+1+1
 * 要求:输入一个正整数,找出符合这种要求的所有正整数序列(序列不重复)
 ************************************************************************/

#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
using namespace std;

using namespace std;
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        vector<vector<int>> res;
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, res, 0, std::unique_ptr<vector<int>> (new vector<int>));
    }
private:
    void backtrack(vector<int>& candidates, int target, vector<vector<int>> res, int i,
        std::unique_ptr<vector<int>> &&tmp_list)
    {
        if (target < 0) return;
        if (target == 0) {
            res.insert(res.end(), tmp_list->begin(), tmp_list->end());
        }
        for (int start = i; start < candidates.size(); start++) {
            if (target < 0) break;
            tmp_list->insert(candidates.at(start));
            backtrack(candidates, target - candidates[start], res, start, tmp_list);
            tmp_list->erase(tmp_list->size() - 1);
        }
    }
};
int  main()
{


    return 0;
}