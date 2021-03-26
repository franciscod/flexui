#include "flexui/Nodes/Elements/Button.hpp"

#include "flexui/Events/Events.hpp"
#include "flexui/Events/EventsController.hpp"

namespace flexui {

	Button::Button() : Element("button")
	{
	}

	Button::~Button()
	{
	}

	void Button::executeDefault(EventBase* evt)
	{
		Element::executeDefault(evt);

		switch (evt->type) {
		case EventTypeID::MOUSE_DOWN:
			//getSurface()->getEventsController()->captureElement(this);
			break;
		case EventTypeID::MOUSE_UP:
            //getSurface()->getEventsController()->captureElement(nullptr);
			break;
		}
	}

}
