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

vector<DtVideojuego*> ControladorPartidas::obtenerVideojuegosJugador() {
	Fabrica *fabrica = Fabrica::getInstancia();
    iControladorUsuarios* controladorusuarios = fabrica->getControladorUsuarios();
    string j = controladorusuarios->getUsuarioEnSesion();
    vector<DtVideojuego*> VideojuegosJugador = controladorusuarios->obtenerVideojuegosJugador(j);
    
    return VideojuegosJugador;
}

void ControladorPartidas::SeleccionarVideojuego(string Nombre) {
    this->videojuegoseleccionado = Nombre; // guarda
}

vector<DtPartida*> ControladorPartidas::ObtenerAnteriores() { // se define la partida como INDIVIDUAL y se devuelve todas las partidas anteriores para el usuario en sesion y el videojuego guardado
    this->tipoPartida = "individual";
    
    Fabrica *fabrica = Fabrica::getInstancia();
    iControladorUsuarios* controladorusuarios = fabrica->getControladorUsuarios();
    string j=controladorusuarios->getNickJugadorEnSesion(); // castear para ver si es jugador????
    Partida* p = NULL;
    vector<DtPartida*> anteriores;
    if (this->dicPartidas.size() != 0) // si hay partidas
    {
        std::map<int, Partida*>::iterator it;
        for (it = this->dicPartidas.begin(); it != this->dicPartidas.end(); ++it)
        {
            Partida* p = it->second; // obtengo la partida actual
            PartidaIndividual* partidaI = dynamic_cast <PartidaIndividual*> (p);
            if ((partidaI!=NULL) && (partidaI->getVideojuego() == videojuegoseleccionado)) { 
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

void ControladorPartidas::seleccionarJugadores(vector<string> idJugadores) { // da un id partida hay que controlar que corresponda a uno de los dados anteriormente.
    this->JugadoresApartidaMulti = idJugadores;
}

void ControladorPartidas::setTipoPartida(string tipo) {
	this->tipoPartida = tipo;
}


void ControladorPartidas::iniciarPartida() {  // crear una instancia con los datos guardados segun corresponda a una partida individual o a una multijugador

 	ControladorPartidas::identificadorpartida++;
 	Fabrica* fabrica = Fabrica::getInstancia();
	iControladorUsuarios* controladorusuarios = fabrica->getControladorUsuarios();
	string jugador = controladorusuarios->getNickJugadorEnSesion();
	DtFechaHora* fechaInicio=controladorusuarios->getFechaSistema();
	Partida* partida;
	if (this->tipoPartida == "individual"){
		
		PartidaIndividual* p =new PartidaIndividual(this->identificadorpartida,fechaInicio,this->videojuegoseleccionado,jugador);
		cout << "Partida individual creada correctamente" << endl; 
		partida =p;
		this->Continuacion=NULL;
	}else{
		vector<string> dicSalidas;
		DtFechaHora* s=NULL;
		if (this->JugadoresApartidaMulti.size() != 0) {	
        	std::vector<string>::iterator it;
	        for (it = this->JugadoresApartidaMulti.begin(); it != this->JugadoresApartidaMulti.end(); ++it){
	            dicSalidas.push_back((*it)); // se crea el map de salidas con los nick de los jugadores y vacia la salida
	        }
    	}	
    	
			partida = new PartidaMultijugador(this->identificadorpartida,jugador,fechaInicio,this->videojuegoseleccionado,this->envivo, dicSalidas);
			
			cout << "Partida multijugador creada correctamente" << endl; 
	}
    		
	
	
	this->dicPartidas.insert(pair<int, Partida*> (this->identificadorpartida, partida));
	
}

//Abandonar Partida Multijugador
vector<DtPartida*> ControladorPartidas::ObtenerPartidasActivas() {
	Fabrica *fabrica = Fabrica::getInstancia();
    iControladorUsuarios* controladorusuarios = fabrica->getControladorUsuarios();
    
    string jugador = controladorusuarios->getNickJugadorEnSesion();
   // Partida* p = NULL;
    vector<DtPartida*> activas;
    if (!this->dicPartidas.empty()) {
 	
        std::map<int, Partida*>::iterator it;
        for (it = this->dicPartidas.begin(); it != this->dicPartidas.end(); ++it)
        {
           // Partida* p = it->second; // obtengo la partida actual
            PartidaMultijugador* partidaM = dynamic_cast <PartidaMultijugador*> (it->second);
            if (partidaM != NULL) {
            	
                set<string> jugadoresunidos = partidaM->getNicknameJugadoresActivos(); // en cada partida multi hay que fijarse si el jugador está
                std::set<string>::iterator itj;
                for (itj = jugadoresunidos.begin(); itj != jugadoresunidos.end(); ++itj)
                {   	
                    if ((*itj) == jugador) { activas.push_back(partidaM->getDataPartida()); } // si esta la ponemos para devolver en activas
                }
            }
        }
    }
    return activas;
}

void ControladorPartidas::AbandonarPartidaActiva(int id) {
    Fabrica *fabrica = Fabrica::getInstancia();
    iControladorUsuarios* controladorusuarios = fabrica->getControladorUsuarios();
    
    string j=controladorusuarios->getNickJugadorEnSesion();
    PartidaMultijugador* partidaM = dynamic_cast <PartidaMultijugador*> (this->dicPartidas.find(id)->second);
    if (partidaM!=NULL) { // si la encontro
        partidaM->abandonaPartidaJugador(j);
    }
    else {
        //throw(invalid_argument, "Esta partida no existe");
    }
}

// Finalizar Partida
vector<DtPartida*> ControladorPartidas::ListarPartidasNoFinalizadas() {
	ControladorUsuarios* controladorusuarios = ControladorUsuarios::getInstancia();
    string j=controladorusuarios->getNickJugadorEnSesion();
      
    vector<DtPartida*> noFinalizadas;
    std::map<int, Partida*>::iterator it;
    for (it = this->dicPartidas.begin(); it != this->dicPartidas.end(); ++it)
    {	
        Partida* p = it->second; // obtengo la partida actual
        	cout << (p)->getJugador() << endl;
        if ((p->getDuracion()==NULL )&&(p->getJugador()==j)) {// si esta sin finalizar y es del jugador se agrega
                noFinalizadas.push_back(p->getDataPartida());
                
        }
    }
    return noFinalizadas;
}


set<string> ControladorPartidas::obtenerJugadoresMulti(int idPartida) {
	set<string> ret;
    PartidaMultijugador* partidaM = dynamic_cast <PartidaMultijugador*> (this->dicPartidas.find(idPartida)->second);
    if (partidaM!=NULL){
        ret = partidaM->getNicknameJugadoresActivos();
    }
    else {
        delete(partidaM);
        // throw invalid_argument " Todo mal con esta id";
    }
	return ret;
} // // dentro de finalizar partidamultijudador devuelve los jugadores que estan jugando PARTIDA MULTIJUGADOR


bool ControladorPartidas::ingreseIdPartida(int idPartida) {// el sistema guarda esta info para continuar partida INDIVIDUAL no finalizada.
    this->partidaAfinalizar = idPartida;
    return true;
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

vector<string> ControladorPartidas::darSinFinalizar(vector<string> videojuegos){
	vector<string> devolver;
	std::vector<string>::iterator it;
    for (it = videojuegos.begin(); it != videojuegos.end(); ++it){
    	std::map<int, Partida*>::iterator itp;
    	for (itp = dicPartidas.begin(); itp != dicPartidas.end(); ++itp){
        	Partida* p = itp->second; // obtengo la partida actual
        	if ((p->getDuracion()==NULL )&&(p->getVideojuego()==(*it))) {// si esta sin finalizar y es del jugador se agrega
            	devolver.push_back((*it));
        	}
    	}
	}
	for (it = devolver.begin(); it != devolver.end(); ++it){
    	std::map<int, Partida*>::iterator itp;
    	for (itp = ControladorPartidas::dicPartidas.begin(); itp != ControladorPartidas::dicPartidas.end(); ++itp){
        	Partida *p = itp->second; // obtengo la partida actual
        	if ((p->getDuracion()!=NULL )&&(p->getVideojuego()==(*it))) {// si esta sin finalizar y es del jugador se agrega
            	devolver.erase((it));
        	}
    	}
	}
	return devolver;
}

bool ControladorPartidas::hayActivas(){
	bool devolver=false;
	std::map<int, Partida*>::iterator itp;
    	for (itp = ControladorPartidas::dicPartidas.begin(); itp != dicPartidas.end(); ++itp){
        	Partida* p = itp->second; // obtengo la partida actual
        	if (p->getDuracion()!=NULL ) {
            	devolver=true;
        	}
    	}
return devolver;
}


