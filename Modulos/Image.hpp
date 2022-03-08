#ifndef Image_HPP
#define Image_HPP

#include <vector>
#include <string.h>
#include <string>
#include "Pixel.hpp"

using namespace std;

struct Img
{
  string name;
  string px;
  string comment;
  unsigned int height = 0;
  unsigned int width = 0;
  unsigned int max = 0;
  vector< vector<Pixel> > valores;
};

//#include "Image.hxx"

#endif /*Image_HPP*/