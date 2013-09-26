#include <functional>
#include "frankie.hpp"

module(Foo, {
	Get("/", [](frankie::Context ctx) {
		return frankie::Response("Ho");
	});
});

module(Bar, {
	Get("/bar", [](frankie::Context ctx) {
		return frankie::Response("Hai");
	});
});

int main() {
	frankie::run(9090);

	return 0;
}