#include <functional>
#include "../../frankie/frankie.hpp"

using namespace frankie;
using namespace ent;

struct msg : entity {
	std::string x;

	mapping map() {
		return mapping() << eref(x);
	}
};

module(P, {
	// expected input {"x":"hai"} || <entity><x>hai</x></entity>
	Post("/", [](Context c) {
		auto e = Deserialize<msg>(c);
		e.x = "Sup?";
		return Serialize<msg>(e, c);
	});
});

int main() {
	frankie::run(9090);

	return 0;
}