#include "../DtJugador.h"

DtJugador::DtJugador(string emai, string contrasenia, string nick, string descripcion){
    email = emai;
    this->contrasenia = contrasenia;
    nickname = nick;
    this->descripcion = descripcion;
};
string DtJugador::getEmail(){
    return this->email;
};
string DtJugador::getContrasenia(){
    return this->contrasenia;
};
string DtJugador::getNickname() const{
    return nickname;
};
string DtJugador::getDescripcion(){
    return this->descripcion;
};