#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <string.h>
#include <algorithm>

using namespace std;

struct opt{
    string str;
    int optNum;

    opt(string s, int num) : str(s), optNum(num){ }
};

class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        queue<opt> BSTQ;
        BSTQ.push(opt(start, 0));
        int bankLen = bank.size();
        set<string> visited;

        while(!BSTQ.empty()){
            opt thisOpt = BSTQ.front();
            BSTQ.pop();
            if(thisOpt.str == end){
                return thisOpt.optNum;
            }
            if(visited.count(thisOpt.str)){
                continue;
            }
            for(int i = 0; i != bankLen; i ++){
                string seq = bank[i];
                int diffNum = 0;
                for(int j = 0; j != seq.length(); j ++){
                    if(thisOpt.str[j] != seq[j]){
                        diffNum ++;
                    }
                    if(diffNum >= 2){
                        break;
                    }
                }
                if(diffNum == 1){
                    BSTQ.push(opt(seq, thisOpt.optNum + 1));
                }
            }
            visited.insert(thisOpt.str);
        }
        return -1;
    }
};

int main(int argc, char const *argv[]) {
    vector<string> bank;
    bank.push_back("AACCGGTA");
    Solution solution;
    int result = solution.minMutation("AACCGGTT", "AACCGGTA", bank);
    cout << "The result is:" << result << endl;
    /* code */
    return 0;
}
