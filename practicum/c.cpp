#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

long long getNumberOfGoodPairs(int n, const vector<int> &numbers) {
    unordered_map<int, int> rems;
    long long count = 0;
    for (size_t i = 0; i < n; i++) {
        auto rem = numbers[i] % 200;
        count += rems[rem];
        rems[rem]++;
    }
    return count;
}

int readInt() {
    int x;
    cin >> x;
    return x;
}

vector<int> readList(int n) {
    vector<int> res(n);
    for (int i = 0; i < n; i++) {
        cin >> res[i];
    }
    return res;
}

int main() {
    int n = readInt();
    vector<int> numbers = readList(n);
    cout << getNumberOfGoodPairs(n, numbers);
}
