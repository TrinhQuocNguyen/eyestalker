//  Copyright (C) 2016  Terence Brouns, t.s.n.brouns@gmail.com

//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.

//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.

//  You should have received a copy of the GNU General Public License
//  along with this program.  If not, see <http://www.gnu.org/licenses/>

#ifndef ARRAYS
#define ARRAYS

#include <vector>

const std::vector<double> parametersEye  = {0.005,  // Alpha average
                                             0.20,  // Alpha features
                                             0.10,  // Alpha certainty
                                             0.75,  // Alpha position
                                                4,  // Canny blur level
                                                5,  // Canny kernel size
                                            300.0,  // Canny threshold low
                                            600.0,  // Canny threshold high
                                               15,  // Curvature offset
                                             0.40,  // Edge length fraction
                                                3,  // Ellipse fit number maximum
                                              120,  // Ellipse fit error maximum
                                               12,  // Glint size
                                              320,  // Circumference max
                                               60,  // Circumference min
                                              0.4,  // Aspect ratio min
                                             1.20,  // Circumference offset
                                             1.15,  // Circumference change threshold
                                             1.15,  // Aspect ratio change threshold
                                               10,  // Displacement change threshold
                                             0.39,  // Score threshold
                                             0.15}; // Score difference threshold


const std::vector<double> parametersBead = {0.005,  // Alpha average
                                             0.75,  // Alpha miscellaneous
                                             0.10,  // Alpha certainty
                                             0.75,  // Alpha predicted
                                                4,  // Canny blur level
                                                3,  // Canny kernel size
                                            300.0,  // Canny threshold low
                                            600.0,  // Canny threshold high
                                               15,  // Curvature offset
                                             0.40,  // Edge length fraction
                                                3,  // Ellipse fit number maximum
                                               80,  // Ellipse fit error maximum
                                                0,  // Glint size
                                              130,  // Circumference max
                                               90,  // Circumference min
                                              0.8,  // Aspect ratio min
                                             1.10,  // Circumference offset
                                             1.10,  // Circumference change threshold
                                             1.10,  // Aspect ratio change threshold
                                               10,  // Displacement change threshold
                                             0.39,  // Score threshold
                                             0.15}; // Score difference threshold

