#pragma once
#ifndef MATRIXUTLILS_H
#define MATRIXUTLILS_H

#include "linalg.h"
#include "linked_node.h"
#include <set>
#include <unordered_set>
#include <vector>

using namespace linalg;

/*
* Various matrix related functions
*/

template<typename F>
static F det(matrix<F> A);
template<typename F>
static matrix<F> adj(matrix<F> A);
template<typename F>
static matrix<F> rref(matrix<F> A, matrix<F> b = matrix<F>());
template<typename F>
static std::vector<matrix<F>> ker(matrix<F> A);
template<typename F>
static matrix<F> solve(matrix<F> A, matrix<F> b);
template<typename F>
static matrix<F> aug(matrix<F> A, matrix<F> b);
template<typename F>
static matrix<F> proj_matrix(initializer_list<matrix<F>> span); 
template<typename F>
static matrix<F> inv(matrix<F> A);

using vec = matrix<realnum>;
using vertex = linked_node<vec>;

static vec centroid(vector<vertex> points) {
	int dim = points[0].data.get_rows();
	vector<realnum> center(dim);

	for (int i = 0; i < dim; i++) { center[i] = 0; }
	for (vertex point : points) {
		for (int i = 0; i < dim; i++) { center[i] += point.data[i][0]; }
	}
	for (int i = 0; i < dim; i++) { center[i] /= (realnum)points.size(); }

	return vec(center);
}





#include "matrixutils.hpp"

#endif

