#include "../partida.h"
#include <string>
#include <iostream>
using namespace std;
	
	// Setters
void Partida::setIdPartida(int id){
	this->idPartida=id;
}
void Partida::setDuracion(DtFechaHora* dur){
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
DtFechaHora* Partida::getDuracion(){
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

DtFechaHora *Partida::diferencia(DtFechaHora *fechaInicial, DtFechaHora *fechafin){
		int anio=fechafin->getAnio() - fechaInicial->getAnio();
		int mes=fechafin->getMes() - fechaInicial->getMes();
		int dia=fechafin->getDia() - fechaInicial->getDia();
		int hora=fechafin->getHora() - fechaInicial->getHora();
		int minuto=fechafin->getMinuto() - fechaInicial->getMinuto();
		if (minuto<0){
			hora=hora-1;
			minuto=60-abs(minuto);
		}
		if (hora<0){
			dia=dia-1;
			hora=24-abs(hora);
		}
		if (dia<0){
			mes=mes-1;
			dia=30-abs(dia);
		}
		if (mes<0){
			anio=anio-1;
			mes=12-abs(mes);
		}
		DtFechaHora *dur= new DtFechaHora(anio,mes,dia,hora,minuto);
		return dur;
		
		
}
