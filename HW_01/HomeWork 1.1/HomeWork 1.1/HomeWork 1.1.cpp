#include <iostream>
#include <fstream>

std::ifstream fin("in.txt");
std::ofstream fout("out.txt");

void array_size(int &x) {
	if (fin.is_open() == true) {
		fin >> x;
	}
	else {
		std::cout << "Файл in.txt не найден";
	}
}

int* array_body(int &x) {
	int* array = new int[x];

	for (int i = 0; i < x; ++i) {
		if (fin.eof() == false) {
			fin >> array[i];
		}
		else {
			break;
		}
	}

	return array;
}

void write_to_file(int* array, int size) {
	fout << size << "\n";

	for (int i = 0; i < size; ++i) {
		fout << array[i] << " ";
	}

	fout << "\n";
}
int main()
{
	int n;
	int m;
	
	array_size(n);
	int* array = array_body(n);
	array_size(m);
	int* array2 = array_body(m);

	for (int i = 0; i < n; ++i) {
		if (i == n - 1) {
			break;
		}
		else {
			std::swap(array[i], array[i + 1]);
		}
	}

	for (int i = m - 1; i > 0; --i) {
		if (i == 0) {
			break;
		}
		else {
			std::swap(array2[i], array2[i - 1]);
		}
	}

	write_to_file(array2, m);
	write_to_file(array, n);

	delete[] array;
	delete[] array2;

	fin.close();
	fout.close();

	return 0;
}

