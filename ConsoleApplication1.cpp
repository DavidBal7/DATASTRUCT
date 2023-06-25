#include <iostream>
using namespace std;
/*int main() {
    int vector[] = { 5, 10, 15, 20, 25, 30, 35, 40 }; 
    // Tamaño del vector
    int n = 8; 
    int suma = 0;

    for (int i = 0; i < n; i++) {
        suma += vector[i];
    }

    cout << "La suma de todos los elementos del vector es: " << suma << endl;

    return 0;
}*/
/*#include <iostream>
using namespace std;

int main() {
    int vector[] = { 5, 10, 15, 20, 25, 30, 35, 40 }; 
    //tamaño del vector
    int n = 8; 
    int suma = 0;

    cout << "Los numeros pares del vector son: ";

    for (int i = 0; i < n; i++) {
        //al dividir el numero por 2 el residuo es 0 entonces es par
        if (vector[i] % 2 == 0) { 
            //hacemos la suma de todos los elementos pares
            suma += vector[i]; 
            //enviamos a consola los numeros pares
            cout << vector[i] << " "; 
            
        }
    }

    cout << "\nLa suma de todos los elementos pares del vector es: " << suma << endl;

    return 0;
}*/


/*#include <iostream>
using namespace std;

int main() {
    int vector[] = { 5, 10, 15, 20, 25, 30, 35, 40 }; 
    //tamaño del vector
    int n = 8; 
    //enviamos a consola el vector original
    cout << "El vector original es: ";
    for (int i = 0; i < n; i++) {
        cout << vector[i] << " ";
    }
    cout << endl;

   // invertimos el vector ayudandonos de una variable temporal
    for (int i = 0; i < n / 2; i++) {
        int temp = vector[i];
        vector[i] = vector[n - i - 1];
        vector[n - i - 1] = temp;
    }
    //enviamos a consola el vector invertido
    cout << "El vector invertido es: ";
    for (int i = 0; i < n; i++) {
        cout << vector[i] << " ";
    }
    cout << endl;

    return 0;
}*/

