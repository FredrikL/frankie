#include <iostream>
#include <functional>
#include "frankie.hpp"


module(Foo, {
	Get("/foo", [](frankie::Context ctx) {
		std::cout << "Ho" << std::endl;
		frankie::Response r;
		return r;
	});
});

module(Bar, {
	Get("/bar", [](frankie::Context ctx) {
		std::cout << "Hai" << std::endl;
		frankie::Response r;
		return r;
	});
});

int main() {
	std::cout << frankie::regs().size() << std::endl;

	for(auto &x : frankie::regs()){
		std::cout << x.name << std::endl;
	}

	frankie::Registry r(frankie::regs());

	auto foo = r.create("Foo");

	return 0;
}