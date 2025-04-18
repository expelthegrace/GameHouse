#pragma once

#include <functional>
#include <unordered_map>

#include "ConnectionHandler.h"

template<typename payload_t>
class EventBase
{
    using CallbackFunc = std::function<void(payload_t)>;

public:
	EventBase() = default;
    virtual ~EventBase() = default;
	
    EventBase(const EventBase&) = delete;
    EventBase(EventBase&&) = delete;
    EventBase& operator=(const EventBase&) = delete;
    EventBase& operator=(EventBase&&) = delete;

    template <typename object_t>
    [[nodiscard]] ConnectionHandler<payload_t> Connect(object_t* objectPtr, void (object_t::* func)(payload_t))
    {
        CallbackFunc callbackMethod = std::bind(func, objectPtr, std::placeholders::_1);
        ConnectedObjects.try_emplace(reinterpret_cast<void*>(objectPtr), callbackMethod);

        ConnectionHandler<payload_t> newHandler(this, objectPtr);
        return newHandler;
    }

    template <typename object_t>
    void Disconnect(object_t* object);

    void Emit(payload_t payload);

private:
    
    // object and its callback method for this event. For now limted to one per object.
    std::unordered_map<void*, CallbackFunc> ConnectedObjects;

};

template <typename payload_t>
void EventBase<payload_t>::Emit(payload_t payload)
{
    auto connectionsIt = ConnectedObjects.begin();

    while (connectionsIt != ConnectedObjects.end())
    {
        const auto& [objectPtr, objectCallback] = *connectionsIt;

        if (objectPtr != nullptr)
        {
            objectCallback(payload);
            connectionsIt++;
        }
        else
        {
            connectionsIt = ConnectedObjects.erase(connectionsIt);
        }
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