#include "../DtCategoria.h"

DtCategoria::DtCategoria(string nombre, string tipo, string descripcion){
    this->nombre = nombre;
    this->tipo = tipo;
    this->descripcion = descripcion;
};
string DtCategoria::getNombre(){
    return this->nombre;
};
string DtCategoria::getTipo(){
    return this->tipo;
};
string DtCategoria::getDescripcion(){
    return this->descripcion;
};