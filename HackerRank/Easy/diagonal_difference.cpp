/*
 * Complete the 'diagonalDifference' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts 2D_INTEGER_ARRAY arr as parameter.
 */

int diagonalDifference(vector<vector<int>> arr) {
    int n = arr.size();
    int row = 0;
    int col = 0;   
    int sum_1 = 0;

    while (row < n) {
        sum_1 += arr[row][col];
        row++;
        col++;
    }

    row = 0;
    col = n - 1;
    int sum_2 = 0;

    while (row < n) {
        sum_2 += arr[row][col];
        row++;
        col--;
    }

    int sol = abs(sum_1 - sum_2);

    return sol;
}