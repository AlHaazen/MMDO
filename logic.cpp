#include "logic.h"


void MakeVector(int m, int n, vector<vector<double> > *matrix)
{
    // cout<<"SSM "<< (*matrix)[0][0];
    int i, j;
    int row = (*matrix).size(), col = (*matrix)[0].size();

    cout<<endl<<"SSM "<<row<<' ';
    cout<<col<<endl;

    if((*matrix)[m][n] == 0)
    {
        for(i = 0; i < row; i++)
            if((*matrix)[i][n] != 0)
                break;
        if(i == row+1)
            return;
        for(j = 0; j <col; j++)
            (*matrix)[m][j] += (*matrix)[i][j];
    }
    double a = (*matrix)[m][n];
    for(j = 0; j < col; j++)
        (*matrix)[m][j] /= a;
    for(i = 0; i < row; i++)
    {
        if(i == m)
            continue;
        a = (*matrix)[i][n];
        for(j = 0; j <col; j++)
            (*matrix)[i][j] -= a*(*matrix)[m][j];
    }
}

void MatrixOut(vector<vector<double> > *matrix)
{
    //    printf("\n");
    //    int i, j;
    //    for(j = 0; j < J-1; j++)
    //        printf("   X%d   ", j+1);
    //    printf("   B\n");
    //    for(i = 0; i < I; i++)
    //    {
    //        for(j = 0; j < J; j++)
    //            printf("% 7.3lf ", matrix[i][j]);
    //        printf("\n");
    //    }
    ////    printf("\n");
}

double FormSimlexRow(vector<vector<double> > *matrix, vector<double> *value, vector<double> *simplex, vector<double> *multi)
{
    int row = (*matrix).size(), col =  (*matrix)[0].size();

    double mult[row];
    int i, j, k;
    double result = 0;
    for(j = 0; j < col; j++)
    {
        if((k = oVector(*matrix, j)) != -1)
        {
            mult[k] = value->at(j);
            multi->at(k)=mult[k];
        }
    }
    for(j = 0; j <col; j++)
    {
        for(i = 0; i < row; i++)
            simplex->at(j) += mult[i]*(*matrix)[i][j];
        simplex->at(j) -= value->at(j);
    }

    for(i = 0; i < row; i++)
        result += mult[i]*(*matrix)[i][col-1];
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

int ValidateSimplexRow(vector<double> *simplex, int op)
{
    /// op
    /// 1 = min, -1 - max

    cout<<op<<endl;
    int r = -1, j;

    double min;
    if(op)
        min=-0;
    else
        min=0;

    for(j = 0; j <simplex->size()-1; j++)
       if(simplex->at(j) < 0 && !op || simplex->at(j) > 0 && op)
        {
            if(op)
            {
                if(min < simplex->at(j))
                {
                    min = simplex->at(j);
                    r = j;
                }
            }

            else
                if(min > simplex->at(j))
                {
                    min = simplex->at(j);
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
