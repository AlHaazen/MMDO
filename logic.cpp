#include "logic.h"

void MakeVector(int m, int n, vector<vector<double> > &matrix)
{

    int i, j;
    int row = matrix.size(), col = matrix[0].size();

    if(matrix[m][n] == 0)
    {
        for(i = 0; i < row; i++)
            if(matrix[i][n] != 0)
                break;
        if(i == row+1)
            return;
        for(j = 0; j <col; j++)
            matrix[m][j] += matrix[i][j];
    }

    double a = matrix[m][n];
    for(j = 0; j < col; j++)
        matrix[m][j] /= a;
    for(i = 0; i < row; i++)
    {
        if(i == m)
            continue;
        a = matrix[i][n];
        for(j = 0; j <col; j++)
            matrix[i][j] -= a*matrix[m][j];
    }
}

double FormSimlexRow(vector<vector<double> > &matrix, vector<double> &value, vector<double> &simplex, vector<double> &multi)
{
    int row = matrix.size(), col =  matrix[0].size();

    double mult[row];
    int i, j, k;
    double result = 0;
    for(j = 0; j < col-1; j++)
    {
        if((k = oVector(matrix, j)) != -1)
        {
            mult[k] = value.at(j);
            multi.at(k)=mult[k];
        }
    }

    for(j = 0; j <col; j++)
    {
        for(i = 0; i < row; i++)
            simplex.at(j) += mult[i]*matrix[i][j];
        simplex.at(j) -= value.at(j);
    }

    for(i = 0; i < row; i++)
        result += mult[i]*matrix[i][col-1];

    simplex.at(simplex.size()-1) = result;
    return result;
}

int  oVector(vector<vector<double> > matrix, int n)
{
    int row = matrix.size(), col = matrix[0].size();
    int i, zero = 0, one = -1;
    for(i = 0; i <row; i++)
        if(matrix[i][n] == 0)
            zero++;
        else
            if(matrix[i][n] == 1)
                one = i;
            else
                return -1;
    if(zero == row-1 && one != -1)
        return one;
    else
        return -1;
}

int ValidateSimplexRow(vector<double> &simplex)
{
    int r = -1, j;

    double min = INFINITY;

    for(j = 0; j <simplex.size()-1; j++)
        if(simplex.at(j) < 0)
        {
            if(min > simplex.at(j))
            {
                min = simplex.at(j);
                r = j;
            }

        }
        else
            continue;

    return r;
}

int MinimalGRZero(int n, vector<vector<double> > matrix)
{
    int row = matrix.size(), col = matrix[0].size();
    double MGRZ = 10000005000000;
    int i, r = -1;
    for(i = 0; i <row; i++)
        if(matrix[i][n] > 0 && matrix[i][col-1] >= 0)
            if(matrix[i][col-1]/matrix[i][n] < MGRZ)
            {
                r = i;
                MGRZ = matrix[i][col-1]/matrix[i][n];
            }
    return r;
}

QString Simplex(vector<vector<double> > &matrix, vector<double> &value)
{
    QString stringResult = "";
    int validatei, validatej = 0;

    while(validatej != -1)
    {
        vector<double> simplex;
        simplex.resize(matrix[0].size(),0);

        vector<double> multi;
        multi.resize(matrix.size(),0);

        FormSimlexRow(matrix, value, simplex,multi);

        stringResult += formOutput(matrix,multi,value,simplex);
        stringResult +="\n\n\n";

        validatej = ValidateSimplexRow(simplex);

        if(validatej != -1)
        {
            validatei = MinimalGRZero(validatej, matrix);
            if(validatei == -1)
            {
                cout << "Не сумісна матриця\n";
                return "";
            }
            MakeVector(validatei, validatej,matrix);
        }
    }
    return stringResult;
}

QString formOutput(vector<vector<double> > &matrix, vector<double> &multi, vector<double> &value, vector<double> &simplex)
{
    QString s = "";
    s += QString("\t");
    for(unsigned i = 0; i < matrix[0].size() - 1; i++)
    {
        QString buf;
        buf.sprintf(" X%d\t", i+1);
        s += buf;
    }
    s += QString(" B\n");

    s += QString("C\t");
    for(unsigned i = 0; i < matrix[0].size() - 1; i++)
    {
        QString buf;
        if(fabs(value[i]) > 100000)// треба буде подумати
            buf.sprintf(" -M\t");
        else
            buf.sprintf(" %.2lf\t", value[i]);
        s += buf;
    }
    s += "\n";

    for(unsigned i = 0; i < matrix.size(); i++)
    {
        if(fabs(multi[i]) < 100000)
            s += QString(" %1\t|").arg(multi[i]);
        else
            s += QString(multi[i] < 0 ? "-M\t|":" M\t|");
        for(unsigned j = 0; j < matrix[0].size(); j++)
        {
            QString buf;
            buf.sprintf("% .2lf", matrix[i][j]);
            s+=buf;
            if(j<matrix[0].size()-1)
                s+="\t";

        }
        s += "\n";
    }
    s+="Simplex row:\n\t";
    for(unsigned i = 0; i < matrix[0].size(); i++)
    {

        QString buf;
        if(fabs(simplex[i]) < 100000)// треба буде подумати
            buf.sprintf("% .2lf\t", simplex[i]);
        else
            buf.sprintf(simplex[i] < 0 ? "-M\t":" M\t");
        s+=buf;
    }

    return s;
}
