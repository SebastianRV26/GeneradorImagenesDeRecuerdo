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
unsigned int width, height;

/**
 * 1. Carga de imagenes en los formatos: JPG, TIFF y PNG.
 * Resolución mínima:
 * Resolución máxima:
 * Resize si pasa la resolución:
 * @param path: ruta, nombre y extención de la imagen
 * @return image (sfImage) imagen a utilizar.
 */
sfImage *loadImage(char *path){
    sfImage* image = NULL;
    image = sfImage_createFromFile(path);
    sfVector2u size = sfImage_getSize(image);

    width = size.x;
    height = size.y;

    int minSize = 500;
    int maxXSize = 1200;
    int maxYSize = 1200;
    printf("\nSizex: %i, sizey: %i", width, height);

    if (width < minSize || height < minSize){
        printf("\nImagen demaciado pequennia");
        return NULL;
    } else if (width > maxXSize || height > maxYSize) {
        // hacerle resize
        printf("\nHacer Resize");
    }
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
    printf("\nEscoja el Tipo de letra: ");

    printf("\nEscoja el tamaño de la letra: ");
}

/**
 * 3. Posición y ajuste del texto en la imagen. El texto puede colocarse arriba,
 * abajo o en ambas partes al mismo tiempo (implica que se pueden recibir no uno
 * si no dos textos perfectamente… cualquiera de los dos puede venir vacío y por
 * ende no se colocará nada en la imagen). Debe recortarse o restringirse la
 * cantidad de texto en función de las dimensiones de la imagen.
 */
void setText(char *text1, char *text2){
    // Se crean los objetos de tipo texto y se setean su contenido
    sfText* textoArriba = sfText_create();
    sfText* textoDebajo = sfText_create();
    sfText_setString(textoArriba, text1);
    sfText_setString(textoDebajo, text2);

    sfTexture* *texture = sfTexture_create(width, height); // textura
    sfSprite *sprite = sfSprite_create(); // sprite

    // Depende, yo la uso porque al sprite no se le puede meter image, asi que dentro
    // del textura le meto la imagen, ya el sprite si acepta texture
}

/**
 * 4. Almacenamiento en memoria de la postal en formato de imagen (sea el mismo
 * formato de la imagen de entrada o alguno otro disponible) utilizando el nombre
 * que el usuario indique y la extensión o solicitada o definida por el
 * programador.
 *
 * @param image imagen a guardar.
 * @param path ruta a guarar la imagen.
 */
void saveImage(struct sfImage *image, char *path){
    printf("\nIndique la ruta, el nombre y la extencion de la imagen: ");

    sfImage_saveToFile(image, path);
    printf("\nImagen guardada correctamente");
}

int main() {
    printf("Hello, World!\n");
    printf("Ingrese la ruta de la imagen (aceptamos jpg, png)");

    // Paso 1
    sfImage *image = loadImage("C:\\Users\\Usuario\\Downloads\\bugs2.jpg");
    if(image == NULL){
        return -1;
    }

    // Paso 2

    // Paso 3
    //printf("\nIngrese el texto de arriba de la imagen: ");

    //printf("\nIngrese el texto de abajo de la imagen: ");
    setText("Meme", "Tenemos");

    // Paso 4
    saveImage(image, "C:\\Users\\Usuario\\Downloads\\output.png");

    return 0;
}
