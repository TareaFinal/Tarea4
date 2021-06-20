#include "../DtPartidaIndividual.h"

DtPartidaIndividual::DtPartidaIndividual(int idPartida, DtFechaHora *duracion, DtFechaHora *fechaInicio, string nickname, string videojuego, int partidaContinuada) { 
	this->idPartida = idPartida; 
	this->duracion = duracion; //no deberia de ser de tipo float?
    this->fechaInicio = fechaInicio;
    this->nicknameCreador = nickname;
    this->videojuego = videojuego;
    this->partidaContinuada = partidaContinuada;
}

int DtPartidaIndividual::getPartidaContinuada(){
    return this->partidaContinuada;
}

ostream &operator<< (ostream &os, DtPartidaIndividual* pi) { 
	os << "----------------------------------------\n"
	   << "---Partida Individual---" << endl
       << "Id: " << pi->getIdPartida() << "\n"
       << "Duracion: " <<  pi->getDuracion()->getDia() << "/" << pi->getDuracion()->getMes() << "/" << pi->getDuracion()->getAnio() << " Esto es un DtFechahora, ojo!!!\n" //aca devuelve algo de tipo fechahora, revisar!
       << "Fecha de inicio: " <<  pi->getFechaInicio()->getDia() << "/" << pi->getFechaInicio()->getMes() << "/" << pi->getFechaInicio()->getAnio() << " Esto es un DtFechahora, ojo!!!\n"
       << "Creador: " << pi->getNicknameCreador() << "\n"
       << "Videojuego: " << pi->getVideojuego() << "\n"
       << "Es continuacion: ";

    if (pi->getPartidaContinuada() != 0)
   		os	<< "Si, continua la partida numero "<< pi->getPartidaContinuada() <<"\n";
	else 
   		os	<< "No\n";
	   
	return os;
};
