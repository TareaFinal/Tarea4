#include "../partida.h"
#include <string>
#include <iostream>
using namespace std;
	
	// Setters
void Partida::setIdPartida(int id){
	this->idPartida=id;
}
void Partida::setDuracion(float dur){
	this->duracion=dur;
}
void Partida::setFechaInicio(DtFechaHora *fechainicio){
	FechaInicio=fechainicio;
}
void Partida::setVideoJuego(string juego){
	this->Videojuego=juego;
}
void Partida::setJugador(string jugador){
	this->duenio=jugador;
}
// Getters
int Partida::getPartida(){
	return this->idPartida;
}
float Partida::getDuracion(){
	return this->duracion;
}
DtFechaHora* Partida::getFechaInicio(){
	return this->FechaInicio;
}
string Partida::getVideojuego(){
	return this->Videojuego;
}
string Partida::getJugador(){
	return this->duenio;
}

float Partida::diferencia(DtFechaHora *fechaInicial, DtFechaHora *fechafin){

		double minFin = (double) fechafin->getMinuto();
		double minInicio = (double) fechaInicial->getMinuto();

		double fin = (double) (fechafin->getAnio()*365*24 + fechafin->getMes()*30*24 + fechafin->getDia()*24 + fechafin->getHora()) + minFin/60;
		double inicio = (double) (fechaInicial->getAnio()*365*24 + fechaInicial->getMes()*30*24 + fechaInicial->getDia()*24 + fechaInicial->getHora()) + minInicio/60;
		
		float horasDeJuego =  fin - inicio;
		return horasDeJuego;
}
