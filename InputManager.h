#pragma once

#include "Singleton.h"

#include <SDL3/SDL.h>

#include <queue>


template<typename Event>
class InputEventManager : public Singleton<InputEventManager<Event>>
{
	std::queue<Event> m_events;

	void HandleEvent(const Event& event);	// define this function for each instance
public:
	void HandleEvents()
	{
		while (m_events.size() > 0)
		{
			HandleEvent(m_events.front());
			m_events.pop();
		}
	}

	void AddEvent(const Event& event)
	{
		m_events.push(event);
	}
};

class InputManager : public Singleton<InputManager>
{
	InputEventManager<SDL_KeyboardEvent> m_keyboard;
	InputEventManager<SDL_MouseMotionEvent> m_mouseMotion;
	InputEventManager<SDL_MouseButtonEvent> m_mouseButton;
	InputEventManager<SDL_MouseWheelEvent> m_mouseWheel;
	InputEventManager<SDL_GamepadAxisEvent> m_gamepadAxis;
	InputEventManager<SDL_GamepadButtonEvent> m_gamepadButton;
	
public:
	void AddEvent(const SDL_Event& event);
	void HandleEvents();
};