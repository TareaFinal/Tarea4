using namespace std;

class controladorVideojuegos : public iControladorVideojuegos {
	
	private:
	static controladorVideojuegos instancia;
        set<Categoria> categorias;
        set<Videojuego> videojuegos;
	public:
        static controladorVideojuegos getInstancia();
        float calcularEstadistica(IdEstadistica estadistica);
        float calcularHorasJugadas(Videojuego videojuego);
        set<DtJugadores> jugadoresSuscriptosAVideojuego(string nombre);
        void eliminarVideojuego(string nombre);
        set<DtVideojuego> obtenerVideojuegos();
        void confirmarEliminacion();
        bool ingreseNombreVideojuego(string nombreVideojuego);
        set<DtEstadistica> listarEstadisticas(string nombreVideojuego);
        bool esTemporal(Suscripcion s);
        Suscripcion ingresarNombre(string nombre);
        void ingresarCategoria(DtCategoria cat);
};