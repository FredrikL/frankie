#include <functional>
#include <entity/entity.h>
#include <entity/json.h>
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
	Post("/", [](Context c) {
		auto e = Deserialize<msg>(c);
		return e.x;
	});
});

int main() {
	frankie::run(9090);

	return 0;
}