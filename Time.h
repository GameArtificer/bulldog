#pragma once

#include <chrono>

using TimePoint = std::chrono::time_point<std::chrono::steady_clock>;
using TickInterval = unsigned long long;

inline TimePoint GetCurrentTime();
inline TickInterval GetDeltaTime();

// advances the internal timer used for determining frame delta time
// returns the new delta time value stored internally
// this value can be queried at any time using GetDeltaTime()
TickInterval Tick(); 