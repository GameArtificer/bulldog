#include "InputManager.h"

void InputManager::AddEvent(const SDL_Event& event)
{
	switch (event.type)
	{
		case SDL_EVENT_KEY_UP:
		case SDL_EVENT_KEY_DOWN:
		{
			m_keyboard.AddEvent(event.key);
		} break;

		case SDL_EVENT_MOUSE_MOTION:
		{
			m_mouseMotion.AddEvent(event.motion);
		} break;

		case SDL_EVENT_MOUSE_BUTTON_DOWN:
		case SDL_EVENT_MOUSE_BUTTON_UP:
		{
			m_mouseButton.AddEvent(event.button);
		} break;

		case SDL_EVENT_MOUSE_WHEEL:
		{
			m_mouseWheel.AddEvent(event.wheel);
		} break;

		case SDL_EVENT_GAMEPAD_AXIS_MOTION:
		{
			m_gamepadAxis.AddEvent(event.gaxis);
		} break;

		case SDL_EVENT_GAMEPAD_BUTTON_DOWN:
		case SDL_EVENT_GAMEPAD_BUTTON_UP:
		{
			m_gamepadButton.AddEvent(event.gbutton);
		} break;
	}
}


void InputEventManager<SDL_KeyboardEvent>::HandleEvent(const SDL_KeyboardEvent& kbEvent)
{
	kbEvent.keysym;
	kbEvent.type;
	
}

void InputEventManager<SDL_MouseMotionEvent>::HandleEvent(const SDL_MouseMotionEvent& event)
{

}

void InputEventManager<SDL_MouseButtonEvent>::HandleEvent(const SDL_MouseButtonEvent& event)
{

}

void InputEventManager<SDL_MouseWheelEvent>::HandleEvent(const SDL_MouseWheelEvent& event)
{

}

void InputEventManager<SDL_GamepadAxisEvent>::HandleEvent(const SDL_GamepadAxisEvent& event)
{

}

void InputEventManager<SDL_GamepadButtonEvent>::HandleEvent(const SDL_GamepadButtonEvent& event)
{

}


void InputManager::HandleEvents()
{
	m_keyboard.HandleEvents();
	

}