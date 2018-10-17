#ifndef __CAL_H_INCLUDED__
#define __CAL_H_INCLUDED__

using namespace std;
namespace trab2 {
    void iCronometro();
    double pCronometro();
    
    namespace vector {
        void add(int, string);
        int buscar(string);
    }

    namespace map {
        void add(int, string);
        int buscar(string);
    }

    namespace hash {
        void iniciar(int);
        void add(int, string);
        int buscar(string);
    }
}

#endif
