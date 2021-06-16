#include "../DtJugador.h"

DtJugador::DtJugador(string email, string contrasenia, string nickname, string descripcion){
    this->email = email;
    this->contrasenia = contrasenia;
    this->nickname = nickname;
    this->descripcion = descripcion;
};
string DtJugador::getEmail(){
    return this->email;
};
string DtJugador::getContrasenia(){
    return this->contrasenia;
};
string DtJugador::getNickname(){
    return this->nickname;
};
string DtJugador::getDescripcion(){
    return this->descripcion;
};