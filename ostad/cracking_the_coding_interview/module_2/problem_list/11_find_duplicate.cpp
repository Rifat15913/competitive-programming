#include "iostream"
#include "cstdio"
#include <unordered_map>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif

    int tc;
    int input;
    unordered_map<int, int> numberCounts;
    int result;

    // test case
    scanf("%d", &tc);

    for (int i = 0; i < tc; i++) {
        scanf("%d", &input);
        numberCounts[input] = ++numberCounts[input];

        if (numberCounts[input] > 1) {
            result = input;
        }
    }

    cout << result << endl;

    return 0;
}