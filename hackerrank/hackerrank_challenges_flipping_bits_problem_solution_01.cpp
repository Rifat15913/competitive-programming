#include "vector"
#include "iostream"
#include "cstdio"

using namespace std;

vector<unsigned int> flipBits(vector<unsigned int> &nums);

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif

    int tc;
    unsigned int input;
    vector<unsigned int> numbers;

    scanf("%d", &tc);

    for (int i = 0; i < tc; i++) {
        scanf("%u", &input);
        numbers.push_back(input);
    }

    for (auto item: flipBits(numbers)) {
        cout << item << endl;
    }

    return 0;
}

vector<unsigned int> flipBits(vector<unsigned int> &nums) {
    vector<unsigned int> flippedNumbers;

    flippedNumbers.reserve(nums.size());
    for(unsigned int item : nums) {
        flippedNumbers.push_back(~item);
    }

    return flippedNumbers;
}