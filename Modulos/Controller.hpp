#ifndef Controller_HPP
#define Controller_HPP

#include <iostream>
#include <iomanip>
#include <string.h>
#include <string>
#include <cstdlib>
#include <list> 
#include <vector>
#include <fstream>
#include <set>
#include <iterator>

#include "Pixel.hpp"
#include "Image.hpp"
#include "Volume.hpp"

using namespace std;


// Entrega 1
Img cargar_imagen (string nombre);
Vol cargar_volumen (string nombreBase, unsigned int cant);
void info_imagen(Img i);
void info_volumen(Vol v);
string proyeccion2D ( string dir, string criterio, string nombre );

#include "Controller.hxx"

#endif /*Controller_HPP*/