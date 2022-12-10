//Filename: dijkstra.cpp
//Author: Daniel Kruze
//Create Date: 11/20/21
//Compile Date: 11/23/21

#include <iostream> // cin, cout
#include <bits/stdc++.h> // everything else

using namespace std; // std namespace for library functions

/*
* the following map holds an int key, representing a point on a graph, and a vector value of ordered pairs representing other 
*   points and their distance from the key point.
*/
map<int, vector<pair<int, float>>> graph; // map representing the graph of all points
vector<int> path = {0}; // vector holding values for valid points in the final path
float pathDistance = 0.0; // float representing the final distance traveled

/*
* The following function populates the global map with points, representing the supplied graph
* Expected input: n/a
* Expected output: a map of 16 points, 1 through 16
*/
void insertGraph() { // accept no parameters
    // a single point is an integer, and a vector of pairs with other integers (other points) and floats (relative distances)
    graph.insert({1, {{2,0.32},{3,0.4}}});
    graph.insert({2, {{5,0.4}}});
    graph.insert({3, {{4,0.1},{6,0.2}}});
    graph.insert({4, {{5,0.08},{7,0.2}}});
    graph.insert({5, {{8,0.2}}});
    graph.insert({6, {{7,0.1},{9,0.28}}});
    graph.insert({7, {{8,0.05},{9,0.15}}});
    graph.insert({8, {{10,0.35}}});
    graph.insert({9, {{10,0.25}}});
    graph.insert({10, {{11,0.2},{12,0.3},{13,0.3}}});
    graph.insert({11, {{13,0.2}}});
    graph.insert({12, {{14,0.45}}});
    graph.insert({13, {{14,0.05},{15,0.28}}});
    graph.insert({14, {{16,0.3}}});
    graph.insert({15, {{16,0.2}}});
    graph.insert({16, {{}}});
}

/*
* The following function prints out the points on the map and their relative distances
* Expected input: global map
* Expected output: 15 detailed descriptions of points on the command line: the last point has no relative distances
*/
void printGraph() { // accept no parameters
    for (auto x : graph) { // for a key-value pair in the global map
        if (x.first == 16) { // if we are evaluating the last pair
            break; // stop printing
        }
        cout << "\nNode " << x.first << " has edges with:" << endl; // print the key of the point (its "name")
        for (auto y : x.second) { // for every pair in the vector value of a key-value pair
            cout << "Node " << y.first << " at length " << y.second << endl; // print the details of the given pair
        }
    }
    cout << endl; // spacer line
}

/*
* The following function uses dijkstra's algorithm to calculate the shortest distance from relative paths, point 1 to point 16
* It does this by evaluating distances of neighbors as a set, and then marking the shortest neighbor as a visited neighbor and not checking it again
* It then adds a visited point to a vector set, and adds its relative distance to a global total
* Expected input: global map
* Expected output: vector of visited points, float of total distance, messages to the command line detailing them
*/
void dijkstraGraph() { // accept no parameters
    int ynext; // integer for holding a point key
    for (auto x : graph) { // for every key-value pair in the global map
        if (x.first == 16) { // if we are evaluating the last point
            break; // stop evaluating
        }
        if (x.first != 1) { // if we are not evaluating the first point
            if (x.first != ynext) { // check that the key is not the same as the above key (which will be set as the "current" key)
                continue; // skip evaluating this point, we are not currently visiting that point
            }
        }
        float ycheck = 1.0; // let a float hold a relative distance value
        int ynode; // let an integer hold a point key
        for (auto y : x.second) { // for every pair in the vector value of a given map point
            if (y.second > ycheck) { // if the distance to the given point is bigger than the above float
                continue; // skip evaluating this pair, the distance is not the shortest
            }
            ycheck = y.second; // since the above check was not passed, this distance must be shortest--set it to the above float
            ynode = y.first; // let this point be set to the above int
        }
        ynext = ynode; // once the closest neighbor has been determined, set that neighbor as "current," to be evaluated next
        pathDistance += ycheck; // add the relative distance of this point to the global distance variable
        if (path.back() != ynode) { // if the new "current" point hasn't already been visited
            path.push_back(ynode); // add this point to the list of visited points
        }
    }
    cout << "Ideal path using Dijkstra's algorithm:\n" << endl; // notify the user that you will print the ideal path
    cout << "   1 -> "; // start with point 1, which will not be pushed into the vector of visited points by the above algorithm
    for (int i = 1; i <= path.size(); i++) { // for as many iterations as there are visited points
        if (i == path.size() - 1) { // if we are at the last point, or the second-to-last iteration
            cout << path[i] << endl; // print the last visited point
            break; // stop iterating
        }
        cout << path[i] << " -> "; // print the current member of the vector with a directional indicator
    }
    cout << "\nDistance traveled on this path:\n" << pathDistance << endl; // print out the total distance traveled
}

int main() { // driver function
    insertGraph(); // create the map of points
    printGraph(); // print its details out so the user can understand the map
    dijkstraGraph(); // calculate the shortest traversal from point 1 to point 16
    return 0; // end driver function
}