/*#include <iostream>

using namespace std;

int main() {
    const int n = 8;

    int matriz[n][n];

    //creamos la matriz identidad
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                //si la posicion en columna y fila es la misma entonces ponemos un 1
                matriz[i][j] = 1;
            }
            //si la posicion en columna y fila es diferente entonces ponemos un 0
            else {
                matriz[i][j] = 0;
            }
        }
    }

    //mostramos en consola la matriz identidad
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
#include <iostream>

using namespace std;

int main() {
    const int n = 5;  // Tamaño de los vectores

    int vector1[n] = { 1, 2, 3, 4, 5 };
    int vector2[n] = { 10, 20, 30, 40, 50 };
    int resultado[n];

    // Suma de los vectores
    for (int i = 0; i < n; i++) {
        resultado[i] = vector1[i] + vector2[i];
    }

    // Impresión del resultado
    cout << "La suma de los vectores es:" << endl;
    for (int i = 0; i < n; i++) {
        cout << resultado[i] << " ";
    }
    cout << endl;

    return 0;
}
#include <iostream>

using namespace std;

void generarTrianguloPascal(int altura) {
    int triangulo[altura][altura];

    // Inicializar la primera columna con unos
    int i = 0;
    while (i < altura) {
        triangulo[i][0] = 1;
        i++;
    }

    // Generar el Triángulo de Pascal
    i = 1;
    while (i < altura) {
        int j = 1;
        while (j <= i) {
            triangulo[i][j] = triangulo[i - 1][j - 1] + triangulo[i - 1][j];
            j++;
        }
        i++;
    }

    // Imprimir el Triángulo de Pascal
    i = 0;
    while (i < altura) {
        int j = 0;
        while (j <= i) {
            cout << triangulo[i][j] << " ";
            j++;
        }
        cout << endl;
        i++;
    }
}

int main() {
    int altura;

    cout << "Ingrese la altura del Triángulo de Pascal: ";
    cin >> altura;

    generarTrianguloPascal(altura);

    return 0;
}
#include <iostream>

using namespace std;

void generarTrianguloPascal(int altura) {
    int triangulo[altura][altura];

    // Inicializar el Triángulo de Pascal con unos en la primera columna
    int i = 0;
    while (i < altura) {
        triangulo[i][0] = 1;
        i++;
    }

    // Generar el Triángulo de Pascal
    i = 2;
    while (i < altura) {
        int j = 1;
        while (j < i) {
            triangulo[i][j] = triangulo[i - 1][j - 1] + triangulo[i - 1][j];
            j++;
        }
        i++;
    }

    // Imprimir el Triángulo de Pascal
    i = 0;
    while (i < altura) {
        int j = 0;
        while (j <= i) {
            cout << triangulo[i][j] << " ";
            j++;
        }
        cout << endl;
        i++;
    }
}

int main() {
    int altura;

    cout << "Ingrese la altura del Triángulo de Pascal: ";
    cin >> altura;

    generarTrianguloPascal(altura);

    return 0;
}*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define principal 199
#define total 240

typedef struct {
    char codigo[7];
    char autor[41];
    char titulo[41];
} Libro;

#define desplazamiento(n) ((n) * 1)

Libro Arreglo_TablaHash[total];

void creacion(void);
void compra(void);
void venta(void);
void consulta(void);
void colisiones(Libro lib);
int hasear(char c[]);
long transformaClave(const char c[]);
void escribir(Libro lib);
void desplegarVariableD(void);
void desplegarTodo(void);
void guardarDatos(FILE* archivo);
void cargarDatos(FILE* archivo);
void mostrarElementos(void);

int main()
{
    char opcion;
    FILE* archivo = NULL;

    if (fopen_s(&archivo, "libros.dat", "r") == 0) {
        cargarDatos(archivo);
        fclose(archivo);
    }
    else {
        creacion();
    }

    do
    {
        puts("1. Compra    ");
        puts("2. Venta     ");
        puts("3. Consulta  ");
        puts("4. Desplegar Todo");
        puts("5. Mostrar elementos");
        puts("6. Imprimir el valor de d");
        puts("7. Salir      ");

        do {
            printf("Elige una opcion: ");
            scanf_s("%c%*c", &opcion, sizeof(opcion));

            if (opcion == '7') {
                break;  // Salir
            }
        } while (opcion < '1' || opcion > '6');

        switch (opcion)
        {
        case '1':
            compra();
            break;
        case '2':
            venta();
            break;
        case '3':
            consulta();
            break;
        case '4':
            desplegarTodo();
            break;
        case '5':
            mostrarElementos();
            break;
        case '6':
            desplegarVariableD();
            break;
        }
    } while (opcion != '7');

    if (fopen_s(&archivo, "libros.dat", "w") == 0) {
        guardarDatos(archivo);
        fclose(archivo);
    }
    else {
        printf("No se pudo guardar la informacion.\n");
    }

    return 0;
}

void creacion(void) {
    Libro lib = { "*", "", "" };
    int i;
    strcpy_s(lib.codigo, sizeof(lib.codigo), "*");
    for (i = 0; i < total; i++)
        Arreglo_TablaHash[i] = lib;
}

void compra(void)
{
    Libro lib;
    long posicion;

    printf("Codigo: ");
    scanf_s("%s%*c", lib.codigo, sizeof(lib.codigo));
    printf("Autor:  ");
    fgets(lib.autor, sizeof(lib.autor), stdin);
    printf("Titulo: ");
    fgets(lib.titulo, sizeof(lib.titulo), stdin);

    posicion = hasear(lib.codigo);
    posicion = desplazamiento(posicion);

    if (strcmp(Arreglo_TablaHash[posicion].codigo, "*") == 0)    /*libre */
    {
        Arreglo_TablaHash[posicion] = lib;
        printf("Registro grabado en la direccion: %ld\n", posicion);
    }
    else if (strcmp(lib.codigo, Arreglo_TablaHash[posicion].codigo) == 0)
    {
        puts("Codigo repetido, revisar los datos.");
        return;
    }
    else
        colisiones(lib);
}

