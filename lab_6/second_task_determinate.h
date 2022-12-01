#pragma once
#include "Header.h"
#include "Base_operation_matrix.h"
#include "scanf_write_matrix_1.h"



// �-��� �������� ������� � ������������ ����
void triangulation(vector<vector<double>>& Matrix, int size_matrix) {
	double multyply;
	for (int i = 0; i < size_matrix - 1; i++) {
		int imax = find_ind_max_elem_in_column(Matrix, i, size_matrix);
		if (i != imax) {
			swap(Matrix[i], Matrix[imax]);
		}
		for (int j = i + 1; j < size_matrix; j++) {
			multyply = -Matrix[j][i] / Matrix[i][i];
			for (int k = i; k < size_matrix; k++) {
				Matrix[j][k] += Matrix[i][k] * multyply;
			}
		}
		cout << i + 1 << " ��������" << '\n';
		write_matrix_console(Matrix);
		cout << '\n';
	}
}
 
// �-��� ������� ������������ ����������� �������
void determinate_triangulation_matrix(vector<vector<double>>& Matrix, int size_matrix) {
	double determinate = 1;
	for (int i = 0; i < size_matrix; i++) {
		determinate *= Matrix[i][i];
	}
	cout << "������������ ������� = " << determinate << '\n';
}