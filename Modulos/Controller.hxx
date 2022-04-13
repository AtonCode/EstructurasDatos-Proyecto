#include "Controller.hpp"
/**
 * @brief Funcion que carga la imagen
 * 
 * @param nombre nombre de la imagen pgm
 * @return Img imagen cargada
 */
Img cargar_imagen (string nombre){
  ifstream entrada;
  Img temp;
  int cont = 1;
  entrada.open(nombre,ios::in);
  if(!entrada.is_open()){
    cout<<"La imagen "<<nombre<<" no ha podido ser cargada"<<endl;
    return temp;
  }else{
    int i = 0;
    while(!entrada.eof()){
      temp.name = nombre; 
      char *linea = new char[2000];
      entrada.getline(linea,2000,'\n');
      if(linea[0] != NULL){
        //cout<<"Linea: "<<linea<<endl;
        if ( i == 0){
          temp.px = linea;
          i++;
        }else if (i == 1){
          if(linea[0]== '#'){
            temp.comment = linea;
            i++; 
          }else{
            char *ptr = strtok(linea," ");
            temp.width = stoi(ptr);
            ptr = strtok(NULL," ");
            temp.height = stoi(ptr);
            i += 2;
          }
        }else if (i == 2){
          char *ptr = strtok(linea," ");
          temp.width = stoi(ptr);
          ptr = strtok(NULL," ");
          temp.height = stoi(ptr);
          i++;
        }else if (i == 3){
          char *ptr = strtok(linea," ");
          temp.max = stoi(ptr);
          i++;
        }else
        if( i >= 4 ){
          if(temp.px == "P2"){
            vector<Pixel> vtemp;
            char *ptr = strtok(linea," ");
            Pixel ptemp;
            while (ptr != NULL){
              ptemp.gr = stoi(ptr);
              vtemp.push_back(ptemp);
              //cout<<" "<<ptr;
              ptr = strtok (NULL, " "); 
            }
            //cout<<"..........."<<endl;
            //cout<<"Lista "<<i<<endl;
            temp.valores.push_back(vtemp);
            i++;
            //cout<<endl;
          }
          
          if (temp.px == "P3"){
            vector<Pixel> vtemp;
            char *ptr = strtok(linea," ");
            Pixel ptemp;
            while (ptr != NULL){
              if(cont == 1){
                //cout<<"r: "<<ptr<<endl;
                ptemp.r = stoi(ptr);
                cont++;
              }else if(cont == 2){
                //cout<<"g: "<<ptr<<endl;
                ptemp.g = stoi(ptr);
                cont++;
              }else if(cont == 3){
                //cout<<"b: "<<ptr<<endl;
                ptemp.b = stoi(ptr);
                ptemp.gr = (ptemp.r + ptemp.g + ptemp.b)/3;
                vtemp.push_back(ptemp);
                cont = 1;
              }
              //vtemp.push_back(ptemp);
              //cout<<" "<<ptr;
              ptr = strtok (NULL, " ");
              
            }
            //cout<<"..........."<<endl;
            //cout<<"Lista "<<i<<endl;
            temp.valores.push_back(vtemp);
            i++;
            //cout<<endl;
          }
        }
      }
    }
    /*
    cout<<"PX: "<<temp.px
      <<" Nombre: "<<temp.name
      <<" Comment: "<<temp.comment
      <<" W: "<<temp.width
      <<" H: "<<temp.height
      <<" M: "<<temp.max<<endl;
    */
    //cout<<"La imagen "<<nombre<<" ha sido cargada"<<endl;
    return temp;
  }
}

/**
 * @brief Funcion para cargar el volumen
 * 
 * @param nombreBase nombre de la imagen ppm
 * @param cant eje z que se usa para recorrer la imagen
 * @return Vol volumen cargado
 */
Vol cargar_volumen (string nombreBase, unsigned int cant){
  Vol temp;
  temp.z = cant;
  vector<Img> vtemp;
  Img img; 
  string rutaImagen;
  temp.name = nombreBase;
  //cout<<cant<<endl;
  for(int i = 1; i < cant+1; i++){
    if(i < 10){
      rutaImagen = nombreBase + "/" + nombreBase + "0" + to_string(i) + ".ppm";
      cout<<rutaImagen<<endl;
      //cout<<nombre<<"/"<<nombre<<"0"<<i<<".ppm"<<endl;
      img = cargar_imagen(rutaImagen);
      if(img.height != 0)
        vtemp.push_back(img);
      else{
        cout<<"El volumen "<<nombreBase<<" no ha podido ser cargado"<<endl;
        return temp;
      }
    }else{
      rutaImagen = nombreBase + "/" + nombreBase + to_string(i) + ".ppm";
      //cout<<s<<endl;
      //cout<<nombre<<"/"<<nombre<<i<<".ppm"<<endl;
      img = cargar_imagen(rutaImagen);
      if(img.height != 0)
        vtemp.push_back(img);
      else{
        cout<<"El volumen "<<nombreBase<<" no ha podido ser cargado"<<endl;
        return temp;
      }
    }
  }
  temp.imagenes = vtemp;
  //cout<<temp.imagenes.front().width<<endl;
  temp.x = temp.imagenes[0].width;
  temp.y = temp.imagenes[0].height;
  //cout<<temp.x<<" "<<temp.y<<endl;
  return temp;
}

