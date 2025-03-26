#pragma once

#include <functional>
#include <unordered_map>
#include <iostream> //MARC

//#include "ConnectionHandler.h"

template<typename payload_t>
class EventBase
{
    using CallbackFunc = std::function<void(payload_t)>;

public:
	EventBase() = default;
	
    EventBase(const EventBase&) = delete;
    EventBase(EventBase&&) = delete;
    EventBase& operator=(const EventBase&) = delete;
    EventBase& operator=(EventBase&&) = delete;

    template <typename object_t>
    void Connect(object_t* object, void (object_t::* func)(payload_t));

    template <typename object_t>
    void Disconnect(object_t* object);

    void Emit(payload_t payload);

private:
    std::unordered_map<void*, CallbackFunc> ConnectedObjects;

};

template <typename payload_t>
template <typename object_t>
void EventBase<payload_t>::Connect(object_t* object, void (object_t::* func)(payload_t))
{
    CallbackFunc callbackMethod = std::bind(func, object, std::placeholders::_1);
    ConnectedObjects.try_emplace(reinterpret_cast<void*>(object), callbackMethod);
}

template <typename payload_t>
void EventBase<payload_t>::Emit(payload_t payload)
{
    for (auto& [objectPtr, objectCallback] : ConnectedObjects)
    {
        objectCallback(payload);
    }
}

template <typename payload_t>
template <typename object_t>
void EventBase<payload_t>::Disconnect(object_t* object)
{
    auto it = ConnectedObjects.find(object);

    if (it != ConnectedObjects.end()) {
        ConnectedObjects.erase(it);
    }
}