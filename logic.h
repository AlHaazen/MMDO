#ifndef LOGIC_H
#define LOGIC_H

#include <QString>

#include <vector>
#include <iostream>
#include <math.h>


using namespace std;

/*!
 * \brief MakeVector Робить одиничний вектор в m рядку n стовпця
 * \param m
 * \param n
 * \param matrix
 */
void MakeVector(int m, int n, vector<vector<double> > &matrix);
/*!
 * \brief FormSimlexRow формує симплекс рядок на основі
 * \param matrix матриці
 * \param value цін
 * \param simplex сюди записує результат
 * \param multi масив додаткових коефів
 * \return
 */
double FormSimlexRow(vector< vector<double> > &matrix, vector<double> &value, vector<double> &simplex, vector<double> &multi); //0!=0.0
/*!
 * \brief oVector перевіряє чи є n-ний стовпець матриці є одиничним вектором
 * \param matrix
 * \param n
 * \return -1 якщо щось пішло не так, x - рядок в якому є 1
 */
int oVector( vector< vector<double> > matrix, int n);
/*!
 * \brief ValidateSimplexRow дивиться на симплекс рядок
 * \param simplex
 * \return стовпець, який треба оптимізовувати
 */
int ValidateSimplexRow(vector<double> &simplex);
/*!
 * \brief MinimalGRZero шукає найменше додатнє число в n стовпці
 * \param n
 * \param matrix
 * \return
 */
int MinimalGRZero(int n,  vector< vector<double> > matrix);
/*!
 * \brief Simplex Крутить симплекс метод на основі вхідних даних
 * \param matrix вхідна матриця коефіцієнтів
 * \param value масив цін
 * \return форматована стрічка із проміжних обрахунків
 */
QString Simplex(vector<vector<double> > &matrix, vector<double> &value);
/*!
 * \brief formOutput формує стрічку, котра містить дані про матрицю
 * \param matrix
 * \param multi
 * \param value
 * \param simplex
 * \return
 */
QString formOutput(vector<vector<double> > &matrix, vector<double> &multi, vector<double> &value, vector<double> &simplex);

#endif // LOGIC_H
