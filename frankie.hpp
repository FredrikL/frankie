#pragma once

#include "module.hpp"
#include "registry.hpp"
 
#define FAKE_NAME(name) name ## _reg

#define module(name, body) class name : public frankie::Module { public: name() body}; \
	frankie::known FAKE_NAME(name)({#name, []() {return std::shared_ptr<frankie::Module>(new name());}});

