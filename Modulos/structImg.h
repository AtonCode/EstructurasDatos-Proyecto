#ifndef structImg_H
#define structImg_H

#include <iostream>
#include <list> 
#include <vector>
#include <fstream>

using namespace std;

struct Img
{
  string px;
  string comment;
  unsigned int height;
  unsigned int width;
  unsigned int max;
  list< vector<int> > valores;
};

struct Volumen
{
  string nombre;
  unsigned int tam;
  list <Img> imagenes;

};

bool cargar_imagen (string nombre);

#include "structImg.hxx"

#endif