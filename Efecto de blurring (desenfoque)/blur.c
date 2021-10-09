#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *image, *outputImage, *lecturas;
    //FILE *data;
    image = fopen("img3.bmp","rb");          //Imagen original a transformar
    outputImage = fopen("imgOut3.bmp","wb");    //Imagen transformada
    //data = fopen("Image_data.txt","w");    //Imagen transformada
    long ancho;
    long alto;
    unsigned char r, g, b;               //Pixel
    unsigned char* ptr;
    int avgB = 0, avgG = 0, avgR = 0;
    int ile = 0;

    unsigned char xx[54];
    int cuenta = 0;
    for(int i=0; i<54; i++) {
      xx[i] = fgetc(image);
      fputc(xx[i], outputImage);   //Copia cabecera a nueva imagen
    }
    ancho = (long)xx[20]*65536+(long)xx[19]*256+(long)xx[18];
    alto = (long)xx[24]*65536+(long)xx[23]*256+(long)xx[22];
    printf("largo img %li\n",alto);
    printf("ancho img %li\n",ancho);
    

    ptr = (unsigned char*)malloc(alto*ancho*3* sizeof(unsigned char));

    while(!feof(image)){
        b = fgetc(image);
        g = fgetc(image);
        r = fgetc(image);
        
        unsigned char pixel = 0.21*r+0.72*g+0.07*b;

        ptr[cuenta]= pixel; //b
        ptr[cuenta+1] = pixel; //g
        ptr[cuenta+2] = pixel; //r
        cuenta++;
    } 

    //-------------------------blur
    for(int xx = 0; xx < alto; xx++){
        for(int yy = 0; yy < ancho; yy++){
            avgB = avgG = avgR = 0;
            ile = 0;

            for(int x = xx; x < alto && x < xx + 11; x++){
                for(int y = yy; y < ancho && y < yy + 11; y++){
                    avgB += ptr[(x) * ancho + (y) ];
                    avgG += ptr[(x) * ancho + (y) + 1];
                    avgR += ptr[(x) * ancho + (y) + 2];
                    ile++;
                }
            }
            avgB = avgB / ile;
            avgG = avgG / ile;
            avgR = avgR / ile;

            fputc(ptr[(xx) * ancho + (yy) ] = avgB, outputImage);
            fputc(ptr[(xx) * ancho + (yy) + 1] = avgG, outputImage);
            fputc(ptr[(xx) * ancho + (yy) + 2] = avgR, outputImage);
        }
    }
    free(ptr);
    fclose(image);
    fclose(outputImage);
    return 0;
}
