#pragma once
#include <Core.h>
namespace Mortal {

#define EVENT_CLASS_TYPE(type) static EventType GetType() {return EventType::##type; } \
	virtual EventType GetEventType() const override { return GetType();} \
							   virtual const char* GetName() const override {return #type; }
#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }

	enum class EventType
	{
		None=0,
		WindowClose,
		WindowResize,
		WindowFocus,
		WindowMoved,
		WindowLostFocus,
		Tick,
		Update,
		Render,
		KeyPressed,
		KeyReleased,
		MouseButtonPressed,
		MouseButtonReleased,
		MouseMoved,
		MouseScrolled
	};

	enum EventCategory
	{
		None = 0,
		App=BIT(0),
		Input=BIT(1),
		Keyboard=BIT(2),
		Mouse=BIT(3),
		Click=BIT(4)
	};

	class ME_ENGINE_API Event
	{
		friend class EventDispatcher;
	public:
		virtual EventType GetEventType() const = 0;
		virtual int GetCategoryFlags() const = 0;
		virtual const char* GetName() const = 0;
		virtual std::string ToString() const { return GetName(); }
		inline bool IsInCategory(EventCategory category)
		{
			return GetCategoryFlags() & category;
		}
	protected:
		bool m_handled = false;
	};

	class EventDispatcher
	{
		template<typename T>
		using EventFn = std::function<bool(T&)> ;
		Event& m_Event;
	public:
		EventDispatcher(Event& event): m_Event(event)
		{}
		template<typename T>
		void Dispatch(EventFn<T> dispatchFunction)
		{
			if (m_Event.GetEventType() == T::GetType())
			{
				m_Event.m_handled = dispatchFunction(*(T*)&m_Event);
				return true;
			}
			return false;
		}

	};
	inline std::ostream& operator <<(std::ostream& os, const Event& e)
	{
		return os << e.ToString();
	}
}
