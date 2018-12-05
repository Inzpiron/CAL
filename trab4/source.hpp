#ifndef __CAL_H_INCLUDED__
#define __CAL_H_INCLUDED__

using namespace std;
namespace trab4 {
    void iCronometro();
    double pCronometro();
    class Node{
    public:
        int index;
        int x;
        int y;
        Node();
        Node(int, int, int);
    };

    class Graph {
    public:
        vector< vector < pair<double, int> > > lAdj;
        vector< vector < double > > mAdj;
        vector< Node > nodelist;
        Graph();
        Graph(int v);
        void add(Node);
        void connect(int, int);
    };

    namespace {
        auto start = std::chrono::high_resolution_clock::now();
        const int INF = 0x3f3f3f3f;
    }

    namespace guloso {
        namespace {
            Graph g;
            double konst = INF;
            bool check;
        }

        void run(int, vector<bool>&, int, double);
        void startWorker(Graph&);
    }

    namespace backtracking {
        namespace {
            double konst = INF;
            Graph g;
        }

        void run(int, vector<bool>, int, double);
        void startWorker(Graph&);
    }
}

#endif