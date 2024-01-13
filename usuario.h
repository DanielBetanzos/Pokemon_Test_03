#ifndef USUARIO_H
#define USUARIO_H

#include "pokemon.h"
#include "pokebola.h"
#include "arena.h"

/**
 * @brief La clase Usuario representa a las acciones que puede realizar el usuario en el juego.
 */
class Usuario
{
public:
    /**
     * @brief Constructor predeterminado de la clase Usuario.
     */
    Usuario();

    /**
     * @brief Solicita al usuario ingresar el número de Pokémones que desea tener en su pokebola.
     * @return Número de Pokémon ingresado por el usuario.
     */
    int ingresarNoPokemones();

    /**
     * @brief Permite al usuario seleccionar el modo de pelea y realiza la configuración correspondiente.
     * @param Pokemon1 Puntero al Pokémon del usuario.
     * @param Pokemon2 Puntero al Pokémon de la máquina.
     * @param pokebola Puntero a la pokebola del usuario.
     * @param size Tamaño de la pokebola.
     */
    void seleccionarModoDePelea(Pokemon* Pokemon1, Pokemon* Pokemon2, Pokebola* pokebola, int size);
};

#endif // USUARIO_H
