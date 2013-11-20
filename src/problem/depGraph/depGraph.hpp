/* $Id: depGraph.hpp 154 2009-06-16 18:52:53Z pbelotti $ */
/*
 * Name:    depGraph.hpp
 * Author:  Pietro Belotti
 * Purpose: class for manipulating dependencies between variables
 *
 * (C) Carnegie-Mellon University, 2007. 
 * This file is licensed under the Common Public License (CPL)
 */

#ifndef DEPGRAPH_HPP
#define DEPGRAPH_HPP

#include <vector>
#include <set>

#include "CouenneTypes.hpp"
#include "expression.hpp"
#include "exprAux.hpp"
#include "CouenneProblemElem.hpp"


/// structure for comparing nodes in the dependence graph
struct compNode {
  inline bool operator () (const DepNode *n0, const DepNode *n1) const;
};


/// vertex of a dependence graph. Contains variable and its forward
/// star (all variables it depends on)

class DepNode {

protected:

  /// index of variable associated with node
  int index_;

  /// index nodes on which this one depends (forward star in
  /// dependence graph)
  std::set <DepNode *, compNode> *depList_;

  /// order in which this variable should be updated, evaluated, etc.
  int order_;

public:

  /// fictitious constructor: only fill in index (such object is used
  /// in find() and then discarded)
  DepNode  (int ind):
    index_   (ind),
    depList_ (new std::set <DepNode *, compNode>),
    order_   (-1) {}

  /// destructor
  ~DepNode () 
  {if (depList_) delete depList_;}

  /// return index of this variable
  inline int Index () const 
  {return index_;}

  /// return index of this variable
  inline int Order () const 
  {return order_;}

  /// return all variables it depends on
  inline std::set <DepNode *, compNode> *DepList () const 
  {return depList_;}

  /// does this variable depend on variable with index xi?
  bool depends (int xi, bool = false, 
		std::set <DepNode *, compNode> *already_visited = NULL) const;

  /// assign numbering to all nodes of graph
  void createOrder (DepGraph *);

  /// debugging procedure
  void print (int = 0, bool descend = false) const;
};


/// structure for comparing nodes

bool compNode::operator () (const DepNode *n0, const DepNode *n1) const
{return (n0 -> Index () < n1 -> Index ());}


/// Dependence graph. Shows dependence of auxiliary variable on other
/// (auxiliary and/or original) variables

class DepGraph {

protected:

  /// set of variable nodes
  std::set <DepNode *, compNode> vertices_;

  /// counter to assign numbering to all nodes
  int counter_;

public:

  /// constructor
  DepGraph  (): counter_ (0) {}

  /// destructor
  ~DepGraph () {
    for (std::set <DepNode *, compNode>::iterator i = vertices_.begin ();
	 i != vertices_.end (); ++i) 
      delete (*i);
  }

  /// return vertex set
  std::set <DepNode *, compNode> &Vertices () 
  {return vertices_;}

  /// node index counter
  inline int &Counter () 
  {return counter_;}

  /// insert new variable if new
  void insert (exprVar *);

  /// insert new auxiliary if new
  void insert (exprAux *);

  /// delete element
  void erase (exprVar *);

  /// does w depend on x?
  bool depends (int, int, bool = false);

  /// assign numbering to all nodes of graph
  void createOrder ();

  /// debugging procedure
  void print (bool descend = false);

  /// search for node in vertex set
  DepNode *lookup (int index);

  /// check for dependence cycles in graph
  bool checkCycles ();
};

#endif
