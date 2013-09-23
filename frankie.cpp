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

	return 0;
}