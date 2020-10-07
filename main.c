#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stb_image_resize.h>
#include <SFML/Graphics.h>
#include <malloc.h>
#include <mem.h>
#include <conio.h>
#include <ctype.h>

/**
 * @author Sebastian Rojas Vargas.
 * Compilador: MinGW 32 bits.
 * Librerías externas:
 * SFML (v2.5.1) https://www.sfml-dev.org/download.php (GCC 7.3.0 MinGW (DW2) - 32-bit)
 * CSFML https://www.sfml-dev.org/download/csfml/ (GCC - 32-bit)
 */

typedef enum { BMP, JPG, TIFF, PNG } Formato;

/// Variables globales.
unsigned int width, height;
unsigned int sizeText;
unsigned int size;
int flag = 0;

/**
 * Reajuste de la imagem.
 */
sfImage* resize(sfImage *originalImage){
    sfImage *image = NULL;
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture = sfTexture_createFromImage(originalImage, NULL);

    sfVector2f vectorRequired = {(float)(1000.0/width), (float)(1000.0/height)};
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setScale(sprite, vectorRequired);
    sfFloatRect newSize = sfSprite_getGlobalBounds(sprite);
    width = (int)newSize.width;
    height = (int)newSize.height;

    sfRenderTexture *renderTexture = sfRenderTexture_create(width, height, sfTrue);
    sfRenderTexture_drawSprite(renderTexture, sprite,NULL);
    const sfTexture *pTexture = sfRenderTexture_getTexture(renderTexture);
    image = sfTexture_copyToImage(pTexture);
    sfImage_flipVertically(image);
    return image;
}

/**
 * 1. Carga de imagenes en los formatos: JPG, TIFF y PNG.
 *
 * Resolución mínima: 400.
 * Resolución máxima: 1000.
 * Resize si pasa la resolución:
 * @param path: ruta, nombre y extención de la imagen
 * @return image (sfImage) imagen a utilizar.
 */
sfImage *loadImage(char *path){
    sfImage* image = NULL;
    image = sfImage_createFromFile(path);
    sfVector2u sizes = sfImage_getSize(image);

    width = sizes.x;
    height = sizes.y;

    int minSize = 400;
    int maxSize = 1000;
    printf("\nDimensiones de la imagen original: largo: %i, altura: %i", width, height);
    flag = 1;
    if (width < minSize || height < minSize){
        printf("\nImagen demaciado pequennia");
        flag = 0;
        return NULL;
    } else if (width > maxSize || height > maxSize) {
        printf("\nSe hizo un reajuse de dimensiones a %ix%i", maxSize, maxSize);
        return resize(image);
    }
    return image;
}

/**
 * 4. Almacenamiento en memoria de la imagen.
 *
 * @param image: imagen a guardar.
 * @param path: ruta, nombre y extención de la imagen a guarar.
 */
void saveImage(struct sfImage *image, char *path){
    if (image != NULL) {
        sfImage_saveToFile(image, path);
        printf("\nImagen guardada correctamente");
    }
}

/**
 * 2. Personalización del texto a “empotrar” en la imagen por parte del usuario.
 * Tipos de letra entre una cantidad finita definida y tamaños también entre
 * algunos definidos. Se pueden utilizar índices para mayor facilidad de lectura
 * y parametrización. Por ejemplo, hipotéticamente, el tipo de letra 3 y el
 * tamaño 4. El programador deberá saber cual es el tipo de letra indexado por
 * el 3 y el tamaño indexado con el 4.
 * @param sizeTextP 0 pequeño, 1 grande.
 * @param typeText 0 Arial, 1 Times New Roman, 2 Nirvana.
 */
char* setTypes(int sizeTextP, int typeText){
    if (flag == 0){
        return NULL;
    }
    size = sizeTextP;
    if (sizeTextP == 0){
        printf("\nUsted escogio letra pequenniaa");
        sizeText = height/15;
    } else if (sizeTextP == 1){
        printf("\nUsted escogio letra grande");
        sizeText = height/10;
    }
    if (typeText == 1){
        printf("\nUsted escogio Times New Roman");
        return "C:\\Users\\Usuario\\Downloads\\fonts\\times.ttf";
    } else if (typeText == 2){
        printf("\nUsted escogio Nirvana");
        return "C:\\Users\\Usuario\\Downloads\\fonts\\NIRVANA.TTF";
    }
    printf("\nUsted escogio Arial");
    return "C:\\Users\\Usuario\\Downloads\\fonts\\arial.ttf";
}

/**
 * 3. Posición y ajuste del texto en la imagen. El texto puede colocarse arriba,
 * abajo o en ambas partes al mismo tiempo (implica que se pueden recibir no uno
 * si no dos textos perfectamente… cualquiera de los dos puede venir vacío y por
 * ende no se colocará nada en la imagen). Debe recortarse o restringirse la
 * cantidad de texto en función de las dimensiones de la imagen.
 *
 * @param color 0 blanco, 1 negro
 */
