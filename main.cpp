#include <vector>
#include <string>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <iostream>
#include <iterator>
#include <numeric>
#include <iconv.h>

#include <boost/algorithm/string.hpp>

static std::vector<std::string> split(const std::string &input, const std::string &delim = " \t,;");

std::vector<std::string> split(const std::string &input, const std::string &delim) {
        std::vector<std::string> result;
        boost::split(result, input, boost::is_any_of(delim), boost::token_compress_on);
        result.erase(std::remove_if(result.begin(), result.end(), [](const std::string &token) {
                return token.empty();
        }), result.end());
        return result;
}

int main(void) {

    //char data_size[]="020000";
    char data_size[] = {'0', '1'};
    std::stol(data_size, nullptr, 16);

    std::vector<int> surveyFrameCount;
    std::string surveyFrameCountStr("3 2 1");
    std::vector<std::string> tokens = split(surveyFrameCountStr);
    //std::transform(tokens.begin(), tokens.end(), std::back_inserter(surveyFrameCount), [](const std::string &s) {return std::stoi(s);});
    std::transform(tokens.begin(), tokens.end(), std::back_inserter(surveyFrameCount), [](const std::string &s) {return std::stoi(s);});

    for(auto s:surveyFrameCount){
        std::cout << s << std::endl;
    }

    return 0;
}
