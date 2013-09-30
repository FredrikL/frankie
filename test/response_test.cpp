#include <bandit/bandit.h>
#include "../frankie/response.hpp"

using namespace bandit;
using namespace frankie;

go_bandit([](){
	describe("response:", [](){

		it("should have a default status of 200", [](){
			Response resp("foo");
			AssertThat(resp.status(), Equals(200u));
		});


		it("NotFoundResponse should have status 404", [](){
			NotFoundResponse resp;
			AssertThat(resp.status(), Equals(404u));
		});
	});

});
