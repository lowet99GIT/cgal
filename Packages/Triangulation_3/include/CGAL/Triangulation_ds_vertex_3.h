// ============================================================================
//
// Copyright (c) 1998 The CGAL Consortium
//
// This software and related documentation is part of an INTERNAL release
// of the Computational Geometry Algorithms Library (CGAL). It is not
// intended for general use.
//
// ----------------------------------------------------------------------------
//
// release       :
// release_date  :
//
// file          : include/CGAL/Triangulation_ds_vertex_3.h
// revision      : $Revision$
// author(s)     : Monique Teillaud <Monique.Teillaud@sophia.inria.fr>
//
// coordinator   : INRIA Sophia Antipolis 
//                 (Mariette Yvinec <Mariette.Yvinec@sophia.inria.fr>)
//
// ============================================================================
//
// vertex of a combinatotial triangulation of any dimension <=3
//
// ============================================================================

#ifndef CGAL_TRIANGULATION_DS_VERTEX_3_H
#define CGAL_TRIANGULATION_DS_VERTEX_3_H

#include <CGAL/Triangulation_ds_iterators_3.h>

CGAL_BEGIN_NAMESPACE

template <class Vb, class Cb >
class  Triangulation_ds_vertex_3 
  : public Vb
{

public:
  typedef typename Vb::Point Point;
  typedef Triangulation_ds_vertex_3<Vb,Cb> Vertex;
  typedef Triangulation_ds_cell_3<Vb,Cb> Cell;
//   typedef Triangulation_ds_cell_circulator_3<Vertex,Cell> Cell_circulator;
//   typedef Triangulation_ds_vertex_circulator_3<Vertex,Cell> Vertex_circulator;
//   typedef Triangulation_ds_edge_circulator_3<Vertex,Cell> Edge_circulator;

  // CONSTRUCTORS

  inline 
  Triangulation_ds_vertex_3()
    : Vb()
  {}
    
  inline 
  Triangulation_ds_vertex_3(const Point & p)
    :  Vb(p)
  {}
    
  inline 
  Triangulation_ds_vertex_3(const Point & p, Cell * c)
    :  Vb(p, c)
  {}

  inline 
  Triangulation_ds_vertex_3(Cell * c)
    :  Vb(c)
  {}

  // ACCESS

  // point()
  //inherited from Vb

  inline 
  Cell* cell() const
  {
    return ( (Cell *) (Vb::cell()) );
  }
    
  // SETTING

  // set_point()
  //inherited from Vb

  inline 
  void set_cell(Cell* c)
  {
    Vb::set_cell(c);
  }

  inline 
  void set_point(const Point & p)
  {
    Vb::set_point(p);
  }

  // USEFUL CONSTANT TIME FUNCTIONS

  // USEFUL NON CONSTANT TIME FUNCTIONS

//   int degree() const
//   {
// TBD with edge circulator
//   }
  
//   inline Vertex_circulator incident_vertices()
//   {
//     return Vertex_circulator(this, cell());
//   }
    
//   inline Cell_circulator incident_cells()
//   {
//     return Cell_circulator(this, cell());
//   }
    
//   inline Cell_circulator incident_cells(const Cell* c)
//   {
//     return Cell_circulator(this, c);
//   }
    
//   inline Edge_circulator incident_edges()
//   {
//     return Edge_circulator(this, cell());
//   }
       
//   inline Edge_circulator incident_edges(const Cell* c)
//   {
//     return Edge_circulator(this, c);
//   }

    
  // CHECKING

   bool is_valid(bool verbose = false, int level = 0) const
  {
    bool result = Vb::is_valid(verbose,level);
    result = result && cell()->has_vertex(this);
    if ( ! result ) {
      if ( verbose ) {
	std::cerr << "invalid vertex" << std::endl;
      }
      CGAL_triangulation_assertion(false);
    }
    return result;
  }
};

CGAL_END_NAMESPACE

#endif // CGAL_TRIANGULATION_DS_VERTEX_3_H
