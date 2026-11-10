Algoritmo VectorPropio
    Definir A, v, w, lambda, tol Como Real
    Definir i, j, ref Como Entero
    Definir esPropio Como Logico
    Dimension A[3,3], v[3], w[3]
    tol <- 0.000001
    Para i <- 1 Hasta 3
        Para j <- 1 Hasta 3
            Escribir "A[",i,",",j,"]: "
            Leer A[i,j]
        FinPara
    FinPara
    Para i <- 1 Hasta 3
        Escribir "v[",i,"]: "
        Leer v[i]
    FinPara
    // w = A*v
    Para i <- 1 Hasta 3
        w[i] <- 0
        Para j <- 1 Hasta 3
            w[i] <- w[i] + A[i,j]*v[j]
        FinPara
    FinPara
    // primera componente no nula de v
    ref <- 0
    Para i <- 1 Hasta 3
        Si ref = 0 Y abs(v[i]) > tol Entonces
            ref <- i
        FinSi
    FinPara
    Si ref = 0 Entonces
        Escribir "El vector nulo no es vector propio"
    SiNo
        lambda <- w[ref]/v[ref]
        esPropio <- Verdadero
        Para i <- 1 Hasta 3
            Si abs(w[i] - lambda*v[i]) > tol Entonces
                esPropio <- Falso
            FinSi
        FinPara
        Si esPropio Entonces
            Escribir "Es vector propio, lambda = ", lambda
        SiNo
            Escribir "No es vector propio"
        FinSi
    FinSi
FinAlgoritmo