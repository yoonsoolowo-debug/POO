// Problema 2: Álgebra cuántica (producto punto, transpuesta, (A+)* = A^T, normalización)
// Compilar: g++ problema2_algebra_cuantica.cpp -o problema2
// Para trabajar con reales, deja la parte imaginaria en 0.
#include <iostream>
#include <vector>
#include <complex>
#include <cmath>
using namespace std;

typedef complex<double> cd;
typedef vector<vector<cd> > MatC;

cd leerComplejo(const string& nombre) {
    double re, im;
    cout << nombre << " (parte real e imaginaria): ";
    cin >> re >> im;
    return cd(re, im);
}

// <u|v> = suma de conj(u_k) * v_k
cd productoPunto(const vector<cd>& u, const vector<cd>& v) {
    cd suma(0, 0);
    for (size_t k = 0; k < u.size(); k++)
        suma += conj(u[k]) * v[k];
    return suma;
}

// A^T
MatC transpuesta(const MatC& A) {
    int n = A.size();
    MatC T(n, vector<cd>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            T[j][i] = A[i][j];
    return T;
}

// Conjugar cada elemento
MatC conjugar(const MatC& A) {
    int n = A.size();
    MatC C(n, vector<cd>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = conj(A[i][j]);
    return C;
}

// A+ = (A^T)*
MatC adjunta(const MatC& A) {
    return conjugar(transpuesta(A));
}

bool iguales(const MatC& A, const MatC& B) {
    const double tol = 1e-6;
    for (size_t i = 0; i < A.size(); i++)
        for (size_t j = 0; j < A.size(); j++)
            if (abs(A[i][j] - B[i][j]) > tol) return false;
    return true;
}

bool normalizar(vector<cd>& v) {
    double norma = sqrt(real(productoPunto(v, v)));
    if (norma < 1e-6) return false;
    for (size_t k = 0; k < v.size(); k++)
        v[k] /= norma;
    return true;
}

int main() {
    // 1. Producto punto
    const int M = 4;
    vector<cd> u(M), v(M);
    for (int k = 0; k < M; k++) u[k] = leerComplejo("u[" + to_string(k + 1) + "]");
    for (int k = 0; k < M; k++) v[k] = leerComplejo("v[" + to_string(k + 1) + "]");
    cd p = productoPunto(u, v);
    cout << "<u|v> = " << real(p) << " + " << imag(p) << "i" << endl;

    // 2. Verificar (A+)* = A^T
    const int N = 3;
    MatC A(N, vector<cd>(N));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            A[i][j] = leerComplejo("A[" + to_string(i + 1) + "][" + to_string(j + 1) + "]");

    MatC lado1 = conjugar(adjunta(A));  // (A+)*
    MatC lado2 = transpuesta(A);        // A^T
    if (iguales(lado1, lado2))
        cout << "Se cumple (A+)* = A^T" << endl;
    else
        cout << "No se cumple" << endl;

    // 3. Normalizar vector de 4 componentes
    vector<cd> w(M);
    for (int k = 0; k < M; k++) w[k] = leerComplejo("w[" + to_string(k + 1) + "]");
    if (normalizar(w)) {
        for (int k = 0; k < M; k++)
            cout << "w[" << k + 1 << "] = " << real(w[k]) << " + " << imag(w[k]) << "i" << endl;
        cout << "Norma comprobada = " << sqrt(real(productoPunto(w, w))) << endl;
    } else {
        cout << "Vector nulo, no se puede normalizar" << endl;
    }
    return 0;
}
