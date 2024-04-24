// to identify the no of groups in sparse matrix//
#include <stdio.h>
#define ROWS 5
#define COLS 5

int matrix[ROWS][COLS] = {
    {1,1,1,0,0},
    {1,1,1,0,0},
    {0,0,0,0,0},
    {0,0,0,2,2},
    {1,1,0,2,2}
};

int a[ROWS][COLS];

void mark_group(int row, int col, int group) {
    if (a[row][col] || matrix[row][col] == 0) {
        return;
    }
    a[row][col] = group;
    if (row > 0) {
        mark_group(row-1, col, group);
    }
    if (row < ROWS-1) {
        mark_group(row+1, col, group);
    }
    if (col > 0) {
        mark_group(row, col-1, group);
    }
 if (col < COLS-1) {
        mark_group(row, col+1, group);
    }
}

int main() {
    int group_count = 0;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (a[i][j] == 0 && matrix[i][j] == 1) {
                group_count++;
                mark_group(i, j, group_count);
            }
        }
    }
    printf("Number of groups: %d\n", group_count);
return 0;
}