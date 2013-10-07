#pragma once

#include <map>
#include <functional>
#include <string>
#include "context.hpp"
#include "response.hpp"

namespace frankie {

	typedef std::function<frankie::Response(frankie::Context)> func;
	

	class Module{
		public:
			bool canHandle(const std::string protocol, const std::string path) { 
				auto dict = getForProtocol(protocol);
					
				for(auto &k : dict) {
					if(k.first == path)
						return true;
				}
				return false;
			};

			frankie::Response handle(const Context ctx) {
				auto dict = getForProtocol(ctx.protocol());

				if(dict.find(ctx.path()) != dict.end()){
					return dict[ctx.path()](ctx);
				}
 				return frankie::NotFoundResponse();
			}

		protected:
			void Get(std::string path, func f) {
				get[path] = f;
			}

			void Post(std::string path, func f) {
				post[path] = f;
			}

		private:

			const std::map<std::string, func> & getForProtocol(const std::string protocol) const {
				if(protocol == "POST")
					return post;

				return get;
			}

			std::map<std::string, func> get;
			std::map<std::string, func> post;
	};
};