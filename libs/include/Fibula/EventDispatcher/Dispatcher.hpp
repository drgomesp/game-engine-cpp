#pragma once

#include <map>
#include <string>
#include <vector>
#include <memory>

#include "Event.hpp"
#include "Listener.hpp"
#include "Payload.hpp"
#include <boost/shared_ptr.hpp>

namespace Fibula {
    namespace EventDispatcher {
        class Listener;

        using namespace std;

        using ListenerVector = vector<shared_ptr<Listener>>;
        using ListenerMap = map<string, ListenerVector>;
    }
}

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

            ~Dispatcher()
            { }

        private:
            ListenerMap::const_iterator searchListenersByPrefix(const string &prefix) const;
        };
    }
}
