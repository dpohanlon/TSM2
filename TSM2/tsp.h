#ifndef TSM2_tsp_h
#define TSM2_tsp_h

using namespace std;

class Tsp
{
private:
    
    vector<vector<long> > weights;
    vector<long> route;
    long places;
    long routeLength;
    
public:
    
    Tsp(int dumPlaces);
    
    Tsp(int dumPlaces, bool FillRandom);
    
    long getPlaces(void) {return places;}
    
    long getWeights(int from, int to) {return weights[from][to];}
    
    long getRoute(int index) {return route[index];}
    
    long getRouteSize(void) {return route.size();}
    
    long getRouteLength(void) {return routeLength;}
    
    long initweights(int places);
    
    void routelen(void);
    
    long routelen(vector<long> routeIn);
    
    void exchangeNodes(int routeIndexA, int routeIndexB);
    
    void exchangeNodes(vector<long> &routeIn, int routeIndexA, int routeIndexB);
    
    void fillweights(void);
    
    void initRoute(void);
};


#endif
