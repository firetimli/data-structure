#include "image.h"
using namespace std;

void Image::flipleft(){
  // create a new image
  // initialize height and width
  int width = this -> width();
  int height = this -> height();

  for (int y = 0; y < height; y++){
    for(int col = 0; col < (width+1)/2; col++){
      RGBAPixel * front = (* this)(col,y);
      RGBAPixel * end = (* this)(width-col-1,y);
      // swap front and end pointers
      RGBAPixel temp = * front;
      *front = * end;
      *end = temp;

    }
  }
}

void Image::adjustbrightness(int r, int g, int b){
  int width = this -> width();
  int height = this -> height();

  for (int y = 0; y < height; y++)
  {
    for (int x = 0; x < width; x++){

        	RGBAPixel * currOutPixel = (* this)(x,y);
          //
          if(currOutPixel->red +r >= 0 && currOutPixel->red +r <= 255){
            currOutPixel->red += r;
          }
          else if (currOutPixel->red + r < 0){
            currOutPixel->red = 0;
          }
          else{
            currOutPixel->red = 255;
          }
          //
          if(currOutPixel->green+g >= 0 && currOutPixel->green+g <= 255){
            currOutPixel->green += g;
          }
          else if(currOutPixel->green + g < 0){
            currOutPixel->green = 0;
          }
          else {
            currOutPixel->green = 255;
          }

          //
          if(currOutPixel->blue+b >= 0 && currOutPixel->blue+b <= 255){
            currOutPixel->blue += b;
          }
          else if (currOutPixel->blue + b < 0){
            currOutPixel->blue = 0;
          }
          else{
            currOutPixel->blue = 255;
          }
    }

  }
}

void Image::invertcolors(){
  int width = this -> width();
  int height = this -> height();
  for (int y = 0; y < height; y++){
    for (int x = 0; x < width; x++){
      RGBAPixel * currOutPixel = (* this)(x,y);

      currOutPixel->red = 255 - currOutPixel->red;
      currOutPixel->green = 255 - currOutPixel->green;
      currOutPixel->blue = 255 - currOutPixel->blue;
    }

  }

}
