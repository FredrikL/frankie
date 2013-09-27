#include <functional>
#include "frankie/frankie.hpp"

module(Foo, {
	Get("/", [](frankie::Context ctx) {
		return "Ho";
	});
});

module(Baz, {
	Get("/Baz", [](frankie::Context){
		return "baz";
	});
	Get("/Fuu", [](frankie::Context){
		return "fuu";
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