/**
 * @brief Funcion que muestra por pantalla informacion
 *        almacenada en la structur de una Img como nombre, h,w. Vigila
 *        de que esta imagen se encuentre cargada antes de dar algun resultado
 * @param i identifica la imagen que ingresa por parametro
 */
void info_imagen(Img i){
  if (i.height != 0 ){
    cout<<"Imagen cargada en memoria: "<<i.name<<endl;
    cout<<"Ancho: "<<i.width<<" Alto: "<<i.height<<endl;
  }else
    cout<<"No hay una imagen guardada en memoria"<<endl;  
}

/**
 * @brief Funcion que muestra por pantalla informacion
 *        almacenada en la structur de una Vol como nombre y tamano
 *        de que esta imagen se encuentre cargada antes de dar algun resultado
 * 
 * @param v identifica el volumen que ingresa por parametro
 */
void info_volumen(Vol v){
  if(v.imagenes.size() > 0){
    cout<<"Imagen cargada en memoria: "<<v.name<<endl;
    cout<<"Tamaño: "<<v.z<<endl;
  }
}
/**
 * @brief Funcion que proyecta la imagen en 2D
 * 
 * @param dir Direccion de la proyeccion
 * @param criterio mediana, promedio, min o max
 * @param nombre nombre del volumen
 * @param v dato de tipo volumen
 * @return string retorna el archivo con la proyección
 */
