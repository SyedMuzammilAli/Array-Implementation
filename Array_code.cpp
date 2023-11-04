#include <iostream>
#include <vector>

class SparseMatrix {
private:
    int rows, cols;
    std::vector<int> row;
    std::vector<int> col;
    std::vector<int> value;

public:
    SparseMatrix(int r, int c) : rows(r), cols(c) {
        // Initialize the sparse matrix with zeros
        row.clear();
        col.clear();
        value.clear();
    }

    void set(int r, int c, int v) {
        if (r < 0 || r >= rows || c < 0 || c >= cols) {
            std::cout << "Invalid row or column index." << std::endl;
            return;
        }

        // Check if the value is non-zero, and store it
        if (v != 0) {
            row.push_back(r);
            col.push_back(c);
            value.push_back(v);
        }
    }

    int get(int r, int c) {
        for (int i = 0; i < row.size(); i++) {
            if (row[i] == r && col[i] == c) {
                return value[i];
            }
        }
        return 0; // Return 0 for zero elements
    }
};

int main() {
    SparseMatrix matrix(3, 3);

    matrix.set(0, 0, 1);
    matrix.set(0, 1, 0);
    matrix.set(0, 2, 0);
    matrix.set(1, 0, 0);
    matrix.set(1, 1, 2);
    matrix.set(1, 2, 0);
    matrix.set(2, 0, 0);
    matrix.set(2, 1, 0);
    matrix.set(2, 2, 3);

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << matrix.get(i, j) << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
