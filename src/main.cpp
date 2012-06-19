#include <iostream>
#include <vector>
#include "route.h"
#include "route.h"
#include "mt.h"

using namespace std;

const int nodes = 100;

int main (int argc, const char * argv[])
{
    int i = 0;
    int T = 0;

    int ex1 = 0;
    int ex2 = 0;
    int oldLength = 0;
    int newLength = 0;
    int bestLength = 0;

    vector<long> dumRoute;
    vector<long> bestRoute;

    Route route(nodes);

    MersenneTwister mt;

    for (i=0; i<route.getRouteSize(); ++i) {
        dumRoute.push_back(route.getRoute(i));
    }
    bestLength = route.length(dumRoute);
    for (T = (nodes/10); T > 0; --T){
        for (i = 0; i < 100; ++i){
            ex1 = (int)(mt.random()*route.getPlaces());
            ex2 = (int)(mt.random()*route.getPlaces());
            if (ex1 != ex2){
                oldLength = route.length(dumRoute);
                route.exchangeNodes(dumRoute, ex1, ex2);
                newLength = route.length(dumRoute);
                if(!route.moveTo((double)oldLength, (double)newLength, T)){
                    route.exchangeNodes(dumRoute, ex1, ex2);
                }
                else{
                    if (bestLength > newLength){
                        bestLength = newLength;
                        bestRoute = dumRoute;
                    }
                }
            }
        }
    }

    cout << "-----------------------" << endl;
    cout << "Best Length: " << bestLength << endl;
    cout << "-----------------------" << endl;

    for (i = 0; i < route.getRouteSize(); ++i){
        cout << bestRoute[i] << endl;
    }

    cout << "-----------------------" << endl;
    
    return 0;
}
