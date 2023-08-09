#include "iostream"
#include "cstdio"
#include "set"

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif

    int tc;
    int input;
    set<int> numbers;

    // test case
    scanf("%d", &tc);

    for (int i = 0; i < tc; i++) {
        scanf("%d", &input);
        numbers.insert(input);
    }

    for (int i: numbers) {
        cout << i << " ";
    }

    return 0;
}