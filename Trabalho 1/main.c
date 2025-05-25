char* longestNiceSubstring(char* s) {
    int comprimento = strlen(s);
    int comprimaximo = 0, inicia = 0;

    for (int i = 0; i < comprimento; i++) {
        for (int j = i; j < comprimento; j++) {
            int maiuscula[26] = {0};
            int minuscula[26] = {0};
        
            for (int k = i; k <= j; k++) {
                char c = s[k];
                
                if (c >= 'A' && c <= 'Z')
                    maiuscula[c - 'A'] = 1;
                else if (c >= 'a' && c <= 'z')
                    minuscula[c - 'a'] = 1;
            }

            int boa = 1;
            for (int l = 0; l < 26; l++) {
                if (maiuscula[l] != minuscula[l]) {
                    boa = 0;
                    break;
                }
            }

            if (boa && (j - i + 1) > comprimaximo) {
                comprimaximo = (j - i) + 1;
                inicia = i;
            }
        }
    }

    char* resposta = (char*)malloc((comprimaximo + 1) * sizeof(char));
    strncpy(resposta, s + inicia, comprimaximo);
    resposta[comprimaximo] = '\0';
    return resposta;
}
