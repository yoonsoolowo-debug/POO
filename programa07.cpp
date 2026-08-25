// sudo apt get install gnuplot  
/*  
Se realiza una gráfica con el programa Gnuplot.  
Gnuplot es un programa informático de interfaz de línea de comandos para generar gráficas.   
Se una la función fprintf() que escribe en un archivo externo.  
*/  
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main() {  
    double valoresX[11] = {0.0, 1.0, 1.0, 1.5, 2.0, 2.5, 3.0, 3.5, 4.0, 4.5, 5.0};  
    double valoresY[11] = {0.0, 4.0, 0.0, 1.0, 0.0, 1.5, 0.0, 1.0, 0.0, 0.5, 0.0};  
    int i;  
  
// 1. Crear archivo de datos  
// El método fopen() abre un archivo en modo escritura "w".  
// fprintf() escribe los datos en el archivo de salida.   
    ofstream archivoPuntos("Puntos-A-graficar.txt");

    for (i = 0; i < 11; i++) {  
        archivoPuntos << valoresX[i] << " " << valoresY[i] << endl;
    }

    archivoPuntos.close();

// Se cierra el archivo con fclose().      
//  
// 2. Abrir canal a Gnuplot.  
// La función popen() abre un proceso ejecutando un comando en el shell o intérprete de órdenes.  
// Abre una tubería, pipe, para ejecutar gnuplot.  
    FILE *gnuplot = popen("gnuplot -persist", "w");  
//     
    if (gnuplot == NULL) {  
        cerr << "No se pudo ejecutar gnuplot" << endl;
        return 1;  
    }  
//  
    // 3. Enviar comandos de configuración  
    fprintf(gnuplot, "set title \"Grafica líneas entre puntos\"\n");
    fprintf(gnuplot, "set grid\"\n"); 
    fprintf(gnuplot, "set xlabel \"Valores de X\"\n");  
    fprintf(gnuplot, "set ylabel \"Valores de Y\"\n");  
      
    // Graficar usando la primera y segunda columna  
    fprintf(gnuplot, "plot \"Puntos-A-graficar.txt\" using 1:2 with linespoints pt 6 ps 1 lc rgb 'blue'   \n");  
// linespoints      
    pclose(gnuplot);  

    return 0;
}
