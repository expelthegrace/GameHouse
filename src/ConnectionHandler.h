#pragma once

#include "Event.h"

template <typename T>
class ConnectionHandler
{
public:
    ConnectionHandler(ConnectionHandler&&) = default;
    ConnectionHandler& operator=(ConnectionHandler&&) = default;

    ~ConnectionHandler();

private:
    ConnectionHandler(EventBase<T>* eventHandled, void* callbackObject) :
        eventHandled(eventHandled),
        callbackObject(callbackObject)
    {}

    ConnectionHandler() = delete;
    ConnectionHandler(const ConnectionHandler&) = delete;
    ConnectionHandler& operator=(const ConnectionHandler&) = delete;

private:
    EventBase<T>* eventHandled;
    void* callbackObject;
};

template<typename T>
inline ConnectionHandler<T>::~ConnectionHandler()
{
    if (eventHandled != nullptr)
    {
        eventHandled->Disconnect(callbackObject);
    }
}

