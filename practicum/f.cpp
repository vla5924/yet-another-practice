#include <iostream>

using namespace std;

bool differsByCase(char a, char b) { return a < b && b - a == 'a' - 'A' || b < a && a - b == 'a' - 'A'; }

string convertToGoodString(string bad) {
    while (true) {
        int sz = bad.size();
        if (sz <= 1)
            return bad;
        string good;
        int replacements = 0;
        for (int i = 0; i < sz; i++) {
            if (i < sz - 1 && differsByCase(bad[i], bad[i + 1])) {
                i++;
                replacements++;
                continue;
            }
            good.push_back(bad[i]);
        }
        if (replacements == 0)
            return good;
        bad = good;
    }
}

int main() {
    string bad;
    cin >> bad;
    cout << convertToGoodString(bad);
}
