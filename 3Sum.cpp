class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        int size = nums.size();
        
        if(size < 3){
            return result;
        }
        
        int front = 0;
        int end = 0;
        int partSum = 0;
        
        for(int i = 0; i != size - 2; i ++){
            int target = - nums[i];
            if(target < (nums[i] * 2)){
                break;
            }
            
            front = i + 1;
            end = size - 1;
            
            while(front < end){
                partSum = nums[front] + nums[end];
                if(partSum == target){
                    result.push_back({nums[front], nums[end], nums[i]});
                    
                    while(nums[front] == nums[front + 1] && front < size - 1){
                        front ++;
                    }
                    front ++;
                    
                    while(nums[end] == nums[end - 1] && end > 1){
                        end --;
                    }
                    end --;
                } else if(partSum > target){
                    end --;
                } else{
                    front ++;
                }
            }
            
            while(nums[i] == nums[i + 1] && i < size - 2){
                i ++;
            }
        }
        
        return result;
    }
};