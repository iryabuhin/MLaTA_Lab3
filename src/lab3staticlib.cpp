#include "lab3staticlib.h"

namespace Lab3 {

	int** ReadWrite::readMatrix (std::fstream& infile, int rows, int cols)
	{
		int** C = new int* [rows];

		for (int i = 0; i < rows; i++) {
			C[i] = new int[cols];
			for (int j = 0; j < cols; j++) {
				infile >> C[i][j];
			}
		}

		return C;
	}

	int ReadWrite::writeMatrix (std::fstream& outstream, int** A, int rows, int cols)
	{
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				outstream << A[i][j] << ' ';
			}
			outstream << std::endl;
		}
		return 1;
	}


	int** MatrixOperations::mergeRows (int** A, int** B, int rows, int col1, int col2) {
		int newlen = col1 + col2;
		int** result = new int* [rows];
		for (int i = 0; i < rows; i++)
			result[i] = new int[newlen];

		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < col1; j++) {
				result[i][j] = A[i][j];
			}
			for (int j = 0; j < col2; j++) {
				result[i][j + col1] = B[i][j];
			}
		}

		return result;
	}

	int** MatrixOperations::mergeByAlternatingColumns(int** A, int** B, int rows, int cols1, int cols2) {
		int newlen = cols1 + cols2;
		int** result = new int* [rows];

		for (int i = 0; i < rows; i++) {
			result[i] = new int[newlen];
			for (int j = 0; j < newlen; j++) {
				if (j % 2) {
					result[i][j] = B[i][static_cast<int>(j / 2.0)];
				}
				else {
					result[i][j] = A[i][static_cast<int>(j / 2.0)];
				}
			}
		}

		if (cols1 != cols2) {
			int max_cols = cols1 > cols2 ? cols1 : cols2;
			int min_cols = newlen - max_cols;


			for (int i = 0; i < rows; i++) {
				for (int j = min_cols; j < max_cols; j++) {
					if (max_cols == cols1)
						result[i][j + min_cols] = A[i][j];
					else
						result[i][j + min_cols] = B[i][j];
				}
			}
		}

		return result;
	}
}

