#include "../DtVideojuego.h"
#include "../../fabrica.h"
#include "../../IControladorUsuarios.h"

DtVideojuego::DtVideojuego(string nombre, string descripcion, float puntajePromedio, float totalDeHorasJugadas, string empresa, map<int,float> costos, vector<string> cats){

    this->nombre = nombre;
    this->descripcion = descripcion;
    this->puntajePromedio = puntajePromedio;
    this->totalDeHorasJugadas = totalDeHorasJugadas;
    this->empresa = empresa;
    auto iter = costos.find(1);
	this->costoMensual=iter->second;
	iter = costos.find(3);
	this->costoTrimestral=iter->second;
	iter = costos.find(12);
	this->costoAnual=iter->second;
	iter = costos.find(0);
	this->costoVitalicio=iter->second;
	this->cats = cats;
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

float DtVideojuego::getCostoMensual(){
	return this->costoMensual;
};

float DtVideojuego::getCostoTrimestral(){
	return this->costoTrimestral;
};

float DtVideojuego::getCostoAnual(){
	return this->costoAnual;
};

float DtVideojuego::getCostoVitalicio(){
	return this->costoVitalicio;
};

vector<string> DtVideojuego::getStringCats(){
	return this->cats;
}
//vector<DtCategoria> DtVideojuego::getDtCategorias(){
//	return this->datacategorias;
//}

ostream &operator<< (ostream &os, DtVideojuego* vi) {
	Fabrica* fabrica = Fabrica::getInstancia();
	iControladorUsuarios *ctrlUsuarios = fabrica->getControladorUsuarios();
	string tipo = ctrlUsuarios->getTipoUsuario();
	vector<string> categorias = vi->getStringCats();

	os 	<< "----------------------------------------\n"
		<< "Titulo: " << vi->getNombre() << endl
		<< "Empresa: " << vi->getEmpresa() << endl
		<< "Puntaje promedio: " << vi->getPuntajePromedio() << endl
		<< "Costo mensual: " << vi->getCostoMensual() << endl
		<< "Costo trimestral: " << vi->getCostoTrimestral() << endl
		<< "Costo anual: " << vi->getCostoAnual() << endl
		<< "Costo vitalicio: " << vi->getCostoVitalicio() << endl
		<< "Descripcion: " << vi->getDescripcion() << endl;

		if (tipo == "d") {
			os << "Total de horas jugadas: " << vi->getTotalDeHorasJugadas() << "\n";
		}
		os << "Categorias: " << endl;
		for (auto c : categorias){
			os << c << endl;
		}

		os << endl;

	return os;
};
