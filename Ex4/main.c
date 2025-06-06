int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize) {
    int* stack = (int*)malloc(sizeof(int) * temperaturesSize);
    int top = -1;
    int* answer = (int*)malloc(sizeof(int) * temperaturesSize);

    for (int i = temperaturesSize - 1; i >= 0; i--) {
        while (top != -1 && temperatures[stack[top]] <= temperatures[i]) {
            top--;
        }
        answer[i] = (top == -1) ? 0 : (stack[top] - i);
        stack[++top] = i;
    }

    *returnSize = temperaturesSize;
    free(stack);
    return answer;
}
