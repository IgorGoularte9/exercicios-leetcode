int canBeTypedWords(char* text, char* brokenLetters) {
    int brk[128] = {0};  
    for (int i = 0; brokenLetters[i] != '\0'; i++) {
        brk[(unsigned char)brokenLetters[i]] = 1;
    }

    int ans = 0;
    char* token = strtok(text, " ");  
    while (token != NULL) {
        int ok = 1;
        for (int i = 0; token[i] != '\0'; i++) {
            if (brk[(unsigned char)token[i]]) {
                ok = 0;
                break;
            }
        }
        if (ok) ans++;
        token = strtok(NULL, " ");  
    }

    return ans;
}

//1935