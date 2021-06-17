#include "../Videojuego.h"
#include "../Fabrica.h"

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

Videojuego::Videojuego::Videojuego(string n, string d, float* costos, Desarrollador *desarrollador) {
	Fabrica *fabrica = Fabrica::getInstancia();
	iControladorVideojuegos *controlador = fabrica->getControladorVideojuegos(); 
	if (!controlador->existeVideojuego(n)) {
		this->nombre = n;
		this->descripcion = d;
		this->costos = costos;
		this->desarrollador = desarrollador;
		
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

float *Videojuego::getCostos() {
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

				
DtVideojuego *Videojuego::getDataVideojuego(float promedio, float totalDeHorasJugadas) {
	DtVideojuego *dataVideojuego = new DtVideojuego(this->nombre, this->descripcion, promedio, totalDeHorasJugadas, this->desarrollador->getEmpresa()); /////////////////////////////// ¿Qué le paso al constructor?
	return dataVideojuego;
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
		
void Videojuego::setCostos(float *costos) {
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
		cout << "La categoría ya está ingresada en el videojuego.";
	}
}

void Videojuego::agregarSuscripcion(Suscripcion *s) {
	vector<Suscripcion*>::iterator it = find(this->suscripciones.begin(), this->suscripciones.end(), s);
	
	if (it != this->suscripciones.end()) {
		this->suscripciones.push_back(s);
		cout << "Suscripción agregada correctamente.";
	} else {
		cout << "La ya existe una suscripción en este videojuego.";
	}
}

void Videojuego::agregarEstadistica(Estadistica *e) {
	vector<Estadistica*>::iterator it = find(this->estadisticas.begin(), this->estadisticas.end(), e);
	
	if (it != this->estadisticas.end()) {
		this->estadisticas.push_back(e);
		cout << "Estadística agregada correctamente.";
	} else {
		cout << "La estadística ya está ingresada en el videojuego.";
	}
}
/*
void Videojuego::eliminarCategoria(Categoria *c) {

	vector<Categoria*>::iterator it = find(this->categorias.begin(), this->categorias.end(), c);
	int posicion = distance(this->categorias.begin(), (*it));
	this->categorias.erase(posicion);
	cout << "Categoría removida correctamente.";
}

void Videojuego::eliminarSuscripcion(Suscripcion *s) {
	vector<Suscripcion*>::iterator it = find(this->suscripciones.begin(), this->suscripciones.end(), s);
	int posicion = distance(this->suscripciones.begin(), (*it));
	this->suscripciones.erase(posicion);
	cout << "Suscripción removida correctamente.";
}

void Videojuego::eliminarEstadistica(Estadistica *e) {
	vector<Estadistica*>::iterator it = find(this->estadisticas.begin(), this->estadisticas.end(), e);
	int posicion = distance(this->estadisticas.begin(), (*it));
	this->estadisticas.erase(posicion);
	cout << "Estadística removida correctamente.";
}

float Videojuego::calcularEstadistica(int idEstadistica) {
	for (int i = 0; i <= estadisticas.size(); i++)              // Busca la estadística por ID.
		if (estadisticas[i].getID() == idEstadistica) 				
			return (estadisticas[i].calcular(this->nombre));					// Si la encuentra la calcula y retorna el resultado.											
}

int Videojuego::calcularPuntajePromedio() {
	float promedio = 0.0;
	int suma = 0;
	if (this->puntajes.size() != 0)
	{
		vector<int>::iterator it;
		for (it = this->puntajes.begin(); it != this->puntajes.end(); ++it)
			suma = suma + it;
		promedio = suma/(this->puntajes.size());	
	}
	
	return promedio;
}
*/
