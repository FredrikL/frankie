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

		describe("accept headers", [](){
			std::string request = "GET / HTTP/1.1\r\nHost: www.example.com\r\nAccept: application/xml,application/xhtml+xml,text/html;q=0.9,text/plain;q=0.8,image/png,*/*;q=0.5";
			Context c(request);
			auto headers = c.accept_headers();

			it("should parse all accept headers", [&](){
				AssertThat(headers.size(), Equals(6ul));
			});

			it("should be sorted by priority", [&](){
				AssertThat(headers[0], Equals("application/xml"));
			});

			it("should have lowest q last", [&](){
				AssertThat(headers[5],Equals("*/*;q=0.5"));
			});
		});

		describe("content-type", [](){
			std::string request = "POST / HTTP/1.1Host: www.example.com\r\nAccept: application/xml,application/xhtml+xml,text/html;q=0.9,text/plain;q=0.8,image/png,*/*;q=0.5\r\nContent-Type: application/json";
			Context c(request);

			it("should parse content-type if present",[&](){
				AssertThat(c.content_type(), Equals("application/json"));
			});
		});
    });

});
