#ifndef CATEGORIA
#define CATEGORIA 

#include "DataTypes/DtCategoria.h"
#include "Desarrollador.h"
#include "ControladorVideojuegos.h"



class Categoria {
	private: 
		string nombre;
		string tipo;
		string descripcion;
		Desarrollador *desarrollador;
	
	public:
		Categoria(string n, string t, string d, Desarrollador *desarrollador);
		string getNombre();
		string getTipo();
		string getDescripcion();
		DtCategoria *getDataCategoria();
		
		void setNombre(string nombre);
		void setTipo(string tipo);
		void setDescripcion(string descripcion);
		void setDesarrollador(Desarrollador *desarrollador);
};

#endif
