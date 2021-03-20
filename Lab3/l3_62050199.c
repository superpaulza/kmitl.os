#include<stdio.h>

int m_a [2][3] = { {1,2,3}, {4,5,6} };
int m_b [3][2] = { {6,3}, {5,2}, {4,1} } ;
int m_c [2][2] = { {0,0}, {0,0} };
int m = 2;
int n = 2;
int p = 3;

void row_by_col(int r, int c) {
	int k = 0;
	for(k = 0; k < p; k++) {
		m_c[r][c] += m_a[r][k] * m_b[k][c];
	}
}
int main() {
	int row = 0, col = 0;
	for(row = 0; row < m; row++) {
		for (col = 0; col < n; col++) {
			row_by_col(row,col);
			printf("%d ", m_c[row][col]);
		}
		printf("\n");
	}
	return 0;
}