const std::vector<double> arrayCircumferences = {60,65.918,71.837,77.755,83.673,89.592,95.51,101.43,107.35,113.27,119.18,125.1,131.02,136.94,142.86,148.78,154.69,160.61,166.53,172.45,178.37,184.29,190.2,196.12,202.04,207.96,213.88,219.8,225.71,231.63,237.55,243.47,249.39,255.31,261.22,267.14,273.06,278.98,284.9,290.82,296.73,302.65,308.57,314.49,320.41,326.33,332.24,338.16,344.08,350};
const std::vector<double> arrayAspectRatios   = {0.4,0.41224,0.42449,0.43673,0.44898,0.46122,0.47347,0.48571,0.49796,0.5102,0.52245,0.53469,0.54694,0.55918,0.57143,0.58367,0.59592,0.60816,0.62041,0.63265,0.6449,0.65714,0.66939,0.68163,0.69388,0.70612,0.71837,0.73061,0.74286,0.7551,0.76735,0.77959,0.79184,0.80408,0.81633,0.82857,0.84082,0.85306,0.86531,0.87755,0.8898,0.90204,0.91429,0.92653,0.93878,0.95102,0.96327,0.97551,0.98776,1};
const std::vector<double> arrayCurvatureMax   = {111.8,108.2,104.5,100.5,96.5,92.5,88.4,84.4,80.6,76.9,73.5,70.3,67.4,64.7,62.3,60.1,58.2,56.5,55.1,53.8,52.7,51.7,50.9,50.2,49.6,49  ,48.6,48.2,47.8,47.5,47.2,47  ,46.8,46.6,46.4,46.3,46.1,46  ,45.9,45.7,45.6,45.5,45.3,45.2,45  ,44.9,44.7,44.5,44.4,44.2,
                                                 110.2,106.6,102.8,98.8 ,94.8,90.7,86.7,82.8,79  ,75.5,72.1,69  ,66.2,63.6,61.3,59.2,57.4,55.8,54.4,53.2,52.2,51.3,50.5,49.8,49.2,48.7,48.3,47.9,47.6,47.3,47.1,46.9,46.7,46.5,46.3,46.2,46  ,45.9,45.8,45.6,45.5,45.3,45.2,45.1,44.9,44.7,44.6,44.4,44.2,44  ,
                                                 108.5,104.8,100.9,97   ,92.9,88.9,84.9,81.1,77.4,73.9,70.6,67.6,64.9,62.4,60.2,58.3,56.6,55.1,53.7,52.6,51.6,50.8,50  ,49.4,48.9,48.4,48  ,47.6,47.3,47.1,46.8,46.6,46.5,46.3,46.1,46  ,45.8,45.7,45.6,45.5,45.3,45.2,45  ,44.9,44.7,44.6,44.4,44.2,44  ,43.8,
                                                 106.6,102.8,99   ,95   ,91  ,87  ,83  ,79.3,75.6,72.2,69.1,66.2,63.6,61.2,59.1,57.2,55.6,54.2,52.9,51.9,50.9,50.1,49.5,48.9,48.4,47.9,47.6,47.2,47  ,46.7,46.5,46.3,46.2,46  ,45.9,45.7,45.6,45.5,45.3,45.2,45.1,44.9,44.8,44.6,44.5,44.3,44.1,43.9,43.7,43.5,
                                                 104.6,100.8,96.9 ,92.9 ,88.9,84.9,81  ,77.3,73.8,70.5,67.4,64.6,62.1,59.9,57.8,56.1,54.5,53.2,52  ,51  ,50.1,49.4,48.8,48.2,47.8,47.4,47  ,46.7,46.5,46.3,46.1,45.9,45.7,45.6,45.5,45.3,45.2,45.1,45  ,44.9,44.7,44.6,44.4,44.3,44.1,43.9,43.7,43.5,43.3,43.1,
                                                 102.5,98.7 ,94.7 ,90.7 ,86.7,82.8,79  ,75.3,71.9,68.7,65.7,63  ,60.6,58.4,56.5,54.8,53.4,52.1,51  ,50  ,49.2,48.6,48  ,47.5,47  ,46.7,46.4,46.1,45.9,45.7,45.5,45.3,45.2,45.1,45  ,44.8,44.7,44.6,44.5,44.4,44.3,44.1,44  ,43.8,43.6,43.5,43.3,43  ,42.8,42.6,
                                                 100.4,96.6 ,92.6 ,88.6 ,84.6,80.7,76.9,73.3,69.9,66.8,64  ,61.4,59  ,57  ,55.1,53.5,52.1,50.9,49.9,49  ,48.2,47.6,47.1,46.6,46.2,45.9,45.6,45.3,45.1,45  ,44.8,44.7,44.5,44.4,44.3,44.2,44.1,44  ,43.9,43.8,43.6,43.5,43.4,43.2,43  ,42.8,42.6,42.4,42.2,42  ,
                                                 98.4 ,94.5 ,90.5 ,86.5 ,82.5,78.6,74.9,71.4,68.1,65  ,62.2,59.7,57.5,55.5,53.7,52.2,50.9,49.7,48.8,47.9,47.2,46.6,46.1,45.7,45.3,45  ,44.7,44.5,44.3,44.1,44  ,43.9,43.8,43.7,43.6,43.5,43.4,43.2,43.1,43  ,42.9,42.8,42.6,42.5,42.3,42.1,41.9,41.7,41.4,41.2,
                                                 96.5 ,92.5 ,88.5 ,84.5 ,80.5,76.7,73  ,69.5,66.3,63.3,60.6,58.2,56  ,54.1,52.4,51  ,49.7,48.6,47.7,46.9,46.2,45.6,45.1,44.7,44.3,44  ,43.8,43.6,43.4,43.2,43.1,43  ,42.9,42.8,42.7,42.6,42.5,42.4,42.3,42.2,42  ,41.9,41.7,41.6,41.4,41.2,41  ,40.8,40.6,40.3,
                                                 94.7 ,90.7 ,86.6 ,82.6 ,78.7,74.9,71.2,67.8,64.7,61.8,59.1,56.8,54.7,52.8,51.2,49.8,48.6,47.5,46.6,45.9,45.2,44.6,44.2,43.8,43.4,43.1,42.9,42.7,42.5,42.3,42.2,42.1,42  ,41.9,41.8,41.7,41.5,41.4,41.3,41.2,41.1,40.9,40.7,40.6,40.4,40.2,40  ,39.8,39.5,39.3,
                                                 93   ,89   ,84.9 ,80.9 ,77  ,73.2,69.6,66.3,63.2,60.4,57.8,55.5,53.5,51.7,50.2,48.8,47.6,46.6,45.7,45  ,44.3,43.8,43.3,42.9,42.6,42.3,42.1,41.9,41.7,41.5,41.3,41.2,41.1,41  ,40.8,40.7,40.6,40.5,40.3,40.2,40  ,39.9,39.7,39.5,39.3,39.1,38.9,38.7,38.4,38.2,
                                                 91.4 ,87.4 ,83.3 ,79.3 ,75.4,71.7,68.2,64.9,61.9,59.1,56.7,54.4,52.5,50.8,49.2,47.9,46.8,45.8,45  ,44.2,43.6,43.1,42.6,42.2,41.9,41.6,41.3,41.1,40.9,40.7,40.6,40.4,40.3,40.1,40  ,39.8,39.7,39.5,39.4,39.2,39  ,38.9,38.7,38.5,38.2,38  ,37.8,37.5,37.3,37.1,
                                                 89.9 ,85.8 ,81.8 ,77.8 ,73.9,70.3,66.8,63.6,60.7,58  ,55.6,53.5,51.6,49.9,48.5,47.2,46.1,45.2,44.3,43.6,43  ,42.5,42  ,41.6,41.3,41  ,40.7,40.5,40.3,40.1,39.9,39.7,39.6,39.4,39.2,39.1,38.9,38.7,38.5,38.3,38.1,37.9,37.7,37.4,37.2,37  ,36.7,36.5,36.2,36  ,
                                                 88.5 ,84.4 ,80.3 ,76.4 ,72.6,69  ,65.6,62.5,59.6,57  ,54.7,52.7,50.8,49.2,47.8,46.6,45.5,44.6,43.8,43.1,42.5,42  ,41.6,41.2,40.8,40.5,40.3,40  ,39.8,39.6,39.4,39.2,39  ,38.8,38.6,38.4,38.2,38  ,37.8,37.5,37.3,37.1,36.8,36.5,36.3,36  ,35.7,35.5,35.2,35  ,
                                                 87.1 ,83   ,79   ,75.1 ,71.3,67.8,64.5,61.4,58.7,56.2,53.9,51.9,50.2,48.6,47.3,46.1,45.1,44.2,43.4,42.8,42.2,41.7,41.2,40.8,40.5,40.2,39.9,39.6,39.4,39.2,38.9,38.7,38.5,38.3,38.1,37.8,37.6,37.4,37.1,36.8,36.6,36.3,36  ,35.8,35.5,35.2,34.9,34.6,34.3,34.1,
                                                 85.8 ,81.7 ,77.7 ,73.8 ,70.1,66.7,63.4,60.5,57.8,55.4,53.2,51.3,49.6,48.1,46.8,45.7,44.7,43.9,43.1,42.5,41.9,41.4,41  ,40.6,40.2,39.9,39.6,39.3,39.1,38.8,38.6,38.3,38.1,37.9,37.6,37.4,37.1,36.8,36.6,36.3,36  ,35.7,35.4,35.1,34.8,34.5,34.2,33.9,33.6,33.3,
                                                 84.4 ,80.4 ,76.4 ,72.6 ,69  ,65.6,62.5,59.6,57  ,54.6,52.6,50.7,49.1,47.7,46.4,45.3,44.4,43.6,42.8,42.2,41.7,41.2,40.7,40.4,40  ,39.7,39.4,39.1,38.8,38.6,38.3,38  ,37.8,37.5,37.2,37  ,36.7,36.4,36.1,35.8,35.5,35.2,34.8,34.5,34.2,33.9,33.6,33.3,33  ,32.7,
                                                 83.1 ,79.1 ,75.2 ,71.4 ,67.9,64.6,61.5,58.7,56.2,54  ,52  ,50.2,48.6,47.3,46.1,45  ,44.1,43.3,42.6,42  ,41.5,41  ,40.6,40.2,39.8,39.5,39.2,38.9,38.6,38.3,38.1,37.8,37.5,37.2,36.9,36.6,36.3,36  ,35.7,35.4,35  ,34.7,34.4,34.1,33.7,33.4,33.1,32.8,32.5,32.2,
                                                 81.9 ,77.9 ,74   ,70.3 ,66.8,63.6,60.6,58  ,55.5,53.4,51.4,49.7,48.2,46.9,45.8,44.8,43.9,43.1,42.4,41.8,41.3,40.9,40.4,40  ,39.7,39.3,39  ,38.7,38.4,38.1,37.8,37.5,37.2,36.9,36.6,36.3,36  ,35.7,35.3,35  ,34.7,34.3,34  ,33.7,33.3,33  ,32.7,32.4,32.1,31.8,
                                                 80.6 ,76.7 ,72.8 ,69.2 ,65.8,62.7,59.8,57.2,54.9,52.8,50.9,49.3,47.8,46.6,45.5,44.5,43.7,42.9,42.3,41.7,41.2,40.7,40.3,39.9,39.6,39.2,38.9,38.6,38.3,38  ,37.6,37.3,37  ,36.7,36.4,36  ,35.7,35.4,35  ,34.7,34.3,34  ,33.6,33.3,33  ,32.7,32.4,32.1,31.7,31.4,
                                                 79.4 ,75.5 ,71.7 ,68.2 ,64.9,61.8,59  ,56.5,54.2,52.2,50.4,48.9,47.5,46.3,45.2,44.3,43.5,42.8,42.1,41.6,41.1,40.6,40.2,39.8,39.4,39.1,38.8,38.4,38.1,37.8,37.5,37.1,36.8,36.5,36.1,35.8,35.4,35.1,34.7,34.4,34  ,33.7,33.4,33  ,32.7,32.4,32.1,31.8,31.4,31.1,
                                                 78.2 ,74.3 ,70.6 ,67.1 ,63.9,60.9,58.2,55.8,53.6,51.7,50  ,48.5,47.2,46  ,45  ,44.1,43.3,42.6,42  ,41.4,41  ,40.5,40.1,39.7,39.3,39  ,38.6,38.3,37.9,37.6,37.3,36.9,36.6,36.2,35.9,35.5,35.2,34.8,34.5,34.1,33.8,33.4,33.1,32.8,32.5,32.2,31.8,31.5,31.2,30.8,
                                                 77   ,73.2 ,69.5 ,66.1 ,63  ,60.1,57.5,55.2,53.1,51.2,49.6,48.1,46.9,45.7,44.8,43.9,43.1,42.5,41.9,41.3,40.8,40.4,40  ,39.6,39.2,38.8,38.5,38.1,37.8,37.4,37.1,36.7,36.4,36  ,35.6,35.3,34.9,34.6,34.2,33.9,33.5,33.2,32.9,32.6,32.3,31.9,31.6,31.3,30.9,30.5,
                                                 75.8 ,72.1 ,68.5 ,65.2 ,62.1,59.3,56.8,54.6,52.5,50.7,49.2,47.8,46.6,45.5,44.5,43.7,43  ,42.3,41.7,41.2,40.7,40.3,39.9,39.5,39.1,38.7,38.3,38  ,37.6,37.2,36.9,36.5,36.1,35.8,35.4,35  ,34.7,34.3,34  ,33.6,33.3,33  ,32.7,32.4,32.1,31.8,31.4,31.1,30.7,30.1,
                                                 74.7 ,71   ,67.5 ,64.3 ,61.3,58.6,56.2,54  ,52  ,50.3,48.8,47.5,46.3,45.2,44.3,43.5,42.8,42.2,41.6,41.1,40.6,40.1,39.7,39.3,38.9,38.5,38.2,37.8,37.4,37  ,36.7,36.3,35.9,35.5,35.2,34.8,34.5,34.1,33.8,33.4,33.1,32.8,32.5,32.2,31.9,31.6,31.2,30.8,30.4,29.8,
                                                 73.5 ,69.9 ,66.5 ,63.4 ,60.5,57.9,55.5,53.4,51.5,49.9,48.4,47.1,46  ,45  ,44.1,43.4,42.7,42  ,41.5,41  ,40.5,40  ,39.6,39.2,38.8,38.4,38  ,37.6,37.2,36.8,36.5,36.1,35.7,35.3,35  ,34.6,34.2,33.9,33.6,33.3,32.9,32.6,32.3,32.1,31.7,31.4,31  ,30.6,30  ,29.4,
                                                 72.4 ,68.9 ,65.5 ,62.5 ,59.7,57.2,54.9,52.9,51.1,49.5,48.1,46.8,45.8,44.8,43.9,43.2,42.5,41.9,41.3,40.8,40.3,39.9,39.4,39  ,38.6,38.2,37.8,37.4,37  ,36.6,36.2,35.9,35.5,35.1,34.7,34.4,34  ,33.7,33.4,33.1,32.8,32.5,32.2,31.9,31.6,31.2,30.8,30.3,29.7,28.9,
                                                 71.3 ,67.8 ,64.6 ,61.6 ,58.9,56.5,54.3,52.3,50.6,49.1,47.7,46.6,45.5,44.6,43.7,43  ,42.3,41.7,41.2,40.7,40.2,39.7,39.3,38.8,38.4,38  ,37.6,37.2,36.8,36.4,36  ,35.6,35.3,34.9,34.5,34.2,33.9,33.5,33.2,32.9,32.7,32.4,32.1,31.8,31.4,31  ,30.6,30  ,29.2,28.3,
                                                 70.3 ,66.9 ,63.7 ,60.8 ,58.2,55.8,53.7,51.9,50.2,48.7,47.4,46.3,45.3,44.3,43.5,42.8,42.2,41.6,41  ,40.5,40  ,39.5,39.1,38.7,38.2,37.8,37.4,37  ,36.6,36.2,35.8,35.4,35.1,34.7,34.4,34  ,33.7,33.4,33.1,32.8,32.5,32.3,32  ,31.6,31.3,30.8,30.3,29.6,28.7,27.6,
                                                 69.2 ,65.9 ,62.8 ,60   ,57.5,55.2,53.2,51.4,49.8,48.3,47.1,46  ,45  ,44.1,43.3,42.6,42  ,41.4,40.8,40.3,39.8,39.4,38.9,38.5,38  ,37.6,37.2,36.8,36.4,36  ,35.6,35.2,34.9,34.5,34.2,33.9,33.6,33.3,33  ,32.7,32.4,32.1,31.8,31.5,31.1,30.6,29.9,29.1,28.1,26.9,
                                                 68.2 ,65   ,62   ,59.3 ,56.8,54.6,52.7,50.9,49.4,48  ,46.8,45.7,44.8,43.9,43.1,42.4,41.8,41.2,40.7,40.1,39.6,39.2,38.7,38.2,37.8,37.4,37  ,36.6,36.2,35.8,35.4,35  ,34.7,34.3,34  ,33.7,33.4,33.2,32.9,32.6,32.3,32  ,31.7,31.3,30.8,30.2,29.5,28.5,27.4,26.1,
                                                 67.2 ,64   ,61.2 ,58.5 ,56.2,54  ,52.1,50.5,49  ,47.6,46.5,45.4,44.5,43.7,42.9,42.2,41.6,41  ,40.5,39.9,39.4,38.9,38.5,38  ,37.6,37.2,36.7,36.3,35.9,35.6,35.2,34.8,34.5,34.2,33.9,33.6,33.3,33.1,32.8,32.5,32.2,31.9,31.6,31.1,30.5,29.8,28.9,27.8,26.6,25.4,
                                                 66.2 ,63.2 ,60.4 ,57.8 ,55.5,53.5,51.6,50  ,48.6,47.3,46.2,45.2,44.3,43.4,42.7,42  ,41.4,40.8,40.2,39.7,39.2,38.7,38.3,37.8,37.4,36.9,36.5,36.1,35.7,35.4,35  ,34.7,34.4,34.1,33.8,33.5,33.2,33  ,32.7,32.4,32.1,31.8,31.4,30.8,30.2,29.3,28.3,27.1,25.9,24.6,
                                                 65.3 ,62.3 ,59.6 ,57.1 ,54.9,52.9,51.2,49.6,48.2,47  ,45.9,44.9,44  ,43.2,42.5,41.8,41.2,40.6,40  ,39.5,39  ,38.5,38  ,37.6,37.1,36.7,36.3,35.9,35.6,35.2,34.9,34.5,34.2,33.9,33.7,33.4,33.1,32.9,32.6,32.3,32  ,31.6,31.1,30.5,29.7,28.7,27.6,26.4,25.1,24  ,
                                                 64.4 ,61.5 ,58.8 ,56.4 ,54.3,52.4,50.7,49.2,47.8,46.6,45.6,44.6,43.7,42.9,42.2,41.6,40.9,40.3,39.8,39.3,38.8,38.3,37.8,37.4,36.9,36.5,36.1,35.7,35.4,35  ,34.7,34.4,34.1,33.8,33.6,33.3,33.1,32.8,32.5,32.2,31.9,31.4,30.8,30.1,29.2,28.1,26.9,25.6,24.4,23.4,
                                                 63.5 ,60.7 ,58.1 ,55.8 ,53.7,51.9,50.2,48.8,47.5,46.3,45.3,44.3,43.5,42.7,42  ,41.3,40.7,40.1,39.5,39  ,38.5,38  ,37.6,37.1,36.7,36.3,35.9,35.6,35.2,34.9,34.6,34.3,34  ,33.8,33.5,33.3,33  ,32.8,32.5,32.1,31.7,31.2,30.5,29.6,28.6,27.4,26.1,24.9,23.8,23  ,
                                                 62.6 ,59.9 ,57.4 ,55.1 ,53.2,51.4,49.8,48.4,47.1,46  ,44.9,44  ,43.2,42.4,41.7,41  ,40.4,39.8,39.3,38.8,38.3,37.8,37.4,36.9,36.5,36.1,35.8,35.4,35.1,34.8,34.5,34.2,33.9,33.7,33.5,33.2,33  ,32.7,32.4,32  ,31.5,30.8,30  ,29  ,27.9,26.6,25.4,24.3,23.3,22.6,
                                                 61.7 ,59.1 ,56.7 ,54.5 ,52.6,50.9,49.3,47.9,46.7,45.6,44.6,43.7,42.9,42.1,41.4,40.8,40.2,39.6,39  ,38.5,38  ,37.6,37.1,36.7,36.3,36  ,35.6,35.3,35  ,34.7,34.4,34.1,33.9,33.6,33.4,33.2,32.9,32.6,32.2,31.8,31.2,30.4,29.5,28.4,27.1,25.9,24.7,23.7,23  ,22.4,
                                                 60.9 ,58.3 ,56   ,53.9 ,52  ,50.4,48.9,47.5,46.3,45.3,44.3,43.4,42.6,41.8,41.2,40.5,39.9,39.3,38.8,38.3,37.8,37.4,36.9,36.5,36.2,35.8,35.5,35.2,34.9,34.6,34.3,34.1,33.8,33.6,33.4,33.1,32.8,32.5,32.1,31.5,30.8,29.9,28.8,27.6,26.4,25.2,24.2,23.3,22.7,22.2,
                                                 60.1 ,57.6 ,55.3 ,53.3 ,51.5,49.9,48.4,47.1,46  ,44.9,44  ,43.1,42.3,41.6,40.9,40.2,39.6,39.1,38.6,38.1,37.6,37.2,36.7,36.4,36  ,35.7,35.3,35.1,34.8,34.5,34.3,34  ,33.8,33.6,33.3,33.1,32.7,32.3,31.8,31.2,30.3,29.3,28.1,26.9,25.7,24.6,23.7,23  ,22.5,22.1,
                                                 59.3 ,56.9 ,54.7 ,52.7 ,51  ,49.4,48  ,46.7,45.6,44.6,43.6,42.8,42  ,41.3,40.6,40  ,39.4,38.8,38.3,37.8,37.4,37  ,36.6,36.2,35.9,35.6,35.3,35  ,34.7,34.5,34.2,34  ,33.8,33.5,33.3,33  ,32.6,32.1,31.5,30.7,29.8,28.6,27.4,26.2,25  ,24.1,23.3,22.8,22.3,22  ,
                                                 58.5 ,56.2 ,54.1 ,52.2 ,50.4,48.9,47.6,46.3,45.2,44.2,43.3,42.4,41.7,41  ,40.3,39.7,39.1,38.6,38.1,37.6,37.2,36.8,36.4,36.1,35.8,35.5,35.2,34.9,34.7,34.4,34.2,34  ,33.8,33.5,33.2,32.9,32.4,31.9,31.1,30.2,29.1,27.9,26.7,25.5,24.5,23.7,23.1,22.6,22.3,22  ,
                                                 57.8 ,55.5 ,53.4 ,51.6 ,49.9,48.4,47.1,45.9,44.8,43.8,42.9,42.1,41.4,40.7,40  ,39.4,38.9,38.4,37.9,37.4,37  ,36.7,36.3,36  ,35.7,35.4,35.1,34.9,34.6,34.4,34.2,34  ,33.7,33.5,33.1,32.7,32.2,31.5,30.7,29.6,28.4,27.2,26  ,24.9,24.1,23.4,22.9,22.5,22.3,22.1,
                                                 57   ,54.8 ,52.8 ,51   ,49.4,48  ,46.7,45.5,44.4,43.5,42.6,41.8,41.1,40.4,39.8,39.2,38.7,38.2,37.7,37.3,36.9,36.5,36.2,35.9,35.6,35.3,35.1,34.8,34.6,34.4,34.2,34  ,33.7,33.4,33  ,32.5,31.9,31.1,30.1,29  ,27.7,26.5,25.4,24.5,23.7,23.2,22.8,22.5,22.3,22.1,
                                                 56.3 ,54.1 ,52.2 ,50.4 ,48.9,47.5,46.2,45.1,44.1,43.1,42.3,41.5,40.8,40.1,39.5,39  ,38.4,38  ,37.5,37.1,36.8,36.4,36.1,35.8,35.5,35.3,35.1,34.8,34.6,34.4,34.2,33.9,33.6,33.3,32.8,32.3,31.5,30.6,29.5,28.2,27  ,25.9,24.9,24.1,23.5,23.1,22.7,22.5,22.3,22.2,
                                                 55.5 ,53.5 ,51.6 ,49.9 ,48.4,47  ,45.8,44.7,43.7,42.8,41.9,41.2,40.5,39.8,39.3,38.7,38.2,37.8,37.4,37  ,36.6,36.3,36  ,35.8,35.5,35.3,35  ,34.8,34.6,34.4,34.2,33.9,33.6,33.1,32.6,31.9,31  ,30  ,28.8,27.5,26.3,25.3,24.5,23.8,23.4,23  ,22.7,22.5,22.4,22.3,
                                                 54.8 ,52.8 ,51   ,49.3 ,47.9,46.5,45.3,44.3,43.3,42.4,41.6,40.9,40.2,39.6,39  ,38.5,38.1,37.6,37.2,36.9,36.6,36.3,36  ,35.7,35.5,35.3,35  ,34.8,34.6,34.4,34.1,33.8,33.4,32.9,32.3,31.5,30.4,29.3,28  ,26.8,25.8,24.9,24.2,23.6,23.3,23  ,22.8,22.6,22.5,22.4,
                                                 54.1 ,52.1 ,50.4 ,48.8 ,47.4,46.1,44.9,43.9,42.9,42.1,41.3,40.6,40  ,39.4,38.8,38.4,37.9,37.5,37.1,36.8,36.5,36.2,36  ,35.7,35.5,35.3,35.1,34.8,34.6,34.4,34.1,33.7,33.3,32.7,31.9,30.9,29.8,28.6,27.3,26.2,25.3,24.5,24  ,23.5,23.2,23  ,22.8,22.7,22.6,22.5,
                                                 53.4 ,51.5 ,49.8 ,48.2 ,46.9,45.6,44.5,43.5,42.6,41.7,41  ,40.3,39.7,39.2,38.7,38.2,37.8,37.4,37.1,36.7,36.4,36.2,35.9,35.7,35.5,35.3,35.1,34.9,34.6,34.3,34  ,33.6,33  ,32.3,31.4,30.3,29.1,27.9,26.7,25.7,24.9,24.3,23.8,23.5,23.2,23  ,22.9,22.8,22.7,22.6,
                                                 52.7 ,50.9 ,49.2 ,47.7 ,46.4,45.2,44.1,43.1,42.2,41.4,40.7,40.1,39.5,39  ,38.5,38.1,37.7,37.3,37  ,36.7,36.4,36.2,35.9,35.7,35.5,35.3,35.1,34.9,34.6,34.3,33.9,33.4,32.7,31.8,30.8,29.6,28.4,27.2,26.1,25.3,24.6,24.1,23.7,23.5,23.3,23.1,23  ,22.9,22.8,22.7};
