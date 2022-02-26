#include "structImg.h"

bool cargar_imagen (string nombre){
  ifstream entrada;
  entrada.open(nombre,ios::in);
  if(!entrada.is_open()){
    cout<<"No se pudo abrir el archivo"<<endl;
    exit(1);
  }else{
    int i = 0;
    while(!entrada.eof()){
      Img temp;
      char *linea = new char[1000];
      entrada.getline(linea,1000,'\n');
      if ( i == 0){
        temp.px = linea;
        cout<<linea<<endl;
        i++;
      }else if (i == 1){
        if(linea[0]== #){
          temp.comment = linea;
          i++; 
        }else{
          char *ptr = strtok(linea," ");
          temp.width = stoi(ptr);
          char *ptr = strtok(NULL," ");
          temp.height = stoi(ptr);
          i += 2;
        }
      }else if (i == 2){
        char *ptr = strtok(linea," ");
        temp.width = stoi(ptr);
        char *ptr = strtok(NULL," ");
        temp.height = stoi(ptr);
        i++;
      }else if (i == 3){
        char *ptr = strtok(linea," ");
        temp.max = stoi(ptr);
      }
    }
  }

  
}