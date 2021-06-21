#include "../DtVideojuego.h"
#include "../../fabrica.h"
#include "../../IControladorUsuarios.h"

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
	Fabrica* fabrica = Fabrica::getInstancia();
	iControladorUsuarios *ctrlUsuarios = fabrica->getControladorUsuarios();
	string tipo = ctrlUsuarios->getTipoUsuario();
	
	os 	<< "----------------------------------------\n"
		<< "Titulo: " << vi->getNombre() << endl
		<< "Empresa: " << vi->getEmpresa() << endl;
		if (tipo == "d") {
			os << "Puntaje promedio: " << vi->getPuntajePromedio() << endl;
		}
		os << "Descripcion: " << vi->getDescripcion() << endl;
		if (tipo == "d") {
			os << "Total de horas jugadas: " << vi->getTotalDeHorasJugadas() << "\n";
		}

	return os;
}
