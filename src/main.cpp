#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <boost/regex.hpp>
#include <string>

int main() {
	std::string line = "Subject: Re: GRAVITY";
	boost::regex pattern("^Subject: (Re: |Aw: )*(.*)$");
	boost::smatch matches;
	if (boost::regex_match(line, matches, pattern)) {
		std::cout << matches[2] << std::endl;
	}
    return 0;
}
