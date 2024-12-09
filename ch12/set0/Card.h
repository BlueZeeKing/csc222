#include <string>
using namespace std;

struct Card
{
    int suit, rank;

    Card();
    Card(int, int);
    string to_string() const;
    bool operator==(const Card&) const;
    bool operator>(const Card&) const;
    bool operator<=(const Card&) const;
};
