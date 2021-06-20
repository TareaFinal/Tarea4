CPP      = g++
OBJ      = scr/Categoria.o scr/Comentario.o scr/ControladorPartidas.o scr/ControladorUsuarios.o scr/ControladorVideojuegos.o scr/desarrollador.o scr/Estadistica1.o scr/Estadistica2.o scr/Fabrica.o scr/main.o scr/PartidaIndividual.o scr/PartidaMultijugador.o scr/suscripcion.o scr/temporal.o scr/usuario.o scr/Videojuego.o scr/vitalicia.o DataTypes/cpp/DtCategoria.o DataTypes/cpp/DtComentario.o DataTypes/cpp/DtEstadistica.o DataTypes/cpp/DtFechaHora.o DataTypes/cpp/DtJugador.o DataTypes/cpp/DtPartida.o DataTypes/cpp/DtPartidaIndividual.o DataTypes/cpp/DtPartidaMultijuador.o DataTypes/cpp/DtVideojuego.o scr/Estadistica.o scr/jugador.o scr/partida.o
LINKOBJ  = scr/Categoria.o scr/Comentario.o scr/ControladorPartidas.o scr/ControladorUsuarios.o scr/ControladorVideojuegos.o scr/desarrollador.o scr/Estadistica1.o scr/Estadistica2.o scr/Fabrica.o scr/main.o scr/PartidaIndividual.o scr/PartidaMultijugador.o scr/suscripcion.o scr/temporal.o scr/usuario.o scr/Videojuego.o scr/vitalicia.o DataTypes/cpp/DtCategoria.o DataTypes/cpp/DtComentario.o DataTypes/cpp/DtEstadistica.o DataTypes/cpp/DtFechaHora.o DataTypes/cpp/DtJugador.o DataTypes/cpp/DtPartida.o DataTypes/cpp/DtPartidaIndividual.o DataTypes/cpp/DtPartidaMultijuador.o DataTypes/cpp/DtVideojuego.o scr/Estadistica.o scr/jugador.o scr/partida.o
BIN      = laboratorio
RM       = rm

.PHONY: all all-before all-after clean clean-custom

all: all-before $(BIN) all-after

clean: clean-custom
	${RM} $(OBJ) $(BIN)

#pampalaboratorio: scr/Categoria.o scr/Comentario.o scr/ControladorPartidas.o scr/ControladorUsuarios.o scr/ControladorVideojuegos.o scr/desarrollador.o scr/Estadistica1.o scr/Estadistica2.o scr/Fabrica.o scr/main.o scr/PartidaIndividual.o scr/PartidaMultijugador.o scr/suscripcion.o scr/temporal.o scr/usuario.o scr/Videojuego.o scr/vitalicia.o DataTypes/cpp/DtCategoria.o DataTypes/cpp/DtComentario.o DataTypes/cpp/DtEstadistica.o DataTypes/cpp/DtFechaHora.o DataTypes/cpp/DtJugador.o DataTypes/cpp/DtPartida.o DataTypes/cpp/DtPartidaIndividual.o DataTypes/cpp/DtPartidaMultijuador.o DataTypes/cpp/DtVideojuego.o scr/Estadistica.o scr/jugador.o scr/partida.o
#	g++ scr/Categoria.o scr/Comentario.o scr/ControladorPartidas.o scr/ControladorUsuarios.o scr/ControladorVideojuegos.o scr/desarrollador.o scr/Estadistica1.o scr/Estadistica2.o scr/Fabrica.o scr/main.o scr/PartidaIndividual.o scr/PartidaMultijugador.o scr/suscripcion.o scr/temporal.o scr/usuario.o scr/Videojuego.o scr/vitalicia.o DataTypes/cpp/DtCategoria.o DataTypes/cpp/DtComentario.o DataTypes/cpp/DtEstadistica.o DataTypes/cpp/DtFechaHora.o DataTypes/cpp/DtJugador.o DataTypes/cpp/DtPartida.o DataTypes/cpp/DtPartidaIndividual.o DataTypes/cpp/DtPartidaMultijuador.o DataTypes/cpp/DtVideojuego.o scr/Estadistica.o scr/jugador.o scr/partida.o -o $(BIN)

$(BIN): $(OBJ)
	$(CPP) $(LINKOBJ) -o $(BIN)


scr/Categoria.o: scr/Categoria.cpp
	$(CPP) -c scr/Categoria.cpp -o scr/Categoria.o

scr/Comentario.o: scr/Comentario.cpp
	$(CPP) -c scr/Comentario.cpp -o scr/Comentario.o

scr/ControladorPartidas.o: scr/ControladorPartidas.cpp
	$(CPP) -c scr/ControladorPartidas.cpp -o scr/ControladorPartidas.o

