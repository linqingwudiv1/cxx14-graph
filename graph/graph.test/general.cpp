// Copyright (c) 2016 Andrew Sutton
// All rights reserved

#include "../graph.hpp"
#include "../output.hpp"

#include <cassert>
#include <iostream>


#include "../ngraph.hpp"

using namespace origin;
using namespace NGraph;

int
main()
{
  using G = graph<char, int>;
  G g;
  
  //array of verties id
  vertex_t v[] {
    g.add_vertex('a'), // 0
    g.add_vertex('b'), // 1
    g.add_vertex('c'), // 2
    g.add_vertex('d'), // 3
    g.add_vertex('e'), // 4
    g.add_vertex('f')  // 5
  };

  //array of edges id
  edge_t e[] {
    g.add_edge(v[0], v[1], 0), // a -- b, line id
    g.add_edge(v[0], v[3], 1), // a -- d, line id
    g.add_edge(v[1], v[2], 2), // b -- c, line id
    g.add_edge(v[1], v[3], 3), // b -- d, line id
    g.add_edge(v[2], v[0], 4), // c -- a, line id
    g.add_edge(v[3], v[2], 5), // d -- c, line id
    g.add_edge(v[4], v[5], 6), // e -- f, line id
  };

  assert(g.num_vertices() == 6);
  assert(g.num_edges() == 7);

  assert(g.degree(0) == 3);
  assert(g.degree(1) == 3);
  assert(g.degree(2) == 3);
  assert(g.degree(3) == 3);
  assert(g.degree(4) == 1);
  assert(g.degree(5) == 1);

  // TODO: Verify out- and in-edge lists for the graph.

  assert(g.has_edge(0, 1));
  assert(g.has_edge(1, 0));
  assert(g.first(0) == 0);
  assert(g.second(0) == 1);
  assert(g.opposite(0, 0) == 1);
  assert(g.opposite(0, 1) == 0);
  
  assert(g.has_edge(0, 3));
  assert(g.has_edge(3, 0));
  assert(g.first(1) == 0);
  assert(g.second(1) == 3);
  assert(g.opposite(1, 0) == 3);
  assert(g.opposite(1, 3) == 0);

  assert(g.has_edge(1, 2));
  assert(g.has_edge(2, 1));
  assert(g.first(2) == 1);
  assert(g.second(2) == 2);
  assert(g.opposite(2, 1) == 2);
  assert(g.opposite(2, 2) == 1);

  assert(g.has_edge(1, 3));
  assert(g.has_edge(3, 1));
  assert(g.first(3) == 1);
  assert(g.second(3) == 3);
  assert(g.opposite(3, 1) == 3);
  assert(g.opposite(3, 3) == 1);

  assert(g.has_edge(2, 0));
  assert(g.has_edge(0, 2));
  assert(g.first(4) == 2);
  assert(g.second(4) == 0);
  assert(g.opposite(4, 2) == 0);
  assert(g.opposite(4, 0) == 2);

  assert(g.has_edge(3, 2));
  assert(g.has_edge(2, 3));
  assert(g.first(5) == 3);
  assert(g.second(5) == 2);
  assert(g.opposite(5, 3) == 2);
  assert(g.opposite(5, 2) == 3);

  assert(g.has_edge(4, 5));
  assert(g.has_edge(5, 4));
  assert(g.first(6) == 4);
  assert(g.second(6) == 5);
  assert(g.opposite(6, 4) == 5);
  assert(g.opposite(6, 5) == 4);

  // Make sure non-existent edges don't exist.
  assert(!g.has_edge(0, 5));


  // print 
  print_graph<G> print(std::cout, g);
  print();



#pragma region nGraph
  tGraph<std::size_t> g1;
  char v1[]{ 'a','b','c','d','e', 'f'};
  
  g1.set_undirected();
  
  g1.insert_vertex(0);
  g1.insert_vertex(1);
  g1.insert_vertex(2);
  g1.insert_vertex(3);
  g1.insert_vertex(4);
  g1.insert_vertex(5);

  g1.insert_undirected_edge(0, 1);
  g1.insert_undirected_edge(0, 3);
  g1.insert_undirected_edge(1, 2);
  g1.insert_undirected_edge(1, 3);
  g1.insert_undirected_edge(2, 0);
  g1.insert_undirected_edge(3, 2);
  g1.insert_undirected_edge(4, 5);
  
  assert(g1.num_vertices() == 6);
  assert(g1.num_edges() == 7);

  assert(g1.degree(0) == 3);
  assert(g1.degree(1) == 3);
  assert(g1.degree(2) == 3);
  assert(g1.degree(3) == 3);
  assert(g1.degree(4) == 1);
  assert(g1.degree(5) == 1);
  
  assert(g1.has_edge(0, 1));
  assert(g1.has_edge(1, 0));

  //assert(g1.first(0) == 0);
  //assert(g1.second(0) == 1);
  //assert(g1.opposite(0, 0) == 1);
  //assert(g1.opposite(0, 1) == 0);



  g1.print();
  //g1.edge_list
#pragma endregion
}
