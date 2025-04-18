#pragma once

#include "Event.h"

template <typename payload_t>
class ConnectionHandler
{
    template<typename payload_t>
    friend class EventBase;

private:
    template<template<typename> class EventBase, typename payload_t>
    ConnectionHandler(EventBase<payload_t>* eventHandledPtr, void* callbackObject) :
        eventHandledPtr(eventHandledPtr),
        callbackObject(callbackObject)
    {}

public:
    ConnectionHandler() = default;
    ConnectionHandler(ConnectionHandler&& other)
        : eventHandledPtr(other.eventHandledPtr)
        , callbackObject(other.callbackObject)

    {
        other.eventHandledPtr = nullptr;
        other.callbackObject = nullptr;
    }
    ConnectionHandler& operator=(ConnectionHandler&& other)
    {
        eventHandledPtr = other.eventHandledPtr;
        callbackObject = other.callbackObject;

        other.eventHandledPtr = nullptr;
        other.callbackObject = nullptr;

        return *this;
    }

    ~ConnectionHandler();

    ConnectionHandler(const ConnectionHandler&) = delete;
    ConnectionHandler& operator=(const ConnectionHandler&) = delete;

    void Disconnect();

private:
    EventBase<payload_t>* eventHandledPtr = nullptr;
    void* callbackObject = nullptr;
};

template<typename payload_t>
inline ConnectionHandler<payload_t>::~ConnectionHandler()
{
    Disconnect();
}

template<typename payload_t>
inline void ConnectionHandler<payload_t>::Disconnect()
{
    if (eventHandledPtr != nullptr)
    {
        eventHandledPtr->Disconnect(callbackObject);
        eventHandledPtr = nullptr;
        callbackObject = nullptr;
    }
}

