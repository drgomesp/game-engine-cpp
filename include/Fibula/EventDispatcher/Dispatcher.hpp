#pragma once

#include <map>
#include <string>
#include <vector>

namespace Fibula {
    namespace EventDispatcher {
        using namespace std;

        class Listener;
        typedef std::vector<std::shared_ptr<Listener>> ListenerVector;
        typedef std::map<std::string, ListenerVector> ListenerMap;
    }
}

#include "Event.hpp"
#include "Listener.hpp"
#include "Payload.hpp"
#include <boost/shared_ptr.hpp>

namespace Fibula {
    namespace EventDispatcher {

        using namespace std;

        class Dispatcher
        {
        private:
             ListenerMap listeners;
        public:
            void addListener(const string &eventName, shared_ptr<Listener> listener);
            void dispatchEvent(const string &eventName, shared_ptr<const Event> event) const;
            ~Dispatcher() { }
        private:
            ListenerMap::const_iterator searchListenersByPrefix(const std::string &prefix) const;
        };
    }
}
