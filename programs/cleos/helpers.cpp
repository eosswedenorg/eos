
#include <cctype>
#include "helpers.hpp"

namespace eosio { namespace client { namespace helpers {

	std::string& url_encode(std::string& str) {

		char hex[17] = "0123456789ABCDEF";

		for(int i = 0; i < str.length(); i++) {

			char ch = str[i];

			if ( !(isalnum(ch) || ch == '-' || ch == '_' || ch == '.' || ch == '~') ) {
				std::string rep = "%";
				rep += hex[(ch & 0xF0) >> 4];
				rep += hex[ch & 0x0F];
				str.replace(i, 1, rep);
				i += 2;
			}
		}
		return str;
    }

}}}
