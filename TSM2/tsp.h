#ifndef TSM2_tsp_h
#define TSM2_tsp_h

using namespace std;

class Tsp
{
private:
    
    vector<vector<int> > weights;
    vector<int> route;
    int places;
    long routeLength;
    
public:
    
    Tsp(int dumPlaces);
    
    Tsp(int dumPlaces, bool FillRandom);
    
    int getPlaces(void) {return places;}
    
    int getWeights(int from, int to) {return weights[from][to];}
    
    int getRoute(int index) {return route[index];}
    
    long getRouteSize(void) {return route.size();}
    
    long getRouteLength(void) {return routeLength;}
    
    long initweights(int places);
    
    void routelen(void);
    
    void exchangeNodes(int routeIndexA, int routeIndexB);
    
    void fillweights(void);
    
    void initRoute(void);
};


#endif
