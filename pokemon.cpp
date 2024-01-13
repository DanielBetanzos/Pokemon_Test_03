#include "pokemon.h"
#include <QString>
#include <QDebug>

/**
 * @brief Constructor por defecto de la clase Pokemon.
 * Inicializa un Pokemon con valores predeterminados.
 */
Pokemon::Pokemon() : name{"Pokemon 1"}, tipo{"Fuego"}, health{100}, damage{60}, defense{30}, level{3}, derrotado{false}
{
    qInfo() << "Invocando al Pokemon por default";
}

/**
 * @brief Constructor parametrizado de la clase Pokemon.
 * @param name Nombre del Pokemon.
 * @param tipo Tipo del Pokemon.
 * @param health Salud del Pokemon.
 * @param damage Daño del Pokemon.
 * @param defense Defensa del Pokemon.
 * @param level Nivel del Pokemon.
 * @param derrotado Estado de derrota del Pokemon.
 */
Pokemon::Pokemon(QString name, QString tipo, int health, int damage, int defense, int level, bool derrotado) : name{name} , tipo{tipo}, health{health} , damage{damage} , defense{defense}, level{level}, derrotado{false}
{

}

/**
 * @brief Destructor de la clase Pokemon.
 */
Pokemon::~Pokemon()
{

}

/**
 * @brief Imprime los datos del Pokemon.
 */
void Pokemon::printData()
{
    qInfo() << "Pokemon: " << name;
    qInfo() << "Tipo: "    << tipo;
    qInfo() << "Salud: "   << health;
    qInfo() << "Daño: "    << damage;
        qInfo() << "Defensa: " << defense;
    qInfo() << "Nivel: "   << level;
}

/**
 * @brief Modifica la salud del Pokemon después de un ataque.
 * @param damage Cantidad de daño recibido.
 */
void Pokemon::modHealth(int damage)
{
    health -= damage;
    if(health < 0)
    {
        health = 0; // Aseguramos que la vida no sea negativa.
    }
}

/**
 * @brief Marca al Pokemon como derrotado.
 */
void Pokemon::marcarComoDerrotado()
{
    derrotado = true;
}