sfImage *setText(char *text1, char *text2, struct sfImage *image, char *typeFont, int color){
    if (flag == 0){
        return NULL;
    }
    /// Se crean los objetos de tipo texto y se setean su contenido
    sfText* textoArriba = sfText_create();
    sfText* textoDebajo = sfText_create();
    sfText_setString(textoArriba, text1);
    sfText_setString(textoDebajo, text2);

    sfTexture *texture = sfTexture_createFromImage(image, NULL); // textura
    sfSprite *sprite = sfSprite_create(); // sprite

    if (color == 1) {
        sfText_setColor(textoArriba, sfBlack);
        sfText_setColor(textoDebajo, sfBlack);
    }
    // (width/(strlen(text1)*0.2))
    /// Establecer la posición del textp
    sfVector2f position1 = {200, 10}; // si el texto es muy largo se corta
    unsigned int pos = height-(height/12);
    if (size == 1){
        pos = height-(height/8);
    }
    sfVector2f position2 = {200, (float)pos}; // si el texto es muy largo se corta
    sfText_setPosition(textoArriba, position1);
    sfText_setPosition(textoDebajo, position2);
    /// Cambiar la textura de origen de un objeto
    sfSprite_setTexture(sprite, texture, sfTrue);

    sfFont * font = sfFont_createFromFile(typeFont);
    sfText_setCharacterSize(textoArriba, sizeText);
    sfText_setFont(textoArriba, font);
    sfText_setCharacterSize(textoDebajo, sizeText);
    sfText_setFont(textoDebajo, font);

    sfRenderTexture *renderTexture = sfRenderTexture_create(width, height, sfTrue);
    sfRenderTexture_drawSprite(renderTexture, sprite,NULL);
    sfRenderTexture_drawText(renderTexture, textoArriba,NULL);
    sfRenderTexture_drawText(renderTexture, textoDebajo,NULL);
    const sfTexture *pTexture = sfRenderTexture_getTexture(renderTexture);

    sfImage *imageWithText = sfTexture_copyToImage(pTexture);
    sfImage_flipVertically(imageWithText);
    //saveImage(imageWithText, "C:\\Users\\Usuario\\Downloads\\output.png");
    return imageWithText;
}

int main() {
    printf("\n//////////////////////////////////////////////////////////////////");
    printf("\n\tPrueba 0 con imagen muy pequennia");
    /// Paso 1
    sfImage *image = loadImage("C:\\Users\\Usuario\\Downloads\\bill.jpg");
    /// Paso 2
    char *typeFont = setTypes(0, 0);
    /// Paso 3
    image = setText("Memelandia", "Tenemos", image, typeFont, 1);
    /// Paso 4
    saveImage(image, "C:\\Users\\Usuario\\Downloads\\output0.png");


    printf("\n\n//////////////////////////////////////////////////////////////////");
    printf("\n\tPrueba 1 - texto: Arial tamannio pequennio color blanco");
    /// Paso 1
    image = loadImage("C:\\Users\\Usuario\\Downloads\\bugs.jpg");
    /// Paso 2
    typeFont = setTypes(0, 0);
    /// Paso 3
    image = setText("Bugs Bunny", "Tenemos", image, typeFont, 0);
    /// Paso 4
    saveImage(image, "C:\\Users\\Usuario\\Downloads\\output1.png");


    printf("\n\n//////////////////////////////////////////////////////////////////");
    printf("\n\tPrueba 2 - texto: Times New Roman tamannio grande color negro");
    /// Paso 1
    image = loadImage("C:\\Users\\Usuario\\Downloads\\bugs2.jpg");
    /// Paso 2
    typeFont = setTypes(1, 1);
    /// Paso 3
    image = setText("Bugs Bunny", "Tenemos", image, typeFont, 1);
    /// Paso 4
    saveImage(image, "C:\\Users\\Usuario\\Downloads\\output2.png");


    printf("\n\n//////////////////////////////////////////////////////////////////");
    printf("\n\tPrueba 3 - texto: Arial tamannio grande, mucho texto");
    /// Paso 1
    image = loadImage("C:\\Users\\Usuario\\Downloads\\sc.jpg");
    /// Paso 2
    typeFont = setTypes(1, 0);
    /// Paso 3
    image = setText("San Carlos mi linda tierra, donde vive mi querer hay una",
                    "elevada sierra donde veo el sol nacer y la luz esplendoroza", image, typeFont, 1);
    /// Paso 4
    saveImage(image, "C:\\Users\\Usuario\\Downloads\\output3.png");

    return 0;
}
