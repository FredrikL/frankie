#include <functional>
#include "../../frankie/frankie.hpp"

using namespace frankie;

struct msg {
	std::string x;

	template<class Archive>
	void serialize(Archive & archive)
	{
		archive(CEREAL_NVP(x));
	}
};

module(P, {
	// expected input {"x":"hai"}
	Post("/", [](Context c) {
		auto e = Deserialize<msg>(c);
		e.x = "Sup?";
		return Serialize<msg>(e);
	});
});

int main() {
	frankie::run(9090);

	return 0;
}