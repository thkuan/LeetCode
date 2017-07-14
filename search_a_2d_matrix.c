bool searchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target) {
    int row_index = 0, i = 0, result = 0;
    
    /* Search row head iteratively */
    for (i = 0; i < matrixRowSize; i++) {
        if (target > matrix[i][0]) {
            row_index = i;
        } else if (target == matrix[i][0]) {
            result = 1;
            break;
        }
    }
    
    /* Search each column of specified row iteratively */
    for (i = 0; i < matrixColSize; i++) {
        if (target == matrix[row_index][i]) {
            result = 1;
            break;
        } else if (target < matrix[row_index][i]) {
            /* Compared element excceeds target */
            result = 0;
            break;
        }
    }
    
    return result;
}
