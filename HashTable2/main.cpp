#include <iostream>
#include "Info.h"

int main(){
    Info info(707);
    info.readData("datosOrdenadosHT.txt");
    //info.printData();
    info.findIp("10.15.170.220");
   
    info.findIp("10.15.170.223");
    
}

