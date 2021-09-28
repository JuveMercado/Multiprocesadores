#include <stdio.h>
#include <stdlib.h>
void document(int dato[], char d[], char c[])
{
  FILE *fptr;
  fptr=fopen(d,"w");
  fprintf(fptr, "%s", c);
  for(int i =0; i<256; i++){
    fprintf(fptr,"\n %d", dato[i]);
  }
  fclose(fptr);
}
int main()
{
    FILE *image, *outputImage, *lecturas;
    image = fopen("img.bmp","rb");          //Imagen original a transformar
    outputImage = fopen("result1.bmp","wb");    //Imagen transformada
    long ancho;
    long alto;
    unsigned char r, g, b;               //Pixel
    unsigned char* ptr;

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
    unsigned int red[256];
    unsigned int green[256];
    unsigned int blue[256];
    unsigned int bwred[256];
    unsigned int bwgreen[256];
    unsigned int bwblue[256];
    
    for(int i =0; i<= 256; i++)
    {
        red[i]=0;
        green[i]=0;
        blue[i]=0;
    }
    while(!feof(image)){
      b = fgetc(image);
      g = fgetc(image);
      r = fgetc(image);
      
      red[r]+=1;
      green[g]+=1;
      blue[b]+=1;
      unsigned char pixel = 0.21*r+0.72*g+0.07*b;

      ptr[cuenta] = pixel; //b
      ptr[cuenta+1] = pixel; //g
      ptr[cuenta+2] = pixel; //r

      bwblue[ptr[cuenta]]+=1;
      bwgreen[ptr[cuenta+1]]+=1;
      bwred[ptr[cuenta+2]]+=1;
      cuenta++;

    }
                                            //Grises
    cuenta = ancho;
    for (int i = 0; i < alto*ancho*3; ++i) {
      fputc(ptr[i+(cuenta*3)+2], outputImage);
      fputc(ptr[i+(cuenta*3)+1], outputImage);
      fputc(ptr[i+(cuenta*3)], outputImage);
      cuenta--;
      if (cuenta == 0){
        cuenta = ancho;
      }
    }

    document(red, "red.txt", "Datos Red");
    document(blue, "blue.txt", "Datos Blue");
    document(green, "green.txt", "Datos Green");
    document(bwblue, "BwBlue.txt", "Datos Blue black and white");
    document(bwgreen, "BwGreen.txt", "Datos Green black and white");
    document(bwred, "BwRed.txt", "Datos Red black and white");
    free(ptr);
    fclose(image);
    fclose(outputImage);
    return 0;
}
