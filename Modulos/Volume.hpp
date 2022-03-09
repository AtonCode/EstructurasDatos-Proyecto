/**
 * @brief Estrucutra del volumen
 * @param name el nombre del archivo vol
 * @param x coordenada x
 * @param y coordenada y
 * @param z coordenad z
 * @param imagenes vector de imagenes
 */

#ifndef Volume_HPP
#define Volume_HPP

#include "Image.hpp"

struct Vol{

  string name;
  unsigned int x;
  unsigned int y; 
  unsigned int z;
  vector <Img> imagenes;

};

//#include "Volume.hxx"

#endif