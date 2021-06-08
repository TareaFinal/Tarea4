#include "DtFechaHora.h"
#include <string>
using namespace std;

class partida {

private:
	int idComentario;
	DtFechaHora Fecha;
	string texto;
public:
	//Constructor
	Comentario(int idComent, DtFechaHora fecha,string texto);
	//Destructor
	~Comentario();
	//Setters
	void setIdComentario(int idComent);
	void setFecha(DtFechaHora date);
	void setTexto(string texto);
	//Getters
	int getIdComentario();
	DtFechaHora getFechaHora();
	string getTexto();
};
