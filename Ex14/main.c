int countGoodSubstrings(const char *s) {
    int ans = 0;
    int n = strlen(s);

    for (int i = 0; i + 2 < n; ++i) {
        if (s[i] != s[i+1] && s[i+1] != s[i+2] && s[i] != s[i+2]) {
            ans++;
        }
    }

    return ans;
}

//1876