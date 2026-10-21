#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

const double m = 12.0;    // kg
const double k = 0.125;   // N s^2/m^2
const double g = 9.8;     // m/s^2

// dv/dt = g - (k/m) v^2
double f(double v) {
    return g - (k / m) * v * v;
}

void rk2(double h, double t_final) {
    double v = 0.0, t = 0.0;
    int pasos = static_cast<int>(round(t_final / h));

    cout << "\n=== Runge-Kutta 2do orden, h = " << h << " ===\n";
    cout << fixed << setprecision(4);
    cout << setw(4) << "n" << setw(8) << "t" << setw(12) << "v"
         << setw(12) << "k1" << setw(12) << "k2" << "\n";

    for (int n = 0; n < pasos; n++) {
        double k1 = f(v);
        double k2 = f(v + 0.75 * k1 * h);
        cout << setw(4) << n << setw(8) << t << setw(12) << v
             << setw(12) << k1 << setw(12) << k2 << "\n";
        v += h * (k1 / 3.0 + 2.0 * k2 / 3.0);
        t += h;
    }
    cout << setw(4) << pasos << setw(8) << t << setw(12) << v << "\n";
    cout << "v(" << t_final << ") = " << v << " m/s\n";
}

int main() {
    rk2(1.0, 6.0);
    rk2(0.5, 6.0);
    cout << "\nVelocidad terminal = " << sqrt(m * g / k) << " m/s\n";
    return 0;
}
