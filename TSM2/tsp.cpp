#include <iostream>
#include <vector>
#include "mt.h"
#include "tsp.h"

MersenneTwister mt;

Tsp::Tsp(int dumPlaces)
{
    places = dumPlaces;
    initweights(dumPlaces);
}

Tsp::Tsp(int dumPlaces, bool FillRandom)
{
    places = dumPlaces;
    initweights(dumPlaces);
    
    if (FillRandom) {
        fillweights();
    }
}

/* Initialize weights to square 2d vector (places x places) */    

long Tsp::initweights(int places)
{   
    int i = 0;
    vector<int> dumvec (places);
    for (i=0; i<places; ++i) {
        weights.push_back(dumvec);
    }
    return weights.size();
}

/* Find total length of current route. Iterates to route.size()-1 as the path to the i+1 node
 is calculated by the ith iteration, and the final entry should describe a return to the start node, 0.
 For example route = {0, 1, 4, 3, 5, 8, 6, 7, 0} represents travelling from 0 to 1, from 1 to 4, etc. */

void Tsp::routelen(void)
{
    int i = 0;
    
    for (i=0; i<route.size()-1; ++i) {
        routeLength+=weights[route[i]][route[i+1]];
    }
}

long Tsp::routelen(vector<int> routeIn)
{
    int i = 0;
    long dumRouteLength = 0;
    
    for (i=0; i<routeIn.size()-1; ++i) {
        dumRouteLength+=weights[routeIn[i]][routeIn[i+1]];
    }
    return dumRouteLength;
}

void Tsp::exchangeNodes(int routeIndexA, int routeIndexB)
{
    int temp = 0;
    temp = route[routeIndexA];
    route[routeIndexA] = route[routeIndexB];
    route[routeIndexB] = temp;
    routelen();
}

void Tsp::exchangeNodes(vector<int> &routeIn, int routeIndexA, int routeIndexB)
{
    int temp = 0;
    temp = routeIn[routeIndexA];
    routeIn[routeIndexA] = routeIn[routeIndexB];
    routeIn[routeIndexB] = temp;
}

void Tsp::fillweights(void)
{
    int i = 0, j = 0;
    
    for (i = 0; i < places; ++i) {
        for (j = 0; j < places; ++j) {
            if (i == j) {
                weights[i][j] = 100*places;
            }
            else
                weights[i][j] = mt.random()*100;
        }
    }
}

void Tsp::initRoute(void)
{
    int i = 0, j = 0, next = 0;
    unsigned int next_weight = 0; //Unsigned because dumLarge is unsigned
    vector<vector<int> > workingWeights;
    const unsigned int dumLarge = ~0;
    
    /* Make a working copy of weights that we can delete columns in */
    
    for (i=0; i<places; ++i) {
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
                workingWeights[j][next]=dumLarge;
            }
        }
    }
    routelen(); // Calculate the length of this initial route
}

