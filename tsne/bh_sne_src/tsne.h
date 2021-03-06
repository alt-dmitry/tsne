/*
 *  tsne.h
 *  Header file for t-SNE.
 *
 *  Created by Laurens van der Maaten.
 *  Copyright 2012, Delft University of Technology. All rights reserved.
 *
 */


#ifndef TSNE_H
#define TSNE_H


static inline double sign(double x) { return (x == .0 ? .0 : (x < .0 ? -1.0 : 1.0)); }


class TSNE
{    
public:
    void run(double* X, int N, int D, double* Y, int no_dims, double perplexity, double theta, unsigned int seed, int max_iter=1000, int stop_lying_iter=250, int mom_switch_iter=250);
    bool load_data(double** data, int* n, int* d, double* theta, double* perplexity);
    void save_data(double* data, int* landmarks, double* costs, int n, int d);

    void symmetrizeMatrix(unsigned int** row_P, unsigned int** col_P, double** val_P, int N); // should be static!

    
private:
    void computeGradient(double* P, unsigned int* inp_row_P, unsigned int* inp_col_P, double* inp_val_P, double* Y, int N, int D, double* dC, double theta);
    void computeExactGradient(double* P, double* Y, int N, int D, double* dC);
    double evaluateError(double* P, double* Y, int N, int D);
    double evaluateError(unsigned int* row_P, unsigned int* col_P, double* val_P, double* Y, int N, int D, double theta);
    void zeroMean(double* X, int N, int D);
    void computeGaussianPerplexity(double* X, int N, int D, double* P, double perplexity);
    void computeGaussianPerplexity(double* X, int N, int D, unsigned int** _row_P, unsigned int** _col_P, double** _val_P, double perplexity, int K);
    void computeSquaredEuclideanDistance(double* X, int N, int D, double* DD);
    double randn();
};

#endif
