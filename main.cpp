#include <iostream>
#include <vector>

int main() {
    int n;
    std::cout << "Digite o tamanho do lado da caixa espiral: ";
    std::cin >> n;

    std::vector<std::vector<int>> matrix(n, std::vector<int>(n, 0));

    int value = 0;
    int rowStart = 0, rowEnd = n - 1;
    int colStart = 0, colEnd = n - 1;

    while (value < n*n) {
        for (int i = colStart; i <= colEnd; i++) {
            matrix[rowStart][i] = ++value;
        }

        for (int i = rowStart + 1; i <= rowEnd; i++) {
            matrix[i][colEnd] = ++value;
        }

        for (int i = colEnd - 1; i >= colStart; i--) {
            matrix[rowEnd][i] = ++value;
        }

        for (int i = rowEnd - 1; i > rowStart; i--) {
            matrix[i][colStart] = ++value;
        }

        rowStart++;
        rowEnd--;
        colStart++;
        colEnd--;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << matrix[i][j] << "\t";
        }
        std::cout << std::endl;
    }

    return 0;
}
