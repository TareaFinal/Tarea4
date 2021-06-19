#include "../ControladorPartidas.h"

ControladorPartidas *ControladorPartidas::instancia = NULL;

ControladorPartidas *ControladorPartidas::getInstancia() {
	if (instancia == NULL)
		instancia = new ControladorPartidas();

	return instancia;	
}

ControladorPartidas::ControladorPartidas() {
	
}

float ControladorPartidas::darHorasDePartida(string videojuego) {
	Partida* p = NULL;
	float horas=0;
    if (this->dicPartidas.size() != 0) // si hay partidas
    {
        std::map<int, Partida*>::iterator it;
        for (it = this->dicPartidas.begin(); it != this->dicPartidas.end(); ++it)
        {
            Partida* p = it->second; // obtengo la partida actual
            horas+=p->darTotalDeHorasParticipantes();
    	}
	}
	return horas;        
}

vector<DtVideojuego> ControladorPartidas::obtenerVideojuegosJugador() {
	Fabrica *fabrica = Fabrica::getInstancia();
    iControladorUsuarios* controladorusuarios = fabrica->getControladorUsuarios();
    string j = controladorusuarios->getUsuarioEnSesion();
    vector<DtVideojuego> VideojuegosJugador = controladorusuarios->obtenerVideojuegosJugador(j);
    
    return VideojuegosJugador;
}

void ControladorPartidas::SeleccionarVideojuego(string Nombre) {
    this->videoJuegoAContinuar = Nombre; // guarda
}

vector<DtPartida*> ControladorPartidas::ObtenerAnteriores() { // se define la partida como INDIVIDUAL y se devuelve todas las partidas anteriores para el usuario en sesion y el videojuego guardado
    this->tipoPartida = "individual";
    
    Fabrica *fabrica = Fabrica::getInstancia();
    iControladorUsuarios* controladorusuarios = fabrica->getControladorUsuarios();
    string j=controladorusuarios->getUsuarioEnSesion(); // castear para ver si es jugador????
    Partida* p = NULL;
    vector<DtPartida*> anteriores;
    if (this->dicPartidas.size() != 0) // si hay partidas
    {
        std::map<int, Partida*>::iterator it;
        for (it = this->dicPartidas.begin(); it != this->dicPartidas.end(); ++it)
        {
            Partida* p = it->second; // obtengo la partida actual
            PartidaIndividual* partidaI = dynamic_cast <PartidaIndividual*> (p);
            if ((p!=NULL) && (p->getVideojuego() == videojuegoseleccionado)) { 
                if (partidaI->getJugador() == j) { //la partida no guarda el jugador!! Tremendo ya lo puse en el .h por otro lado ¿TODAS LAS PARTIDAS DE ESE VIDEOJUEGO SE PUEDEN CONTINUAR?
                    anteriores.push_back(partidaI->getDataPartida());
                }
                //delete pdtpartida;

            }

        }
    }
    
    return anteriores;
}

void ControladorPartidas::seleccionarPartida(int idPartida) { // da un id partida hay que controlar que corresponda a uno de los dados anteriormente.
    partidaIndividualAContinuar = idPartida; // guarda
    this->Continuacion= dynamic_cast <PartidaIndividual*> (dicPartidas.find(idPartida)->second); // ojo si falla el dynamic cast nunca es continuacion
    
}

void ControladorPartidas::Transmitida(bool t) { // se define la partida como MULTIJUGADOR y se guarda ese dato para luego armar la partida.
    this->tipoPartida = "multijugador";
    this->envivo = t;
}

vector<DtJugador> ControladorPartidas::obtenerJugadoresSuscriptos() {  // partida MULTIJUGADOR queremos ver quien mas puede participar
    Fabrica *fabrica = Fabrica::getInstancia();
    iControladorVideojuegos* controladorvideojuegos = fabrica->getControladorVideojuegos();
    
    return controladorvideojuegos->jugadoresSuscriptosAVideojuego(videojuegoseleccionado); //esto esta bien
}

void ControladorPartidas::seleccionarJugadores(vector<DtJugador> idJugadores) { // da un id partida hay que controlar que corresponda a uno de los dados anteriormente.
  //  this->JugadoresApartidaMulti = idJugadores;
}

void ControladorPartidas::iniciarPartida() { //SIN TERMINAR!!
 // crear una instancia con los datos guardados segun corresponda a una partida individual o a una multijugador
/*	ControladorPartidas::identificadorpartida++;
	ControladorUsuarios* controladorusuarios = ControladorUsuarios::getInstancia();
	string jugador = controladorusuarios->getUsuarioEnSesion();
	DtFechaHora* fechaInicio=controladorusuarios->getFechaSistema();
	Partida* partida;
	if (ControladorPartidas::tipoPartida == "individual"){
		PartidaIndividual* p =new PartidaIndividual(this->identificadorpartida,jugador,nullptr, fechaInicio,this->videojuegoseleccionado,this->Continuacion);
		partida =p;
		this->Continuacion=NULL;
	}
	else{
	PartidaMultijugador* p =new PartidaMultijugador(ControladorPartidas::identificadorpartida,videojuegoseleccionado,this->envivo);
	Partida* partida =p;
	}
	
	dicPartidas.insert(std::make_pair(this->identificadorpartida, partida)); */
}

