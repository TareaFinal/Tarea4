#include "../ControladorVideojuegos.h"
#include "../temporal.h"
#include "../vitalicia.h"
#include "../DataTypes/DtCategoria.h"
#include "../Estadistica1.h"
#include "../Estadistica2.h"

//instacia del controlador de videojuegos
ControladorVideojuegos *ControladorVideojuegos::instancia = NULL;
Fabrica *fab = Fabrica::getInstancia();

ControladorVideojuegos *ControladorVideojuegos::getInstancia() {
	if (instancia == NULL)
		instancia = new ControladorVideojuegos();

	return instancia;	
}

ControladorVideojuegos::ControladorVideojuegos() {
	
}

// se calcula la estadiistica para el videojuego
float ControladorVideojuegos::calcularEstadistica(int estadistica, string nomVideojuego) {
	
    bool encontre = false;
    float numeroEncontrado = 0.0;
        Estadistica* cat;

    for (auto f : ControladorVideojuegos::estadisticas){
        if (f->getID() == estadistica){
                        numeroEncontrado = f->calcular(nomVideojuego);//nomVideojuego);
                }
    }
    return numeroEncontrado;

}

//se calculan las horas juagdas al videojuego
float ControladorVideojuegos::calcularHorasJugadas(string videojuego) {
	return fab->getControladorPartidas()->darHorasDePartida(videojuego);	
}

//devuelve los jugadores suscritos al videojuego 
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

//seteamos el candidato a eliminar por el desarrollador
void ControladorVideojuegos::eliminarVideojuego(string nombre) {
    this->nomVJaEliminar = nombre;
}

//se listan todos los videojegos
vector<DtVideojuego> ControladorVideojuegos::solicitarVideojuegos() {

    float totHoras = 0.0;
	vector<DtVideojuego> dtVideojuegos;
    for (auto f : ControladorVideojuegos::videojuegos) {
        totHoras = 0.0;
    	Videojuego* v = f;
        totHoras = fab->getControladorPartidas()->darHorasDePartida(f->getNombre());
        vector<string> cats;
        for (auto c : f->getCategorias()){
            cats.push_back(c->getNombre());
        }
        DtVideojuego ret = DtVideojuego(v->getNombre(), v->getDescripcion(), v->calcularPuntajePromedio(), totHoras, v->getDesarrollador()->getEmpresa(), v->getCostos(), cats);
        dtVideojuegos.push_back(ret);
    }
    return dtVideojuegos;
}

// se listan los videojuegos que el desarrollador es el creador
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

// se listan los videojuegos del desarrollador es el creador y que estan finalizadas
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
    return fab->getControladorPartidas()->darSinFinalizar(dtVideojuegos);
}

// se elimina el videojuego
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

//devuelve true si existe un videojuego con ese nombre
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

//lista las estadisticas del sistema
vector<string> ControladorVideojuegos::consultarEstadisticas(string nombreVideojuego) {
Fabrica* fab = Fabrica::getInstancia();
    iControladorUsuarios* ctrlUsuarios = fab->getControladorUsuarios();
    vector<string> estadisticasAMostrar;
    vector<int> stats = ctrlUsuarios->getDesarrolladorEnSesion()->getStats();
    for (auto f : ControladorVideojuegos::estadisticas) {
    	for (auto s : stats) {
			if (f->getID() == s) {
    			string ret = "Nombre: " + f->getNombre() + " \nValor: " + to_string(f->calcular(nombreVideojuego)) + " \n----------------------- "; 
        		estadisticasAMostrar.push_back(ret);
        		break;
        		//dtEstadisticas.insert(ret);
			}
		}
    }
    return estadisticasAMostrar;
    /**/
	//set<DtEstadistica> estadisticas;
	//return estadisticas;
}

//lista todas las estadisticas del sistema
vector<DtEstadistica> ControladorVideojuegos::listarEstadisticas() {
	vector<DtEstadistica> dtEstadisticas;
    for (auto f : ControladorVideojuegos::estadisticas) {
        DtEstadistica ret = DtEstadistica(f->getID(), f->getNombre(), f->getDescripcion(), 0);
        dtEstadisticas.push_back(ret);
        //dtEstadisticas.insert(ret);
        }
    return dtEstadisticas;
	
}

// devuelve true si existe una suscripcion temporal del jugador al videojuego 
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

// se da de alta en el sistema una nueva categoria
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

// devuelve true si existe una videojuego con el mismo nombre en el sistema
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

