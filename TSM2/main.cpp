#include <iostream>
#include <vector>
#include "mt.h"
#include "tsp.h"

using namespace std;

int main (int argc, const char * argv[])
{
    int i = 0, j = 0;
    const unsigned int d = ~0;
    
    Tsp tsp(10, true);
    
    for (i = 0; i < tsp.getPlaces(); ++i) {
        for (j = 0; j < tsp.getPlaces(); ++j) {
            cout << tsp.getWeights(i,j) << ",";
        }
        cout << endl;
    }
    
    cout << "\n";
    
    tsp.initRoute();
    
    cout << "\n";
    
    for (i = 0; i < tsp.getPlaces(); ++i) {
        for (j = 0; j < tsp.getPlaces(); ++j) {
            cout << tsp.getWeights(i,j) << ",";
        }
        cout << endl;
    }
    
    cout << "\n" << endl;
    
    for (i = 0; i < tsp.getPlaces()+1; ++i) {
        cout << tsp.getRoute(i) << ",";
    }
    
    cout << "\n";

    cout << tsp.getRouteSize()<< ", " << tsp.getRouteLength() << endl;
    
    cout << d << endl;
    
    return 0;
}

