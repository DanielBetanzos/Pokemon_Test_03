#include "arena.h"
#include "pokemon.h"
#include <QDebug>
#include <QString>
#include <random>
#include <chrono>
#include <string>
#include <sstream>
#include <iostream>
using namespace std;

/**
 * @brief Constructor de la clase Arena.
 * @param pokemon1 Puntero al primer Pokémon.
 * @param pokemon2 Puntero al segundo Pokémon.
 */
Arena::Arena(Pokemon* pokemon1, Pokemon* pokemon2)
{
    qInfo() << "Constructor de la arena";
}

/**
 * @brief Simula una batalla uno a uno entre dos Pokémones.
 * @param pokemon1 Puntero al primer Pokémon.
 * @param pokemon2 Puntero al segundo Pokémon.
 */
void Arena::oneByOne(Pokemon *pokemon1, Pokemon* pokemon2)
{
    //Creación del motor aleatorio para determinar quién empieza la partida, si el usuario o la máquina
    unsigned int semilla = chrono::steady_clock::now().time_since_epoch().count();
    std::default_random_engine motor{semilla};
    uniform_int_distribution<short> distNm{1, 2};
    int turno{distNm(motor)};

    qInfo() << "Los pokemones a pelear son: " << pokemon1->getName() << "Y" << pokemon2->getName();

    //Mientras la salud de ambos Pokémones sea mayor a 0, se ejecutará la pelea
    while(pokemon1->getHealth() > 0 && pokemon2->getHealth() > 0)
    {
     //Si el numero aleatorio generado es 1, comienza el usuario
        if(turno==1)
        {
            qInfo() << "Empieza: " << pokemon1->getName();
            qInfo() << "FIGHT!";
            atacar(pokemon1, pokemon2);
            qInfo() << "PS de: " << pokemon1->getName() << " : " << pokemon1->getHealth();
            qInfo() << "PS de: " << pokemon2->getName() << " : " << pokemon2->getHealth();
            atacar(pokemon2, pokemon1);
            qInfo() << "PS de: " << pokemon1->getName() << " : " << pokemon1->getHealth();
            qInfo() << "PS de: " << pokemon2->getName() << " : " << pokemon2->getHealth();
        }
      //Si el numero aleatorio generado es 2, comienza la máquina
        if(turno==2)
        {
            qInfo() << "Empieza: " << pokemon2->getName();
            qInfo() << "FIGHT!";
            atacar(pokemon2, pokemon1);
            qInfo() << "PS de: " << pokemon1->getName() << " : " << pokemon1->getHealth();
            qInfo() << "PS de: " << pokemon2->getName() << " : " << pokemon2->getHealth();
            atacar(pokemon1, pokemon2);
            qInfo() << "PS de: " << pokemon1->getName() << " : " << pokemon1->getHealth();
            qInfo() << "PS de: " << pokemon2->getName() << " : " << pokemon2->getHealth();
        }
    }
    //Si la salud del Pokémon del usuario es mayor al de la máquina, gana el Pokémon del usuario
    if(pokemon1->getHealth() > pokemon2->getHealth())
    {
        qInfo() << pokemon1->getName()<< "Es el GANADOR!!!";
    //De otra forma, gana la máquina
    }
    else
    {
        qInfo() << pokemon2->getName() << "Es el GANADOR!!!";
    }
}

/**
 * @brief Realiza una batalla tipo "Last One Standing" entre Pokémones de la pokebola del usuario.
 * @param pokebola Referencia a la pokebola que contiene a los Pokémon.
 * @param size Número de Pokémones en la pokebola (tamaño del arreglo pokebola).
 */
void Arena::lastOneStand(Pokebola& pokebola, int size)
{
    qInfo() << "ENTRAN" << size << "POKEMONES";
    qInfo() << "SOLO UNO SALDRA VICTORIOSO!!!";
    qInfo() << "Comienza la Batalla!";
//Función para recorrer el arreglo de Pokémones en la pokebola, inicia en la posición 0 y acaba en la posición del tamaño de la pokebola-1 para i
// y acaba en la posición del tamaño de la pokebola para j
    for (size_t i = 0; i < size - 1; ++i)
    {
        for (size_t j = i + 1; j < size; ++j)
        {
            //Si los Pokémones no han sido derrotados, se ejecutará la pelea
            if (!pokebola.espacio[i]->Derrotado() && !pokebola.espacio[j]->Derrotado())
            {
                oneByOne(pokebola.espacio[i], pokebola.espacio[j]);

                if (pokebola.espacio[i]->getHealth() == 0)
                {
                    pokebola.espacio[i]->marcarComoDerrotado();
                }
                else if (pokebola.espacio[j]->getHealth() == 0)
                {
                    pokebola.espacio[j]->marcarComoDerrotado();
                }
            }
        }
    }
    //Función para buscar cual es el Pokémon vencedor, es decir, el último que mantiene el atributo derrotado como false.
    for(size_t i= 0; i < size-1; i++)
    {
        if(!pokebola.espacio[i]->Derrotado())
        {
            qInfo() << pokebola.espacio[i]->getName() << "ES EL POKEMON VENCEDOR!!!";
        }
    }
}

/**
 * @brief Realiza un ataque entre dos Pokémones durante la batalla.
 * @param atacante Puntero al Pokémon atacante.
 * @param defensor Puntero al Pokémon defensor.
 */
void Arena::atacar(Pokemon *atacante, Pokemon *defensor)
{

    //Motor para generar un número aleatorio para variar los ataques de los Pokémones
    unsigned int semilla = chrono::steady_clock::now().time_since_epoch().count();
    std::default_random_engine motor{semilla};
    uniform_int_distribution<short> distNm{1, 10};
    int randomMod{distNm(motor)};

    int ataque = (((2*(atacante->getLevel())+10)/25)*((atacante->getDamage())/(defensor->getDefense())) + 2) * randomMod;

    qInfo() << atacante->getName() << "ataca a " << defensor->getName();
    defensor->modHealth(ataque);
}
