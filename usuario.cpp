#include "usuario.h"
#include <iostream>
#include <QDebug>
using namespace std;

/**
 * @brief Constructor por defecto de la clase Usuario.
 */
Usuario::Usuario()
{

}

/**
 * @brief Solicita al usuario ingresar el número de pokemones que desea tener en su pokebola.
 * @return Número de pokemones ingresados por el usuario.
 */
int Usuario::ingresarNoPokemones()
{
    int numero_de_pokemones{};
    qInfo() << "Ingresa el número de pokemones que quieres tener en tu pokebola";
            cin >> numero_de_pokemones;

    return numero_de_pokemones;
}

/**
 * @brief Permite al usuario seleccionar el modo de pelea y realiza la pelea correspondiente.
 * @param pokemon_user Pokemon del usuario.
 * @param pokemon_mchine Pokemon "seleccionado" por la máquina.
 * @param pokebola1 Pokebola del usuario.
 * @param numero Número de pokemones en la pokebola del usuario.
 */
void Usuario::seleccionarModoDePelea(Pokemon* pokemon_user, Pokemon* pokemon_mchine, Pokebola* pokebola1, int numero)
{
  bool opcionvalida{false};
    do{
        qInfo() << "¿Qué modo de pelea quieres?: ";
        qInfo() << "1. 1 VS 1;";
        qInfo() << "2. LAST 1 STAND";

        Arena arena1(pokemon_user, pokemon_mchine);

        int opc2{};
        cin >> opc2;


        if(opc2 == 1)
        {
            qInfo() << "Ha seleccionado el modo 1 vs 1";
            arena1.oneByOne(pokemon_user, pokemon_mchine);
            opcionvalida = true;
        }
        if(opc2 == 2)
        {
            qInfo() << "Ha seleccionado el modo Last One Standing";
            qInfo() << "En este modo, pelearán todos los pokemones de su pokebola!";
                       arena1.lastOneStand(*pokebola1, numero);
            opcionvalida = true;
        }

        else
        {
            qInfo() << "Seleccion no valida :(";
            opcionvalida = false;
        }
    }while(!opcionvalida);

}
