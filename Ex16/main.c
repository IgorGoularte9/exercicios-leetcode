bool isSumEqual(char* firstWord, char* secondWord, char* targetWord) {
    auto int getVal(char* s) {
        int val = 0;
        for (int i = 0; s[i] != '\0'; i++) {
            val = val * 10 + (s[i] - 'a');
        }
        return val;
    }

    return getVal(firstWord) + getVal(secondWord) == getVal(targetWord);
}


// exercicio 1880