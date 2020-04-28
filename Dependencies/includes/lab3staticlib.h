#pragma once
#include <fstream>

namespace Lab3 {
	class ReadWrite {
	public:
		static int** readMatrix(std::fstream& infile, int rows, int cols);

		static int writeMatrix(std::fstream& outstream, int** A, int rows, int cols);
	};

	class MatrixOperations {
	public:
		static int** mergeRows(int** A, int** B, int rows, int col1, int col2);

		static int** mergeByAlternatingColumns(int** A, int** B, int rows, int cols1, int cols2);
	};
}