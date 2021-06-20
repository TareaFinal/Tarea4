#include "../Categoria.h"


#include <string>

Categoria::Categoria(string n, string t, string d, Desarrollador *desarrollador) {
	Fabrica *fabrica = Fabrica::getInstancia();
	iControladorVideojuegos *controlador = fabrica->getControladorVideojuegos(); 
	if (!controlador->existeCategoria(n)) {
		this->nombre = n;
		this->tipo = t;
		this->descripcion = d;
		if (desarrollador != NULL)
			this->desarrollador = desarrollador;
		
		cout << "Categoría ingresada correctamente.";
		
	} else {
		cout << "Ya existe una categoría con ese nombre.";
	}
}

string Categoria::getNombre(){
	return this->nombre;
}

string Categoria::getTipo() {
	return this->tipo;
}
		
string Categoria::getDescripcion() {
	return this->descripcion;
}
		
DtCategoria *Categoria::getDataCategoria() {
	DtCategoria *dataCategoria = new DtCategoria(this->nombre, this->tipo, this->descripcion);			/////// ¿Qué le paso al Dt?
	return dataCategoria;
}
		
void Categoria::setNombre(string nombre) {
	Fabrica *fabrica = Fabrica::getInstancia();
	iControladorVideojuegos *controlador = fabrica->getControladorVideojuegos(); 
	if (!controlador->existeCategoria(nombre))
		this->nombre = nombre;
	else 
		cout << "Ya existe una categoría con ese nombre.";
}

void Categoria::setTipo(string tipo) {
	this->tipo = tipo;
}

void Categoria::setDescripcion(string descripcion) {
	this->descripcion = descripcion;
}

void Categoria::setDesarrollador(Desarrollador *desarrollador) {
	if (desarrollador != NULL)
		this->desarrollador = desarrollador;
}
