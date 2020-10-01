#include <stdio.h>

typedef enum { BMP, JPG, TIFF, PNG } Formato;
typedef enum { ARIAL, TIMES_NEW_ROMAN, HEVATICA} TipoLetra;
//typedef enum { 12, JPG, TIFF, PNG } TamañoLetra;

/**
 * 1. Carga de fotografías al menos en tres formatos a escoger entre BMP, JPG,
 * TIFF y PNG. Esta carga debe realizarse recibiendo de parámetro la ruta de
 * acceso a la imagen en el disco duro para que se permita cargar cualquier
 * imagen que se requiera. Se debe restringir al leer la imagen que tenga al
 * menos una resolución mínima que defina el programador y que si la imagen es
 * más grande que una resolución máxima también definida por el programador,
 * esta se pueda re ajustar a dichas dimensiones.
 */

void cargarFoto(){
    char *ruta = "";
    printf("Escoja el formato: ");

    // resolución mínima: (rechazarlo si es muy pequeña)

    // resolución máxima:

    // reajustar imagen o rechazarlo

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
    //printf("Hello, World!\n");
    cargarFoto();

    return 0;
}
