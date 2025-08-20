// LeetCode 54

int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize){
    if (matrixSize == 0) {
        *returnSize = 0;
        return NULL;
    }

    int row_begin = 0, row_end = matrixSize - 1;
    int col_begin = 0, col_end = matrixColSize[0] - 1;
    int* ans = (int*)malloc(sizeof(int) * (matrixSize * matrixColSize[0]));
    *returnSize = 0;

    while (row_begin <= row_end && col_begin <= col_end) {
        for (int i = col_begin; i <= col_end; ++i) {
            ans[(*returnSize)++] = matrix[row_begin][i];
        }
        ++row_begin;

        for (int i = row_begin; i <= row_end; ++i) {
            ans[(*returnSize)++] = matrix[i][col_end];
        }
        --col_end;

        if (row_begin <= row_end) {  
            for (int i = col_end; i >= col_begin; --i) {
                ans[(*returnSize)++] = matrix[row_end][i];
            }
            --row_end;
        }

        if (col_begin <= col_end) {  
            for (int i = row_end; i >= row_begin; --i) {
                ans[(*returnSize)++] = matrix[i][col_begin];
            }
            ++col_begin;
        }
    }
    return ans;
}


