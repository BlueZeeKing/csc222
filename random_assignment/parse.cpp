#include <istream>
#include <vector>
#include <string>
using namespace std;

vector<vector<string>> parse(istream& stream) {
    vector<vector<string>> result;
    vector<string> inner_list;

    while (!stream.eof()) {
        string line;
        getline(stream, line);
        if (line.empty()) {
            continue;
        } else if (line == "===") {
            result.push_back(inner_list);
            inner_list.clear();
        } else {
            inner_list.push_back(line);
        }
    }

    result.push_back(inner_list);

    return result;
}
