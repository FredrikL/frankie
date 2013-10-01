#include <functional>
#include "frankie/frankie.hpp"

module(Foo, {
	Get("/", [](frankie::Context) {
		return "Ho";
	});
});

module(Baz, {
	Get("/Baz", [](frankie::Context c){
		auto p = c.parameters();
		return "baz" + p["foo"];
	});
	Get("/Foo", [](frankie::Context){
		return "foo";
	});
});

module(Bar, {
	Get("/bar", [](frankie::Context) {
		return "Hai";
	});
});

int main() {
	frankie::run(9090);

	return 0;
}