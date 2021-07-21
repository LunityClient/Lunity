#ifndef LUNITY_CLIENT_EVENTS_EVENTREGISTRY
#define LUNITY_CLIENT_EVENTS_EVENTREGISTRY

#include <functional>
#include <vector>

class Event;

enum EVENT_ID {
	EVENT_BASE,
	LP_HEAD_ROT_Y_EVENT,
	LP_HEAD_ROT_CHANGE_EVENT
};

struct Listener {
	EVENT_ID id;
	std::function<void(Event*)> callback;

	Listener(EVENT_ID id, std::function<void(Event*)> callback);
};

class EventRegistry {
	static inline EventRegistry* instance;
	std::vector<Listener>* listeners;
	EventRegistry();
public:
	static auto GetInstance() -> EventRegistry*;
	//Functions that return 'void' and have 'Event*' as a parameter can have a callback
	//NOTE: Even though events are pointers, THEY SHOULD NOT BE CREATED WITH THE "new" KEYWORD!
	void AddSubscriber(std::function<void(Event*)> callback, EVENT_ID listenId);
	//NOTE: Even though events are pointers, THEY SHOULD NOT BE CREATED WITH THE "new" KEYWORD!
	void DispatchEvent(Event* event);
};

#endif /* LUNITY_CLIENT_EVENTS_EVENTREGISTRY */