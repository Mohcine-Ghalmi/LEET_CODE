
int removeElement(vector<int>& nums, int val) {
    for (vector<int>::iterator it = nums.begin(); it != nums.end();) {
        if (*it == val) {
            it = nums.erase(it);
            continue;
        }
        ++it;
    }

    return (nums.size());
}
