#include <stdio.h>
#include <string.h>
#include <stdlib.h>
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
unsigned int width, height, sizeText;
char *typeFont;

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
        /// hacerle resize
        printf("\nHacer Resize");
    }
    /// reajustar imagen o rechazarlo
    return image;
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
    sfImage_saveToFile(image, path);
    printf("\nImagen guardada correctamente");
}

/**
 * 2. Personalización del texto a “empotrar” en la imagen por parte del usuario.
 * Tipos de letra entre una cantidad finita definida y tamaños también entre
 * algunos definidos. Se pueden utilizar índices para mayor facilidad de lectura
 * y parametrización. Por ejemplo, hipotéticamente, el tipo de letra 3 y el
 * tamaño 4. El programador deberá saber cual es el tipo de letra indexado por
 * el 3 y el tamaño indexado con el 4.
 * @param sizeTextP 0 pequeño, 1 grande.
 * @param typeText 0 Arial, 1 Times New Roman.
 */
void setTypes(int sizeTextP, int typeText){
    if (sizeTextP == 0){
        sizeText = 30;
    } else if (sizeText == 1){
        sizeText = 50;
    }
    typeFont = (char*)malloc(1);
    if (typeText == 0){
        printf("1");
        strcpy(typeFont, "C:\\Users\\Usuario\\Downloads\\fonts\\arial.ttf");
        printf("2");
    } else if (typeText == 1){
        printf("1");
        strcpy(typeFont, "C:\\Users\\Usuario\\Downloads\\fonts\\times.ttf");
        printf("2");
    }
}

/**
 * 3. Posición y ajuste del texto en la imagen. El texto puede colocarse arriba,
 * abajo o en ambas partes al mismo tiempo (implica que se pueden recibir no uno
 * si no dos textos perfectamente… cualquiera de los dos puede venir vacío y por
 * ende no se colocará nada en la imagen). Debe recortarse o restringirse la
 * cantidad de texto en función de las dimensiones de la imagen.
 */
void setText(char *text1, char *text2, struct sfImage *image){
    /// Se crean los objetos de tipo texto y se setean su contenido
    sfText* textoArriba = sfText_create();
    sfText* textoDebajo = sfText_create();
    sfText_setString(textoArriba, text1);
    sfText_setString(textoDebajo, text2);

    sfTexture *texture = sfTexture_createFromImage(image, NULL); // textura
    sfSprite *sprite = sfSprite_create(); // sprite

    /// Establecer la posición de un sprite
    //sfVector2f position = sfSprite_getPosition(sprite);
    //sfSprite_setPosition(sprite, position);
    
    /// Cambiar la textura de origen de un objeto
    sfSprite_setTexture(sprite, texture, sfTrue);

    printf("\n font %s", typeFont);
    sfFont * font = sfFont_createFromFile("C:\\Users\\Usuario\\Downloads\\fonts\\times.ttf"); //typeFont
    sfText_setCharacterSize(textoArriba, 50);
    sfText_setFont(textoArriba, font);

    sfRenderTexture *renderTexture = sfRenderTexture_create(width, height, sfTrue);
    sfRenderTexture_drawSprite(renderTexture, sprite,NULL);
    sfRenderTexture_drawText(renderTexture, textoArriba,NULL);
    sfTexture *pTexture = sfRenderTexture_getTexture(renderTexture);

    sfImage *ima = sfTexture_copyToImage(pTexture);
    sfImage_flipVertically(ima);
    saveImage(ima, "C:\\Users\\Usuario\\Downloads\\output.png");

}

int main() {
    printf("Hello, World!\n");

    /// Paso 1
    sfImage *image = loadImage("C:\\Users\\Usuario\\Downloads\\bugs2.jpg");
    if(image == NULL){
        return -1;
    }

    /// Paso 2
    //setTypes(0, 0);

    /// Paso 3
    //printf("\nIngrese el texto de arriba de la imagen: ");

    //printf("\nIngrese el texto de abajo de la imagen: ");
    setText("Meme", "Tenemos", image);

    /// Paso 4
    //saveImage(image, "C:\\Users\\Usuario\\Downloads\\output.png");

    return 0;
}
