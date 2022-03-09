/**
 * @file Controller.hpp
 * @brief Controlador de las funciones
 * 
 */

#ifndef Controller_HPP
#define Controller_HPP

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <list> 
#include <fstream>
#include <set>
#include <iterator>
#include "Volume.hpp"


// Entrega 1
Img cargar_imagen (string nombre);
Vol cargar_volumen (string nombreBase, unsigned int cant);
void info_imagen(Img i);
void info_volumen(Vol v);
string proyeccion2D ( string dir, string criterio, string nombre );

#include "Controller.hxx"

#endif /*Controller_HPP*/