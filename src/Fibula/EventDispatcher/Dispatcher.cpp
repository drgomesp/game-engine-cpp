#include <Fibula/EventDispatcher/Dispatcher.hpp>
#include <boost/regex.h>

#include <iostream>

using namespace Fibula::EventDispatcher;

void Dispatcher::addListener(const std::string &eventName, boost::shared_ptr<Listener> listener)
{
    ListenerVector registeredListeners;

    if (this->listeners.find(eventName) != this->listeners.end()) {
        registeredListeners = this->listeners.at(eventName);
    }

    registeredListeners.push_back(listener);
    std::pair<std::string, ListenerVector> pair(eventName, registeredListeners);
    this->listeners.insert(pair);
}

void Dispatcher::dispatchEvent(const std::string &eventName, boost::shared_ptr<Event> event) const
{
    ListenerMap::const_iterator it = this->searchListenersByPrefix(eventName);

    for (it; it != this->listeners.end(); ++it) {
        ListenerVector candidates = it->second;

        for (boost::shared_ptr<Listener> listener: candidates) {
            LISTENER_RESPONSE response = listener->handleEvent(event);
        }
    }
}

ListenerMap::const_iterator Dispatcher::searchListenersByPrefix(const std::string &prefix) const
{
    std::cout << "Searching listeners by event name: " << prefix << std::endl;
    ListenerMap::const_iterator it = this->listeners.lower_bound(prefix);

    if (it != this->listeners.end()) {
        const std::string &key = it->first;

        // Is it a prefix?
        std::cout << "Key: " << key << std::endl;

        if (key.compare(0, prefix.size(), prefix) == 0) {
            std::cout << "Found candidate for event: " << prefix << std::endl;
            return it;
        }
    }

    return this->listeners.end();
}

size_t Dispatcher::getListenerMemorySize(Listener listener) const
{
    return sizeof(listener) + this->listeners.size();
}
