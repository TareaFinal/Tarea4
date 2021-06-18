#include "../fabrica.h"
#include "../ControladorVideojuegos.h"

ControladorVideojuegos *ControladorVideojuegos::instancia = NULL;
Fabrica *fab = Fabrica::getInstancia();

ControladorVideojuegos *ControladorVideojuegos::getInstancia() {
	if (instancia == NULL)
		instancia = new ControladorVideojuegos();

	return instancia;	
}

ControladorVideojuegos::ControladorVideojuegos() {
	
}

float ControladorVideojuegos::calcularEstadistica(int estadistica, string nomVideojuego) {
	
    bool encontre = false;
    float numeroEncontrado = 0.0;
        Estadistica* cat;

    for (auto f : ControladorVideojuegos::estadisticas){
        if (f->getID() == estadistica){
                        return f->calcular(nomVideojuego);//nomVideojuego);
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

    //return numeroEncontrado;

    return 0.0;
}


float ControladorVideojuegos::calcularHorasJugadas(string videojuego) {
	return fab->getControladorPartidas()->darHorasDePartida(videojuego);	
}

vector<DtJugador> ControladorVideojuegos::jugadoresSuscriptosAVideojuego(string videojuego) {
	return fab->getControladorUsuarios()->listarJugadoresSuscriptosVideojuego(videojuego);
}

void ControladorVideojuegos::eliminarVideojuego(string nombre) {
	for (auto f : ControladorVideojuegos::videojuegos) {
        Videojuego v = *f;
        if (v.getNombre() == nombre){
                ControladorVideojuegos::videojuegos.erase(f);
        }
    }
}

vector<DtVideojuego> ControladorVideojuegos::obtenerVideojuegos() {
//	set<DtVideojuego> videojuegos;
//	return videojuegos;
	vector<DtVideojuego> dtVideojuegos;
    for (auto f : ControladorVideojuegos::videojuegos) {
        DtVideojuego ret = DtVideojuego(f->getNombre(), f->getDescripcion(), 0.0, 0.0, f->getDesarrollador()->getEmpresa());
        dtVideojuegos.push_back(ret);
        //dtEstadisticas.insert(ret);
        }
    return dtVideojuegos;
}

void ControladorVideojuegos::confirmarEliminacion() {
	
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

vector<DtEstadistica> ControladorVideojuegos::listarEstadisticas(string nombreVideojuego) {
    /**/
    vector<DtEstadistica> dtEstadisticas;
    for (auto f : ControladorVideojuegos::estadisticas) {
        DtEstadistica ret = DtEstadistica(f->getID(), f->getNombre(), f->getDescripcion(), f->calcular(nombreVideojuego));
        dtEstadisticas.push_back(ret);
        //dtEstadisticas.insert(ret);
        }
    return dtEstadisticas;
    /**/
	//set<DtEstadistica> estadisticas;
	//return estadisticas;
	
}

bool ControladorVideojuegos::esTemporal(Suscripcion *s) {
	return true;
}

Suscripcion *ControladorVideojuegos::ingresarNombre(string nombre) {
	Suscripcion *s = NULL;
	return s;
}

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
