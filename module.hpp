#pragma once

#include <map>
#include <functional>
#include <string>
#include "context.hpp"
#include "response.hpp"

namespace frankie {

	typedef std::function<frankie::Response(frankie::Context)> ffunc;
	

	class Module{
		public:
			bool canHandle(const std::string protocol, const std::string path) { 
				for(auto &k : get) {
					if(k.first == path)
						return true;
				}
				return false;
			};

			frankie::Response handle(const Context ctx) {
				return get[ctx.path()](ctx);
			}

		protected:
			void Get(std::string path, ffunc f) {
				get[path] = f;
			}

		private:
			std::map<std::string, ffunc> get;
	};
};