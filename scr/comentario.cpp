#include "../comentario.h"
#include <string>
#include <iostream>
using namespace std;

	// Constructor
Comentario::Comentario(int idComent, DtFechaHora fecha, string texto, PartidaMultijugador* partida)
{
	idComentario=idComent;
	Fecha=fecha;
	texto=texto;
	partida=partida;
}
	// Destructor
Comentario::~Comentario() {
	}
	
	// Setters
void Comentario::setIdComentario(int id){
	idComent=id;
}
void Comentario::setFecha(DtFechaHora date){
	fecha=date;
}
void Comentario::setTexto(string texto){
	texto=texto;
}
void setPartidaMultijugador(PartidaMultijugador* partida){
	partida=partida
}
	
	// Getters
int Comentario::getIdComentario() {
	return idComent;
}
DtFechaHora Comentario::getFechaHora() {
	return fecha;
}
int Comentario::getTexto() {
	return texto;
}
PartidaMultijugador* getPartidaMultijugador(){
	return partida;
}

	//no hay funciones
}
