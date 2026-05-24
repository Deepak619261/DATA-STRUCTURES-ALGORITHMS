class Solution {
public:
    int minOperations(string s) {
    int n=s.size();
        int costA = 0;
for (int i = 0; i < n; i++) {
    char expected = (i % 2 == 0) ? '0' : '1';
    if (s[i] != expected) costA++;
}
    return min(costA,n-costA);
    }
};