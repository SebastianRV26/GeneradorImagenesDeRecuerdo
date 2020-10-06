#include <stdio.h>
#include <string.h>
#include <stb_image_resize.h>
#include <SFML/Graphics.h>

/**
 * @author Sebastian Rojas Vargas.
 * Compilador: MinGW 32 bits.
 */

typedef enum { BMP, JPG, TIFF, PNG } Formato;
typedef enum { ARIAL, TIMES_NEW_ROMAN, HEVATICA} TipoLetra;
//typedef enum { 12, JPG, TIFF, PNG } TamañoLetra;

/// Variables globales.
char *root = "C:\\Users\\Usuario\\Downloads\\";


/**
 * 1. Carga de imagenes en los formatos: JPG, TIFF y PNG.
 * Resolución mínima:
 * Resolución máxima:
 * Resize si pasa la resolución:
 * @param path: ruta, nombre y extención de la imagen
 * @return image (sfImage) imagen a utilizar.
 */
sfImage *cargarFoto(char *path){
    sfImage* image = NULL;
    image = sfImage_createFromFile(path);
    sfVector2u size = sfImage_getSize(image);

    int minSize = 700;
    int maxXSize = 1200;
    int maxYSize = 1200;

    if (size.x < minSize || size.y < minSize){
        printf("Imagen demaciado pequeña");
        return NULL;
    } else if (size.x > maxXSize || size.y > maxYSize) {
        // hacerle resize
        printf("Hacer Resize");
    }
    printf("Sizex: %i, sizey: %i", size.x, size.y);
    // reajustar imagen o rechazarlo
    return image;
}

/**
 * 2. Personalización del texto a “empotrar” en la imagen por parte del usuario.
 * Tipos de letra entre una cantidad finita definida y tamaños también entre
 * algunos definidos. Se pueden utilizar índices para mayor facilidad de lectura
 * y parametrización. Por ejemplo, hipotéticamente, el tipo de letra 3 y el
 * tamaño 4. El programador deberá saber cual es el tipo de letra indexado por
 * el 3 y el tamaño indexado con el 4.
 */
void pedirTipos(){
    // pedir Tipos de letra y tamaños de letra
    printf("Escoja el Tipo de letra: ");

    printf("Escoja el tamaño de la letra: ");
}

/**
 * 3. Posición y ajuste del texto en la imagen. El texto puede colocarse arriba,
 * abajo o en ambas partes al mismo tiempo (implica que se pueden recibir no uno
 * si no dos textos perfectamente… cualquiera de los dos puede venir vacío y por
 * ende no se colocará nada en la imagen). Debe recortarse o restringirse la
 * cantidad de texto en función de las dimensiones de la imagen.
 */
void pedirTexto(){
    printf("Ingrese el texto de arriba de la imagen: ");

    printf("Ingrese el texto de abajo de la imagen: ");
}

/**
 * 4. Almacenamiento en memoria de la postal en formato de imagen (sea el mismo
 * formato de la imagen de entrada o alguno otro disponible) utilizando el nombre
 * que el usuario indique y la extensión o solicitada o definida por el
 * programador.
 */
void guardarImagen(){
    printf("Indique el nombre de la imagen: ");
}

int main() {
    printf("Hello, World!\n");
    printf("Ingrese la ruta de la imagen (aceptamos jpg, png)");

    sfImage *image = cargarFoto("C:\\Users\\Usuario\\Downloads\\ide.png");
    if(image == NULL){
        return -1;
    }

    return 0;
}
