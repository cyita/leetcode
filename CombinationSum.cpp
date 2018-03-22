#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end(), less<int>());

        for(int i = candidates.size() - 1; i != -1; i --){
            if(candidates[i] <= target){
                return subSum(candidates, i, target);
            }
        }
        vector<vector<int>> emptyResult;

        return emptyResult;
    }

    vector<vector<int>> subSum(vector<int>& candidates, int end, int target){
        if(end == -1 || target < candidates[0]){
            vector<vector<int>> emptyResult;
            return emptyResult;
        }

        int i = 0;

        vector<vector<int>> result;

        while(target - candidates[end] * i >= 0){
            vector<vector<int>> subResult = subSum(candidates, end - 1, target - candidates[end] * i);
            subResult = combineResult(subResult, candidates[i], i);

            int len = subResult.size();

            for(int i = 0; i != len; i ++){
                result.push_back(subResult[i]);
            }
            i ++;
        }

        return result;
    }

    vector<vector<int>> combineResult(vector<vector<int>> subResult, int combNum, int repeatTime){
        if(repeatTime <= 0){
            vector<vector<int>> emptyResult;
            return emptyResult;
        }

        if(subResult.empty()){
            vector<vector<int>> newResult;

            vector<int> resultArr;
            for(int i = 0; i != repeatTime; i ++){
                resultArr.push_back(combNum);
            }

            newResult.push_back(resultArr);
            return newResult;
        }

        int len = subResult.size();

        for(int i = 0; i != len; i ++){
            for(int j = 0; j != repeatTime; j ++){
                subResult[i].push_back(combNum);
            }
        }

        return subResult;
    }
};

int main(int argc, char const *argv[]) {
    vector<int> candidates;
    candidates.push_back(2);
    candidates.push_back(3);
    candidates.push_back(6);
    candidates.push_back(7);
    return 0;
}
