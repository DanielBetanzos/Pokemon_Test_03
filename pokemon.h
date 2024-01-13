#ifndef POKEMON_H
#define POKEMON_H

#include <QString>

/**
 * @brief La clase Pokemon representa a un personaje Pokémon.
 */
class Pokemon
{
private:
    /**
     * @brief Nombre del Pokémon.
     */
    QString name{};

    /**
     * @brief Tipo del Pokémon.
     */
    QString tipo{};

    /**
     * @brief Puntos de salud del Pokémon.
     */
    int health{};

    /**
     * @brief Puntos de daño que puede infligir el Pokémon.
     */
    int damage{};

    /**
     * @brief Puntos de defensa del Pokémon.
     */
    int defense{};

    /**
     * @brief Nivel del Pokémon.
     */
    int level{};

    /**
     * @brief Indica si el Pokémon ha sido derrotado.
     */
    bool derrotado{};

public:
    /**
     * @brief Constructor predeterminado de la clase Pokemon.
     */
    Pokemon();

    /**
     * @brief Constructor de la clase Pokemon con parámetros específicos.
     * @param name Nombre del Pokémon.
     * @param tipo Tipo del Pokémon.
     * @param health Puntos de salud del Pokémon.
     * @param damage Puntos de daño que puede infligir el Pokémon.
     * @param defense Puntos de defensa del Pokémon.
     * @param level Nivel del Pokémon.
     * @param derrotado Indica si el Pokémon ha sido derrotado.
     */
    Pokemon(QString name, QString tipo, int health, int damage, int defense, int level, bool derrotado);

    /**
     * @brief Destructor virtual de la clase Pokemon.
     */
    virtual ~Pokemon();

    /**
     * @brief Obtiene el nombre del Pokémon.
     * @return Nombre del Pokémon.
     */
    inline QString getName() { return name; }

    /**
     * @brief Obtiene el tipo del Pokémon.
     * @return Tipo del Pokémon.
     */
    inline QString getTipo() { return tipo; }

    /**
     * @brief Obtiene los puntos de salud del Pokémon.
     * @return Puntos de salud del Pokémon.
     */
    inline int getHealth() { return health; }

    /**
     * @brief Obtiene los puntos de daño que puede infligir el Pokémon.
     * @return Puntos de daño del Pokémon.
     */
    inline int getDamage() { return damage; }

    /**
     * @brief Obtiene los puntos de defensa del Pokémon.
     * @return Puntos de defensa del Pokémon.
     */
    inline int getDefense() { return defense; }

    /**
     * @brief Obtiene el nivel del Pokémon.
     * @return Nivel del Pokémon.
     */
    inline int getLevel() { return level; }

    /**
     * @brief Indica si el Pokémon ha sido derrotado.
     * @return true si el Pokémon ha sido derrotado, false en caso contrario.
     */
    inline bool Derrotado() { return derrotado; }

    /**
     * @brief Modifica los puntos de salud del Pokémon después de recibir daño.
     * @param damage Cantidad de daño recibido.
     */
    void modHealth(int damage);

    /**
     * @brief Marca al Pokémon como derrotado.
     */
    void marcarComoDerrotado();

    /**
     * @brief Imprime la información del Pokémon.
     */
    virtual void printData(); // Implementación del método fuera de la clase base.
};

#endif // POKEMON_H

