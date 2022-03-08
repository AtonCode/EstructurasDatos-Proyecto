
bool helpCommands(){

    cout << "\t|-" <<  setfill('-') << setw(100) << "-|" << endl;
    cout<<"\t\t\t\t\t\t COMANDOS DISPONIBLES"<<endl;
    cout<<endl;
    cout<<"\t\t\t\t\t Sintaxix: Comando [paramentro 1] [paramentro 2]"<<endl;
    cout << "\t|-" <<  setfill('-') << setw(100) << "-|" << endl;
    cout<<endl;

    printf("\t\t\t COMANDO \t\t\t\t\t\t\t DESCRIPCION \n\n\n");
    cout<<endl;

    cout<<"\t [1] cargar_imagen [nombre_imagen.pgm]: \t\t-->\t\t";
    cout<<"Cargar en memoria la imagen identificada con el nombre_imagen.pgm"<<endl;
    cout<<endl;

    cout<<"\t [2] cargar_volumen [nombre_base] [n_im]: \t\t-->\t\t";
    cout<<"Cargar en memoria la serie ordenada de imágenes identicada con el\n \t\t\t\t\t\t\t\t\t\tnombre_base y cuyo tamaño corresponde a n_im imágenes (max 99)\n\n";
    cout<<endl;

    cout<<"\t [3] info_imagen: \t\t\t\t\t-->\t\tMuestra la información básica de la imagen actualmente cargada en memoria"<<endl;
    cout<<endl;

    cout<<"\t [4] info_volumen: \t\t\t\t\t-->\t\tMuestra la información básica de la serie de imágenes (volumen) cargadas \n \t\t\t\t\t\t\t\t\t\tactualmente en memoria: nombre base,cantidad de imágenes,ancho en pixeles y alto en pixeles"<<endl;
    cout<<endl;

    cout<<"\t [5] proyeccion2D [dirección] [criterio] [nombre_archivo.pgm]: --> \tGenera una proyección 2D de las imagenes en memoria. La direccion puede ser \n \t\t\t\t\t\t\t\t\t\tentre x,y,z, el cirterio entre el minimo, el maximo, promedio, o mediana de intensidad,\n \t\t\t\t\t\t\t\t\t\tpara ser guardada en nombre_archivo.pmg "<<endl;
    cout<<endl;

    cout << "\t|-" <<  setfill('-') << setw(170) << "-|" << endl;
    cout<<endl;
    cout<<endl;

    return true;
    
}

void manejadorComandos(Img &img, Vol &v){

  char *opcion = new char[500];
  bool enter = true;

  while(true){
    bool encontrado = false;
    cout<<"$ ";
    cin.getline(opcion,500,'\n');
    if(opcion[0] != NULL){
      //cout<<"if"<<endl;
      char *ptr = strtok(opcion," ");
  
      if (strcmp(ptr,"clear")==0){
          system("clear");
      }

      if (strcmp(ptr,"cls")==0){
          system("cls");
      }

      if (strcmp(ptr,"ayuda")==0){
        encontrado = helpCommands(); 
      }

      if(strcmp(ptr,"salir")==0){
        exit(1);
      }

      if(strcmp(ptr,"cargar_imagen")==0){
        ptr=strtok(NULL,"\n");
        img = cargar_imagen(ptr);
        if(img.max > 0){
          cout<<"La imagen "<<ptr<<" ha sido cargada"<<endl;
        }
        else{
          cout<<"La imagen "<<ptr<<" no ha podido ser cargada"<<endl;
        }
        encontrado = true;
      }

      if(strcmp(ptr,"cargar_volumen") == 0){
        ptr = strtok(NULL," ");
        char *base = ptr;
        ptr = strtok(NULL,"\n");
        char *num = ptr;
        v = cargar_volumen(base,stoi(num)); 
        if(v.imagenes.size()>0){
          cout<<"El volumen "<<base<<" ha sido cargado"<<endl;
        }
        else{
          cout<<"El volumen "<<base<<" no ha podido ser cargado"<<endl;
        }
        encontrado = true;
      }
      
      if(strcmp(ptr,"info_imagen") == 0){
        info_imagen(img);
        encontrado = true;
      }
      
      if(strcmp(ptr,"info_volumen")==0){
        info_volumen(v);
        encontrado = true;
      }

      if(strcmp(ptr,"proyeccion2D")==0){
        ptr=strtok(NULL," ");
        char *dir = ptr;
        cout<<"dir: "<<dir<<endl;
        ptr=strtok(NULL," ");
        char *crit = ptr;
        cout<<"crit: "<<crit<<endl;
        ptr=strtok(NULL,"\n");
        char *nomb = ptr;
        cout<<"nombre: "<<nomb<<endl;
        string p2D = proyeccion2D(dir,crit,nomb,v);
        if(p2D != ""){
          cout<<"La proyección 2D del volumen en memoria ha sido generada"<<endl;
        }
        else{
          cout<<"El volumen aún no ha sido cargado en memoria. La proyección 2D del volumen en memoria no ha podido ser generada"<<endl;
        }
        encontrado = true;
      }
      if (!encontrado){
        cout<<"Comando no encontrado, digite el comando ayuda para saber más"<<endl;
      }
    }
  }   
}