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
