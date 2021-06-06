class fabrica {
	
	private:
		static fabrica instancia;
	public:
		ControladorVideojuegos getControladorVideojuegos();
        ControladorUsuarios getControladorVideojuegos();
        ControladorPartidas getControladorVideojuegos();
        static Fabrica getInstancia();

};