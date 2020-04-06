#ifndef _GRAPH_SEARCH_H_
#define _GRAPH_SEARCH_H_

#include <vector>
#include <queue>
#include <stack>
#include <map>
#include "directedgraph.h"

class TopSort
{
public:
    vector<Node *> Kahns(DirectedGraph &graph);
    vector<Node *> mDFS(DirectedGraph &graph);
    void mDFSUtil(Node *node, vector<Node *> &stack);
    vector<Node*> extract_keys(map<Node*, int> const &input_map)
    {
        vector<Node*> retval;
        for (auto const &element : input_map)
        {
            retval.push_back(element.first);
        }
        return retval;
    }
};

#endif