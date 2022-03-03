#ifndef Image_HPP
#define Image_HPP

#include <vector>
#include <string.h>
#include <string>
#include "Pixel.hpp"

using namespace std;

class Image{

  private:

    vector< vector<Pixel> > vectorPixeles;
    string comment;
    string name;
    string px;
    unsigned int height = 0;
    unsigned int width = 0;
    unsigned int max = 0;


  Public:

    Image(
          string _px, string _name,
          string _comment,
          unsigned int _height,
          unsigned int _width,
          unsigned int _max
        );

    void getInfo_imagen();
    Image cargar_imagen (string _nombreRuta);
    
};

//#include "Image_HPP.hxx"

#endif /*Image_HPP*/