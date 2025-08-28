char * maximumNumber(char * num, int* change, int changeSize){
    int n = strlen(num);
    bool changed = false;
    for (int i = 0; i < n; ++i) {
        char d = '0' + change[num[i] - '0'];
        if (changed && d < num[i]) {
            break;
        }
        if (d > num[i]) {
            changed = true;
            num[i] = d;
        }
    }
    return num;
}


// leetcode 1946