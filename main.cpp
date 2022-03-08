/*

Proyecto Estructuras de Datos 2022-10 Javeriana
Grupo 2:
  Abril Cano & Alejandro Sacristan & Humberto Rueda.

Comando de Ejecucion: g++ -std=c++11 Modulos/ManejadorComandos.cpp main.cpp -o EstructurasProyecto && ./EstructurasProyecto

*/


#include "Modulos/ManejadorComandos.h"

using namespace std;

int main() {
  //system("clear");
  
  Img img;
  Vol v;
  
  manejadorComandos(img,v);
  
  //img = cargar_imagen("t1_icbm_5mm_/t1_icbm_5mm_01.ppm");
  
  /*
  ofstream myfile;
  string nombre = "Prueba";
  myfile.open (nombre);
  for (int i = 0; i < 216; i++){
    for (int j = 0; j < 180; j++){
      myfile<<img.valores[i][j].r<<" "<<img.valores[i][j].g<<" "<<img.valores[i][j].b<<" ";
    }
    myfile<<endl;
  }
  myfile.close();
  */
  
  //v = cargar_volumen("t1_icbm_5mm_",36);
  /*
  if(v.imagenes.size()> 0){
    //cout<<v.name<<endl;
    cout<<"Volumen Cargado con exito"<<endl;
  }
  */
  //proyeccion2D ('y',"mediana","t1_icbm_5mm_",v);
  //v = cargar_volumen("IM-211-0003-t2",12); 

  return 0;
}




  


