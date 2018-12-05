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
    //lAdj[u].push_back({dist, v});
    //lAdj[v].push_back({dist, u});
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

double trab4::backtracking::startWorker(Graph &_g) {
    g = _g;
    vector<bool> v(g.mAdj.size(), false);
    v[0] = true;
    konst = INF;
    run(0, v, 1, 0.0);
    return konst;
}
///fim


///Guloso
void trab4::guloso::run(int u, vector<bool>& visitado, int n, double dist) {
    if(n == visitado.size()) {
        check = true;
        konst = dist + g.mAdj[0][u];
    } else {
        for(int i = 0; i < g.lAdj[u].size(); i++) {
            pair<int, int> v = g.lAdj[u][i];
            if(v.second != u && !check && !visitado[v.second]) {
                visitado[v.second] = true;
                run(v.second, visitado, n+1, dist + g.mAdj[u][v.second]);
            }
        }
    }
}

double trab4::guloso::startWorker(Graph& _g) {
    g = _g;
    check = false;
    vector<bool> v(g.mAdj.size(), false);
    v[0] = true;
    run(0, v, 1, 0.0);

    return konst;
}
///fim


///aproximação
double trab4::aprox::prim(){
    vector<double> dist(g.mAdj.size(), INF);
    vector<bool> visitado(g.mAdj.size(), false);
    int curr = 0;
    double custo = 0;
    while (curr != -1) {
        visitado[curr]= true;

        for (int i = 0; i < g.mAdj.size(); i++) {
            if (curr != i && g.mAdj[curr][i] != 0) {
                dist[i] = min(dist[i], g.mAdj[curr][i]);
            }
        }
    
        int curr_aux = -1;
        int min_dist = INF;
        for (int i = 0; i < g.mAdj.size(); i++) {
            if (!visitado[i] && dist[i] < min_dist) {
                curr_aux = i;
                min_dist = dist[i];
            }
        }

        if(curr_aux == -1) {
            custo += g.mAdj[curr][0];
            curr = -1;
        } else {
            cout << curr << " " << curr_aux << " " <<  g.mAdj[curr][curr_aux] << endl;
            mst[curr].push_back(curr_aux);
            mst[curr_aux].push_back(curr);
            curr = curr_aux;
            custo += g.mAdj[curr][curr_aux];
        }
    }

    return custo;
}

double trab4::aprox::startWorker(Graph& _g) {
    g = _g;
    mst = vector<vector<int> >(g.mAdj.size());
    konst = prim();

    return konst;
}
///