char* longestDiverseString(int a, int b, int c) {
    typedef struct {
        char letra;
        int qtd;
    } Letra;

    Letra letras[3] = { {'a', a}, {'b', b}, {'c', c} };
    char* res = malloc(1000);
    int i = 0;

    while (1) {
        
        for (int x = 0; x < 2; x++) {
            for (int y = x + 1; y < 3; y++) {
                if (letras[y].qtd > letras[x].qtd) {
                    Letra temp = letras[x];
                    letras[x] = letras[y];
                    letras[y] = temp;
                }
            }
        }

        int colocou = 0;

        for (int j = 0; j < 3; j++) {
            if (letras[j].qtd == 0) continue;


            if (i >= 2 && res[i-1] == letras[j].letra && res[i-2] == letras[j].letra) {
                continue;
            }

            res[i++] = letras[j].letra;
            letras[j].qtd--;
            colocou = 1;
            break;
        }

        if (!colocou) break;
    }

    res[i] = '\0';
    return res;
}
