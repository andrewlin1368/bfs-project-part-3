#include <set>
#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include "LabeledGraph.h"
#include <fstream>

using namespace std;

LabeledGraph::LabeledGraph(string filename)
{
    ifstream myfile(filename);
    string temp;
    while (getline(myfile, temp))
    {
        string temp2 = temp.substr(0, temp.find(')') + 1);
        string temp3 = temp.substr(temp.find(')') + 2, temp.length() + 1);
        vector<string> container;
        string temp4;
        for (int i = 0; i < temp3.length(); i++)
        {
            if (temp3[i] != '/')
                temp4 += temp3[i];
            else
            {
                container.push_back(temp4);
                temp4.clear();
            }
        }
        container.push_back(temp4);
        add_vertex(temp2);
        for (auto x : container)
        {
            add_vertex(x);
            add_edge(temp2, x);
        }
    }
    myfile.close();
}

void LabeledGraph::add_vertex(string vlabel)
{
    auto itr = indexedLabels.find(vlabel);
    if (itr != indexedLabels.end())
        return;
    labels.push_back(vlabel);
    indexedLabels.insert(pair<string, int>(vlabel, V()));
    set<int> s;
    vertices.push_back(s);
}

void LabeledGraph::add_edge(string source, string target)
{
    if (!contains(source))
        add_vertex(source);
    if (!contains(target))
        add_vertex(target);
    vertices[indexedLabels[source]].insert(indexedLabels[target]);
    vertices[indexedLabels[target]].insert(indexedLabels[source]);
    nedges++;
}

bool LabeledGraph::contains(string vlabel) const
{
    return indexedLabels.find(vlabel) != indexedLabels.end();
}

set<int> LabeledGraph::neighbors(int v) const
{
    return vertices[v];
}

string LabeledGraph::label(int v) const
{
    return labels[v];
}

int LabeledGraph::index(string vlabel)
{
    return indexedLabels[vlabel];
}

ostream &operator<<(ostream &out, const LabeledGraph &g)
{
    for (int i = 0; i < g.vertices.size(); i++)
    {
        auto itr = g.indexedLabels.find(g.labels.at(i));
        cout << itr->first << "--> " << itr->second << "--> ";
        for (auto itr = g.vertices.at(i).begin(); itr != g.vertices.at(i).end(); itr++)
        {
            cout << g.labels.at(*itr) << " ";
        }
        cout << "\n";
    }
    return out;
}

void LabeledGraph::display(std::string name)
{
    auto itr = indexedLabels.find(name);
    if (itr == indexedLabels.end())
    {
        cout << "Does not exist\n";
        return;
    }
    for (auto it = vertices.at(itr->second).begin(); it != vertices.at(itr->second).end(); it++)
    {
        cout << labels.at(*it) << "    ";
    }
}