class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0 || nums.size() == 1){
            return nums.size();
        }
        
        int deletedVec = 0;
        int lookAhead = 1;
        
        while(lookAhead < nums.size()){
            if(nums[deletedVec] == nums[lookAhead]){
                lookAhead ++;
            } else{
                swap(nums, ++ deletedVec, lookAhead);
                lookAhead ++;
            }
        }
        
        return deletedVec + 1;
    }
    
    void swap(vector<int>& nums, int a, int b){
        int temp = nums[a];
        nums[a] = nums[b];
        nums[b] = temp;
    }
};