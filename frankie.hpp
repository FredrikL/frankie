#pragma once

#include <boost/asio.hpp>
#include "module.hpp"
#include "registry.hpp"
#include "server.hpp"
 
#define FAKE_NAME(name) name ## _reg

#define module(name, body) class name : public frankie::Module { public: name() body}; \
	frankie::known FAKE_NAME(name)({#name, []() {return std::shared_ptr<frankie::Module>(new name());}});

namespace frankie {
	void run(int port) {
/*
		std::cout << frankie::regs().size() << std::endl;

		for(auto &x : frankie::regs()){
			std::cout << x.name << std::endl;
		}

		frankie::Registry r(frankie::regs());

		auto foo = r.create("Foo");

		if(foo->canHandle("GET","/")) {
			std::cout << "can handle!" << std::endl;
			foo->handle("GET", "/");
		}

*/
		boost::asio::io_service service;
		frankie::Server server(service, port);
		service.run();
	}
}
