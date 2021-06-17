#include "../fabrica.h"
#include "../ControladorVideojuegos.h"
#include "../ControladorPartidas.h"
#include "../ControladorUsuarios.h"

ControladorVideojuegos* ControladorVideojuegos::instancia = NULL;
Fabrica *fab = Fabrica::getInstancia();

ControladorVideojuegos* ControladorVideojuegos::getInstancia() {
	if (instancia == NULL)
		instancia = new ControladorVideojuegos();

	return instancia;	
}

float ControladorVideojuegos::calcularEstadistica(int estadistica, string nomVideojuego) {
	bool encontre = false;
    float numeroEncontrado = 0.0;
	Estadistica* cat;

    for (auto f : ControladorVideojuegos::estadisticas){
        if (f->getID() == estadistica){
			return f->calcular(nomVideojuego);
		}
    }
	/*
    std::set<Estadistica*>::iterator it;
    for ( it = ControladorVideojuegos::estadisticas.begin(); it != ControladorVideojuegos::estadisticas.end(); ++it) {
    	Estadistica f = *it;
        DtEstadistica ret = f.getDataEstadistica();
        if (f->getDataEstadistica().getIdEstadistica() == estadistica){
			return f->calcular(f->getDataEstadistica().getNombre());
		}
	}
    */
	//falta calcular la estaditica que encontramos que esta en la variable cat
	return numeroEncontrado;
}


float ControladorVideojuegos::calcularHorasJugadas(string videojuego) {
	return fab->getControladorPartidas()->darHorasDePartida(videojuego);	
}

set<DtJugador> ControladorVideojuegos::jugadoresSuscriptosAVideojuego(string videojuego) {
	return fab->getControladorUsuarios()->listarJugadoresSuscriptosVideojuego(videojuego);
}

void ControladorVideojuegos::eliminarVideojuego(string nombre) {
    for (auto f : ControladorVideojuegos::videojuegos) {
        Videojuego v = *f;
		if (v.getNombre() == nombre){
			ControladorVideojuegos::videojuegos.erase(f);
		}
	}
    /*
	std::set<Videojuego*>::iterator it;
	for (it = ControladorVideojuegos::videojuegos.begin(); it != ControladorVideojuegos::videojuegos.end(); ++it) {
    	Videojuego v = *it;
		if (v.getNombre() == nombre){
			videojuegos.erase(it);
		}
	}
    */
    
}

set<DtVideojuego> ControladorVideojuegos::obtenerVideojuegos() {
	set<DtVideojuego> dtVideojuegos;
    for (auto f : ControladorVideojuegos::videojuegos) {
        Videojuego v = *f;
        DtVideojuego ret = DtVideojuego(v.getNombre(), v.getDescripcion(), 0, 0, "");//v.getPuntajes(), 0, v.getEmpresa());
        dtVideojuegos.insert(ret);
	}
	return dtVideojuegos;
}

void ControladorVideojuegos::confirmarEliminacion() { //no se que hace esto
	
}

bool ControladorVideojuegos::ingreseNombreVideojuego(string nombreVideojuego) { 
    bool ret = false;
    for (auto f : ControladorVideojuegos::videojuegos) {
        Videojuego v = *f;
        if (v.getNombre() == nombreVideojuego){
            return true;
        }
	}
	return ret;
}

set<DtEstadistica> ControladorVideojuegos::listarEstadisticas(string nombreVideojuego) {
	set<DtEstadistica> dtEstadisticas;
    for (auto f : ControladorVideojuegos::estadisticas) {
        DtEstadistica ret = DtEstadistica(f->getID(), f->getNombre(), f->getDescripcion(), f->calcular(nombreVideojuego));
        dtEstadisticas.insert(ret);
	}
	return dtEstadisticas;	
}

bool ControladorVideojuegos::esTemporal(Suscripcion *s) { //dudas, quien es el responsable de esto? 
    bool ret = false;
	return ret;
}

/*
Suscripcion* ControladorVideojuegos::ingresarNombre(string nombre) { //hay que hacer esta funcion
	Suscripcion s = Suscripcion();
	return s;
}
*/

void ControladorVideojuegos::ingresarCategoria(DtCategoria *cat) {
	
}

bool ControladorVideojuegos::existeVideojuego(string nombre) {
    bool ret = false;
    for (auto f : ControladorVideojuegos::videojuegos) {
        Videojuego v = *f;
        if (v.getNombre() == nombre){
            return true;
        }
	}
	return ret;
}

bool ControladorVideojuegos::existeCategoria(string nombre) {
    bool ret = false;
    for (auto f : ControladorVideojuegos::categorias) {
        Categoria v = *f;
        if (v.getNombre() == nombre){
            return true;
        }
	}
	return ret;
}

bool ControladorVideojuegos::existeEstadistica(int id) {
    bool ret = false;
    for (auto f : ControladorVideojuegos::estadisticas) {
        if (f->getID() == id){
            return true;
        }
	}
	return ret;
}