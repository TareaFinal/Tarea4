#include "../Videojuego.h"
#include "../fabrica.h"

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

Videojuego::Videojuego(string n, string d, Desarrollador *desarrollador, vector<Categoria*> categorias, const map_type) {
	Fabrica *fabrica = Fabrica::getInstancia();
	iControladorVideojuegos *controlador = fabrica->getControladorVideojuegos(); 
	if (!controlador->existeVideojuego(n)) {
		this->nombre = n;
		this->descripcion = d;
		this->costos = map_type();
		this->desarrollador = desarrollador;
		this->categorias = categorias;
		this->puntajesIngresados = 0;
		
		cout << "Videojuego creado correctamente\n.";
		
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

int Videojuego::getCantidadJugadoresSuscriptos() { /////////////////// Arreglar. No se controla que sean solo las activas
	return this->suscripciones.size();
}

vector<Categoria*> Videojuego::getCategorias() {
	return this->categorias;
}

vector<Suscripcion*> Videojuego::getSuscripciones() {
	return this->suscripciones;
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
	this->puntajes.push_back(puntaje); 
	this->puntajesIngresados++;
	cout << "Puntaje agregado\n";
}

void Videojuego::agregarCategoria(Categoria *c) {
	bool existe = false;
	for (auto it = this->categorias.begin(); it != this->categorias.end(); ++it) {
		if (*it == c) {
			existe = true;
			break;
		}		
	}
	
	if (!existe) {
		this->categorias.push_back(c);
		cout << "Categoria agregada correctamente al videojuego\n.";
	} else {
		cout << "La ya existe la categoria en este videojuego\n.";
	}
}

void Videojuego::agregarSuscripcion(Suscripcion *s) {
	bool existe = false;
	for (auto it = this->suscripciones.begin(); it != this->suscripciones.end(); ++it) {
		if (*it == s) {
			existe = true;
			break;
		}		
	}
	
	if (!existe) {
		this->suscripciones.push_back(s);
		cout << "Suscripción agregada correctamente al videojuego\n.";
	} else {
		cout << "La ya existe una suscripción en este videojuego\n.";
	}
}

void Videojuego::agregarEstadistica(Estadistica *e) {
	vector<Estadistica*>::iterator it = find(this->estadisticas.begin(), this->estadisticas.end(), e);
	
	if (it != this->estadisticas.end()) {
		this->estadisticas.push_back(e);
		cout << "Estadística agregada correctamente\n.";
	} else {
		cout << "La estadística ya está ingresada en el videojuego\n.";
	}
}

void Videojuego::eliminarCategoria(Categoria *c) {
	
	for (auto it = this->categorias.begin(); it != this->categorias.end(); ++it) {
		if (*it == c) {
			this->categorias.erase(it++);
			cout << "Categoría removida correctamente\n.";
			break;
		}		
	}
}

void Videojuego::eliminarSuscripcion(Suscripcion *s) {
	for (auto it = this->suscripciones.begin(); it != this->suscripciones.end(); ++it) {
		if (*it == s) {
			this->suscripciones.erase(it++);
			cout << "Suscripción removida correctamente\n.";
			break;
		}		
	}
}

void Videojuego::eliminarEstadistica(Estadistica *e) {
	for (auto it = this->estadisticas.begin(); it != this->estadisticas.end(); ++it) {
		if (*it == e) {
			this->estadisticas.erase(it++);
			cout << "Estadística removida correctamente\n.";
			break;
		}		
	}
}

float Videojuego::calcularEstadistica(int idEstadistica) {
	float ret = 0.0;
	for (auto it = this->estadisticas.begin(); it != this->estadisticas.end(); ++it) {
		if ((*it)->getID() == idEstadistica) {
			this->estadisticas.erase(it++);
			ret = (*it)->calcular(this->nombre);
		}		
	} 
	return ret;         										
}


vector<DtJugador> Videojuego::getJugadoresSuscriptos() {
	vector<DtJugador> jugadores;
	for (auto it = this->suscripciones.begin(); it != this->suscripciones.end(); ++it) {
			Jugador* j = (*it)->getJugador();
			DtJugador dataJugador = DtJugador(j->getEmail(), j->getContrasenia(), j->getNick(), j->getDescripcion());
			jugadores.push_back(dataJugador);
		}
	return jugadores;
}



float Videojuego::calcularPuntajePromedio() {
	float promedio = 0.0;
	int suma = 0;
	if (this->puntajesIngresados > 0) {
		for (auto it = this->puntajes.begin(); it != this->puntajes.end();++it) {
			suma = suma + (*it);
		}
		promedio = suma/(this->puntajes.size());	
	}
	
	return promedio;
}

DtVideojuego *Videojuego::getDataVideojuego() {
	DtVideojuego *dataVideojuego = new DtVideojuego(this->nombre, this->descripcion, this->calcularPuntajePromedio(), this->calcularEstadistica(2), this->desarrollador->getEmpresa()); /////////////////////////////// ¿Qué le paso al constructor?
	return dataVideojuego;
}

