/*
    Travelling Salesman Problem - Using Simulated Annealing

    Argument is the number of (random) city nodes to generate (> 9).

    main.cpp

    Copyright (C) 2012 Daniel O'Hanlon  

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

*/

#include <iostream>
#include <vector>
#include <ctype.h>

#include "route.h"
#include "mt.h"

using namespace std;


int main (int argc, const char * argv[])
{
    int i = 0;
    int T = 0;

    int ex1 = 0;
    int ex2 = 0;
    int oldLength = 0;
    int newLength = 0;
    int bestLength = 0;
    int nodes = 0;

    vector<long> dumRoute;
    vector<long> bestRoute;

    nodes = atoi(argv[1]); // Characters -> 0

    if (nodes < 9){
        cout << "First argument must be a number greater than 10!" << endl;
        return 1;
    }

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
