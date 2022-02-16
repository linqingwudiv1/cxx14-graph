// Copyright (c) 2016 Andrew Sutton
// All rights reserved

#ifndef GRAPH_COMMON_HPP
#define GRAPH_COMMON_HPP

#include "utility.hpp"

#include <cstddef>
#include <vector>
#include <atomic>


namespace origin {

// Used to indicate the absence of labels on graphs and edges.
struct empty { };

// Represents a vertex within a graph.
using vertex_t = std::size_t;

// Represents an edge within a graph.
using edge_t = std::size_t;

// A list of incident edges.
using edge_list = std::vector<edge_t>;


// Construct a label over a vector.
template<typename T>
auto vertex_label(std::vector<T>& vec) {
  return [&vec](vertex_t v) -> T& { return vec[v]; };
}

// Construct a label over a vector.
template<typename T>
auto edge_label(std::vector<T>& vec) {
  return [&vec](edge_t e) -> T& { return vec[e]; };
}

// assign new id 
vertex_t new_edge_id()
{
	static std::atomic<vertex_t> cur_max_vertex = ATOMIC_VAR_INIT(0);
	return cur_max_vertex++;
}

// assign new id 
edge_t new_vertex_id()
{
	static std::atomic<edge_t> cur_max_edge = ATOMIC_VAR_INIT(0);
	return cur_max_edge++;
}

} // namespace origin

#endif
