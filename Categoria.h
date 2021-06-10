#ifndef CATEGORIA
#define CATEGORIA 

#import "../DtCategoria.h"
#import "../Desarrollador.h"

#include <string>

class Categoria {
	private: 
		string nombre
		string tipo
		string descripcion;
		Desarrollador desarrollador;
	
	public:
		string getNombre()
		string getTipo()
		string getDescripcion()
		DtCategoria getDataCategoria();
		
		void setNombre(string nombre);
		void setTipo(string tipo);
		void setDescripcion(string descripcion);
		void setDesarrollador(Desarrollador desarrollador);
};

#endif
