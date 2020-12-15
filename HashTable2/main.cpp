#include <iostream>
#include "Info.h"

int main(){
    
    Info info(707);
    info.readData("datosOrdenadosHT.txt");   
    info.findIp("10.15.170.223");
}

