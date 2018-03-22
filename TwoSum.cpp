class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::vector<int> result;
        std::unordered_map<int, int> before;
        int size = nums.size();
        int elem1 = 0;
        for(int i = 0; i != size; i ++){
        	elem1 = nums[i];
        	if(before.find(target - elem1) == before.end()){
        	    before[elem1] = i + 1;
        	} else{
        	    result.push_back(before[target - elem1]);
        	    result.push_back(i + 1);
        	    return result;
        	}
        }
    }
};