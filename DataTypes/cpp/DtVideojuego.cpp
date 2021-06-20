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

ostream &operator<< (ostream &os, DtVideojuego* vi) {
	os 	<< "----------------------------------------\n"
		<< "Titulo: " << vi->getNombre() << endl
		<< "Empresa: " << vi->getEmpresa() << endl
		<< "Puntaje promedio: " << vi->getPuntajePromedio() << endl
		<< "Descripcion: " << vi->getDescripcion() << endl
		<< "Total de horas jugadas: " << vi->getTotalDeHorasJugadas() << "\n";

	return os;
}
