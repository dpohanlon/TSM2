#include <iostream>
#include <vector>
#include <math.h>

#include "route.h"
#include "mt.h"

MersenneTwister mt;

Route::Route(int dumPlaces)
{
    places = dumPlaces;
    initweights(dumPlaces);
    fillweights();
    initRoute();
}

/* Initialize weights to square 2d vector (places x places) */    
/* Only happens once */

long Route::initweights(int dumPlaces)
{   
    int i = 0;
    vector<long> dumvec (dumPlaces);
    for (i=0; i<dumPlaces; ++i) {
        weights.push_back(dumvec);
    }
    return weights.size();
}

long Route::length(vector<long> routeIn)
{
    int i = 0;
    long dumRouteLength = 0;
    
    for (i = 0; i < routeIn.size() - 1; ++i) {
        dumRouteLength+=weights[routeIn[i]][routeIn[i+1]];
    }
    return dumRouteLength;
}

void Route::fillweights(void)
{
    int i = 0, j = 0;
    
    for (i = 0; i < places; ++i) {
        for (j = 0; j < places; ++j) {
            if (i == j) {
                weights[i][j] = 100 * places;
            }
            else{
                weights[i][j] = mt.random() * places;
            }
        }
    }
}

void Route::initRoute(void)
{
    int i = 0;
    int j = 0;
    int next = 0;
    unsigned long next_weight = 0; //Unsigned because dumLarge is unsigned
    vector<vector<long> > workingWeights;
    const unsigned long dumLarge = ~0;
    
    /* Make a working copy of weights that we can delete columns in */
    
    for (i = 0; i < places; ++i) {
        workingWeights.push_back(weights[i]);
    }
    
    /* Size of route[] should be places+1, start and end at 0 */
    
    for (i = 0; i < places+1; ++i) {
        
        // If the node is the first or last, let this be zero
        // (ie, start and end at 0)
        
        if (i == 0 || i == places) {
            route.push_back(0);
        }
        
        else {
            
            // Initialise the weight of the next node to a huge number
            
            next_weight = dumLarge;
            
            /* For each column (to), if the weight of the transition from the
             previous node in the route to it is less than the temporary next weight,
             make this the next weight and the next node */
            
            for (j = 0; j < places; ++j) {
                if (workingWeights[route[i-1]][j] < next_weight && j!=0) {
                    next_weight = workingWeights[route[i-1]][j];
                    next = j;
                }
            }
            
            // Add next node to route
            
            route.push_back(next);
            
            // Fill column with large so we don't go back
            
            for (j = 0; j < places; ++j) {
                workingWeights[j][next] = dumLarge;
            }
        }
    }
}

bool Route::moveTo(double E, double newE, int T)
{
    double P = 0;
    double k = 0.1; // Needs to be some function of places number (DOES NOTHING)

    P = exp((E - newE)/(double)T);

    if (newE < E){
        return true;
    }
    else if (P > mt.random()){
        return true;
    }
    else{
        return false;
    }
}

void Route::exchangeNodes(vector<long> &routeIn, int routeIndexA, int routeIndexB)
{
    long temp = 0;
    temp = routeIn[routeIndexA];
    routeIn[routeIndexA] = routeIn[routeIndexB];
    routeIn[routeIndexB] = temp;
}