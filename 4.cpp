#include <iostream>
#include <vector>

using namespace std;

bool search(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) {
            return true;
        }

        if (nums[left] < nums[mid]) {
            if (nums[left] <= target && target < nums[mid]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        } else if (nums[left] > nums[mid]) {
            if (nums[mid] < target && target <= nums[right]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        } else {
            left++;
        }
    }

    return false;
}

int main() {
    vector<int> nums1 = {2, 5, 6, 0, 0, 1, 2};
    int target1 = 0;
    cout << (search(nums1, target1) ? "true" : "false") << endl;

    vector<int> nums2 = {2, 5, 6, 0, 0, 1, 2};
    int target2 = 3;
    cout << (search(nums2, target2) ? "true" : "false") << endl;

    return 0;
}


// Out[ut is

true
false
