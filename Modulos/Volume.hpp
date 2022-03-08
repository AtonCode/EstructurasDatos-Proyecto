#ifndef Volume_HPP
#define Volume_HPP

#include <vector>
#include <string.h>
#include <string>
#include <fstream>

#include "Image.hpp"


using namespace std;

struct Vol{

  string name;
  unsigned int x;
  unsigned int y; 
  unsigned int z;
  vector <Img> imagenes;

};

//#include "Volume.hxx"

#endif