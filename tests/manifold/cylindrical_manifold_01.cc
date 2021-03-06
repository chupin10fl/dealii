//----------------------------  cylindrical_manifold_01.cc  ---------------------------
//    Copyright (C) 2011 - 2015 by the mathLab team.
//
//    This file is subject to LGPL and may not be  distributed
//    without copyright and license information. Please refer
//    to the file deal.II/doc/license.html for the  text  and
//    further information on this license.
//
//----------------------------  cylindrical_manifold_01.cc  ---------------------------


// Test cylindrical manifold on a cylinder

#include "../tests.h"


// all include files you need here
#include <deal.II/grid/tria.h>
#include <deal.II/grid/tria_accessor.h>
#include <deal.II/grid/tria_iterator.h>
#include <deal.II/grid/grid_generator.h>
#include <deal.II/grid/tria_boundary_lib.h>
#include <deal.II/grid/manifold_lib.h>
#include <deal.II/grid/grid_out.h>

// Helper function
template <int dim, int spacedim>
void test(unsigned int ref=1)
{
  deallog << "Testing dim " << dim
          << ", spacedim " << spacedim << std::endl;

  CylindricalManifold<dim,spacedim> manifold;

  Triangulation<dim,spacedim> tria;
  GridGenerator::cylinder (tria);

  for (typename Triangulation<dim,spacedim>::active_cell_iterator cell = tria.begin_active(); cell != tria.end(); ++cell)
    {
      cell->set_all_manifold_ids(1);
    }

  tria.set_manifold(1, manifold);
  tria.refine_global(1);

  GridOut gridout;
  gridout.write_msh(tria, deallog.get_file_stream());
}

int main ()
{
  initlog();

  test<3,3>();

  return 0;
}

