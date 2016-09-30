#include <iostream>
#include "png.h"
using namespace std;

// initialize a new output image
// PNG * setOutput(int w, int h)
// {
// 	PNG * image = new PNG(w, h);
// 	return image;
// }

// function that swaps every element from top to bot in a column
void SwapRow(int col_num,PNG * image){
  int height = image ->height();
  for(int row = 0; row < (height+1)/2; row++){
    // bot pointer points to the top of the col and top pointer points to the bot
    RGBAPixel * top = (* image)(col_num,row);
    RGBAPixel * bot = (* image)(col_num,height-row-1);
    // swap top and bot pointers
    RGBAPixel temp = * top;
    *top = * bot;
    *bot = temp;
  }

}

// function that swaps every element from front to end in a row

void SwapCol(int row_num, PNG *image){
  int width = image -> width();
  for(int col = 0; col < (width+1)/2; col++){
    RGBAPixel * front = (* image)(col,row_num);
    RGBAPixel * end = (* image)(width-col-1,row_num);
    // swap front and end pointers
    RGBAPixel temp = * front;
    *front = * end;
    *end = temp;
  }
}

int main(){
  PNG * input = new PNG();
  input->readFromFile("in.png");

  int width = input -> width();
  int height = input -> height();
  //width 512 height 384

  // PNG * output = setOutput(width, height);

  for (int x = 0; x < width; x++){
     SwapRow(x, input);
  }

  for (int y = 0; y < height; y++){
    SwapCol(y,input);
  }

  input->writeToFile("out.png");

}
