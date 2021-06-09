#include "DtFechaHora.h"
#include "DtPartida.h"
#include "Comentario.h"
#include <string>
using namespace std;

class Partida {

protected:
	int idParida;
	DtFechaHora duracion;
	DtFechaHora FechaInicio;
	string Videojuego;
public:
	//Constructor
	Partida(int idpartida, DtFechaHora duracion, DtFechaHora FechaInicio);
	//Destructor
	~Partida();
	//Setters
	void setIdPartida(int id);
	void setDuracion(DtFechaHora duracion);
	void setFechaInicio(DtFechaHora fechainicio);
	void setVideoJuego(string juego);
	//Getters
	int getPartida();
	DtFechaHora getDuracion();
	DtFechaHora getFechaInicio();
	string getVideojuego();
	//operaciones
	float darTotalDeHorasParticipantes();
	virtual terminarPartida();
	DtPartida getDataPartida();
};
