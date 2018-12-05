#include <bits/stdc++.h>
#include "source.hpp"
using namespace std;

///misc
void trab4::iCronometro(void) {
    start = std::chrono::high_resolution_clock::now();
}

double trab4::pCronometro(void) {
    auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = finish - start;
    return elapsed.count();
}
///fim

///NODE
trab4::Node::Node(){}
trab4::Node::Node(int i, int x, int y) {
    this->index = i;
    this->x = x;
    this->y = y;
}
///fim

///GRAPH
trab4::Graph::Graph(){}
trab4::Graph::Graph(int v) {
    nodelist = vector<Node>(v);
    mAdj = vector<vector<double>> (v, vector<double>(v));
    lAdj = vector<vector< pair<double, int> > > (v);
}

void trab4::Graph::add(Node u) {
    nodelist[u.index] = u;
    
    for(int i = 0; i < nodelist.size() - 1; i++) {
        if(i != u.index)
            connect(i, u.index);
    }
}

void trab4::Graph::connect(int u, int v){
    double dist = sqrt(pow(nodelist[u].x - nodelist[v].x, 2) + pow(nodelist[u].y - nodelist[v].y, 2));
    mAdj[u][v] = dist;
    mAdj[v][u] = dist;
    lAdj[u].push_back({dist, v});
    lAdj[v].push_back({dist, u});
}
///fim


///backtracking
void trab4::backtracking::run(int u, vector<bool> visitado, int n, double dist) {
    visitado[u] = true;
    if(n == visitado.size()) {
        konst = min(konst, dist + g.mAdj[0][u]);
    } else {
        for(int i = 0; i < visitado.size(); i++) {
            if(!visitado[i] && i != u) {
                run(i, visitado, n+1, dist + g.mAdj[u][i]);
            }
        }
    }
}

void trab4::backtracking::startWorker(Graph &_g) {
    g = _g;
             //0, 1, 2, 3, 4
    /*g.mAdj = {{0, 2, 4, 2, 1},
              {2, 0, 5, 4, 3},
              {4, 5, 0, 6, 1},
              {2, 4, 6, 0, 2},
              {1, 3, 1, 2, 0}};*/
    vector<bool> v(g.mAdj.size(), false);
    v[0] = true;
    konst = INF;
    run(0, v, 1, 0.0);
    cout << "[Backtracking] " << konst << endl;        
}
///fim


///Guloso
void trab4::guloso::run(int u, vector<bool>& visitado, int n, double dist) {
    if(n == visitado.size()) {
        check = true;
        konst = dist + g.mAdj[0][u];
    }

    sort(g.lAdj[u].begin(), g.lAdj[u].end());
    for(int i = 0; i < g.lAdj[u].size(); i++) {
        if(i != u) {
            pair<int, int> v = g.lAdj[u][i];

            if(!visitado[v.second] && !check) {
                visitado[v.second] = true;
                run(v.second, visitado, n+1, dist + v.first);
            }
        }
    }
}

void trab4::guloso::startWorker(Graph& _g) {
    g = _g;
    check = false;
    vector<bool> v(g.mAdj.size(), false);
    v[0] = true;
    run(0, v, 1, 0.0);
    cout << "[Guloso] " << konst << endl;
}
///fim