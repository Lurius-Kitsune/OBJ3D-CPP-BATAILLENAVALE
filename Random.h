#pragma once

#include "UserInteraction.h"


static int GetRandomNumberInRange(const int _max, const int _min = 0)
{
    random_device _rSeed; // Obtient une graine aléatoire
    mt19937 _gen(_rSeed()); // Initialisation du générateur avec la graine
    uniform_int_distribution<> _distr(_min, _max); // Définit la distribution ( les limites )

    return _distr(_gen);
}