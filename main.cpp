// g++ -std=c++11 Modulos/ManejadorComandos.cpp main.cpp -o EstructurasProyecto && ./EstructurasProyecto
/*
Gupo 2
Abril Cano & Alejandro Sacristan & Humberto Rueda

*/
/*
#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <sstream>
#include "Modulos/ManejadorComandos.h"

using namespace std;

int main() {
  
  clearTerminal('l');
  
    int row = 0, col = 0, num_of_rows = 0, num_of_cols = 0;
    stringstream ss;    
    ifstream infile("Recursos/Imagenes2D/img_02.pgm", ios::binary);

    string inputLine = "";

    getline(infile,inputLine);      // read the first line : P5
    if(inputLine.compare("P5") != 0) cerr << "Version error" << endl;
    cout << "Version : " << inputLine << endl;

    getline(infile,inputLine);  // read the second line : comment
    cout << "Comment : " << inputLine << endl;

    ss << infile.rdbuf();   //read the third line : width and height
    ss >> num_of_cols >> num_of_rows;
    cout << num_of_cols << " columns and " << num_of_rows << " rows" << endl;

    int max_val;  //maximum intensity value : 255
    ss >> max_val;
    cout<<max_val;

    unsigned char pixel;

int **pixel_value = new int*[num_of_rows];
    for(int i = 0; i < num_of_rows; ++i) {
        pixel_value[i] = new int[num_of_cols];
    }

int **integral = new int*[num_of_rows];
    for(int i = 0; i < num_of_rows; ++i) {
        integral[i] = new int[num_of_cols];
    }

    for (row = 0; row < num_of_rows; row++){    //record the pixel values
        for (col = 0; col < num_of_cols; col++){
             ss >> pixel;
             pixel_value[row][col]= pixel;
        }
    }


integral[0][0]=pixel_value[0][0];    
for(int i=1; i<num_of_cols;i++){            //compute integral image
integral[0][i]=integral[0][i-1]+pixel_value[0][i];

} 
for (int i=1;i<num_of_rows; i++){
integral[i][0]=integral[i-1][0]+pixel_value[i][0];
}
for (int i = 1; i < num_of_rows; i++){  
for (int j = 1; j < num_of_cols; j++){
integral[i][j] = integral[i - 1 ][j] + integral [i][j - 1] - integral[i - 1] [j - 1] + pixel_value[i][j]; 
}
}

    ofstream output1("pixel_value.txt");  // output the intensity values of the pgm file
    for (int k=0; k<num_of_rows; k++)
    {
        for (int r=0; r<num_of_cols; r++)
        {
            output1 << pixel_value[k][r] << " ";
        }
        output1 << ";" << endl;
    }
output1.close();

    ofstream output2("integral_value.txt");    // output the integral image
    for (int a=0; a<num_of_rows; a++)
    {
        for (int b=0; b<num_of_cols; b++)
        {
            output2 << integral[a][b] << " ";
        }
        output2 << ";" << endl;
    }
output2.close();

for(int i = 0; i < num_of_rows; ++i) {
        delete [] pixel_value[i];
}
    delete [] pixel_value;

for(int i = 0; i < num_of_rows; ++i) {
        delete [] integral[i];
}
    delete [] integral;

infile.close();  
system("pause");
return 0;
}


  
  //manejadorComandos();

*/