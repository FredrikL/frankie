#include <iostream>
#include <functional>
#include "frankie.hpp"

module(Foo, {
	Get("/", [](frankie::Context ctx) {
		std::cout << "Ho" << std::endl;
		frankie::Response r("Ho");
		return r;
	});
});

module(Bar, {
	Get("/bar", [](frankie::Context ctx) {
		std::cout << "Hai" << std::endl;
		frankie::Response r("Hai");
		return r;
	});
});

int main() {
	frankie::run(9090);

	return 0;
}