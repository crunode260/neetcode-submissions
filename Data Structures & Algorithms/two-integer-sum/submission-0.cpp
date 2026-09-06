class Solution {
public:
    vector<int> twoSum(vector<int>&nums, int target){
        unordered_map<int, int> differences;
        for (int i = 0; i < nums.size(); i++){
            if (differences.count(nums[i]) > 0){
            return {differences[nums[i]], i};
            }
            else{
            differences[target - nums[i]] = i;
            }
        }
        return {};

    }
};