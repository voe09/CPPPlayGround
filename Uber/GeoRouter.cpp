/*
Uber has list of pods and list of cities.
Fit all the cities within least possible number of pods.
Each pod should only contain adjoining cities.

Each pod for Uber have attributes
-Max Number of trips per weeks

Each City

tripsperweek
latitude, longitude
Example 1:-
List of Pods with thresholds
P1 {100}
P2{50}
P3 {50}
P4 {40}

List of cities {trip per week, lat, long)
C1 {20,0,0}
C2 {25,9,10}
C3 {40,4,5}
C4 {50, 15,16}
C5 {60, 15,17}

Output
P1 serve cities C5
P2 -- C1,C2
P3 --- C4
P4 --- C3
 */
