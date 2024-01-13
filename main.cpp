#include <QCoreApplication>
#include "pokemon.h"
#include "pokebola.h"
#include "arena.h"
#include "usuario.h"
#include <iostream>
using namespace std;

/**
 * @brief Función principal del programa.
 * @param argc Número de argumentos de la línea de comandos.
 * @param argv Arreglo de argumentos de la línea de comandos.
 * @return Código de salida del programa.
 */
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // Creación de Pokémon y objetos relacionados
    Pokemon pokemon_1("Pikachu", "Electrico", 280, 100, 50, 32, false);
    Pokemon pokemon_2("Charmander", "Fuego", 350, 150, 80, 36, false);
    Pokemon pokemon_3("Lucario", "Lucha", 400, 150, 70, 43, false);
    Pokemon pokemon_4("Vaporeon", "Agua", 420, 150, 90, 44, false);
    Pokemon pokemon_5("Exeggutor", "Planta", 380, 140, 75, 41, false);
    Pokemon mch_pokemon;
    Pokemon* pokemon_usuario;
    Usuario jugador;

    bool reinicio{};
    int reebot{};

    do{
        // Ingreso del número de Pokémones que el usuario quiere tener en su pokebola
        int size{jugador.ingresarNoPokemones()};

        // Creación de pokebolas
        Pokebola pokebola1(size);
        Pokebola pokebola2(size);

        // Selección y asignación de Pokémones a las pokebolas del usuario y de la máquina
        pokebola1.selectPokemon(&pokemon_1, &pokemon_2, &pokemon_3, &pokemon_4, &pokemon_5);
        mch_pokemon = pokebola2.machineSelect(pokemon_1, pokemon_2, pokemon_3, pokemon_4, pokemon_5);

        // Obtención de un Pokémon de la pokebola del usuario
        pokemon_usuario = pokebola1.sacarPokemon();

        // Selección del modo de pelea por parte del usuario
        jugador.seleccionarModoDePelea(pokemon_usuario, &mch_pokemon, &pokebola1, size);
        qInfo() << "Quieres reiniciar el juego?";
        qInfo() << "1. SI, 2.No";
        cin >> reebot;
        reebot == 1 ? reinicio = true : reinicio = false;


    }while(reinicio);

    return a.exec();
}
