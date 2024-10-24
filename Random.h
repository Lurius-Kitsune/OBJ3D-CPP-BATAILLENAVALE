#pragma once

#include "UserInteraction.h"


static int GetRandomNumberInRange(const int _max, const int _min = 0)
{
    random_device _rSeed; // Obtient une graine al�atoire
    mt19937 _gen(_rSeed()); // Initialisation du g�n�rateur avec la graine
    uniform_int_distribution<> _distr(_min, _max); // D�finit la distribution ( les limites )

    return _distr(_gen);
}