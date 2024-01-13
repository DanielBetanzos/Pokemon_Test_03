#ifndef POKEBOLA_H
#define POKEBOLA_H

#include "pokemon.h"

/**
 * @brief La clase Pokebola representa un contenedor para almacenar Pokémones.
 */
class Pokebola
{
private:
    /**
     * @brief Número de Pokémones en la Pokebola.
     */
    int numero_pokemones{};

public:
    /**
     * @brief Arreglo dinámico de punteros a Pokémon.
     *
     * @details
     * Cada elemento del arreglo almacena la dirección de memoria de un objeto tipo Pokemon.
     * Se define como dinámico para establecer la cantidad de pokemones en tiempo de ejecución
     */
    Pokemon** espacio;

    /**
     * @brief Constructor predeterminado de la clase Pokebola.
     */
    Pokebola();

    /**
     * @brief Constructor de la clase Pokebola con parámetros, en este caso, con un número específico de Pokémones.
     * @param numero_pokemones Número de Pokémones que puede contener la Pokebola.
     */
    Pokebola(int numero_pokemones);

    /**
     * @brief Agrega un Pokémon a la Pokebola.
     * @param pokemon Puntero al Pokémon que se va a agregar.
     */
    void agregaPokemon(Pokemon* pokemon);

    /**
     * @brief Imprime la lista de Pokémones en la Pokebola.
     */
    void printPokebola();

    /**
     * @brief Selecciona manualmente cinco Pokémon para agregar a la Pokebola.
     * @param p1, p2, p3, p4, p5 Punteros a los cinco Pokémon seleccionados.
     */
    void selectPokemon(Pokemon* p1, Pokemon* p2, Pokemon* p3, Pokemon* p4, Pokemon* p5);

    /**
     * @brief Selecciona de manera aleatoria un Pokémon para la máquina de los 5 Pokémones predeterminados.
     * @param p1, p2, p3, p4, p5 Cinco Pokémon candidatos para la selección automática.
     * @return Pokémon seleccionado automáticamente.
     */
    Pokemon machineSelect(Pokemon p1, Pokemon p2, Pokemon p3, Pokemon p4, Pokemon p5);

    /**
     * @brief Saca un Pokémon de la Pokebola y devuelve su puntero.
     * @return Puntero al Pokémon sacado.
     */
    Pokemon* sacarPokemon();
};

#endif // POKEBOLA_H
