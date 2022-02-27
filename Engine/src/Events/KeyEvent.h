#pragma once
#include "Events.h"

namespace Mortal {
	class ME_ENGINE_API KeyEvent :public Event
	{
	public:
		inline int GetKeyCode() const { return m_KeyCode; }

		EVENT_CLASS_CATEGORY(EventCategory::Keyboard | EventCategory::Input)

	protected:
		KeyEvent(int KeyCode) : m_KeyCode(KeyCode)
		{}
		int m_KeyCode;
	};

	class ME_ENGINE_API KeyPressedEvent : public KeyEvent
	{
	public: 
		KeyPressedEvent(int KeyCode, int RepeatCount) : KeyEvent(KeyCode), m_RepeatCount(RepeatCount)
		{}

		inline int GetRepeatCount() const { return m_RepeatCount; }
		EVENT_CLASS_TYPE(KeyPressed)
		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyPressed: " << m_KeyCode << " for " << m_RepeatCount << " times";
			return ss.str();
		}

	protected:
		int m_RepeatCount;
	};

	class ME_ENGINE_API KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(int KeyCode) : KeyEvent(KeyCode)
		{}
		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyReleased: " << m_KeyCode;
			return ss.str();
		}
		EVENT_CLASS_TYPE(KeyReleased)
	};
}