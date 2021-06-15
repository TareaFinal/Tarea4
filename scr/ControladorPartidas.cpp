#include "../ControladorPartidas.h"
#include <set>
using namespace std;

ControladorPartidas::ControladorPartidas() {}

ControladorPartidas* ControladorPartidas::getInstancia()
        {
                if (instancia==0)
                    instancia = new ControladorPartidas();
                return instancia;
        }
// float ControladorPartidas::darHorasDePartida(Partida partida) {}
set<DtVideojuego> ControladorPartidas::obtenerVideojuegosJugador() {
    /*
    std::set<DtVideojuego>::iterator it;
    for (it = copiaVideojuegosJugador.begin(); it != copiaVideojuegosJugador.end(); ++it)
    {
        copiaVideojuegosJugador.erase(it);// vaciando
    }
    ControladorUsuarios* controladorusuarios= ControladorUsuarios::getInstancia();
    */
    string j=controladorusuarios->getUsuarioEnSesion();
    set<DtVideojuego> VideojuegosJugador= controladorusuarios->obtenerVideojuegosJugador(j);
    /*
    for (it = VideojuegosJugador.begin(); it != VideojuegosJugador.end(); ++it)
    {
        DtVideojuego c = new &it; // copia limpia de cada partida
        copiaVideojuegosJugador.insert(c);// hay que vaciar esto al iniciar
    }
    */
    return VideojuegosJugador;
}
void ControladorPartidas::SeleccionarVideojuego(string Nombre)
{
    videoJuegoAContinuar = Nombre; // guarda
    /*
    bool encontrado = false;
    std::set<DtVideojuego>::iterator it;
    for (it = copiaVideojuegosJugador.begin(); it != copiaVideojuegosJugador.end(); ++it) // hay que buscar porque no tengo el dtpartida sino solo su id, si no habría que hacer un map.
    {
        if (it->getNombre() == Nombre) {
            videoJuegoAContinuar = Nombre; // guarda
            encontrado= true;
        }
        if (!encontrado) throw invalid_argument "Este videojuego no es correcto";
    }
    */
}
set<DtPartida> ControladorPartidas::ObtenerAnteriores() // se define la partida como INDIVIDUAL y se devuelve todas las partidas anteriores para el usuario en sesion y el videojuego guardado
{
    tipoPartida = "individual";
    
    continuacion = true;
    /*
    std::set<DtPartida>::iterator it;
    for (it = anteriores.begin(); it != anteriores.end(); ++it)
    {
        copiaAnterioresEnControlador.erase(it);// hay que vaciar esto al iniciar
        delete(it); // aca estoy borrando al iterador???!!! quiero borrar a lo que apunta
    }
    ControladorPartidas::copiaAnterioresEnControlador.clear();
    */
    string jugador = ControladorUsuarios::getUsuarioEnSesion(); // castear para ver si es jugador????
    Partida* p = NULL;
    set<DtPartida> anteriores;
    if (dicPartidas.size() != 0) // si hay partidas
    {
        std::map<int, Partida*>::iterator it;
        for (it = dicPartidas.begin(); it != dicPartidas.end(); ++it)
        {
            Partida* p = it->second; // obtengo la partida actual
            if ((p->tipo() == "individual") && (p->getVideojuego() == videojuegoseleccionado)) { // pregunto el tipo para no castear todas las partidas
                //Partida* pdtpartida = *p;
                PartidaIndividual* partidaI = dynamic_cast <PartidaIndividual*> (p); // casteo
                if (partidaI->getJugador() == jugador) { //la partida no guarda el jugador!! Tremendo ya lo puse en el .h por otro lado ¿TODAS LAS PARTIDAS DE ESE VIDEOJUEGO SE PUEDEN CONTINUAR?
                    anteriores.insert(partidaI->getDataPartida());
                }
                //delete pdtpartida;

            }

        }
    }
    /*
    for (it = anteriores.begin(); it != anteriores.end(); ++it)
    {
        DtPartida c = new(it); // copia limpia de cada partida
        copiaAnterioresEnControlador.insert(c)// hay que vaciar esto al iniciar
    }
    */
    return anteriores;
}

void ControladorPartidas::seleccionarPartida(int idPartida) // da un id partida hay que controlar que corresponda a uno de los dados anteriormente.
{
    partidaIndividualAContinuar = idPartida; // guarda
    /*
    std::set<DtPartida*>::iterator it;
    partidaIndividualAContinuar = -1;
    for (it = copiaAnterioresEnControlador.begin(); it != copiaAnterioresEnControlador.end(); ++it) // hay que buscar porque no tengo el dtpartida sino solo su id, si no habría que hacer un map.
    {
        if ((*it)->getIdPartida() == idPartida) {
            
            break;
        }
    }
    if (partidaIndividualAContinuar == -1) throw invalid_argument "Identificador incorrecto no se puede continuar esta partida";
    */
}
void ControladorPartidas::Transmitida(bool t) // se define la partida como MULTIJUGADOR y se guarda ese dato para luego armar la partida.
{
    ControladorPartidas::tipoPartida = "multijugador";
    ControladorPartidas::envivo = t;
}

