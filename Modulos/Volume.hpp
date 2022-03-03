#ifndef Volume_HPP
#define Volume_HPP

#include <vector>
#include <string.h>
#include <string>
#include <fstream>

#include "Image.hpp"


using namespace std;

class Volume{

  Private:
    vector <Image> vectorImages;
    string name;
    unsigned int x;
    unsigned int y; 
    unsigned int z;

  Public:

    Volume(
          vector <Image> _vectorImages,
          string _baseName,
          unsigned int x,
          unsigned int y,
          unsigned int z

    );
    void getInfo_volumen();
    Volume cargar_volumen (string _nombreBase, unsigned int _cantidadImages);
};

//#include "Volume.hxx"

#endif