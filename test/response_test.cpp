#include <bandit/bandit.h>
#include "../frankie/response.hpp"

using namespace bandit;
using namespace frankie;

go_bandit([](){
	describe("response:", [](){

		it("NotFoundResponse should have status 404", [](){
			NotFoundResponse resp;
			AssertThat(resp.status(), Equals(404u));
		});

	});

});
