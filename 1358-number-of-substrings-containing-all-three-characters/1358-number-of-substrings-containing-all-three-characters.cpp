class Solution {
public:
    int numberOfSubstrings(string s) {
        int left = 0, right = 0;
    int count_a = 0, count_b = 0, count_c = 0;
    int result = 0;
    while (right < s.length()) {
        if (s[right] == 'a') {
            count_a++;
        } else if (s[right] == 'b') {
            count_b++;
        } else if (s[right] == 'c') {
            count_c++;
        }
        while (count_a > 0 && count_b > 0 && count_c > 0) {
            if (s[left] == 'a') {
                count_a--;
            } else if (s[left] == 'b') {
                count_b--;
            } else if (s[left] == 'c') {
                count_c--;
            }
            left++;
        }
        result += left;
        right++;
    }
    return result;
}
};