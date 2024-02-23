#pragma once
#include <iostream>
#include <vector>
using namespace std;

class DSA {
public:
    void Matrix() {
        int r, c;

        cout << "Enter the number of rows=";
        cin >> r;
        cout << "Enter the number of columns =";
        cin >> c;

        vector<vector<int>> a(r, vector<int>(c));
        vector<vector<int>> b(r, vector<int>(c));
        vector<vector<int>> add(r, vector<int>(c));
        vector<vector<int>> sub(r, vector<int>(c));
        vector<vector<int>> mul(r, vector<int>(c));
        vector<vector<int>> div(r, vector<int>(c));

        cout << "Enter the first matrix elements =\n";
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> a[i][j];
            }
        }

        cout << "Enter the second matrix elements =\n";
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> b[i][j];
            }
        }

        // Addition
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                add[i][j] = a[i][j] + b[i][j];
            }
        }

        cout << "Matrix Addition =\n";
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cout << add[i][j] << " ";
            }
            cout << "\n";
        }

        // Subtraction
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                sub[i][j] = a[i][j] - b[i][j];
            }
        }

        cout << "Matrix Subtraction =\n";
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cout << sub[i][j] << " ";
            }
            cout << "\n";
        }

        // Multiplication
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                mul[i][j] = 0;
                for (int k = 0; k < c; k++) {
                    mul[i][j] += a[i][k] * b[k][j];
                }
            }
        }

        cout << "Matrix Multiplication =\n";
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cout << mul[i][j] << " ";
            }
            cout << "\n";
        }

        // Division
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                div[i][j] = 0;
                if (b[i][j] != 0) {
                    div[i][j] = a[i][j] / b[i][j];
                }
            }
        }

        cout << "Matrix Division =\n";
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cout << div[i][j] << " ";
            }
            cout << "\n";
        }
    }
};
