class Solution {
public:
    int search(vector<int>& nums, int target){
    int l = 0;
    int r = nums.size();
    int m;
    while (r > l){
        m = (l + r) / 2;
        if (target > nums[m]){
        l = m + 1;
        }
        else if (target < nums[m]){
        r = m;
        }
        else{
        return m;
        }
    }
    return -1;
}};
