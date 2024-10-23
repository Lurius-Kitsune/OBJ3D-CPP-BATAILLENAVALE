#pragma once
#include "Cordinates.h"


struct Marker
{
	Cordinates cordinate;

	bool HasHit(const Cordinates& _target) const
	{
		return cordinate.x == _target.x
			&& cordinate.y == _target.y;
	}
};

// Todo move into class
struct MarkerData
{
	Marker* markers;
	u_int cordinatesCount;

	MarkerData()
	{
		markers = nullptr;
	}

	~MarkerData()
	{
		delete[] markers;
	}

	void AddMarker()
	{

	}

	void RemoveMarker()
	{

	}

	Cordinates GetCordinatesByIndex(const u_int& _index)
	{

	}

	void ClearMarkers()
	{

	}
};