#include "../ControladorPartidas.h"
#include <string>
#include <set>
using namespace std;
/*
class ControladorPartidas : public iControladorPartidas {
	
	private:
        
		static ControladorPartidas instancia;
                set<Partida> partidas;
        */
ControladorPartidas::ControladorPartidas() {}

ControladorPartidas* ControladorPartidas::getInstancia()
        {
                if (instancia==NULL)
                    instancia = new ContPelicula();
                return instancia;
        }
float ControladorPartidas::darHorasDePartida(Partida partida) {

}
set<DtVideojuego> ControladorPartidas::obtenerVideojuegosJugador() {
    ControladorUsuarios* controladorusuarios= ControladorUsuarios::getInstancia();
    string j=controladorusuarios->getUsuarioEnSesion();
    return controladorusuarios->obtenerVideojuegosJugador(j);
}
set<DtJugador> ControladorPartidas::obtenerJugadoresSuscriptos() {
    ControladorVideojuegos* controladorvideojuegos = ControladorVideojuegos::getInstancia();
    return controladorvideojuegos->jugadoresSuscriptosAVideojuego(Nombre);
}
//set<DtJugador> ControladorPartidas::obtenerJugadoresMulti(int idPartida) { // devuelve los jugadores suscriptos a el videojuego en memoria. PARTIDA MULTIJUGADOR

bool ControladorPartidas::ingreseIdPartida(int idPartida) { // el sistema guarda esta info para continuar partida INDIVIDUAL no finalizada.
    for (it = ControladorPartidas::copiaAnterioresEnControlador.begin(); it != ControladorPartidas::copiaAnterioresEnControlador.end(); ++it)
    {
        if ( it->getidPartida() == idPartida) {
            ControladorPartidas::partidaIndividualAContinuar = idPartida;
            return true;
        }
        else {
            return false;
        }
    }
    
}
void ControladorPartidas::finalizarPartida(int idPartida) {
    Partida* p = NULL;
    std::map<int, Partida*>::iterator it = dicPartidas.find(idPartida);
        if (it != dicPartidas.end()) // si la encontro
            p = it->second;
        p->terminarPartida();
}
void ControladorPartidas::eliminarPartidasVideojuego(string nombre) {
    // hay que eliminar todas las partidas de ese videojuego tanto individuales como multijugador
}

void ControladorPartidas::seleccionarPartida(int idPartida) // da un id partida hay que controlar que corresponda a uno de los dados anteriormente.
{
}

set<DtPartida> ControladorPartidas::ObtenerAnteriores() // se define la partida como INDIVIDUAL y se devuelve todas las partidas anteriores para el usuario en sesion y el videojuego guardado
{
    tipoPartida = "individual";
    ControladorPartidas::copiaAnterioresEnControlador.clear();
    string jugador = ControladorUsuarios::getUsuarioEnSesion(); // castear para ver si es jugador????
    Partida* p = NULL;
    set<DtPartida> anteriores;
    if (dicPartidas.size() != 0) // si hay partidas
    {
        std::map<int, Partida*>::iterator it;
        for (it = dicPartidas.begin(); it != dicPartidas.end(); ++it)
        {
            Partida* p = it->second; // obtengo la partida actual
            if ((p->tipo() = "individual") && (p->getVideojuego() = videojuegoseleccionado)) { // pregunto el tipo para no castear todas las partidas
                PartidaIndividual* partidaI = dynamic_cast <PartidaIndividual*> (&p); // casteo
                if (partidaI->getJugador() = jugador) { //la partida no guarda el jugador!! Tremendo ya lo puse en el .h
                    anteriores.insert(partidaI->getDataPartida());
                }
            }
        }

    }
    for (it = anteriores.begin(); it != anteriores.end(); ++it)
    {
        DtPartida* c = new(it); // copia limpia de cada partida
        ControladorPartidas::copiaAnterioresEnControlador.insert(c)// hay que vaciar esto al iniciar
    }
    return anteriores;
}
void ControladorPartidas::Transmitida(bool t) // se define la partida como MULTIJUGADOR y se guarda ese dato para luego armar la partida.
{
    ControladorPartidas::tipoPartida = "multijugador";
    ControladorPartidas::envivo = t;
}

set<DtPartida> ControladorPartidas::ListarPartidasNoFinalizadas()// devuelve todas las partidas no finalizadas del jugador sin importar el videojuego
{
    set<DtPartida*> finalizadas;
    Partida* p = it->second; // obtengo la partida actual
    if ((p->tipo() = "individual") && (p->getVideojuego() = videojuegoseleccionado)) { // pregunto el tipo para no castear todas las partidas
        PartidaIndividual* partidaI = dynamic_cast <PartidaIndividual*> (&p); // casteo
        if (partidaI->getJugador() = jugador) { //la partida no guarda el jugador!! Tremendo ya lo puse en el .h
            finalizadas.insert(partidaI->getDataPartida());
        }
    }
}
    return finalizadas;
}

void ControladorPartidas::seleccionarJugadores(set<string> idJugadores) // da un id partida hay que controlar que corresponda a uno de los dados anteriormente.
{
}

void ControladorPartidas::iniciarPartida()
{
}
