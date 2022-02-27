#pragma once
#include "Events.h"

namespace Mortal {
	class ME_ENGINE_API MouseMoveEvent :public Event {
	public:
		EVENT_CLASS_CATEGORY(EventCategory::Mouse|EventCategory::Input)
		EVENT_CLASS_TYPE(MouseMoved)

		MouseMoveEvent(float X, float Y) : m_MouseX(X), m_MouseY(Y)
		{}

		inline float GetX() { return m_MouseX; };
		inline float GetY() { return m_MouseY; };

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseMoved: " << m_MouseX << " , " << m_MouseY;
			return ss.str();
		}
	private:
		float m_MouseX, m_MouseY;
	};
	
	class ME_ENGINE_API MouseScrolledEvent :public Event {
	public:
		EVENT_CLASS_CATEGORY(EventCategory::Mouse | EventCategory::Input)
		EVENT_CLASS_TYPE(MouseScrolled)

		MouseScrolledEvent(float ScrollOffsetY) : m_ScrollOffset(ScrollOffsetY)
		{}


		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseScrolled: " << m_ScrollOffset;
			return ss.str();
		}
	private:
		float m_ScrollOffset;
	};

	class ME_ENGINE_API MousePressEvent :public Event {
	public:
		EVENT_CLASS_CATEGORY(EventCategory::Mouse | EventCategory::Input)
		EVENT_CLASS_TYPE(MouseButtonPressed)

		MousePressEvent(int MouseKeyCode) : m_MouseKeyCode(MouseKeyCode)
		{}


		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseClicked: " << m_MouseKeyCode ;
			return ss.str();
		}
	private:
		float m_MouseKeyCode;
	};
	
	class ME_ENGINE_API MouseReleasedEvent :public Event {
	public:
		EVENT_CLASS_CATEGORY(EventCategory::Mouse | EventCategory::Input)
		EVENT_CLASS_TYPE(MouseButtonReleased)

		MouseReleasedEvent(int MouseKeyCode) : m_MouseKeyCode(MouseKeyCode)
		{}


		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseReleased: " << m_MouseKeyCode;
			return ss.str();
		}
	private:
		float m_MouseKeyCode;
	};
}