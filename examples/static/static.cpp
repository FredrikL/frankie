#include <functional>
#include "../../frankie/frankie.hpp"

using namespace frankie;

module(Static, {
	Get("/", [](Context) {
		return StaticResponse("index.html");
	});
});

int main() {
	frankie::run(9090);

	return 0;
}