int firstHalf(vector<int> &nums, int target) {
    int left = 0, right = nums.size() - 1;
    int start = -1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            start = mid;
            right = mid - 1;
        } else if (nums[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    
    return start;
}

int secondHalf(vector<int> &nums, int target) {
    int left = 0, right = nums.size() - 1;
    int end = -1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            end = mid;
            left = mid + 1;
        } else if (nums[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    
    return end;
}

vector<int> searchRange(vector<int>& nums, int target) {
    int start = firstHalf(nums, target);
    int end = secondHalf(nums, target);
    return {start, end};
}
