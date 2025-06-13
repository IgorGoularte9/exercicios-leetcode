int evalRPN(char** tokens, int tokensSize) {
    int pilha[100];
    int top = -1;

      for (int i = 0; i < tokensSize; i++) {
        char* t = tokens[i];
        if(strcmp(t, "+") == 0){
            pilha[top - 1] += pilha[top];
            top--;
        }else if(strcmp(t,"-") == 0){
            pilha[top - 1] -= pilha[top];
            top--;
        }else if(strcmp(t, "*") == 0){
            pilha[top - 1] *= pilha[top];
        }else if(strcmp(t, "/") == 0){
            pilha[top -1 ] /= pilha[top];
            top--;
        }else{
            pilha[++top] = atoi(t);
        }
        }
             return pilha[0];

        }
