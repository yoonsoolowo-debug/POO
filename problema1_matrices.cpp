// Problema 1: Matrices 3x3
// Compilar: g++ problema1_matrices.cpp -o problema1
#include <iostream>
#include <cmath>
using namespace std;

const int N = 3;
typedef double Mat[N][N];

void leerMatriz(Mat M, const char* nombre) {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            cout << nombre << "[" << i + 1 << "][" << j + 1 << "]: ";
            cin >> M[i][j];
        }
}

void imprimirMatriz(Mat M, const char* nombre) {
    cout << nombre << " =" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << M[i][j] << "\t";
        cout << endl;
    }
}

// C = A + B
void sumar(Mat A, Mat B, Mat C) {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            C[i][j] = A[i][j] + B[i][j];
}

// D = A * B
void multiplicar(Mat A, Mat B, Mat D) {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            D[i][j] = 0;
            for (int k = 0; k < N; k++)
                D[i][j] += A[i][k] * B[k][j];
        }
}

// Verifica si A*v = lambda*v. Devuelve true y guarda lambda si es vector propio.
bool esVectorPropio(Mat A, double v[N], double &lambda) {
    const double tol = 1e-6;
    double w[N];
    for (int i = 0; i < N; i++) {
        w[i] = 0;
        for (int j = 0; j < N; j++)
            w[i] += A[i][j] * v[j];
    }
    int ref = -1;
    for (int i = 0; i < N; i++)
        if (fabs(v[i]) > tol) { ref = i; break; }
    if (ref == -1) return false;  // vector nulo
    lambda = w[ref] / v[ref];
    for (int i = 0; i < N; i++)
        if (fabs(w[i] - lambda * v[i]) > tol) return false;
    return true;
}

int main() {
    Mat A, B, C, D;
    cout << "Matriz A:" << endl;
    leerMatriz(A, "A");
    cout << "Matriz B:" << endl;
    leerMatriz(B, "B");

    sumar(A, B, C);
    imprimirMatriz(C, "C = A + B");

    multiplicar(A, B, D);
    imprimirMatriz(D, "D = A * B");

    double v[N], lambda;
    cout << "Vector columna v:" << endl;
    for (int i = 0; i < N; i++) {
        cout << "v[" << i + 1 << "]: ";
        cin >> v[i];
    }
    if (esVectorPropio(A, v, lambda))
        cout << "v es vector propio de A, lambda = " << lambda << endl;
    else
        cout << "v NO es vector propio de A" << endl;
    return 0;
}
