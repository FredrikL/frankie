#pragma once

#include <boost/asio.hpp>
#include "module.hpp"
#include "server.hpp"
 
#define FAKE_NAME(name) name ## _reg

#define module(name, body) class name : public frankie::Module { public: name() body}; \
	frankie::known FAKE_NAME(name)({#name, []() {return std::shared_ptr<frankie::Module>(new name());}});

namespace frankie {
	void run(int port) {
		boost::asio::io_service service;
		frankie::Server server(service, port);
		service.run();
	}
}
