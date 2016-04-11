#ifndef LOGIC_H
#define LOGIC_H

#include <vector>
#include <iostream>
#include <math.h>

using namespace std;


void MakeVector(int m, int n, vector<vector<double> > *matrix);
void MatrixOut( vector< vector<double> > *matrix);
double FormSimlexRow(vector< vector<double> > *matrix, vector<double> *value, vector<double> *simplex, vector<double> *multi); //0!=0.0
int oVector( vector< vector<double> > matrix, int n);
int ValidateSimplexRow(vector<double> *simplex, int op);
int MinimalGRZero(int n,  vector< vector<double> > matrix);


#endif // LOGIC_H
