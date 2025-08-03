 struct TreeNode* balanceBST(struct TreeNode* raiz) {
    struct TreeNode* nos[1000]; 
    int indice = 0;
    percursoEmOrdem(raiz, nos, &indice);
    return construirArvoreBalanceada(nos, 0, indice - 1);
}

void percursoEmOrdem(struct TreeNode* raiz, struct TreeNode** nos, int* indice) {
    if (raiz == NULL) {
        return;
    }
    percursoEmOrdem(raiz->left, nos, indice);
    nos[(*indice)++] = raiz; 
    percursoEmOrdem(raiz->right, nos, indice);
}

struct TreeNode* construirArvoreBalanceada(struct TreeNode** nos, int ini, int fim) {
    if (ini > fim) {
        return NULL;
    }
    int meio = ini + (fim - ini) / 2;
    struct TreeNode* raiz = nos[meio];
    raiz->left = construirArvoreBalanceada(nos, ini, meio - 1); 
    raiz->right = construirArvoreBalanceada(nos, meio + 1, fim); 
    return raiz;
}


