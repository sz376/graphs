#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "directedgraph.h"
#include "topsort.h"

using namespace std;

DirectedGraph createRandomDAGIter(int n)
{
    DirectedGraph graph;
    for (int i = 0; i < n; i++)
    {
        graph.addNode(to_string(i));
    }

    vector<Node *> graphNodes = graph.getAllNodes();
    srand(time(0));
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int v1 = rand() % 100;
            if(v1 < 40)
            {
                graph.addDirectedEdge(graphNodes[i], graphNodes[j]);
            }
        }
    }
    return graph;
}

void print(vector<Node *> allNodes)
{
    for (int i = 0; i < allNodes.size(); i++)
    {
        cout << (allNodes[i])->value << ":[";
        for (int j = 0; j < ((allNodes[i])->neighbors.size()); j++)
        {
            cout << ((allNodes[i])->neighbors[j])->value;
            if (j < ((allNodes[i])->neighbors.size()) - 1)
            {
                cout << ", ";
            }
        }
        cout << "]" << endl;
    }
    cout << endl;
}

void printTraversal(vector<Node *> allnodes)
{
    for (int i = 0; i < allnodes.size(); i++)
    {
        cout << (allnodes[i])->value;
        if (i < allnodes.size() - 1)
        {
            cout << "->";
        }
    }
    cout << endl;
}

int main()
{
    
    DirectedGraph gsmall = createRandomDAGIter(10);
    vector<Node *> allNodes1 = gsmall.getAllNodes();
    print(allNodes1);
    Node *first = new Node("2");
    Node *second = new Node("8");
    gsmall.removeDirectedEdge(first, second);
    allNodes1 = gsmall.getAllNodes();
    cout << "Removing edge between 2 and 8" << endl;
    print(allNodes1);
    TopSort search;
    vector<Node *> KahnsOutput;
    KahnsOutput = search.Kahns(gsmall);
    cout << "Kahns: " << endl;
    printTraversal(KahnsOutput);
    vector<Node*> mDFSOutput;
    mDFSOutput = search.mDFS(gsmall);
    cout << "mDFSOutput: ";
    printTraversal(mDFSOutput);
    /*
    Node *target = new Node("9");
    vector<Node *> DFSOutput;
    DFSOutput = search.DFSRec(gsmall, allNodes1[0], target);
    cout << "DFSRec from 0 to 9" << endl;
    printTraversal(DFSOutput);
    DFSOutput = search.DFSIter(gsmall, allNodes1[0], target);
    cout << "DFSIter from 0 to 9" << endl;
    printTraversal(DFSOutput);
    vector<Node *> BFTOutput;
    BFTOutput = search.BFTRec(gsmall);
    cout << "BFTRec" << endl;
    printTraversal(BFTOutput);

    BFTOutput = search.BFTIter(gsmall);
    cout << "BFTIter" << endl;
    printTraversal(BFTOutput);

    DirectedGraph tenk = createLinkedList(10000);
    BFTRecLinkedList(tenk);
    BFTIterLinkedList(tenk);
*/
    return 0;
}