const std::vector<double> arrayCurvatureMin   = {-0.3,-1.4,-3  ,-4.9,-6.9,-8.7,-10 ,-10.8,-11.2,-11.4,-11.4,-11.3,-11.2,-11.2,-11.1,-11  ,-11  ,-11  ,-11  ,-11.1,-11.2,-11.3,-11.5,-11.6,-11.7,-11.7,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,
                                                 0.1 ,-0.8,-2.1,-3.8,-5.8,-7.8,-9.3,-10.4,-11  ,-11.3,-11.4,-11.3,-11.3,-11.2,-11.1,-11.1,-11  ,-11  ,-11  ,-11.1,-11.2,-11.3,-11.4,-11.6,-11.6,-11.7,-11.7,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,
                                                 0.3 ,-0.3,-1.3,-2.8,-4.7,-6.7,-8.5,-9.9 ,-10.7,-11.2,-11.3,-11.4,-11.3,-11.2,-11.2,-11.1,-11  ,-11  ,-11  ,-11  ,-11.1,-11.2,-11.4,-11.5,-11.6,-11.7,-11.7,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,
                                                 0.5 ,0   ,-0.7,-1.9,-3.6,-5.7,-7.6,-9.2 ,-10.3,-11  ,-11.3,-11.4,-11.3,-11.3,-11.2,-11.1,-11.1,-11  ,-11  ,-11  ,-11.1,-11.2,-11.3,-11.5,-11.6,-11.7,-11.7,-11.7,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,
                                                 0.6 ,0.3 ,-0.3,-1.2,-2.7,-4.5,-6.6,-8.4 ,-9.8 ,-10.7,-11.1,-11.3,-11.4,-11.3,-11.2,-11.1,-11.1,-11  ,-11  ,-11  ,-11  ,-11.1,-11.3,-11.4,-11.5,-11.6,-11.7,-11.7,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,
                                                 0.6 ,0.4 ,0.1 ,-0.6,-1.8,-3.5,-5.5,-7.4 ,-9.1 ,-10.2,-10.9,-11.2,-11.3,-11.3,-11.3,-11.2,-11.1,-11  ,-11  ,-11  ,-11  ,-11.1,-11.2,-11.3,-11.5,-11.6,-11.7,-11.7,-11.7,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,
                                                 0.6 ,0.5 ,0.3 ,-0.2,-1.1,-2.5,-4.3,-6.4 ,-8.2 ,-9.7 ,-10.6,-11.1,-11.3,-11.3,-11.3,-11.2,-11.1,-11.1,-11  ,-11  ,-11  ,-11  ,-11.1,-11.3,-11.4,-11.6,-11.7,-11.7,-11.7,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,
                                                 0.6 ,0.5 ,0.4 ,0.1 ,-0.5,-1.7,-3.3,-5.3 ,-7.3 ,-8.9 ,-10.1,-10.8,-11.2,-11.3,-11.3,-11.3,-11.2,-11.1,-11  ,-11  ,-11  ,-11  ,-11.1,-11.2,-11.4,-11.5,-11.6,-11.7,-11.7,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,
                                                 0.6 ,0.5 ,0.4 ,0.3 ,-0.1,-1  ,-2.3,-4.2 ,-6.2 ,-8.1 ,-9.5 ,-10.5,-11  ,-11.3,-11.3,-11.3,-11.2,-11.1,-11  ,-11  ,-11  ,-11  ,-11.1,-11.2,-11.3,-11.5,-11.6,-11.7,-11.7,-11.7,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,
                                                 0.6 ,0.4 ,0.4 ,0.3 ,0.1 ,-0.5,-1.5,-3.1 ,-5.1 ,-7.1 ,-8.8 ,-10  ,-10.8,-11.2,-11.3,-11.3,-11.2,-11.1,-11.1,-11  ,-11  ,-11  ,-11  ,-11.1,-11.3,-11.4,-11.6,-11.6,-11.7,-11.7,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,
                                                 0.6 ,0.4 ,0.4 ,0.4 ,0.3 ,-0.1,-0.9,-2.2 ,-4   ,-6   ,-7.9 ,-9.4 ,-10.4,-11  ,-11.2,-11.3,-11.3,-11.2,-11.1,-11  ,-11  ,-11  ,-11  ,-11.1,-11.2,-11.4,-11.5,-11.6,-11.7,-11.7,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,
                                                 0.6 ,0.3 ,0.3 ,0.4 ,0.3 ,0.2 ,-0.4,-1.4 ,-2.9 ,-4.9 ,-6.9 ,-8.6 ,-9.9 ,-10.7,-11.1,-11.3,-11.3,-11.2,-11.1,-11  ,-11  ,-11  ,-11  ,-11.1,-11.2,-11.3,-11.5,-11.6,-11.7,-11.7,-11.7,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,
                                                 0.7 ,0.3 ,0.3 ,0.3 ,0.4 ,0.3 ,-0  ,-0.8 ,-2   ,-3.8 ,-5.8 ,-7.7 ,-9.3 ,-10.3,-10.9,-11.2,-11.3,-11.2,-11.2,-11.1,-11  ,-11  ,-11  ,-11  ,-11.1,-11.3,-11.4,-11.6,-11.6,-11.7,-11.7,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,
                                                 0.7 ,0.3 ,0.2 ,0.2 ,0.3 ,0.4 ,0.2 ,-0.3 ,-1.3 ,-2.8 ,-4.7 ,-6.7 ,-8.5 ,-9.8 ,-10.6,-11  ,-11.2,-11.2,-11.2,-11.1,-11  ,-11  ,-11  ,-11  ,-11.1,-11.2,-11.4,-11.5,-11.6,-11.7,-11.7,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,
                                                 0.8 ,0.3 ,0.2 ,0.2 ,0.3 ,0.4 ,0.3 ,0    ,-0.7 ,-1.9 ,-3.6 ,-5.6 ,-7.5 ,-9.1 ,-10.2,-10.8,-11.1,-11.2,-11.2,-11.1,-11.1,-11  ,-11  ,-11  ,-11.1,-11.2,-11.3,-11.5,-11.6,-11.7,-11.7,-11.7,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,
                                                 0.9 ,0.3 ,0.1 ,0.1 ,0.2 ,0.3 ,0.4 ,0.2  ,-0.2 ,-1.1 ,-2.6 ,-4.5 ,-6.5 ,-8.3 ,-9.6 ,-10.5,-11  ,-11.2,-11.2,-11.2,-11.1,-11  ,-11  ,-11  ,-11.1,-11.1,-11.3,-11.4,-11.6,-11.6,-11.7,-11.7,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,
                                                 1.1 ,0.3 ,0.1 ,0   ,0.1 ,0.3 ,0.4 ,0.3  ,0.1  ,-0.5 ,-1.7 ,-3.4 ,-5.4 ,-7.3 ,-8.9 ,-10.1,-10.7,-11.1,-11.2,-11.2,-11.1,-11.1,-11  ,-11  ,-11  ,-11.1,-11.2,-11.4,-11.5,-11.6,-11.7,-11.7,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,
                                                 1.2 ,0.4 ,0.1 ,-0  ,0.1 ,0.2 ,0.3 ,0.4  ,0.3  ,-0.1 ,-1   ,-2.4 ,-4.3 ,-6.3 ,-8.1 ,-9.5 ,-10.4,-10.9,-11.1,-11.2,-11.2,-11.1,-11.1,-11  ,-11  ,-11.1,-11.2,-11.3,-11.5,-11.6,-11.7,-11.7,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,
                                                 1.4 ,0.5 ,0.1 ,-0.1,-0  ,0.1 ,0.2 ,0.4  ,0.4  ,0.2  ,-0.4 ,-1.5 ,-3.2 ,-5.1 ,-7.1 ,-8.8 ,-10  ,-10.7,-11  ,-11.2,-11.2,-11.1,-11.1,-11  ,-11  ,-11.1,-11.2,-11.3,-11.4,-11.6,-11.7,-11.7,-11.7,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,
                                                 1.7 ,0.5 ,0.1 ,-0.1,-0.1,0   ,0.2 ,0.3  ,0.4  ,0.3  ,-0   ,-0.9 ,-2.2 ,-4   ,-6   ,-7.9 ,-9.4 ,-10.3,-10.9,-11.1,-11.2,-11.2,-11.1,-11.1,-11  ,-11.1,-11.1,-11.2,-11.4,-11.5,-11.6,-11.7,-11.7,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,
                                                 1.9 ,0.7 ,0.1 ,-0.1,-0.1,-0.1,0.1 ,0.2  ,0.4  ,0.4  ,0.2  ,-0.3 ,-1.4 ,-3   ,-4.9 ,-6.9 ,-8.6 ,-9.8 ,-10.6,-11  ,-11.1,-11.2,-11.1,-11.1,-11.1,-11.1,-11.1,-11.2,-11.3,-11.5,-11.6,-11.7,-11.7,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,
                                                 2.3 ,0.8 ,0.1 ,-0.1,-0.2,-0.1,0   ,0.2  ,0.3  ,0.4  ,0.4  ,0.1  ,-0.7 ,-2   ,-3.8 ,-5.8 ,-7.7 ,-9.2 ,-10.2,-10.8,-11.1,-11.2,-11.2,-11.1,-11.1,-11.1,-11.1,-11.2,-11.3,-11.4,-11.6,-11.7,-11.7,-11.7,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,
                                                 2.6 ,0.9 ,0.2 ,-0.1,-0.2,-0.2,-0.1,0.1  ,0.2  ,0.4  ,0.5  ,0.3  ,-0.2 ,-1.2 ,-2.8 ,-4.7 ,-6.7 ,-8.5 ,-9.7 ,-10.5,-10.9,-11.1,-11.2,-11.1,-11.1,-11.1,-11.1,-11.1,-11.3,-11.4,-11.5,-11.6,-11.7,-11.7,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,
                                                 3   ,1.1 ,0.3 ,-0.1,-0.2,-0.2,-0.1,-0   ,0.2  ,0.3  ,0.5  ,0.5  ,0.2  ,-0.6 ,-1.8 ,-3.6 ,-5.6 ,-7.6 ,-9.1 ,-10.1,-10.7,-11  ,-11.1,-11.2,-11.1,-11.1,-11.1,-11.1,-11.2,-11.4,-11.5,-11.6,-11.7,-11.7,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,
                                                 3.5 ,1.4 ,0.3 ,-0.1,-0.3,-0.3,-0.2,-0.1 ,0.1  ,0.3  ,0.4  ,0.5  ,0.4  ,-0.1 ,-1.1 ,-2.6 ,-4.5 ,-6.5 ,-8.3 ,-9.6 ,-10.5,-10.9,-11.1,-11.2,-11.1,-11.1,-11.1,-11.1,-11.2,-11.3,-11.4,-11.6,-11.7,-11.7,-11.7,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,
                                                 4   ,1.6 ,0.4 ,-0.1,-0.3,-0.3,-0.3,-0.1 ,0    ,0.2  ,0.4  ,0.5  ,0.5  ,0.2  ,-0.4 ,-1.7 ,-3.4 ,-5.4 ,-7.4 ,-9   ,-10.1,-10.7,-11  ,-11.1,-11.2,-11.1,-11.1,-11.1,-11.2,-11.3,-11.4,-11.5,-11.6,-11.7,-11.7,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,
                                                 4.6 ,1.9 ,0.6 ,-0  ,-0.3,-0.3,-0.3,-0.2 ,-0.1 ,0.1  ,0.3  ,0.5  ,0.6  ,0.5  ,0    ,-0.9 ,-2.4 ,-4.3 ,-6.3 ,-8.1 ,-9.5 ,-10.4,-10.9,-11.1,-11.1,-11.1,-11.1,-11.1,-11.2,-11.2,-11.4,-11.5,-11.6,-11.7,-11.7,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,
                                                 5.2 ,2.2 ,0.7 ,0   ,-0.3,-0.3,-0.3,-0.3 ,-0.1 ,0    ,0.2  ,0.4  ,0.5  ,0.6  ,0.3  ,-0.3 ,-1.5 ,-3.2 ,-5.2 ,-7.2 ,-8.8 ,-10  ,-10.6,-11  ,-11.1,-11.2,-11.1,-11.1,-11.1,-11.2,-11.3,-11.5,-11.6,-11.7,-11.7,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,
                                                 6   ,2.6 ,0.9 ,0.1 ,-0.2,-0.4,-0.4,-0.3 ,-0.2 ,-0.1 ,0.1  ,0.3  ,0.5  ,0.6  ,0.5  ,0.1  ,-0.8 ,-2.2 ,-4.1 ,-6.1 ,-8   ,-9.4 ,-10.3,-10.8,-11.1,-11.1,-11.1,-11.1,-11.1,-11.2,-11.3,-11.4,-11.5,-11.6,-11.7,-11.7,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,
                                                 6.8 ,3   ,1.1 ,0.2 ,-0.2,-0.4,-0.4,-0.3 ,-0.2 ,-0.1 ,0    ,0.2  ,0.4  ,0.6  ,0.6  ,0.4  ,-0.2 ,-1.4 ,-3   ,-5   ,-7   ,-8.7 ,-9.9 ,-10.6,-11  ,-11.1,-11.2,-11.1,-11.1,-11.2,-11.3,-11.4,-11.5,-11.6,-11.7,-11.7,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,
                                                 7.7 ,3.5 ,1.3 ,0.3 ,-0.2,-0.4,-0.4,-0.4 ,-0.3 ,-0.2 ,-0   ,0.1  ,0.3  ,0.5  ,0.6  ,0.6  ,0.2  ,-0.7 ,-2.1 ,-3.9 ,-6   ,-7.8 ,-9.3 ,-10.2,-10.8,-11  ,-11.1,-11.2,-11.2,-11.2,-11.2,-11.3,-11.5,-11.6,-11.7,-11.7,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,
                                                 8.6 ,4   ,1.6 ,0.4 ,-0.1,-0.3,-0.4,-0.4 ,-0.3 ,-0.2 ,-0.1 ,0    ,0.2  ,0.4  ,0.6  ,0.6  ,0.4  ,-0.1 ,-1.2 ,-2.9 ,-4.8 ,-6.8 ,-8.5 ,-9.8 ,-10.5,-10.9,-11.1,-11.2,-11.2,-11.2,-11.2,-11.3,-11.4,-11.6,-11.6,-11.7,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,
                                                 9.7 ,4.6 ,1.9 ,0.6 ,-0.1,-0.3,-0.4,-0.4 ,-0.4 ,-0.3 ,-0.2 ,-0   ,0.1  ,0.3  ,0.5  ,0.6  ,0.6  ,0.2  ,-0.5 ,-1.9 ,-3.7 ,-5.8 ,-7.7 ,-9.2 ,-10.2,-10.7,-11  ,-11.1,-11.2,-11.2,-11.2,-11.3,-11.4,-11.5,-11.6,-11.7,-11.7,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,
                                                 10.8,5.3 ,2.2 ,0.7 ,0   ,-0.3,-0.4,-0.4 ,-0.4 ,-0.3 ,-0.2 ,-0.1 ,0.1  ,0.2  ,0.4  ,0.6  ,0.6  ,0.5  ,-0   ,-1.1 ,-2.7 ,-4.6 ,-6.7 ,-8.4 ,-9.7 ,-10.5,-10.9,-11.1,-11.2,-11.2,-11.2,-11.3,-11.4,-11.5,-11.6,-11.7,-11.7,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,
                                                 12  ,6   ,2.6 ,0.9 ,0.1 ,-0.2,-0.4,-0.4 ,-0.4 ,-0.4 ,-0.3 ,-0.2 ,-0   ,0.1  ,0.3  ,0.5  ,0.6  ,0.6  ,0.3  ,-0.4 ,-1.7 ,-3.5 ,-5.6 ,-7.5 ,-9   ,-10.1,-10.7,-11  ,-11.1,-11.2,-11.2,-11.2,-11.3,-11.5,-11.6,-11.7,-11.7,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,
                                                 13.3,6.8 ,3   ,1.1 ,0.2 ,-0.2,-0.4,-0.4 ,-0.4 ,-0.4 ,-0.3 ,-0.2 ,-0.1 ,0    ,0.2  ,0.4  ,0.6  ,0.7  ,0.5  ,0.1  ,-0.9 ,-2.5 ,-4.4 ,-6.5 ,-8.2 ,-9.6 ,-10.4,-10.9,-11.1,-11.2,-11.2,-11.2,-11.3,-11.4,-11.5,-11.6,-11.7,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,
                                                 14.7,7.7 ,3.5 ,1.4 ,0.3 ,-0.2,-0.4,-0.4 ,-0.4 ,-0.4 ,-0.3 ,-0.3 ,-0.2 ,-0   ,0.1  ,0.3  ,0.5  ,0.7  ,0.7  ,0.4  ,-0.3 ,-1.6 ,-3.3 ,-5.4 ,-7.3 ,-8.9 ,-10  ,-10.6,-11  ,-11.1,-11.2,-11.2,-11.3,-11.4,-11.5,-11.6,-11.7,-11.7,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,
                                                 16.2,8.7 ,4.1 ,1.6 ,0.4 ,-0.1,-0.3,-0.4 ,-0.4 ,-0.4 ,-0.4 ,-0.3 ,-0.2 ,-0.1 ,0    ,0.2  ,0.4  ,0.6  ,0.7  ,0.6  ,0.1  ,-0.8 ,-2.3 ,-4.2 ,-6.3 ,-8.1 ,-9.5 ,-10.3,-10.8,-11.1,-11.2,-11.2,-11.3,-11.4,-11.5,-11.6,-11.7,-11.7,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,
                                                 17.7,9.8 ,4.7 ,1.9 ,0.6 ,-0  ,-0.3,-0.4 ,-0.4 ,-0.4 ,-0.4 ,-0.4 ,-0.3 ,-0.2 ,-0   ,0.1  ,0.3  ,0.5  ,0.7  ,0.7  ,0.4  ,-0.2 ,-1.4 ,-3.2 ,-5.2 ,-7.2 ,-8.8 ,-9.9 ,-10.6,-11  ,-11.1,-11.2,-11.3,-11.3,-11.4,-11.6,-11.7,-11.7,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,
                                                 19.3,10.9,5.4 ,2.3 ,0.8 ,0.1 ,-0.3,-0.4 ,-0.4 ,-0.4 ,-0.4 ,-0.4 ,-0.3 ,-0.2 ,-0.1 ,0    ,0.2  ,0.4  ,0.6  ,0.7  ,0.6  ,0.2  ,-0.7 ,-2.1 ,-4.1 ,-6.1 ,-7.9 ,-9.3 ,-10.3,-10.8,-11.1,-11.2,-11.2,-11.3,-11.4,-11.5,-11.6,-11.7,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,
                                                 20.9,12.1,6.1 ,2.7 ,1   ,0.1 ,-0.2,-0.4 ,-0.4 ,-0.5 ,-0.4 ,-0.4 ,-0.4 ,-0.3 ,-0.2 ,-0   ,0.1  ,0.3  ,0.5  ,0.7  ,0.7  ,0.5  ,-0.1 ,-1.3 ,-3   ,-5   ,-7   ,-8.6 ,-9.8 ,-10.5,-10.9,-11.1,-11.2,-11.3,-11.4,-11.5,-11.6,-11.7,-11.7,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,
                                                 22.6,13.5,6.9 ,3.1 ,1.2 ,0.2 ,-0.2,-0.4 ,-0.4 ,-0.5 ,-0.5 ,-0.4 ,-0.4 ,-0.3 ,-0.2 ,-0.1 ,0    ,0.2  ,0.4  ,0.6  ,0.7  ,0.7  ,0.3  ,-0.6 ,-2   ,-3.9 ,-5.9 ,-7.8 ,-9.2 ,-10.2,-10.8,-11  ,-11.2,-11.3,-11.4,-11.5,-11.6,-11.7,-11.7,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,
                                                 24.3,14.9,7.8 ,3.6 ,1.4 ,0.4 ,-0.1,-0.3 ,-0.4 ,-0.5 ,-0.5 ,-0.4 ,-0.4 ,-0.4 ,-0.3 ,-0.2 ,-0.1 ,0.1  ,0.3  ,0.5  ,0.7  ,0.7  ,0.6  ,-0   ,-1.1 ,-2.8 ,-4.8 ,-6.8 ,-8.5 ,-9.7 ,-10.5,-10.9,-11.1,-11.2,-11.3,-11.4,-11.5,-11.6,-11.7,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,
                                                 26  ,16.3,8.8 ,4.2 ,1.7 ,0.5 ,-0.1,-0.3 ,-0.4 ,-0.5 ,-0.5 ,-0.5 ,-0.4 ,-0.4 ,-0.3 ,-0.2 ,-0.1 ,0    ,0.2  ,0.4  ,0.6  ,0.7  ,0.7  ,0.4  ,-0.4 ,-1.8 ,-3.7 ,-5.7 ,-7.6 ,-9.1 ,-10.1,-10.7,-11  ,-11.2,-11.3,-11.4,-11.5,-11.6,-11.7,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,
                                                 27.7,17.9,9.9 ,4.8 ,2   ,0.6 ,-0  ,-0.3 ,-0.4 ,-0.5 ,-0.5 ,-0.5 ,-0.5 ,-0.4 ,-0.4 ,-0.3 ,-0.2 ,-0.1 ,0.1  ,0.3  ,0.5  ,0.7  ,0.8  ,0.6  ,0.1  ,-1   ,-2.6 ,-4.6 ,-6.6 ,-8.4 ,-9.6 ,-10.4,-10.9,-11.1,-11.3,-11.4,-11.5,-11.6,-11.7,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,
                                                 29.3,19.5,11  ,5.4 ,2.4 ,0.8 ,0.1 ,-0.3 ,-0.4 ,-0.5 ,-0.5 ,-0.5 ,-0.5 ,-0.4 ,-0.4 ,-0.3 ,-0.2 ,-0.1 ,0    ,0.2  ,0.4  ,0.6  ,0.8  ,0.7  ,0.4  ,-0.3 ,-1.7 ,-3.5 ,-5.5 ,-7.5 ,-9   ,-10  ,-10.7,-11  ,-11.2,-11.3,-11.5,-11.6,-11.7,-11.7,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,
                                                 30.9,21.1,12.3,6.2 ,2.7 ,1   ,0.2 ,-0.2 ,-0.4 ,-0.5 ,-0.5 ,-0.5 ,-0.5 ,-0.5 ,-0.4 ,-0.4 ,-0.3 ,-0.2 ,-0.1 ,0.1  ,0.3  ,0.5  ,0.7  ,0.8  ,0.7  ,0.2  ,-0.8 ,-2.4 ,-4.4 ,-6.4 ,-8.2 ,-9.5 ,-10.4,-10.9,-11.1,-11.3,-11.4,-11.5,-11.6,-11.7,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,
                                                 32.5,22.8,13.6,7   ,3.2 ,1.2 ,0.3 ,-0.2 ,-0.4 ,-0.5 ,-0.5 ,-0.5 ,-0.5 ,-0.5 ,-0.4 ,-0.4 ,-0.3 ,-0.2 ,-0.1 ,0    ,0.2  ,0.4  ,0.6  ,0.8  ,0.8  ,0.5  ,-0.2 ,-1.5 ,-3.3 ,-5.3 ,-7.3 ,-8.9 ,-10  ,-10.6,-11  ,-11.2,-11.4,-11.5,-11.6,-11.7,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,
                                                 34  ,24.5,15  ,7.9 ,3.7 ,1.5 ,0.4 ,-0.1 ,-0.3 ,-0.4 ,-0.5 ,-0.5 ,-0.5 ,-0.5 ,-0.5 ,-0.4 ,-0.4 ,-0.3 ,-0.2 ,-0.1 ,0.1  ,0.3  ,0.5  ,0.7  ,0.8  ,0.7  ,0.3  ,-0.7 ,-2.2 ,-4.2 ,-6.3 ,-8.1 ,-9.4 ,-10.3,-10.8,-11.1,-11.3,-11.5,-11.6,-11.7,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,
                                                 35.4,26.1,16.5,8.9 ,4.2 ,1.7 ,0.5 ,-0.1 ,-0.3 ,-0.4 ,-0.5 ,-0.5 ,-0.5 ,-0.5 ,-0.5 ,-0.4 ,-0.4 ,-0.3 ,-0.3 ,-0.1 ,-0   ,0.2  ,0.4  ,0.6  ,0.8  ,0.8  ,0.6  ,-0.1 ,-1.3 ,-3.1 ,-5.1 ,-7.1 ,-8.7 ,-9.9 ,-10.6,-11  ,-11.2,-11.4,-11.6,-11.7,-11.7,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8,-11.8};

#endif // ARRAYS

