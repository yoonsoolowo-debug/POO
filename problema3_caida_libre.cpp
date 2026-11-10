// Problema 3: Caída libre con energía cinética, potencial y graficación (Gnuplot)
// Compilar: g++ problema3_caida_libre.cpp -o problema3
#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
using namespace std;

class CaidaLibre {
private:
    double m;    // masa (kg)
    double h0;   // altura inicial (m)
    double v0;   // velocidad inicial (m/s), positiva hacia arriba
    const double g;

public:
    CaidaLibre(double masa, double alturaInicial, double velocidadInicial)
        : m(masa), h0(alturaInicial), v0(velocidadInicial), g(9.8) {}

    double posicion(double t) const { return h0 + v0 * t - 0.5 * g * t * t; }
    double velocidad(double t) const { return v0 - g * t; }

    double energiaCinetica(double t) const {
        double v = velocidad(t);
        return 0.5 * m * v * v;
    }

    double energiaPotencial(double t) const {
        return m * g * posicion(t);
    }

    // Tiempo en que el objeto llega al suelo (y = 0)
    double tiempoCaida() const {
        return (v0 + sqrt(v0 * v0 + 2 * g * h0)) / g;
    }

    // Guarda t, Ec, Ep, E total en energias.dat y grafica con Gnuplot
    void graficarEnergias(int pasos = 200) const {
        double tf = tiempoCaida();
        double dt = tf / pasos;
        ofstream datos("energias.dat");
        for (int i = 0; i <= pasos; i++) {
            double t = i * dt;
            double ec = energiaCinetica(t);
            double ep = energiaPotencial(t);
            datos << t << " " << ec << " " << ep << " " << ec + ep << "\n";
        }
        datos.close();

        ofstream script("energias.gp");
        script << "set title 'Energias en caida libre'\n"
               << "set xlabel 't (s)'\n"
               << "set ylabel 'Energia (J)'\n"
               << "set grid\n"
               << "plot 'energias.dat' using 1:2 with lines title 'Ec', "
               << "'' using 1:3 with lines title 'Ep', "
               << "'' using 1:4 with lines title 'E total'\n";
        script.close();

        system("gnuplot -persist energias.gp");
    }
};

int main() {
    double m, h0, v0;
    cout << "Masa (kg): ";
    cin >> m;
    cout << "Altura inicial (m): ";
    cin >> h0;
    cout << "Velocidad inicial (m/s, positiva hacia arriba): ";
    cin >> v0;

    CaidaLibre objeto(m, h0, v0);
    cout << "Tiempo de caida: " << objeto.tiempoCaida() << " s" << endl;
    cout << "Ec en t=0: " << objeto.energiaCinetica(0) << " J" << endl;
    cout << "Ep en t=0: " << objeto.energiaPotencial(0) << " J" << endl;
    objeto.graficarEnergias();
    return 0;
}
