#include "../ControladorVideojuegos.h"
#include "../temporal.h"
#include "../vitalicia.h"
#include "../DataTypes/DtCategoria.h"
#include "../Estadistica1.h"
#include "../Estadistica2.h"

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
                        numeroEncontrado = f->calcular(nomVideojuego);//nomVideojuego);
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

vector<DtJugador> ControladorVideojuegos::jugadoresSuscriptosAVideojuego(string videojuego) {
	vector<DtJugador> jugadores;
	
	for (auto f : ControladorVideojuegos::videojuegos) {
        Videojuego *v = f;
        if (v->getNombre() == videojuego){
              jugadores = v->getJugadoresSuscriptos();
        }
    }
	return jugadores;
}

void ControladorVideojuegos::eliminarVideojuego(string nombre) {
    this->nomVJaEliminar = nombre;
}

vector<DtVideojuego> ControladorVideojuegos::solicitarVideojuegos() {
//	set<DtVideojuego> videojuegos;
//	return videojuegos;
	vector<DtVideojuego> dtVideojuegos;
    for (auto f : ControladorVideojuegos::videojuegos) {
    	Videojuego* v = f;
        float totHoras = fab->getControladorPartidas()->darHorasDePartida(f->getNombre());
        vector<string> cats;
        for (auto c : f->getCategorias()){
            cats.push_back(c->getNombre());
        }
        DtVideojuego ret = DtVideojuego(v->getNombre(), v->getDescripcion(), v->calcularPuntajePromedio(), totHoras, v->getDesarrollador()->getEmpresa(), v->getCostos(), cats);
        dtVideojuegos.push_back(ret);
        //dtEstadisticas.insert(ret);
        }
    return dtVideojuegos;
}

vector<DtVideojuego> ControladorVideojuegos::obtenerVideojuegosDes() {
	vector<DtVideojuego> dtVideojuegos;
    for (auto f : ControladorVideojuegos::videojuegos) {
        if(f->getDesarrollador()->getEmail() == fab->getControladorUsuarios()->getUsuarioEnSesion()){
            float totHoras = fab->getControladorPartidas()->darHorasDePartida(f->getNombre());
            vector<string> cats;
            for (auto c : f->getCategorias()){
                cats.push_back(c->getNombre());
            }
            DtVideojuego ret = DtVideojuego(f->getNombre(), f->getDescripcion(), f->calcularPuntajePromedio(), totHoras, f->getDesarrollador()->getEmpresa(), f->getCostos(), cats);
            dtVideojuegos.push_back(ret);
        }
    }
    return dtVideojuegos;
}

vector<string> ControladorVideojuegos::obtenerVideojuegosDesFinalizados() {
    
	vector<string> dtVideojuegos;
    for (auto f : ControladorVideojuegos::videojuegos) {
        if(f->getDesarrollador()->getEmail() == fab->getControladorUsuarios()->getUsuarioEnSesion()){
            float totHoras = fab->getControladorPartidas()->darHorasDePartida(f->getNombre());
            vector<string> cats;
            for (auto c : f->getCategorias()){
                cats.push_back(c->getNombre());
            }
            DtVideojuego ret = DtVideojuego(f->getNombre(), f->getDescripcion(), f->calcularPuntajePromedio(), totHoras, f->getDesarrollador()->getEmpresa(), f->getCostos(), cats);
            dtVideojuegos.push_back(f->getNombre());
        }
    }
    //return dtVideojuegos;
    return fab->getControladorPartidas()->darSinFinalizar(dtVideojuegos);
}

