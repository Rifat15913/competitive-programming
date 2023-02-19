#include "vector"
#include "iostream"
#include "cstdio"

using namespace std;

int binarySearch(vector<int> &nums, int target);
vector<int> twoSum(vector<int> &nums, int sum);

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif

    int tc, input, target;
    vector<int> numbers;

    scanf("%d", &tc);

    for (int i = 0; i < tc; i++) {
        scanf("%d", &input);
        numbers.push_back(input);
    }

    scanf("%d", &target);

    for (auto item: twoSum(numbers, target)) {
        cout << item << " ";
    }

    cout << endl;

    return 0;
}

vector<int> twoSum(vector<int> &nums, int sum) {
    int left = 0;
    int right = nums.size() - 1;

    while(left < right) {
        if(nums[left] + nums[right] == sum) {
            return {left + 1, right + 1};
        } else if(nums[left] + nums[right] < sum) {
            left++;
        } else {
            right--;
        }
    }

    return {};
}

int binarySearch(vector<int> &nums, int target, int startingIndex) {
    int left = startingIndex;
    int right = nums.size() - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (nums[mid] == target) {
            return mid;
        } else if (target < nums[mid]) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return -1;
}
