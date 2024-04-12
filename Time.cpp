#include "Time.h"

// time management

namespace
{
	TimePoint s_lastTickTime = GetCurrentTime();
	TickInterval s_deltaTime;
}

TimePoint GetCurrentTime()
{
	return std::chrono::steady_clock::now();
}

TickInterval GetDeltaTime()
{
	return s_deltaTime;
}

TickInterval Tick()
{
	TimePoint currentTime = GetCurrentTime();
	std::chrono::nanoseconds nsDuration = currentTime - s_lastTickTime;

	s_lastTickTime = currentTime;

	s_deltaTime = std::chrono::duration_cast<std::chrono::duration<TickInterval, std::ratio<1, 1>>>(nsDuration).count();

	return s_deltaTime;
}