string proyeccion2D (string dir, string criterio, string nombre, Vol v){
  //variables para las diferentes direcciones y tamaños
  int primero;
  int segundo; 
  int tercero;
  int tamy;
  int tamx;
  // vector con valores de resultados 
  vector< vector<int> > res;
  //matriz de set para hallar la media
  vector< vector< multiset<int> > > media;
  //Verificar que el volumen esté cargado
  if(nombre != v.name){
    cout<<"El volumen aun no ha sido cargado en memoria"<<endl;
    return "";
  }
  multiset<int>:: iterator it;
 //asignar los ordenes según la dirección 
  if(dir == "z"){
    primero = v.z;
    segundo = v.y; 
    tercero = v.x;
    tamy = segundo;
    tamx = tercero;
    //Llenar matriz de resultados
    for (int i = 0; i < tamy; i++){
      vector<int> v1;
      vector< multiset<int> > vm1;
      for(int j = 0; j < tamx; j++){
        multiset<int> m1;
        vm1.push_back(m1);
        v1.push_back(0);
        
      }
      res.push_back(v1);
      media.push_back(vm1);
    }
    //recorrer volumen
    for( int i = 0; i < primero; i++){
      for (int j = 0; j < segundo; j++){ 
        for (int s = 0; s < tercero; s++){
          if(criterio == "maximo" || criterio == "minimo"){
            //asignar en la primera iteración la primera imagen
            if (i == 0){
              res.at(j).at(s) =  v.imagenes[i].valores[j][s].gr;
            } 
            //Si no es la primera img comparar
            else{
              if (criterio == "maximo"){
                if(res[j][s] < v.imagenes[i].valores[j][s].gr){
                  res.at(j).at(s) =  v.imagenes[i].valores[j][s].gr;
                }
              }
              if (criterio == "minimo"){
                if(res[j][s] > v.imagenes[i].valores[j][s].gr){
                  res.at(j).at(s) =  v.imagenes[i].valores[j][s].gr;
                }
              }
            }
          }
          //fin criterio min y max 
          if (criterio == "promedio"){
            //Suma acumulada de imagenes en el volumen v
            res.at(j).at(s) +=  v.imagenes[i].valores[j][s].gr;
          }
          if(criterio == "mediana"){
            //guardar en un multiset todos los valores
            media.at(j).at(s).insert(v.imagenes[i].valores[j][s].gr);
          }
        }
      }
    }
  //FIN RECORRIDO Z
  }
  if(dir == "x"){
    primero = v.x;
    segundo = v.z; 
    tercero = v.y;
    tamy = segundo;
    tamx = tercero;
    //Llenar matriz de resultados
    for (int i = 0; i < tamy; i++){
      vector<int> v1;
      vector< multiset<int> > vm1;
      for(int j = 0; j < tamx; j++){
        multiset<int> m1;
        vm1.push_back(m1);
        v1.push_back(0);
        
      }
      res.push_back(v1);
      media.push_back(vm1);
    }
    //recorrer volumen
    for( int i = 0; i < primero; i++){
      for (int j = 0; j < segundo; j++){ 
        for (int s = 0; s < tercero; s++){
          if(criterio == "maximo" || criterio == "minimo"){
            //asignar en la primera iteración la primera imagen
            if (i == 0){
              res.at(j).at(s) =  v.imagenes[j].valores[s][i].gr;
            } 
            //Si no es la primera img comparar
            else{
              if (criterio == "maximo"){
                if(res[j][s] < v.imagenes[j].valores[s][i].gr){
                  res.at(j).at(s) =  v.imagenes[j].valores[s][i].gr;
                }
              }
              if (criterio == "minimo"){
                if(res[j][s] > v.imagenes[j].valores[s][i].gr){
                  res.at(j).at(s) =  v.imagenes[j].valores[s][i].gr;
                }
              }
            }
          }
          //fin criterio min y max 
          if (criterio == "promedio"){
            //Suma acumulada de imagenes en el volumen v
            res.at(j).at(s) +=  v.imagenes[j].valores[s][i].gr;
          }
          if(criterio == "mediana"){
            //guradar en un multiset todos los valores 
            media.at(j).at(s).insert(v.imagenes[j].valores[s][i].gr);
          }
        }
      }
    }
    //FIN RECORRIDO X
  }
  if(dir == "y"){
    primero = v.y;
    segundo = v.z; 
    tercero = v.x;
    tamy = segundo;
    tamx = tercero;
    //Llenar matriz de resultados
    for (int i = 0; i < tamy; i++){
      vector<int> v1;
      vector< multiset<int> > vm1;
      for(int j = 0; j < tamx; j++){
        multiset<int> m1;
        vm1.push_back(m1);
        v1.push_back(0);
        
      }
      res.push_back(v1);
      media.push_back(vm1);
    }
    //recorrer volumen
    for( int i = 0; i < primero; i++){
      for (int j = 0; j < segundo; j++){ 
        for (int s = 0; s < tercero; s++){
          if(criterio == "maximo" || criterio == "minimo"){
            //asignar en la primera iteración la primera imagen
            if (i == 0){
              res.at(j).at(s) =  v.imagenes[j].valores[i][s].gr;
            } 
            //comparar
            else{
              if (criterio == "maximo"){
                if(res[j][s] < v.imagenes[j].valores[i][s].gr){
                  res.at(j).at(s) =  v.imagenes[j].valores[i][s].gr;
                }
              }
              if (criterio == "minimo"){
                if(res[j][s] > v.imagenes[j].valores[i][s].gr){
                  res.at(j).at(s) =  v.imagenes[j].valores[i][s].gr;
                }
              }
            }
          }
          //fin criterio min y max 
          if (criterio == "promedio"){
            //Suma acumulada de imagenes en el volumen v
            res.at(j).at(s) +=  v.imagenes[j].valores[i][s].gr;
          }
          if(criterio == "mediana"){
            media.at(j).at(s).insert(v.imagenes[j].valores[i][s].gr);
          }
        }
      }
    }
  //FIN RECORRIDO 
  }
  //Ya se tienen los resultados en res ahora se pasan a los archivos 
  //Impresion del encabezado 
  ofstream myfile;
  string file = "proyeccion2D.pgm";
  myfile.open (file);
  myfile<<"P2"<<endl;
  myfile<<tamx<<" "<<tamy<<endl;
  myfile<<v.imagenes.front().max<<endl;

  //Impresion de los valores segun el criterio 
  if(criterio == "promedio"){
    for (int i = 0; i < tamy; i++){
      for (int j = 0; j < tamx; j++){
        //Promedio de cada respuesta res con el numero de img en el volumen v
        res.at(i).at(j) =  res.at(i).at(j) / tercero ;
        myfile<<res[i][j]<<" ";
      }
      myfile<<endl;
    }  
  }
  
  if(criterio == "maximo" || criterio == "minimo"){
    //cout<<"RESULTADO MAXIMO o MINIMO"<<endl;
    for (int i = 0; i < 5; i++){
      for (int j = 0; j < 5; j++){
        myfile<<res[i][j]<<" ";
      }
      myfile<<endl;
    }
  }
  cout<<"hola";
  //Para la mediana hace falta realizar el calculo pues ya tenemos todos los números
  if(criterio == "mediana"){
    //recorremos para cada posicion de la matriz el set que contienen todos los numeros en orden 
    //la mediana es el numero de la mitad entre todos los números ordenados 
    for (int i = 0; i < tamy; i++){
      for (int j = 0; j < tamx; j++){
        multiset<int>:: iterator it = media.at(i).at(j).begin();
        multiset<int>:: iterator it1;
        float mediana;
        int size = media.at(i).at(j).size();
        //Si la cantidad de numeros son impares es simplemente el de la mitad 
        if (size % 2 != 0){
          advance(it,(size/2));
          mediana = *it;
          res.at(i).at(j) = mediana;
        //Si la cantidad de numeros es par, vamos hasta la mitad, se suma con el anterior y se divide en 2 
        }else{
          advance(it,(size/2));
          mediana = *it;
          it--;
          mediana += *it;
          mediana /= 2;
          res.at(i).at(j) = mediana;
        }
      }
    }
    //Escribir los resultados de la mediana en el archivo
    for (int i = 0; i < 5; i++){
      for (int j = 0; j < 5; j++){
        myfile<<res[i][j]<<" ";
      }
      myfile<<endl;
    }
  }
  return file;
}

