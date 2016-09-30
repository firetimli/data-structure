#ifndef SCENE_H
#define SCENE_H


#include <iostream>
#include "image.h"

class Scene
{
public:
    Scene(int max);
    Scene(const Scene &source);
    ~Scene();
    const Scene & operator= (const Scene & source);
    void changemaxlayers(int newmax);
    void addpicture(const char * 	FileName,int index,int x,int y);
    Image drawscene() const;
    void changelayer(int index,int newindex);
    void translate(int index,int xcoord,int ycoord);
    void deletepicture(int index);
    Image * getpicture(int index)	const;





    // helper function
private:
    int num_image;
    Image ** images;
    int * x_cor;
    int * y_cor;

    void copy(const Scene &source);
    void clear();

};






#endif
