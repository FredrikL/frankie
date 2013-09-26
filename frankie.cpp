#include <functional>
#include "frankie.hpp"

module(Foo, {
	Get("/", [](frankie::Context ctx) {
		return "Ho";
	});
});

module(Bar, {
	Get("/bar", [](frankie::Context ctx) {
		return "Hai";
	});
});

int main() {
	frankie::run(9090);

	return 0;
}