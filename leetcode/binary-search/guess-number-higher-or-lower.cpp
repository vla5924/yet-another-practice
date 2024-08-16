// https://leetcode.com/problems/guess-number-higher-or-lower/

const int picked = 123;

/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 */
int guess(int num) {
    if (num == picked)
        return 0;
    if (num > picked)
        return -1;
    return 1;
}

class Solution {
  public:
    int guessNumber(int n) {
        long left = 1L;
        auto right = static_cast<long>(n) + 1L;
        while (left < right) {
            auto mid = left + (right - left) / 2L;
            int verdict = guess(mid);
            if (verdict == 0) {
                return static_cast<int>(mid);
            }
            if (verdict == 1) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return 0; // unreachable
    }
};

int main() {
    return 0;
}
