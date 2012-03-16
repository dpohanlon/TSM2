#include <iostream>
#include <vector>
#include "mt.h"
#include "tsp.h"

using namespace std;

int main (int argc, const char * argv[])
{
    int i = 0, j = 0;
    long dumLength = 0;
    
    Tsp tsp(10, true);
    
//    for (i = 0; i < tsp.getPlaces(); ++i) {
//        for (j = 0; j < tsp.getPlaces(); ++j) {
//            cout << tsp.getWeights(i,j) << ",";
//        }
//        cout << endl;
//    }
    
//    cout << "\n";
    
    tsp.initRoute();
    
//    cout << "\n" << endl;
    
//    for (i = 0; i < tsp.getPlaces()+1; ++i) {
//        cout << tsp.getRoute(i) << ",";
//    }
    
//    cout << "\n";

    cout << tsp.getRouteSize()<< ", " << tsp.getRouteLength() << endl;
    
    vector<long> dumRoute;
    
    for (i=0; i<tsp.getRouteSize(); ++i) {
        dumRoute.push_back(tsp.getRoute(i));
    }
    
    dumLength = tsp.routelen(dumRoute);
    
    for (i=1; i<tsp.getRouteSize()-1; ++i) {
        for (j=1; j<tsp.getRouteSize()-1; ++j) {
            if (i!=j) {
                tsp.exchangeNodes(dumRoute, i, j);
                if (tsp.routelen(dumRoute)<dumLength) {
                    tsp.exchangeNodes(i, j);
                    dumLength = tsp.routelen(dumRoute);
                }
                else {
                    dumRoute[i] = tsp.getRoute(i);
                    dumRoute[j] = tsp.getRoute(j);
                }
            }            
        }
    }
    
//    for (i = 0; i < tsp.getPlaces()+1; ++i) {
//        cout << dumRoute[i] << ",";
//    }
    
//    cout << "\n";
    
    cout << dumRoute.size()<< ", " << tsp.routelen(dumRoute) << endl;
    
    return 0;
}

