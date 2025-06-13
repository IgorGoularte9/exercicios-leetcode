char* decodeString(char* s) {
    char* strin[100];
    int numpil[100];
    int strintop = -1, numtop = -1;

    char* currStr = (char*)malloc(1000);
    currStr[0] = '\0';

    int i = 0;
    while (s[i]) {
        if (s[i] >= '0' && s[i] <= '9') {
            
            int num = 0;
            while (s[i] >= '0' && s[i] <= '9') {
                num = num * 10 + (s[i] - '0');
                i++;
            }
            numpil[++numtop] = num;
}
