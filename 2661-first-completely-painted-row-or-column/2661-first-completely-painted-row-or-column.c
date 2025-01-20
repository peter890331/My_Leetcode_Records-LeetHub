int firstCompleteIndex(int* arr, int arrSize, int** mat, int matSize, int* matColSize) {
    int max_val = 0;
    for (int row=0; row<matSize; row++) {
        for (int col=0; col<*matColSize; col++) {
            if (mat[row][col] > max_val) {
                max_val = mat[row][col];
            }
        }
    }

    int* row_map = (int*)calloc(max_val+1, sizeof(int));
    int* col_map = (int*)calloc(max_val+1, sizeof(int));
    int* row_sum = (int*)calloc(matSize, sizeof(int));
    int* col_sum = (int*)calloc(*matColSize, sizeof(int));
    
    for (int row=0; row<matSize; row++){
        for (int col=0; col<*matColSize; col++){
            row_map[mat[row][col]] = row;
            col_map[mat[row][col]] = col;
        }
    }

    for (int index=0; index<arrSize; index++){
        int val = arr[index];
        row_sum[row_map[val]] ++;
        if (row_sum[row_map[val]] == *matColSize){
            free(row_sum);
            free(col_sum);
            return index;
        }
        col_sum[col_map[val]] ++;
        if (col_sum[col_map[val]] == matSize){
            free(row_sum);
            free(col_sum);
            return index;
        }
    }

    free(row_sum);
    free(col_sum);
    return -1;

}

// Reference from Sumeet Sharma's solution.