bool canReach(char *s, int minJump, int maxJump) {
    int n = strlen(s);
    if (s[n - 1] == '1') return false;

    int *f = (int *)calloc(n + 1, sizeof(int)); 
    if (!f) return false; 

    f[0] = 1;
    f[1] = -1;
    int c = 0;

    for (int i = 0; i < n; ++i) {
        c += f[i];
        if (c > 0 && s[i] == '0') {
            int l = i + minJump;
            int r = (i + maxJump < n - 1) ? i + maxJump : n - 1;
            if (l < r) {
                f[l]++;
                if (r + 1 < n) f[r + 1]--;
            }
        }
    }

    bool result = (c > 0);
    free(f);
    return result;
}

// leetcode 1871