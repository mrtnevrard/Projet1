//exercice 1

lc=0.1;



i_p=newp; Point(i_p) = {0,0,0,lc}; 
i_p=newp; Point(i_p) = {0,1,0,lc};
i_p=newp; Point(i_p) = {1,0,0,lc};
i_p=newp; Point(i_p) = {1,1,0,lc};

i_p=newp; Point(i_p) = {0,0.5,0,lc};
i_p=newp; Point(i_p) = {0.5,0,0,lc};


i_l=newl; Line(i_l) = {2,4};
i_l=newl; Line(i_l) = {4,3};
i_l=newl; Line(i_l) = {3,6};
i_l=newl; Line(i_l) = {5,2};

Circle(newl) = {5,1,6};

Line Loop (1) = {3,2,1,4,-5};

Plane Surface (news) = {1};

out[] = Extrude {{0,0,0},{-1,1,0},{-2,-2,0}, Pi} {Surface {6}; };

/*
Characteristic Length {1,2,3,4,5,6} = 0.5;

Field[1]=Attractor;
Field[1].EdgesList = {1};
Field[1].NodesList = {2};
Field[1].NNodesByEdge=5;

Field[2] = Threshold;
Field[2].IField = 1;
Field[2].LcMin = lc / 30;
Field[2].LcMax = lc;
Field[2].DistMin = 0.15;
Field[2].DistMax = 0.5;
*/
Background Field = 1;
