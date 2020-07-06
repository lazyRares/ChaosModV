/*
	Effect by Lucas7yoshi
*/

#include <stdafx.h>

static void OnStop()
{
	for (Vehicle veh : GetAllVehs())
	{
		for (int i = 0; i < 48; i++)
		{
			SET_VEHICLE_TYRE_FIXED(veh, i);
		}
	}
}

static void OnTick()
{
	static DWORD64 lastTick = GetTickCount64();
	DWORD64 currentTick = GetTickCount64();

	if (lastTick < currentTick - 1250) // 1250MS = every 1.25 seconds.
	{
		lastTick = currentTick;

		for (Vehicle veh : GetAllVehs())
		{
			for (int i = 0; i < 48; i++) // using code from VehsPopTires.cpp
			{
				if (g_random.GetRandomInt(0, 1)) // random true / false to get ideally 50% of tires popped.
				{
					SET_VEHICLE_TYRE_BURST(veh, i, true, 1000.f);
				}
				else
				{
					SET_VEHICLE_TYRE_FIXED(veh, i);
				}
			}
		}
	}
}

static RegisterEffect registerEffect(EFFECT_VEH_POP_TIRE_LOOP, nullptr, OnStop, OnTick);