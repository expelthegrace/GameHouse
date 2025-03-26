#pragma once

#include <functional>
#include <list>
#include <iostream> //MARC


template<typename payload_t>
class EventBase
{
    using CallbackFunc = std::function<void(payload_t)>;

public:
	EventBase() = default;
	
    EventBase(const EventBase&) = delete;
    EventBase& operator=(const EventBase&) = delete;
    EventBase(EventBase&&) = delete;
    EventBase& operator=(EventBase&&) = delete;

    template <typename object_t>
    void Connect(object_t* object, void (object_t::* func)(payload_t));

    void Emit(payload_t payload);

private:
    std::list<CallbackFunc> ConnectedFuncs;

};

template <typename payload_t>
template <typename object_t>
void EventBase<payload_t>::Connect(object_t* object, void (object_t::* func)(payload_t))
{
    CallbackFunc callbackMethod = std::bind(func, object, std::placeholders::_1);
    ConnectedFuncs.push_back(callbackMethod);
}

template <typename payload_t>
void EventBase<payload_t>::Emit(payload_t payload)
{
    for (auto& callbackFunc : ConnectedFuncs)
    {
        callbackFunc(payload);
    }
}



class Saltador
{
public:
    void HeSaltat(int metres)
    {
        std::cout << "he saltat: " << metres << std::endl;

    }

    void Update();

    void CridaEmitPublic();

private:
    void CridaEmit();

    EventBase<int> JumpEvent;
};
