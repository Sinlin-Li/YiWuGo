#include <iostream>
#include <fstream>
#include <random>

int main() {
    // ʹ�� mt19937_64 �����������
    std::mt19937_64 rng;

    // ������������ӣ�����ʹ�õ�ǰʱ����Ϊ����
    rng.seed(std::random_device()());

    // ������ά����
    const int rows = 3;
    const int cols = 19;
    const int depth = 19;
    unsigned long long a[rows][cols][depth];

    // �����ά����
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            for (int k = 0; k < depth; ++k) {
                a[i][j][k] = rng(); // ������������������
            }
        }
    }

    // ������������ļ�
    std::ofstream outfile("output.txt");
    if (outfile.is_open()) {
        outfile << "const int ZOBRIST_CODE[3][19][19] = {\n";
        for (int i = 0; i < rows; ++i) {
            outfile << "    {\n";
            for (int j = 0; j < cols; ++j) {
                outfile << "        {";
                for (int k = 0; k < depth; ++k) {
                    outfile << a[i][j][k];
                    if (k < depth - 1) {
                        outfile << ", ";
                    }
                }
                outfile << "}";
                if (j < cols - 1) {
                    outfile << ",";
                }
                outfile << "\n";
            }
            outfile << "    }";
            if (i < rows - 1) {
                outfile << ",";
            }
            outfile << "\n";
        }
        outfile << "};\n";
        outfile.close();
        std::cout << "Array data written to output.txt.\n";
    }
    else {
        std::cerr << "Error opening output file!\n";
    }

    return 0;
}
