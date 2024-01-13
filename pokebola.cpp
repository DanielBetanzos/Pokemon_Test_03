#include "pokebola.h"
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
 * @brief Constructor de Pokebola.
 * @param numero_pokemones Número de espacios disponibles en la pokebola.
 */
Pokebola::Pokebola(int numero_pokemones) : numero_pokemones{numero_pokemones}
{
    espacio = new Pokemon*[numero_pokemones];

    for(size_t i = 0; i < numero_pokemones; i++)
    {
        espacio[i] = nullptr;
    }
}

/**
 * @brief Agrega un Pokémon a la pokebola.
 * @param pok Puntero al Pokémon que se agregará.
 */
void Pokebola::agregaPokemon(Pokemon *pok)
{
    for(size_t i = 0; i < numero_pokemones; i++)
    {
        if(espacio[i] == nullptr)
        {
            espacio[i] = pok;
            break;
        }
    }
}

/**
 * @brief Saca un Pokémon de la pokebola.
 * @return Puntero al Pokémon seleccionado.
 */
Pokemon* Pokebola::sacarPokemon()
{
    int pokemon;

    do
    {
        qInfo() << "¿Cuál Pokémon quieres sacar?";
        std::cin >> pokemon;

        if (pokemon >= 1 && pokemon <= numero_pokemones && espacio[pokemon - 1] != nullptr)
        {
            return espacio[pokemon - 1];
        }
        else
        {
            qInfo() << "Número de Pokémon no válido o espacio vacío. Inténtalo de nuevo.";
        }
    }
    while (true);
}

/**
 * @brief Imprime la información de los Pokémon en la pokebola.
 */
void Pokebola::printPokebola()
{
    for(size_t i = 0; i < numero_pokemones; i++)
    {
        if(espacio[i] != nullptr)
        {
            qInfo() << "Pokemon: " << i + 1;
            espacio[i]->printData();
        }
    }
}

/**
 * @brief Selecciona y agrega varios Pokémon a la pokebola.
 * @param pokemon1 Puntero al primer Pokémon.
 * @param pokemon2 Puntero al segundo Pokémon.
 * @param pokemon3 Puntero al tercer Pokémon.
 * @param pokemon4 Puntero al cuarto Pokémon.
 * @param pokemon5 Puntero al quinto Pokémon.
 */
void Pokebola::selectPokemon(Pokemon* pokemon1, Pokemon* pokemon2, Pokemon* pokemon3, Pokemon* pokemon4, Pokemon* pokemon5)
{
    int opc{};

    qInfo() << "Selecciona" << numero_pokemones << "pokemones";
    qInfo() << "1." << pokemon1->getName();
    qInfo() << "2." << pokemon2->getName();
    qInfo() << "3." << pokemon3->getName();
    qInfo() << "4." << pokemon4->getName();
    qInfo() << "5." << pokemon5->getName();

    for(int n = 0; n < numero_pokemones; n++)
    {
        std::cin >> opc;
        if(opc == 1)
        {
            agregaPokemon(pokemon1);
        }
        else if(opc == 2)
        {
            agregaPokemon(pokemon2);
        }
        else if(opc == 3)
        {
            agregaPokemon(pokemon3);
        }
        else if(opc == 4)
        {
            agregaPokemon(pokemon4);
        }
        else if(opc == 5)
        {
            agregaPokemon(pokemon5);
        }
    }
}

/**
 * @brief Selecciona aleatoriamente un Pokémon de una lista dada de Pokémones.
 * @param pokemon1 Primer Pokémon.
 * @param pokemon2 Segundo Pokémon.
 * @param pokemon3 Tercer Pokémon.
 * @param pokemon4 Cuarto Pokémon.
 * @param pokemon5 Quinto Pokémon.
 * @return El Pokémon seleccionado aleatoriamente.
 */
Pokemon Pokebola::machineSelect(Pokemon pokemon1, Pokemon pokemon2, Pokemon pokemon3, Pokemon pokemon4, Pokemon pokemon5)
{
    unsigned int semilla = chrono::steady_clock::now().time_since_epoch().count();
    std::default_random_engine motor{semilla};
    uniform_int_distribution<short> distNm{1, 5};
    int randomMachineNum{distNm(motor)};

    if(randomMachineNum == 1)
    {
        return pokemon1;
    }
    else if(randomMachineNum == 2)
    {
        return pokemon2;
    }
    else if(randomMachineNum == 3)
    {
        return pokemon3;
    }
    else if(randomMachineNum == 4)
    {
        return pokemon4;
    }
    else if(randomMachineNum == 5)
    {
        return pokemon5;
    }
}


