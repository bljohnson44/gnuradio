/* -*- c++ -*- */
/*
 * Copyright 2007 Free Software Foundation, Inc.
 * 
 * This file is part of GNU Radio
 * 
 * GNU Radio is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2, or (at your option)
 * any later version.
 * 
 * GNU Radio is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with GNU Radio; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

// @WARNING@

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <@NAME@.h>
#include <gr_io_signature.h>

@SPTR_NAME@
gr_make_@BASE_NAME@ ()
{
  return @SPTR_NAME@ (new @NAME@ ());
}

@NAME@::@NAME@ ()
  : gr_sync_block ("@BASE_NAME@",
		   gr_make_io_signature (2, 2, sizeof (@I_TYPE@)),
		   gr_make_io_signature (1, 1, sizeof (@O_TYPE@))),
    d_data(0)
{
}

int
@NAME@::work (int noutput_items,
		   gr_vector_const_void_star &input_items,
		   gr_vector_void_star &output_items)
{
  @I_TYPE@ *iptr = (@I_TYPE@ *) input_items[0];
  @I_TYPE@ *ctrl = (@I_TYPE@ *) input_items[1];
  @O_TYPE@ *optr = (@O_TYPE@ *) output_items[0];

  for (int i = 0; i < noutput_items; i++){
    if(ctrl[i] > 0.5) {
      d_data = iptr[i];
    }
    optr[i] = d_data;
  }
  return noutput_items;
}
