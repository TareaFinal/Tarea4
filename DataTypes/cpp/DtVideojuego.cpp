#include "../DtVideojuego.h"

DtVideojuego::DtVideojuego(string nombre, string descripcion, float puntajePromedio, float totalDeHorasJugadas, string empresa){

    this->nombre = nombre;
    this->descripcion = descripcion;
    this->puntajePromedio = puntajePromedio;
    this->totalDeHorasJugadas = totalDeHorasJugadas;
    this->empresa = empresa;
};

string DtVideojuego::getNombre(){
    return this->nombre;
};

string DtVideojuego::getDescripcion(){
    return this->descripcion;
};

float DtVideojuego::getPuntajePromedio(){
    return this->puntajePromedio;
};

float DtVideojuego::getTotalDeHorasJugadas(){
    return this->totalDeHorasJugadas;
};

string DtVideojuego::getEmpresa(){
    return this->empresa;
};