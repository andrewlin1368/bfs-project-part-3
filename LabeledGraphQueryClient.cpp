#include "LabeledGraph.h"
#include <iostream>
using namespace std;

int main()
{
    LabeledGraph g("movies_short.txt");
    string name;
    while (true)
    {
        cout << "Enter a movie or a actor: (press enter to exit): ";
        getline(cin, name);
        if (name.size() == 0)
            break;
        g.display(name);
        cout << "\n";
    }
    return 0;
}