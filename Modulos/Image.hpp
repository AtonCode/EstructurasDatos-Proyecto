#ifndef Image_HPP
#define Image_HPP

#include <vector>
#include <string.h>
#include <string>
#include "Pixel.hpp"

using namespace std;
/**
 * @brief Estructura de una imagen
 * @param name nombre de la imagen
 * @param px tipo de la imagen
 * @param comment comentario acerca de la imagen
 * @param height alto de la imagen
 * @param width ancho de la imagen
 * @param max pixel maximo de la imagen
 * @param valores vector de vectores de pixeles
 */
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