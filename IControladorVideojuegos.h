using namespace std;

class iControladorVideojuegos {

	public:
        virtual float calcularEstadistica(IdEstadistica estadistica) = 0;
        virtual float calcularHorasJugadas(Videojuego videojuego) = 0;
        virtual set<DtJugadores> jugadoresSuscriptosAVideojuego(string nombre) = 0;
        virtual void eliminarVideojuego(string nombre) = 0;
        virtual set<DtVideojuego> obtenerVideojuegos() = 0;
        virtual void confirmarEliminacion() = 0;
        virtual bool ingreseNombreVideojuego(string nombreVideojuego) = 0;
        virtual set<DtEstadistica> listarEstadisticas(string nombreVideojuego) = 0;
        virtual bool esTemporal(Suscripcion s) = 0;
        virtual Suscripcion ingresarNombre(string nombre) = 0;
        virtual void ingresarCategoria(DtCategoria cat) = 0;
};