void venta()
{
    char codigo[7], r;
    long posicion;

    printf("Codigo: ");
    scanf_s("%s%*c", codigo, sizeof(codigo));

    posicion = hasear(codigo);
    posicion = desplazamiento(posicion);

    if (strcmp(Arreglo_TablaHash[posicion].codigo, codigo) == 0)
    {
        escribir(Arreglo_TablaHash[posicion]);
        printf("¿Son correctos los datos? (S/N): ");
        scanf_s("%c%*c", &r, sizeof(r));
        if (toupper(r) == 'S')
        {
            strcpy_s(Arreglo_TablaHash[posicion].codigo, sizeof(Arreglo_TablaHash[posicion].codigo), "*");
        }
    }
    else
        puts("No se encuentra un registro con ese codigo.");
}

void consulta()
{
    char codigo[7];
    long posicion;

    printf("Codigo: ");
    scanf_s("%s%*c", codigo, sizeof(codigo));

    posicion = hasear(codigo);
    posicion = desplazamiento(posicion);

    if (strcmp(Arreglo_TablaHash[posicion].codigo, codigo) == 0 && strcmp(Arreglo_TablaHash[posicion].codigo, "*") != 0)
    {
        escribir(Arreglo_TablaHash[posicion]);
    }
    else
    {
        int i;
        int encontrado = 0;

        for (i = 0; i < total; i++)
        {
            if (strcmp(Arreglo_TablaHash[i].codigo, codigo) == 0 && strcmp(Arreglo_TablaHash[i].codigo, "*") != 0)
            {
                encontrado = 1;
                escribir(Arreglo_TablaHash[i]);
                break;
            }
        }

        if (!encontrado)
            puts("No se encuentra un ejemplar con ese codigo.");
    }
}

void colisiones(Libro lib)
{
    Libro libar;
    int pos = desplazamiento(principal);
    int j = principal;
    int encontrado = 0;

    while ((j < total) && !encontrado)
    {
        libar = Arreglo_TablaHash[j];
        j++;
        if (strcmp(libar.codigo, "*") == 0)    /* libre */
        {
            encontrado = 1;
            Arreglo_TablaHash[j - 1] = lib;
            puts("Datos grabados en el área de sinonimos.");
        }
    }

    if (!encontrado)
        puts("Área de sinonimos completa.");
}

int hasear(char c[])
{
    int i, suma = 0;

    for (i = 0; i < strlen(c); i++)
        c[i] = toupper(c[i]);
    return transformaClave(c) % principal;
}

long transformaClave(const char* clave)
{
    int j;
    long d;

    d = 0;
    for (j = 0; j < strlen(clave); j++)
    {
        d = d * 17 + clave[j];
    }

    if (d < 0) d = -d;
    return d;
}

void escribir(Libro lib)
{
    printf("Codigo: %s\n", lib.codigo);
    printf("Autor:  %s", lib.autor);
    printf("Titulo: %s", lib.titulo);
}

void desplegarVariableD(void)
{
    printf("El valor de d es: %d\n", principal);
}

void desplegarTodo(void)
{
    int i;

    for (i = 0; i < total; i++)
    {
        if (strcmp(Arreglo_TablaHash[i].codigo, "*") != 0)
        {
            printf("Direccion: %d\n", i);
            escribir(Arreglo_TablaHash[i]);
            putchar('\n');
        }
    }
}

void guardarDatos(FILE* archivo)
{
    fwrite(Arreglo_TablaHash, sizeof(Libro), total, archivo);
}

void cargarDatos(FILE* archivo)
{
    fread(Arreglo_TablaHash, sizeof(Libro), total, archivo);
}

void mostrarElementos(void)
{
    int i;

    for (i = 0; i < total; i++)
    {
        if (strcmp(Arreglo_TablaHash[i].codigo, "*") != 0)
        {
            printf("%s\n", Arreglo_TablaHash[i].codigo);
        }
    }
}
