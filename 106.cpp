#include <iostream>
#include <vector>
using namespace std;

// Function to print matrix
void printMatrix(vector<vector<int>>& m, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << m[i][j] << "\t";
        cout << endl;
    }
}

// Function to verify magic square
bool verifyMagicSquare(vector<vector<int>>& m, int n) {
    int magicSum = 0;

    // Calculate magic sum using first row
    for (int j = 0; j < n; j++)
        magicSum += m[0][j];

    // Check rows
    for (int i = 0; i < n; i++) {
        int rowSum = 0;
        for (int j = 0; j < n; j++)
            rowSum += m[i][j];
        if (rowSum != magicSum) return false;
    }

    // Check columns
    for (int j = 0; j < n; j++) {
        int colSum = 0;
        for (int i = 0; i < n; i++)
            colSum += m[i][j];
        if (colSum != magicSum) return false;
    }

    // Check main diagonal
    int d1 = 0;
    for (int i = 0; i < n; i++)
        d1 += m[i][i];
    if (d1 != magicSum) return false;

    // Check secondary diagonal
    int d2 = 0;
    for (int i = 0; i < n; i++)
        d2 += m[i][n - 1 - i];
    if (d2 != magicSum) return false;

    return true;
}

// Construct magic square for odd n (Siamese method)
void oddMagicSquare(vector<vector<int>>& m, int n) {
    int i = 0, j = n / 2;

    for (int num = 1; num <= n * n; num++) {
        m[i][j] = num;
        int newi = (i - 1 + n) % n;
        int newj = (j + 1) % n;

        if (m[newi][newj] != 0) {
            i = (i + 1) % n;
        } else {
            i = newi;
            j = newj;
        }
    }
}

// Construct magic square for doubly-even n (n % 4 == 0)
void doublyEvenMagicSquare(vector<vector<int>>& m, int n) {
    int num = 1;

    // Fill matrix with natural numbers
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            m[i][j] = num++;

    // Invert values in specific positions
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {

            if ((i % 4 == j % 4) || ((i + j) % 4 == 3)) {
                m[i][j] = n * n + 1 - m[i][j];
            }
        }
    }
}

int main() {
    int n;
    cout << "Enter order of Magic Square (n): ";
    cin >> n;

    if (n < 3) {
        cout << "Magic square not possible for n < 3" << endl;
        return 0;
    }

    vector<vector<int>> m(n, vector<int>(n, 0));

    // Odd order
    if (n % 2 == 1) {
        oddMagicSquare(m, n);
    }
    // Doubly-even order
    else if (n % 4 == 0) {
        doublyEvenMagicSquare(m, n);
    }
    else {
        cout << "Magic square for singly-even order (like 6, 10, 14...) is complex and not included here." << endl;
        return 0;
    }

    cout << "\nMagic Square:\n";
    printMatrix(m, n);

    cout << "\nVerifying Magic Square...\n";

    if (verifyMagicSquare(m, n))
        cout << "Magic Square Verified Successfully!" << endl;
    else
        cout << "Error: This is NOT a magic square!" << endl;

    return 0;
}
