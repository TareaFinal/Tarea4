#include "../DtEstadistica.h"

DtEstadistica::DtEstadistica(int idEstadistica, string nombre,	string descripcion,	float valor){
    this->idEstadistica = idEstadistica;
    this->nombre = nombre;
    this->descripcion = descripcion;
    this->valor = valor;
};
int DtEstadistica::getIdEstadistica(){
    return this->idEstadistica;
};
string DtEstadistica::getNombre(){
    return this->nombre;
};
string DtEstadistica::getDescripcion(){
    return this->descripcion;
};
float DtEstadistica::getValor(){
    return this->valor;
};