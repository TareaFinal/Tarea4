#ifndef COMENTARIO
#define COMENTARIO

#include "DataTypes/DtFechaHora.h"
#include "partidaMultijugador.h"
#include <string>
using namespace std;


class Comentario {

private:
	int idComentario;
	DtFechaHora *Fecha;
	Jugador *jugador;
	string texto;
	PartidaMultijugador *partida; //la partida multijugador que realiza el comentario
public:
	//Constructor
	Comentario(int idComent, Jugador *jugador,string texto, PartidaMultijugador *partida);
	//Destructor
	~Comentario();
	//Setters
	void setIdComentario(int idComent);
	void setFecha(DtFechaHora *date);
	void setTexto(string texto);
	//Getters
	int getIdComentario();
	DtFechaHora *getFechaHora();
	string getTexto();
};

#endif
