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
    ConnectionHandler(ConnectionHandler&&) = delete; //MARC es podrien passar els dos a default
    ConnectionHandler& operator=(ConnectionHandler&& other)
    {
        if (this != &other)
        {
            eventHandledPtr = other.eventHandledPtr;
            callbackObject = other.callbackObject;

            other.eventHandledPtr = nullptr;
            other.callbackObject= nullptr;
        }

        std::cout << "Copia &&" << std::endl;


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
        std::cout << "Disconnected" << std::endl;
        eventHandledPtr->Disconnect(callbackObject);
    }
}

