#include <functional>
#include "../../frankie/frankie.hpp"

module(Static, {
	Get("/", [](frankie::Context) {
		return "Ho";
	});
});


int main() {
	frankie::run(9090);

	return 0;
}