void ControladorVideojuegos::confirmarEliminacion() {
		for (auto f : ControladorVideojuegos::videojuegos) {
        Videojuego *v = f;
        if (v->getNombre() == this->nomVJaEliminar){
                fab->getControladorPartidas()->eliminarPartidasVideojuego(nomVJaEliminar);
                ControladorVideojuegos::videojuegos.erase(f);
                delete v;
        }
    }
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

vector<string> ControladorVideojuegos::consultarEstadisticas(string nombreVideojuego) {
    /**/
    vector<string> estadisticasAMostrar;
    for (auto f : ControladorVideojuegos::estadisticas) {
        string ret = "Nombre: " + f->getNombre() + " Valor: " + to_string(f->calcular(nombreVideojuego)); 
        estadisticasAMostrar.push_back(ret);
        //dtEstadisticas.insert(ret);
        }
    return estadisticasAMostrar;
    /**/
	//set<DtEstadistica> estadisticas;
	//return estadisticas;
}

vector<DtEstadistica> ControladorVideojuegos::listarEstadisticas() {
	vector<DtEstadistica> dtEstadisticas;
    for (auto f : ControladorVideojuegos::estadisticas) {
        DtEstadistica ret = DtEstadistica(f->getID(), f->getNombre(), f->getDescripcion(), 0);
        dtEstadisticas.push_back(ret);
        //dtEstadisticas.insert(ret);
        }
    return dtEstadisticas;
	
}


bool ControladorVideojuegos::esTemporal(string videojuego) { // precondicion el videojuego tiene una suscripcion, devuelve true si su suscripcion es temporal
	vector<DtJugador> jugadores;
	string tipo;
	vector<Suscripcion*> suscripciones;
	for (auto f : this->videojuegos) {
        if (f->getNombre() == videojuego){
            suscripciones=f->getSuscripciones();
            break;
        }
    }
	for (auto f : suscripciones) {
	    Suscripcion *s = f;
	    if (s->getJugador()->getEmail()==fab->getControladorUsuarios()->getUsuarioEnSesion()){
	      	tipo = s->TipoSuscripcion();
		}
	}	
    return (tipo=="temporal");	
}

Suscripcion *ControladorVideojuegos::ingresarNombre(string nombre) {
	Suscripcion *s = NULL;
	return s;
}

void ControladorVideojuegos::ingresarCategoria(string nombre, string tipo, string descripcion) {
	bool encontreCategoria = false;
	for (auto f : ControladorVideojuegos::categorias) {
        Categoria v = *f;
        if (nombre == v.getNombre()){
            encontreCategoria = true;
        }   
    }
    
    Desarrollador *des = fab->getControladorUsuarios()->getDesarrolladorEnSesion();
    if(!encontreCategoria){
        categorias.insert(new Categoria(nombre, tipo, descripcion, des));
    }
    else{
        cout << "Ya existe esta categoria";
    }
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

bool ControladorVideojuegos::altaSuscripcion(string videojuego, string tipo, string metodoPago, int validez) {
   iControladorUsuarios *controladorUsuarios = fab->getControladorUsuarios();
	Usuario* usuario = controladorUsuarios->getUsuarioEnSistema(); 
	
	Jugador* jugador = dynamic_cast <Jugador*> (usuario);
	
	for (auto f : ControladorVideojuegos::videojuegos) {
        Videojuego *v = f;
        if (v->getNombre() == videojuego){
   	    	Suscripcion *s = NULL;
            if (tipo == "temporal")
            	s = new Temporal(metodoPago, controladorUsuarios->getFechaSistema(), 0, jugador, v, validez);              //////////////////// Agregar costo del videojuego
			else
				s = new Vitalicia(metodoPago, controladorUsuarios->getFechaSistema(), 0, jugador, v);
			
			jugador->agregarSuscripcion(s);
			v->agregarSuscripcion(s);
			
			return true;	
        }
    }
    
    return false;
    
}

bool ControladorVideojuegos::asignarPuntajeAVideojuego(string nomVideojuego, int puntaje) {
    bool ret = false;
    for (auto f : ControladorVideojuegos::videojuegos) {
        Videojuego *v = f;
        if (v->getNombre() == nomVideojuego){
            v->agregarPuntaje(puntaje);
            ret = true;
            break;
        }
    }
    return ret;
}

void ControladorVideojuegos::publicarVideojuego(){

    Desarrollador *nomDesarrolladorEnSesion = fab->getControladorUsuarios()->getDesarrolladorEnSesion(); //nueva funcion en el controlador
    std::map<int,float> mapaCostos;
    mapaCostos.insert(std::pair<int,float>(0,this->costoVitalicio));
    mapaCostos.insert(std::pair<int,float>(1,this->costoMensual));
    mapaCostos.insert(std::pair<int,float>(3,this->costoTrimestral));
    mapaCostos.insert(std::pair<int,float>(12,this->costoAnual));

    vector<Categoria*> c;

    for (auto f : this->categoriasVideojuego) {
            for (auto j : ControladorVideojuegos::categorias) {
                if (j->getNombre() == f->getNombre() && j->getTipo() == f->getTipo()){
                    c.push_back(j);
                    cout << j->getNombre() << endl;
                }
            }
    }
    //cout << "tengo " << i << " categorias" << endl;
    for (auto f : this->categoriasVideojuego){
        //cout << j->getNombre() << endl;
    };
    this->categoriasVideojuego.clear();
    this->categoriasVideojuego.reserve(0);
    //catVideojuego
    Videojuego* newV = new Videojuego(this->nombreVideojuego, this->descripcionVideojuego, nomDesarrolladorEnSesion, c, mapaCostos);
    ControladorVideojuegos::videojuegos.insert(newV);
}

void ControladorVideojuegos::setearDatosVideojuego(string nombre, string descripcion, float precioMes, float precioTri, float precioAnio, float precioVit) {
	this->nombreVideojuego = nombre;
	this->descripcionVideojuego = descripcion;
	this->costoMensual = precioMes;
	this->costoTrimestral = precioTri;
	this->costoAnual = precioAnio;
	this->costoVitalicio = precioVit;
}

void ControladorVideojuegos::asignarGenero(DtCategoria* gen) {
	this->genero = gen;
}

void ControladorVideojuegos::asignarPlataforma(DtCategoria* plat) {
	this->plataforma = plat;
}

void ControladorVideojuegos::asignarCategorias(vector<DtCategoria*> cats) {
	this->categoriasVideojuego = cats;
	this->categoriasVideojuego.push_back(plataforma);
	this->categoriasVideojuego.push_back(genero);
}

vector<DtCategoria*> ControladorVideojuegos::solicitarCategorias() {
	vector<DtCategoria*> categoriasSolicitadas;
	
	for (auto f : this->categorias) {
                Categoria *cate = f;
                categoriasSolicitadas.push_back(new DtCategoria(cate->getNombre(), cate->getTipo(), cate->getDescripcion()));
            }
	return categoriasSolicitadas;
	
}

void ControladorVideojuegos::seleccionarEstadisticas(vector<DtEstadistica> stats) {
	vector<int> est;
	
	vector<DtEstadistica>::iterator it;
	for (it = stats.begin(); it != stats.end(); it++) {
		est.push_back(it->getIdEstadistica());
	}
	
	iControladorUsuarios *controladorUsuarios = fab->getControladorUsuarios();
	controladorUsuarios->registrarStatsDesarrollador(est);
}

void ControladorVideojuegos::generarStats() {
	this->estadisticas.insert(new Estadistica1(1, "Horas", "Devuelve el total de horas jugadas de un determinado videojuego"));
	this->estadisticas.insert(new Estadistica2(2, "Suscripciones", "Devuelve la cantidad de jugadores suscriptos a un determinado videojuego"));
}

void ControladorVideojuegos::cancelarSuscripcion(string nombreVideojuego){ // precondicion el videojuego tiene una suscripcion temporal del usurio n sesion
	vector<DtJugador> jugadores;
	vector<Suscripcion*> suscripciones;
    Videojuego* v;
	for (auto f : this->videojuegos) {
        if (f->getNombre() == nombreVideojuego){
            suscripciones=f->getSuscripciones();
            v= f;
            break;
        }
    }
    for (auto f : suscripciones) {
	    Suscripcion *s = f;
        if (s != NULL && s->getJugador()->getNick() == fab->getControladorUsuarios()->getNickJugadorEnSesion()){
			Temporal* st=dynamic_cast <Temporal*> (s);
			if (st!=NULL) {
				st->cancelar();
                s->getJugador()->desvincularSub(v);
                break;
			}else{
				cout << "la suscripcion es vitalicia\n.";
			}
		}
	}	
}

vector<DtVideojuego*> ControladorVideojuegos::solicitarVideojuegosSuscripto(){ // devuelve un vector con los DtVideojuegos a los que está suscripto el jugador en sesion
	Usuario* usuarioEnSistema= fab->getControladorUsuarios()->getUsuarioEnSistema(); //toma el usuario en sistema.
	return fab->getControladorUsuarios()->obtenerVideojuegosJugador(usuarioEnSistema->getEmail());
}