//Abandonar Partida Multijugador
vector<DtPartida*> ControladorPartidas::ObtenerPartidasActivas() {
	Fabrica *fabrica = Fabrica::getInstancia();
    iControladorUsuarios* controladorusuarios = fabrica->getControladorUsuarios();
    
    string jugador = controladorusuarios->getUsuarioEnSesion(); // castear para ver si es jugador????
    Partida* p = NULL;
    vector<DtPartida*> activas;
    if (this->dicPartidas.size() != 0) // si hay partidas
    {
        std::map<int, Partida*>::iterator it;
        for (it = this->dicPartidas.begin(); it != this->dicPartidas.end(); ++it)
        {
            Partida* p = it->second; // obtengo la partida actual
            PartidaMultijugador* partidaM = dynamic_cast <PartidaMultijugador*> (p);
            if (partidaM == nullptr) { // pregunto el tipo para no castear todas las partidas está bien esto? o casteo de una?
                set<string> jugadoresunidos = partidaM->getNicknameJugadoresActivos();
                std::set<string>::iterator itj;
                for (itj = jugadoresunidos.begin(); itj != jugadoresunidos.end(); ++itj)
                {
                    if ((*itj) == jugador) { activas.push_back(partidaM->getDataPartida()); }
                }
            }
        }
    }
    return activas;
}

void ControladorPartidas::AbandonarPartidaActiva(int id) {
    Fabrica *fabrica = Fabrica::getInstancia();
    iControladorUsuarios* controladorusuarios = fabrica->getControladorUsuarios();
    
    string j=controladorusuarios->getUsuarioEnSesion();
    PartidaMultijugador* partidaM = dynamic_cast <PartidaMultijugador*> (this->dicPartidas.find(id)->second);
    if (partidaM!=NULL) { // si la encontro
        partidaM->abandonaPartidaJugador(j);
    }
    else {
        //throw(invalid_argument, "Esta partida no existe");
    }
}

vector<DtPartida*> ControladorPartidas::ListarPartidasNoFinalizadas() {
/*	ControladorUsuarios* controladorusuarios = ControladorUsuarios::getInstancia();
    string j=controladorusuarios->getUsuarioEnSesion();
    vector<int> noFinalizadas;
    std::map<int, Partida*>::iterator it;
    for (it = dicPartidas.begin(); it != dicPartidas.end(); ++it)
    {
        Partida* p = it->second; // obtengo la partida actual
        if ((p->getDuracion()==0 )&&(p->getJugador()->getNick()==j)) { // MAL
                noFinalizadas.push_back(p->getPartida());
        }
    }
    return noFinalizadas;
	*/
}


set<string> ControladorPartidas::obtenerJugadoresMulti(int idPartida) {
	
    PartidaMultijugador* partidaM = dynamic_cast <PartidaMultijugador*> (this->dicPartidas.find(idPartida)->second);
    if (partidaM!=nullptr){
        return partidaM->getNicknameJugadoresActivos();
    }
    else {
        delete(partidaM);
        // throw invalid_argument " Todo mal con esta id";
    }

} // // dentro de finalizar partidamultijudador devuelve los jugadores que estan jugando PARTIDA MULTIJUGADOR


bool ControladorPartidas::ingreseIdPartida(int idPartida) {// el sistema guarda esta info para continuar partida INDIVIDUAL no finalizada.
    this->partidaAfinalizar = idPartida;
}

void ControladorPartidas::finalizarPartida() {
	
	if (this->dicPartidas.find(this->partidaAfinalizar) != this->dicPartidas.end()) { // si la encontro
        this->dicPartidas.find(this->partidaAfinalizar)->second->terminarPartida();
    }
    else {
        //throw(invalid_argument, "Esta partida no existe");
    }
}

void ControladorPartidas::eliminarPartidasVideojuego(string nombre) {
    // hay que eliminar todas las partidas de ese videojuego tanto individuales como multijugador
    std::map<int, Partida*>::iterator it;
    for (it = this->dicPartidas.begin(); it != this->dicPartidas.end(); ++it)
    {
        Partida* p = it->second; // obtengo la partida actual
        if (p->getVideojuego()==nombre) {
                delete p;
        }
        this->dicPartidas.erase(it->first);
    }
}


