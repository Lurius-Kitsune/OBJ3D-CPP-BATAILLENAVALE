#pragma once
#include "Random.h"
#include "UserInteraction.h"
struct Cordinates
{
	u_int x;
	u_int y;

	string ToString() const
	{
		return "X: " + to_string(char('A'+x + 1)) + " - Y: " + to_string(y + 1);
	}

	bool IsSame(const Cordinates* _other)const
	{
		return x == _other->x
			&& y == _other->y;
	}

	Cordinates() = default;

	Cordinates(const u_int& _x, const u_int& _y)
	{
		x = _x;
		y = _y;
	}

	/// <summary>
	/// Donne une instance de cordinate Random
	/// </summary>
	/// <param name="_min">Valeur minimum</param>
	/// <param name="_max">Valeur Max</param>
	/// <returns>Instance de cordinate</returns>
	static Cordinates* GetRandom(const u_int& _min, const u_int _max)
	{
		const u_int& _x = GetRandomNumberInRange(_min, _max);
		const u_int& _y = GetRandomNumberInRange(_min, _max);

		return new Cordinates( _x, _y );
	}
};