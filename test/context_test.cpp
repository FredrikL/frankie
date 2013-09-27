#include <bandit/bandit.h>
#include "../frankie/context.hpp"


using namespace bandit;
using namespace frankie;

go_bandit([](){
    describe("context:", [](){
    	std::string request = "GET /index.html HTTP/1.1\r\nHost: www.example.com";

		it("should parse protocl from request", [&](){
			Context ctx(request);

			AssertThat(ctx.protocol(), Equals("GET"));
		});
    });

});