// devuelve true si existe una categoria con el mismo nombre en el sistema
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

// devuelve true si existe una estadistica con el mismo id en el sistema
bool ControladorVideojuegos::existeEstadistica(int id) {
	bool ret = false;
    for (auto f : ControladorVideojuegos::estadisticas) {
        if (f->getID() == id){
            return true;
        }
    }
    return ret;
}

//se da de alta la suscripcion del jugador al videojuego
bool ControladorVideojuegos::altaSuscripcion(string videojuego, string tipo, string metodoPago, int validez) {
   iControladorUsuarios *controladorUsuarios = fab->getControladorUsuarios();
	Usuario* usuario = controladorUsuarios->getUsuarioEnSistema(); 
	
	Jugador* jugador = dynamic_cast <Jugador*> (usuario);
	
	for (auto f : ControladorVideojuegos::videojuegos) {
        Videojuego *v = f;
        if (v->getNombre() == videojuego){
   	    	Suscripcion *s = NULL;
            if (tipo == "temporal")
            	s = new Temporal(metodoPago, controladorUsuarios->getFechaSistema(), 0, jugador, v, validez); 
			else
				s = new Vitalicia(metodoPago, controladorUsuarios->getFechaSistema(), 0, jugador, v);
			
			jugador->agregarSuscripcion(s);
			v->agregarSuscripcion(s);
			
			return true;	
        }
    }
    
    return false;
    
}

//jugador asigna un puntaje al videojuego
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

//desarrolador da de alta un videojuego
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

//se registra en el sistema los datos del nuevo videojuego previo a su alta
void ControladorVideojuegos::setearDatosVideojuego(string nombre, string descripcion, float precioMes, float precioTri, float precioAnio, float precioVit) {
	this->nombreVideojuego = nombre;
	this->descripcionVideojuego = descripcion;
	this->costoMensual = precioMes;
	this->costoTrimestral = precioTri;
	this->costoAnual = precioAnio;
	this->costoVitalicio = precioVit;
}

//se le asigna genero al nuevo videojuego
void ControladorVideojuegos::asignarGenero(DtCategoria* gen) {
	this->genero = gen;
}

//se le asigna plataforma al nuevo videojuego
void ControladorVideojuegos::asignarPlataforma(DtCategoria* plat) {
	this->plataforma = plat;
}

//se le asignan otras categorias al nuevo videojuego
void ControladorVideojuegos::asignarCategorias(vector<DtCategoria*> cats) {
	this->categoriasVideojuego = cats;
	this->categoriasVideojuego.push_back(plataforma);
	this->categoriasVideojuego.push_back(genero);
}

//se listan todas las categorias del sistema
vector<DtCategoria*> ControladorVideojuegos::solicitarCategorias() {
	vector<DtCategoria*> categoriasSolicitadas;
	
	for (auto f : this->categorias) {
                Categoria *cate = f;
                categoriasSolicitadas.push_back(new DtCategoria(cate->getNombre(), cate->getTipo(), cate->getDescripcion()));
            }
	return categoriasSolicitadas;
	
}

//se seleccionan las estadisticas que el desarrollador quiere mostrar
void ControladorVideojuegos::seleccionarEstadisticas(vector<DtEstadistica> stats) {
	vector<int> est;
	
	vector<DtEstadistica>::iterator it;
	for (it = stats.begin(); it != stats.end(); it++) {
		est.push_back(it->getIdEstadistica());
	}
	
	iControladorUsuarios *controladorUsuarios = fab->getControladorUsuarios();
	controladorUsuarios->registrarStatsDesarrollador(est);
}

//se generan estadisticas
void ControladorVideojuegos::generarStats() {
	this->estadisticas.insert(new Estadistica1(1, "Horas", "Devuelve el total de horas jugadas de un determinado videojuego"));
	this->estadisticas.insert(new Estadistica2(2, "Suscripciones", "Devuelve la cantidad de jugadores suscriptos a un determinado videojuego"));
}

//cancela una suscripcion del jugador que esta en sesion al videojuego
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

// devuelve un vector con los DtVideojuegos a los que está suscripto el jugador en sesion
vector<DtVideojuego*> ControladorVideojuegos::solicitarVideojuegosSuscripto(){ 
	Usuario* usuarioEnSistema= fab->getControladorUsuarios()->getUsuarioEnSistema(); //toma el usuario en sistema.
	return fab->getControladorUsuarios()->obtenerVideojuegosJugador(usuarioEnSistema->getEmail());
}
