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
			std::string request = "GET /foo?bar=baz&foo=fu HTTP/1.1\r\nHost: www.example.com";
			Context c(request);

			it("should resolve the correct path", [&](){
				AssertThat(c.path(), Equals("/foo"));
			});

			it("should parse parameters into map", [&]() {
				auto p = c.parameters();

				AssertThat(p["bar"], Equals("baz"));
			});

			 it("should parse second parameter into map", [&]() {
				auto p = c.parameters();

				AssertThat(p["foo"], Equals("fu"));
			});
		});
    });

});
