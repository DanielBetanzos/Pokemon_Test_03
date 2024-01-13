#ifndef ARENA_H
#define ARENA_H

#include "pokemon.h"
#include "pokebola.h"

/**
 * @brief La clase Arena representa el escenario donde los Pokémon van a pelear.
 */
class Arena
{
public:
    /**
     * @brief Constructor de la clase Arena.
     * @param pokemon1 Puntero al primer Pokémon que entrará en la batalla.
     * @param pokemon2 Puntero al segundo Pokémon que entrará en la batalla.
     */
    Arena(Pokemon* pokemon1, Pokemon* pokemon2);

    /**
     * @brief Realiza una batalla 1 vs 1 entre dos Pokémon.
     * @param pokemon1 Puntero al primer Pokémon.
     * @param pokemon2 Puntero al segundo Pokémon.
     */
    void oneByOne(Pokemon* pokemon1, Pokemon* pokemon2);

    /**
     * @brief Realiza una batalla "Last One Standing" entre los Pokémon almacenados en una Pokebola.
     * @param pokebola Referencia a la Pokebola que contiene a los Pokémon.
     * @param size Tamaño de la Pokebola, es decir, la cantidad de Pokémon disponibles.
     */
    void lastOneStand(Pokebola& pokebola, int size);

    /**
     * @brief Realiza un ataque de un Pokémon a otro.
     * @param atacante Puntero al Pokémon que realiza el ataque.
     * @param defensor Puntero al Pokémon que recibe el ataque.
     */
    void atacar(Pokemon* atacante, Pokemon* defensor);
};

#endif // ARENA_H
