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
    ConnectionHandler(ConnectionHandler&& i_other)
        : eventHandledPtr(i_other.eventHandledPtr)
        , callbackObject(i_other.callbackObject)

    {
        i_other.eventHandledPtr = nullptr;
        i_other.callbackObject = nullptr;
    }
    ConnectionHandler& operator=(ConnectionHandler&& i_other)
    {
        eventHandledPtr = i_other.eventHandledPtr;
        callbackObject = i_other.callbackObject;

        i_other.eventHandledPtr = nullptr;
        i_other.callbackObject = nullptr;

        return *this;
    }

    ~ConnectionHandler();

    ConnectionHandler(const ConnectionHandler&) = delete;
    ConnectionHandler& operator=(const ConnectionHandler&) = delete;

private:
    EventBase<payload_t>* eventHandledPtr = nullptr;
    void* callbackObject = nullptr;
};

template<typename payload_t>
inline ConnectionHandler<payload_t>::~ConnectionHandler()
{
    if (eventHandledPtr != nullptr)
    {
        eventHandledPtr->Disconnect(callbackObject);
    }
}

