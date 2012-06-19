#ifndef _route_h
#define _route_h

using namespace std;

class Route
{
private:
    
    vector<vector<long> > weights;
    vector<long> route;
    long places;
    long routeLength;
	long initweights(int);
    void fillweights(void);
    void initRoute(void);

public:

    Route(int);

	long getPlaces(void) {return places;}
    
    long getWeights(int from, int to) {return weights[from][to];}
    
    long getRoute(int index) {return route[index];}
    
    long getRouteSize(void) {return route.size();}
    
    long getRouteLength(void) {return routeLength;}

    long length(vector<long> routeIn);

    bool moveTo(double, double, int);

    void exchangeNodes(vector<long> &, int, int);
};

#endif