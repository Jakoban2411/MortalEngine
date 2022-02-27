#pragma once
#include "Events.h"
namespace Mortal {
	class ME_ENGINE_API WindowResizeEvent : public Event {
	public:
		WindowResizeEvent(unsigned int WindowWidth, unsigned int WindowHeight) :m_WindowWidth(WindowWidth), m_WindowHeight(WindowHeight)
		{
		}
		inline unsigned int GetHeight() { return m_WindowHeight; }
		inline unsigned int GetWidth() { return m_WindowWidth; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "Window Resized: " << m_WindowWidth << " , " << m_WindowHeight;
			return ss.str();
		}
		EVENT_CLASS_CATEGORY(App)
		EVENT_CLASS_TYPE(WindowResize)
	protected:
		unsigned int m_WindowWidth, m_WindowHeight;
	};
	class ME_ENGINE_API WindowCloseEvent : public Event {
	public:
		WindowCloseEvent() {}
		EVENT_CLASS_TYPE(WindowClose)
		EVENT_CLASS_CATEGORY(App)
	};
	class ME_ENGINE_API Tick :public Event {
	public:
		Tick() {}
		EVENT_CLASS_CATEGORY(App)
		EVENT_CLASS_TYPE(Tick)
	};
	class ME_ENGINE_API Update :public Event {
	public:
		Update() {}
		EVENT_CLASS_CATEGORY(App)
			EVENT_CLASS_TYPE(Update)
	};
	class ME_ENGINE_API Render: public Event {
	public:
		Render() {}
		EVENT_CLASS_CATEGORY(App)
			EVENT_CLASS_TYPE(Render)
	};

}
