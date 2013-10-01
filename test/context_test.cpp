#include <bandit/bandit.h>
#include "../frankie/context.hpp"

using namespace bandit;
using namespace frankie;

go_bandit([](){
    describe("context:", [](){
    	std::string request = "GET /index.html HTTP/1.1\r\nHost: www.example.com";
    	Context ctx(request);

		it("should parse protocl from request", [&](){
			AssertThat(ctx.protocol(), Equals("GET"));
		});

		it("should parse path from request", [&](){
			AssertThat(ctx.path(), Equals("/index.html"));
		});

		it("should parse host from request", [&](){
			AssertThat(ctx.host(), Equals("www.example.com"));
		});

		describe("parameters", [](){
			std::string request = "GET /foo?bar=baz HTTP/1.1\r\nHost: www.example.com";
			Context c(request);

			it("should resolve the correct path", [&](){
				AssertThat(c.path(), Equals("/foo"));
			});
		});
    });

});
