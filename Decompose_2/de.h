#pragma once

#include <string>
#include <iostream>
#include <cassert>
#include <vector>
#include <map>

using namespace std;

enum class QueryType;
struct Query;
istream& operator >> (istream& is, Query& q);
struct BusesForStopResponse;
ostream& operator << (ostream& os, const BusesForStopResponse& r);
struct StopsForBusResponse;
ostream& operator << (ostream& os, const StopsForBusResponse& r);
struct AllBusesResponse;
ostream& operator << (ostream& os, const AllBusesResponse& r);

class BusManager {
public:
    void AddBus(const string& bus, const vector<string>& stops);
    BusesForStopResponse GetBusesForStop(const string& stop) const;
    StopsForBusResponse GetStopsForBus(const string& bus) const;
    AllBusesResponse GetAllBuses() const;

private:
    map<string, vector<string>> buses_to_stops;
    map<string, vector<string>> stops_to_buses;
};
