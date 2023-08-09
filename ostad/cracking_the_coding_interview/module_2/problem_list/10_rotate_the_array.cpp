#include "iostream"
#include "cstdio"
#include <vector>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif

    int tc;
    int direction;
    int input;
    vector<int> numbers;

    // test case
    scanf("%d", &tc);

    // direction
    scanf("%d", &direction);

    for (int i = 0; i < tc; i++) {
        scanf("%d", &input);
        numbers.push_back(input);
    }

    int carry;

    if (direction == 0) {
        // rotate the array to right

        for (int i = numbers.size() - 1; i >= 0; i--) {
            if (i == numbers.size() - 1) {
                carry = numbers[i];
            }

            numbers[i] = i > 0 ? numbers[i - 1] : carry;
        }
    } else {
        // rotate the array to left

        for (int i = 0; i < numbers.size(); i++) {
            if (i == 0) {
                carry = numbers[i];
            }

            numbers[i] = i < numbers.size() - 1 ? numbers[i + 1] : carry;
        }
    }

    for (int number: numbers) {
        cout << number << " ";
    }

    cout << endl;

    return 0;
}