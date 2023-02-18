#include <vector>
#include <unordered_map>
#include "iostream"

using namespace std;

vector<int> twoSum(vector<int> &nums, int target);

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

    ::scanf("%d", &target);

    for (auto item: twoSum(numbers, target)) {
        cout << item << " ";
    }

    cout << endl;

    return 0;
}

vector<int> twoSum(vector<int> &nums, int target) {
    vector<int> indices;
    unordered_map<int, int> comps;

    for (int i = 0; i < nums.size(); i++) {
        auto item = comps.find(nums[i]);
        if (item != comps.end()) {
            indices.push_back(item->second);
            indices.push_back(i);

            break;
        } else {
            comps.insert({target - nums[i], i});
        }
    }

    return indices;
}
