#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include "lab3staticlib.h"

const std::string INPUT_FILENAME = "input.txt";
const std::string OUTPUT_FILENAME = "output.txt";

int main() {

	std::fstream instream;
	instream.open(INPUT_FILENAME, std::ios::in);

	// check for errors and output them in stderr
	if (!instream.good()) {
		std::cerr << "Error occured when opening " << INPUT_FILENAME
			<< std::strerror(errno) << std::endl;
	}

	int n1, m1, n2, m2 = 0;

	instream >> n1 >> m1 >> n2 >> m2;

	int** A = nullptr;
	int** B = nullptr;

	A = Lab3::ReadWrite::readMatrix(instream, n1, m1);
	instream.flush();
	B = Lab3::ReadWrite::readMatrix(instream, n2, m2);

	instream.close();

	int** C = nullptr;

	std::fstream outstream;
	outstream.open(OUTPUT_FILENAME, std::ios::out);
	if (!outstream.good()) {
		std::cerr << "Error occured when trying to write to " << OUTPUT_FILENAME
			<< std::strerror(errno) << std::endl;
	}

	int n3, m3 = 0;

	if (n1 == n2) {
		n3 = n1; m3 = m1 + m2;
		outstream << n3 << ' ' << m3 << std::endl;

		C = Lab3::MatrixOperations::mergeRows(A, B, n1, m1, m2);
		Lab3::ReadWrite::writeMatrix(outstream, C, n3, m3);

		C = nullptr;

		outstream << n3 << ' ' << m3 << std::endl;
		C = Lab3::MatrixOperations::mergeByAlternatingColumns(A, B, n1, m1, m2);
		Lab3::ReadWrite::writeMatrix(outstream, C, n3, m3);

		for (int i = 0; i < n3; i++)
			delete[] C[i];
		delete[] C;
	}
	else {
		outstream << "The number of rows in the first and the second input matrices are not equal!" << std::endl;
	}
	outstream.close();
	for (int i = 0; i < n1; i++)
		delete[] A[i];
	delete[] A;

	for (int i = 0; i < n2; i++)
		delete[] B[i];
	delete[] B;

	return 0;
}