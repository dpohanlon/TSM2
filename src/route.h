/*
    route.h
    
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