set<DtJugador> ControladorPartidas::obtenerJugadoresSuscriptos() {  // partida MULTIJUGADOR queremos ver quien mas puede participar
    /*
    std::set<DtJugador>::iterator it;
    copiaSetJugadores.clear();
    for (it = copiaSetJugadores.begin(); it != copiaSetJugadores.end(); ++it) {
        copiaSetJugadores.erase(*it);
        delete(it);
    }
    ControladorVideojuegos* controladorvideojuegos = ControladorVideojuegos::getInstancia();
    
    for (it = setJugadores.begin(); it != setJugadores.end(); ++it){
        DtJugador c = new(*it); // copia limpia de cada jugador
        copiaSetJugadores.insert(c);// hay que vaciar esto al iniciar
    }
    */
    return controladorvideojuegos->jugadoresSuscriptosAVideojuego(videojuegoseleccionado);
}
void ControladorPartidas::seleccionarJugadores(set<DtJugador> idJugadores) // da un id partida hay que controlar que corresponda a uno de los dados anteriormente.
{
    /*
    std::set<string>::iterator itj;
    std::set<string>::iterator its;

    bool cadaj=true, cadas;

    for (itj = idJugadores.begin(); itj != idJugadores.end(); ++itj) {
        cadaj = false;
        for (its = copiaSetJugadores.begin(); its != copiaSetJugadores.end(); ++its) {
            if (*itj == *its) cadaj = true;
        }
        cadas = cadas && cadaj;
    }
    */
    JugadoresApartidaMulti = idJugadores;
    /*
    if (cadas) {  }
    else { throw invalid_argument "Esa lista de jugadores es invalida"; }
    */
}
void ControladorPartidas::iniciarPartida()
{ // crear una instancia con los datos guardados segun corresponda a una partida individual o a una multijugador
}

//Abandonar Partida Multijugador
set<DtPartidaMultijugador> ControladorPartidas::ObtenerPartidasActivas()
{
    string jugador = ControladorUsuarios::getUsuarioEnSesion(); // castear para ver si es jugador????
    Partida* p = NULL;
    set<DtPartidaMultijugador> activas;
    if (dicPartidas.size() != 0) // si hay partidas
    {
        std::map<int, Partida*>::iterator it;
        for (it = dicPartidas.begin(); it != dicPartidas.end(); ++it)
        {
            Partida* p = it->second; // obtengo la partida actual
            if (p->tipo() == "multijugador") { // pregunto el tipo para no castear todas las partidas está bien esto? o casteo de una?
                PartidaMultijugador* partidaM = dynamic_cast <PartidaMultijugador*> (p); // casteo
                set<DtJugador> jugadoresunidos = partidaM->getDtJugadoresActivos();
                std::set<DtJugador>::iterator itj;
                for (itj = jugadoresunidos.begin(); itj != jugadoresunidos.end(); ++itj)
                {
                    if (itj->getNickname() == jugador) activas.insert(partidaM->getDataPartida());
                }
            }
        }
    }
    return activas;
}

void ControladorPartidas::AbandonarPartidaActiva(int id)
{
}
// Caso de uso finalizar partida
set<DtPartida> ControladorPartidas::ListarPartidasNoFinalizadas()// devuelve todas las partidas no finalizadas del jugador sin importar el videojuego
{
    string j = controladorusuarios->getUsuarioEnSesion();
    set<DtPartida> noFinalizadas;
    std::map<int, Partida*>::iterator it;
    for (it = dicPartidas.begin(); it != dicPartidas.end(); ++it)
    {
        Partida* p = it->second; // obtengo la partida actual
        if ((p->getDuracion().getMinuto()==0 )&&(p->getJugador()==j)) { // esto esta mal no se puede chequear contra 0 
                noFinalizadas.insert(p->getDataPartida());
        }
    }
    return noFinalizadas;
}









bool ControladorPartidas::ingreseIdPartida(int idPartida) { // el sistema guarda esta info para continuar partida INDIVIDUAL no finalizada.
    partidaAfinalizar = idPartida;
}
void ControladorPartidas::finalizarPartida()
{
    //Partida* p = NULL;
    
    if (dicPartidas.find(partidaAfinalizar) != dicPartidas.end()) { // si la encontro
        dicPartidas.find(partidaAfinalizar)->second->terminarPartida();
    }
    else {
        //throw(invalid_argument, "Esta partida no existe");
    }
}
set<DtJugador> ControladorPartidas::obtenerJugadoresMulti(int idPartida) {} // devuelve los jugadores suscriptos a el videojuego en memoria. PARTIDA MULTIJUGADOR





    




void ControladorPartidas::eliminarPartidasVideojuego(string nombre) {
    // hay que eliminar todas las partidas de ese videojuego tanto individuales como multijugador
}
ControladorPartidas::~ControladorPartidas() {
    dicPartidas.clear(); // esto debe estar mal hay que deletear uno por uno

}
