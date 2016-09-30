#include"scene.h"
using namespace std;

Scene::Scene(int max){

  num_image = max;

  x_cor = new int[num_image];
  y_cor = new int[num_image];

  images = new Image* [num_image];
  for (int i =0; i < num_image; i++){
    images[i] = NULL;
  }
}

Scene::~Scene(){
  clear();
}

Scene::Scene(const Scene &source){

  copy(source);

}

const Scene & Scene::operator= (const Scene & source){
  if (this != &source)
	{
		clear();
		copy(source);
	}
	return *this;
}

void Scene::changemaxlayers(int newmax){
  Image ** new_images = new Image* [newmax];

  for (int i= 0; i < num_image; i++){
    if(images[i] != NULL && i > newmax){
      cout << "invalid input" << endl;
    }
    else{
      new_images[i] = images[i];
    }

    clear();
    images = new_images;
  }
}

void Scene::addpicture(const char * FileName,int index,int x,int y){
  x_cor[index] = x;
  y_cor[index] = y;

  Image * cur_image = new Image();
  cur_image->readFromFile(FileName);

  if(index > num_image-1){
    cout << "index out of bounds" << endl;
  }
  else {
    images[index] = cur_image;
  }
}


Image Scene::drawscene() const{
  Image *cur_image;
  Image scene_image;
  int scene_width = 0;
  int scene_height =0;

  for (int i =0; i < num_image; i++){

    if(images[i] != NULL){
      cur_image = images[i];
      int height = cur_image->height();
      int width = cur_image->width();


      int cur_x_cor = x_cor[i];
      int cur_y_cor = y_cor[i];


      if( scene_width < width + cur_x_cor){
        scene_width = width + cur_x_cor;
      }

      if( scene_height < height + cur_y_cor){
        scene_height = height + cur_y_cor;
      }
    }

  }

  scene_image.resize(scene_width, scene_height);


  //
  for (int i =0; i < num_image; i++){

    int cur_x_cor = x_cor[i];
    int cur_y_cor = y_cor[i];

    if (images[i] != NULL){
      cur_image = images[i];
      int height = cur_image->height();
      int width = cur_image->width();


      for(int x = 0; x < width; x++){
        for(int y = 0 ; y < height; y++){

          RGBAPixel * currOutPixel = (*cur_image)(x,y);
          RGBAPixel * currScenPixel = (scene_image)(x+cur_x_cor,y+cur_y_cor);
          * currScenPixel = * currOutPixel;
        }
      }
    }
  }

  return scene_image;
}

void Scene::changelayer(int index,int newindex){
  if(index < num_image && newindex < num_image){
    x_cor[newindex] = x_cor[index];
    x_cor[index] = 0;
    y_cor[newindex] = y_cor[index];
    y_cor[index] = 0;
    images[newindex] = images[index];
    images[index] = NULL;
  }
  else{
    cout <<"invalid index" << endl;
  }
}


void Scene::translate(int index,int xcoord,int ycoord){
  if(index < num_image){
    x_cor[index] = xcoord;
    y_cor[index] = ycoord;
  }
  else{
    cout <<"invalid index" << endl;
  }
}

void Scene::deletepicture(int index){
  if(index < num_image){
    delete images[index];
    images[index] = NULL;
    x_cor[index] = 0;
    y_cor[index] = 0;
  }
  else{
    cout <<"invalid index" << endl;
  }
}

Image * Scene::getpicture(int index) const{
  Image * costum;
  if(index < num_image){
    costum = images[index];
  }
  else{
    cout << "invalid index" << endl;
    return NULL;
  }

  return costum;
}










void Scene::copy(const Scene &source){
  num_image = source.num_image;
  x_cor = new int[num_image];
  y_cor = new int[num_image];

  images = new Image* [num_image];

  for (int i =0; i < num_dmage; i++){
    images[i] = NULL;
  }


  for(int i = 0; i < num_image; i++){

    x_cor[i] = source.x_cor[i];
    y_cor[i] = source.y_cor[i];

    if (source.images[i] != NULL){
      Image *copy_image = new Image();

      int height = source.images[i]->height();
      int width = source.images[i]->width();

      copy_image->resize(width,height);

      for(int x = 0; x < width; x++){
        for(int y = 0 ; y < height; y++){

          RGBAPixel * currOutPixel = (*source.images[i])(x,y);
          RGBAPixel * currCopyPixel = (*copy_image)(x,y);
          * currCopyPixel = * currOutPixel;
        }
      }

      images[i] = copy_image;

    }
  }
}

// adfadf



void Scene::clear(){
  delete[] x_cor;
  delete[] y_cor;
  for (int i=0; i < num_image; i++){
    delete images[i];
    images[i] = NULL;

  }
  delete[] images;
}
