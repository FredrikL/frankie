#include <functional>
#include "frankie.hpp"

module(Foo, {
	Get("/", [](frankie::Context ctx) {
		frankie::Response r("Ho");
		return r;
	});
});

module(Bar, {
	Get("/bar", [](frankie::Context ctx) {
		frankie::Response r("Hai");
		return r;
	});
});

int main() {
	frankie::run(9090);

	return 0;
}