scr/ControladorUsuarios.o: scr/ControladorUsuarios.cpp
	$(CPP) -c scr/ControladorUsuarios.cpp -o scr/ControladorUsuarios.o

scr/ControladorVideojuegos.o: scr/ControladorVideojuegos.cpp
	$(CPP) -c scr/ControladorVideojuegos.cpp -o scr/ControladorVideojuegos.o

scr/desarrollador.o: scr/desarrollador.cpp
	$(CPP) -c scr/desarrollador.cpp -o scr/desarrollador.o

scr/Estadistica1.o: scr/Estadistica1.cpp
	$(CPP) -c scr/Estadistica1.cpp -o scr/Estadistica1.o

scr/Estadistica2.o: scr/Estadistica2.cpp
	$(CPP) -c scr/Estadistica2.cpp -o scr/Estadistica2.o

scr/Fabrica.o: scr/Fabrica.cpp
	$(CPP) -c scr/Fabrica.cpp -o scr/Fabrica.o

scr/main.o: scr/main.cpp
	$(CPP) -c scr/main.cpp -o scr/main.o

scr/PartidaIndividual.o: scr/PartidaIndividual.cpp
	$(CPP) -c scr/PartidaIndividual.cpp -o scr/PartidaIndividual.o

scr/PartidaMultijugador.o: scr/PartidaMultijugador.cpp
	$(CPP) -c scr/PartidaMultijugador.cpp -o scr/PartidaMultijugador.o

scr/suscripcion.o: scr/suscripcion.cpp
	$(CPP) -c scr/suscripcion.cpp -o scr/suscripcion.o

scr/temporal.o: scr/temporal.cpp
	$(CPP) -c scr/temporal.cpp -o scr/temporal.o

scr/usuario.o: scr/usuario.cpp
	$(CPP) -c scr/usuario.cpp -o scr/usuario.o

scr/Videojuego.o: scr/Videojuego.cpp
	$(CPP) -c scr/Videojuego.cpp -o scr/Videojuego.o

scr/vitalicia.o: scr/vitalicia.cpp
	$(CPP) -c scr/vitalicia.cpp -o scr/vitalicia.o

DataTypes/cpp/DtCategoria.o: DataTypes/cpp/DtCategoria.cpp
	$(CPP) -c DataTypes/cpp/DtCategoria.cpp -o DataTypes/cpp/DtCategoria.o

DataTypes/cpp/DtComentario.o: DataTypes/cpp/DtComentario.cpp
	$(CPP) -c DataTypes/cpp/DtComentario.cpp -o DataTypes/cpp/DtComentario.o

DataTypes/cpp/DtEstadistica.o: DataTypes/cpp/DtEstadistica.cpp
	$(CPP) -c DataTypes/cpp/DtEstadistica.cpp -o DataTypes/cpp/DtEstadistica.o

DataTypes/cpp/DtFechaHora.o: DataTypes/cpp/DtFechaHora.cpp
	$(CPP) -c DataTypes/cpp/DtFechaHora.cpp -o DataTypes/cpp/DtFechaHora.o

DataTypes/cpp/DtJugador.o: DataTypes/cpp/DtJugador.cpp
	$(CPP) -c DataTypes/cpp/DtJugador.cpp -o DataTypes/cpp/DtJugador.o

DataTypes/cpp/DtPartida.o: DataTypes/cpp/DtPartida.cpp
	$(CPP) -c DataTypes/cpp/DtPartida.cpp -o DataTypes/cpp/DtPartida.o

DataTypes/cpp/DtPartidaIndividual.o: DataTypes/cpp/DtPartidaIndividual.cpp
	$(CPP) -c DataTypes/cpp/DtPartidaIndividual.cpp -o DataTypes/cpp/DtPartidaIndividual.o

DataTypes/cpp/DtPartidaMultijuador.o: DataTypes/cpp/DtPartidaMultijuador.cpp
	$(CPP) -c DataTypes/cpp/DtPartidaMultijuador.cpp -o DataTypes/cpp/DtPartidaMultijuador.o

DataTypes/cpp/DtVideojuego.o: DataTypes/cpp/DtVideojuego.cpp
	$(CPP) -c DataTypes/cpp/DtVideojuego.cpp -o DataTypes/cpp/DtVideojuego.o

scr/Estadistica.o: scr/Estadistica.cpp
	$(CPP) -c scr/Estadistica.cpp -o scr/Estadistica.o

scr/jugador.o: scr/jugador.cpp
	$(CPP) -c scr/jugador.cpp -o scr/jugador.o

scr/partida.o: scr/partida.cpp
	$(CPP) -c scr/partida.cpp -o scr/partida.o