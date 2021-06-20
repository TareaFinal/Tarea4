#include "../Videojuego.h"
#include "../fabrica.h"

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

Videojuego::Videojuego::Videojuego(string n, string d, map<int,float> costos, Desarrollador *desarrollador , vector<Categoria*> catVideojuego) {
	Fabrica *fabrica = Fabrica::getInstancia();
	iControladorVideojuegos *controlador = fabrica->getControladorVideojuegos(); 
	if (!controlador->existeVideojuego(n)) {
		this->nombre = n;
		this->descripcion = d;
		this->costos = costos;
		this->desarrollador = desarrollador;
		this->categorias = categorias;
		
		cout << "Videojuego creado correctamente.";
		
	} else {
		cout << "Ya existe un videojuego con este nombre.";
	}
}

string Videojuego::getNombre() {
	return this->nombre;
}

string Videojuego::getDescripcion() {
	return this->descripcion;
}

map<int,float> Videojuego::getCostos() {
	return this->costos;
}

vector<int> Videojuego::getPuntajes() {
	return this->puntajes;
}

int Videojuego::getCantidadJugadoresSuscriptos() {
	return this->suscripciones.size();
}

vector<Categoria*> Videojuego::getCategorias() {
	return this->categorias;
}

vector<Suscripcion*> Videojuego::getSuscripciones() {
	return this->suscripciones;
}

				
DtVideojuego *Videojuego::getDataVideojuego() {
	DtVideojuego *dataVideojuego = new DtVideojuego(this->nombre, this->descripcion, this->calcularPuntajePromedio(), this->calcularEstadistica(2), this->desarrollador->getEmpresa()); /////////////////////////////// �Qu� le paso al constructor?
	return dataVideojuego;
}

Desarrollador* Videojuego::getDesarrollador() {
	return this->desarrollador;
}


void Videojuego::setNombre(string nombre) {
	Fabrica *fabrica = Fabrica::getInstancia();
	iControladorVideojuegos *controlador = fabrica->getControladorVideojuegos(); 
	if (!controlador->existeVideojuego(nombre))
		this->nombre = nombre;
	else 
		cout << "Ya existe un videojuego con este nombre.";
}

void Videojuego::setDescripcion(string descripcion) {
	this->descripcion = descripcion;
}
		
void Videojuego::setCostos(map<int,float> costos) {
	this->costos = costos;
}
		
void Videojuego::agregarPuntaje(int puntaje) {
	this->puntajes.push_back(puntaje); ////////////////////////////////////////
}

void Videojuego::agregarCategoria(Categoria *c) {
	vector<Categoria*>::iterator it = find(this->categorias.begin(), this->categorias.end(), c);
	
	if (it != this->categorias.end()) {
		this->categorias.push_back(c);
		cout << "Categoria agregada correctamente.";
	} else {
		cout << "La categor�a ya est� ingresada en el videojuego.";
	}
}

void Videojuego::agregarSuscripcion(Suscripcion *s) {
	vector<Suscripcion*>::iterator it = find(this->suscripciones.begin(), this->suscripciones.end(), s);
	
	if (it != this->suscripciones.end()) {
		this->suscripciones.push_back(s);
		cout << "Suscripci�n agregada correctamente.";
	} else {
		cout << "La ya existe una suscripci�n en este videojuego.";
	}
}

void Videojuego::agregarEstadistica(Estadistica *e) {
	vector<Estadistica*>::iterator it = find(this->estadisticas.begin(), this->estadisticas.end(), e);
	
	if (it != this->estadisticas.end()) {
		this->estadisticas.push_back(e);
		cout << "Estad�stica agregada correctamente.";
	} else {
		cout << "La estad�stica ya est� ingresada en el videojuego.";
	}
}

void Videojuego::eliminarCategoria(Categoria *c) {
	
	for (auto it = this->categorias.begin(); it != this->categorias.end();) {
		if (*it == c) {
			this->categorias.erase(it++);
			cout << "Categor�a removida correctamente.";
			break;
		}		
	}
}

void Videojuego::eliminarSuscripcion(Suscripcion *s) {
	for (auto it = this->suscripciones.begin(); it != this->suscripciones.end();) {
		if (*it == s) {
			this->suscripciones.erase(it++);
			cout << "Suscripci�n removida correctamente.";
			break;
		}		
	}
}

void Videojuego::eliminarEstadistica(Estadistica *e) {
	for (auto it = this->estadisticas.begin(); it != this->estadisticas.end();) {
		if (*it == e) {
			this->estadisticas.erase(it++);
			cout << "Estad�stica removida correctamente.";
			break;
		}		
	}
}

float Videojuego::calcularEstadistica(int idEstadistica) {
	for (auto it = this->estadisticas.begin(); it != this->estadisticas.end();) {
		if ((*it)->getID() == idEstadistica) {
			this->estadisticas.erase(it++);
			return (*it)->calcular(this->nombre);
		}		
	}          										
}

float Videojuego::calcularPuntajePromedio() {
	float promedio = 0.0;
	int suma = 0;
	if (this->puntajes.size() != 0)
	{
		for (auto it = this->puntajes.begin(); it != this->puntajes.end();)
			suma = suma + (*it);
		promedio = suma/(this->puntajes.size());	
	}
	
	return promedio;
}

