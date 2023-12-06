#include <iostream>

template <class t>
class table {
private:
	class submas;
	t col;
	t row;
	submas* arr;
	class submas {
	public:
		t* subarr;
		submas() {}
		submas(t size) {
			subarr = new t[size]{};
		}
		t& operator [] (int i) {
			return subarr[i];
		}
		t& operator [] (int i) const {
			return subarr[i];
		}
	};
public:
	table(t rows, t cols) {
		rows < 1 ? row = 1 : row = rows;
		cols < 1 ? col = 1 : col = cols;
		arr = new submas[rows];
		for (int i = 0; i < row; ++i) {
			arr[i] = submas(col);
		}
	}
	submas& operator [] (int i) {
		return arr[i];
	}
	submas& operator [] (int i) const {
		return arr[i];
	}
	int size() {
		return row * col;
	}
	~table() {
		for (int i = 0; i < row; ++i) {
			if (arr[i].subarr != nullptr)
				delete[](arr[i].subarr);
		}
		if (arr != nullptr)
			delete[] arr;
	}
};
int main() {
	table<int> t(3,2);
	t[0][0] = 1;
    std::cout << t[0][0] << " ";

	t[0][0] = 5;
	std::cout << t[0][0] << "\n";
	std::cout << t.size();
}