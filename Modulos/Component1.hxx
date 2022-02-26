#include "Component1.hpp"
#include "structImg.h"

using namespace std;
/*

struct Img
{
  string name;
  string px;
  string comment;
  unsigned int height;
  unsigned int width;
  unsigned int max;
  list< vector<int> > valores;
};


*/
void info_imagen(list<Img>listImg, string nameImg){
  Img imgPGM;
  
  for(auto it =listImg.begin(); it != listImg.end(); it++ ){
    imgPGM = *it;
    if(imgPGM.name == nameImg){
      cout<<"Imagen Encontrada en Memoria "<<endl;
      cout<<imgPGM.px<<endl;
      cout<<imgPGM.height<<" "<<imgPGM.width<<endl;
      cout<<imgPGM.max<<endl;
    }else{cout<<"Imagen No Encontrada en Memoria "<<endl;}
  }

}